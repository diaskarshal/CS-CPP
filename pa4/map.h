
#ifndef MAP_
#define MAP_

#include <iostream>
#include <vector>
#include <string> 
#include <utility>
#include <cmath>
#include <limits>

struct case_insensitive_cmp
{
   case_insensitive_cmp( ) noexcept = default;

   int operator( ) ( const std::string& s1, const std::string& s2 ) const;
      // Case insensitive compare.
      // return a negative number if s1 < s2 (case insensitive).
      // return zero if s1 == s2 (case insensitive).
      // return a positive number if s1 > s2 (case insensitive).
};

template< std::totally_ordered T >
struct standard_cmp
{
   standard_cmp( ) noexcept = default;

   int operator( ) ( const T& t1, const T& t2 ) const
   {
      if( t1 < t2 ) return -1;
      if( t1 > t2 ) return 1;
      return 0;
   }
};

struct case_insensitive_hash
{
   case_insensitive_hash( ) noexcept = default;

   size_t operator( ) ( const std::string& s ) const;
      // Case insensitive hash function.
};


template< std::totally_ordered T >
struct standard_hash
{
   standard_hash( ) noexcept = default;

   size_t operator( ) ( const T& t ) const
   {
      std::hash<T> h;
      return h(t); 
   }
};


struct map
{
   using keytype = std::string;
   // using keyhash = standard_hash< keytype > ;
   // using keycmp = standard_cmp< keytype > ;
   using keyhash = case_insensitive_hash;
   using keycmp = case_insensitive_cmp;
   using valtype = std::string;

public:
   double max_load_factor;
      // Must lie between 0 and 1. 

   size_t truesize;
      // The number of cells that are in use.

   struct cell
   {
      keytype key;
      valtype val; 
      size_t dist;
         // We use std::numeric_limits< size_t > :: max( ) to indicate
         // that the cell is not in use. 

      cell( )
         : dist( std::numeric_limits< size_t > :: max( ))
      { }

      cell( const keytype& key, const valtype& val, size_t dist )
         : key( key ), 
           val( val ),
           dist( dist )
      { }

      cell( keytype&& key, valtype&& val, size_t dist )
         : key( std::move( key )),
           val( std::move( val )), 
           dist( dist )
      { }

      bool isempty( ) const
         { return dist == std::numeric_limits< size_t > :: max( ); }

      void clear( )
      {
         key = keytype( );  // Not really needed.
         val = valtype( );
         dist = std::numeric_limits< size_t > :: max( );
      }

      void print( std::ostream& out ) const; 
   };
 
   std::vector< cell > table;

   size_t exactposition( const keytype& key ) const; 
      // The exact position of key in the table.
      // (on which it would have dist == 0 ).

   size_t wrap( size_t pos ) const;
      // Restrict pos between 0 and table. size( ). 

   static size_t minpow3( size_t sz );
      // Smallest power of 3 that is >= sz. 

   size_t find( const keytype& key, size_t pos ) const;
      // Returns distance at which key was found, 
      // table. size( ) if it doesn't occur.

   void insert_shift_up( size_t pos, cell& c );
      // Insert c at position pos. 
      // If pos is occupied, swap c with table[ pos ]. After 
      // that we look upward for a place to reinsert c. 
      // This is either a place that is empty, or has a distance smaller
      // than the distance of c. In the place is not empty,
      // we swap and continue. 
 
   bool rehash_needed( size_t sz ) const
      { return sz > table. size( ) * max_load_factor; }

      // True if increasing the number of elements to sz would
      // make the load factor so high that a rehash would be needed.

   void rehash( size_t sz );
      // Rehash, so that we become big enough to contain sz elements,
      // taking into account the load factor. 
 
public:
   // Number of buckets cannot be zero. 
   // We always use powers of three. Best would be prime numbers close
   // to powers of two. 
   
   map( double max_load_factor = 0.75, size_t capacity = 3 ) 
      : max_load_factor( max_load_factor ),
        truesize(0),
        table( std::vector< cell > ( minpow3( capacity )))
   { 
      if( max_load_factor <= 0.01 )   
         throw std::logic_error( "max load factor must be > 0" ); 

      if( max_load_factor >= 0.99 )
         throw std::logic_error( "max load factor must be < 1" );
   }

   map( std::initializer_list< std::pair< keytype, valtype >> init, 
        double max_load_factor = 0.75 )
      : map( max_load_factor, init. size( ))
   {
      for( const auto& kv : init )
         insert( kv. first, kv. second );
   }

   map( const map& mp ) = default;

   map( map&& mp ) noexcept
      : max_load_factor( mp. max_load_factor ),
        truesize( std::exchange( mp. truesize, 0 )),
        table( std::exchange( mp. table, std::vector< cell > (3))) 
   { }

   map& operator = ( const map& mp ) = default;

   map& operator = ( map&& mp ) noexcept
   {
      max_load_factor = mp. max_load_factor;
      truesize = std::exchange( mp. truesize, 0 );
      table = std::exchange( mp. table, std::vector< cell > (3));
      return *this;  
   }

   bool contains( const keytype& key ) const; 

   bool insert( const keytype& key, const valtype& val );
      // Returns true if the insertion took place.

   const valtype& at( const keytype& key ) const;
   valtype& at( const keytype& k );

   valtype& operator [] ( const keytype& key );
      // Creates a default value if key is not present.

   bool erase( const keytype& key );
      // Returns true if s was found and removed.

   size_t size() const { return truesize; } 
   size_t capacity( ) const { return table. size( ); } 
   bool empty() const { return !truesize; } 

   void clear();
      // No need to decrease the number of buckets.
     
   void print( std::ostream& out ) const; 

   // The functions below are not part of 
   // the map interface, they are specific for hashing:

   double loadfactor() const 
   {
      return static_cast<double> ( truesize ) / table. size( ); 
         // C-style casts of form (double) map_size are deprecated. 
   }

   double average_dist( ) const;
   double standarddev() const;
      // I am not sure if these numbers have any use.

   void printstatistics( std::ostream& out ) const
   {
      out << "map size =            " << size( ) << "\n";
      out << "load factor =         " << loadfactor( ) <<
          " ( max = " << max_load_factor << " )\n";
      out << "standard deviation =  " << standarddev( ) << "\n";
   }

   void checkinvariants( ) const; 
};

inline std::ostream& operator << ( std::ostream& out, const map::cell& c )
{
   c. print( out );
   return out;
}

inline std::ostream& operator << ( std::ostream& out, const map& m ) 
{
   m. print( out );
   return out;
}

#endif


