
#include "map.h"

// Should be copied from assignment 3: 

int case_insensitive_cmp::operator( ) 
      ( const std::string& s1, const std::string& s2 ) const
{
}


// must be written:

size_t case_insensitive_hash::operator( ) ( const std::string& s ) const
{
} 

size_t map::wrap( size_t pos ) const
{
}

size_t map::exactposition( const keytype& key ) const
{
}

size_t map::minpow3( size_t sz ) 
{
}

size_t map::find( const keytype& key, size_t pos ) const
{
}

void
map::insert_shift_up( size_t pos, cell& c ) 
{
}


bool map::contains( const keytype& key ) const
{
}

bool map::insert( const keytype& key, const valtype& val )
{
}

void map::rehash( size_t sz ) 
{
}

const map::valtype& map::at( const keytype& key ) const 
{
}

map::valtype& map::at( const keytype& key ) 
{
}

map::valtype& map::operator[] ( const keytype& key ) 
{
}

bool map::erase( const keytype& key ) 
{
}

void map::clear( ) 
{
}


void map::cell::print( std::ostream& out ) const
{
   if( isempty( ))
      out << "(empty)";
   else
      out << key << "/" << val << "      (" << dist << ")";
}

double map::average_dist( ) const
{
   // Contrary to our principles:

   if( truesize == 0 )
      return 0.0;

   double sum = 0.0;
   for( const auto& c : table )
   { 
      if( !c. isempty( ))
         sum += c. dist;
   }

   return sum / truesize;
}

double map::standarddev() const
{
   if( truesize == 0 )
      return 0.0;

   double sum = 0.0;
   double av = average_dist();

   for( const auto& c : table )
   {
      if( !c. isempty( ))
      {
         double dif = c. dist - av;
         sum += dif*dif;
      }
   }

   return sqrt( sum / truesize );
}


void map::print( std::ostream& out ) const
{
   out << "hashmap( max_load_factor = " << max_load_factor;
   out << ", size = " << truesize;
   out << ", capacity = " << table. size( ) << " ):\n";

   for( size_t pos = 0; pos != table. size( ); ++ pos )
   {
      if( !table[ pos ]. isempty( ))
         out << pos << " :    " << table[ pos ] << "\n";
   }
}


void map::checkinvariants( ) const
{
   if( table. size( ) < 3 )
      throw std::logic_error( "table size too small" );
 
   size_t i = 0;
   for( const auto& t : table )
   {
      if( !t. isempty( ))
         ++ i;
   }

   if( i != truesize )
   {
      std::cout << i << " / truesize = " << truesize << "\n"; 
      throw std::logic_error( "variable truesize does not hold the true size" );
   }

   if( i > table. size( ) * max_load_factor )
      throw std::logic_error( "load factor > max_load_factor" ); 

   for( size_t pos = 0; pos != table. size( ); ++ pos )
   {
      if( !table[ pos ]. isempty( )) 
      {
         size_t p = exactposition( table[ pos ]. key );
         size_t d = 0;
            // p is the true position where table[ pos ] should be.
 
         while( p != pos )
         {
            if( table[p]. isempty( ))
            {
               std::cout << "cell " << pos << " should have been at " << p << "\n";
               throw std::logic_error( "there is an empty cell" ); 
            }

            if( d > table[p]. dist )
            {
               std::cout << "cell " << pos << " should have been at " << p << "\n";
               throw std::logic_error( "its displacement is bigger" ); 
            }

            p = wrap( p + 1 );
            ++ d; 
         }

         if( table[ pos ]. dist != d )
         {
            std::cout << pos << " : " << table[ pos ];
            std::cout << " has wrong dist field\n";
            std::cout << exactposition( table[ pos ]. key ) << "\n";
            throw std::runtime_error( "distance is wrong" );
         }

      }
   }
}

