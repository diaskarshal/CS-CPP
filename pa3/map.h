
#ifndef MAP_
#define MAP_  

#include <iostream>
#include <string> 
#include <concepts>
#include <utility>

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


struct treenode
{
   using keytype = std::string;
   // using keycmp = standard_cmp< keytype > ; 
   using keycmp = case_insensitive_cmp;
   using valtype = int;

   keytype key; 
   valtype val;

   treenode* left;
   treenode* right;

   treenode( const keytype& key, const valtype& val, 
             treenode* left = nullptr, treenode* right = nullptr )
      : key( key ),
        val( val ), 
        left( left ),
        right( right )  
   { }

};


const treenode* find( const treenode* n, const treenode::keytype& key );
   // Returns nullptr if not found.

treenode** find( treenode** n, const treenode::keytype& key ); 
   // Returns a pointer to nullptr if not found. 
   // The result itself is never nullptr.

size_t size( const treenode* n ); 
   // Returns the number of key/value pairs stored in the tree. 

void deallocate( treenode* n ); 
   // Deallocate the complete tree below n.

treenode* makecopy( const treenode* n );
   // Make a copy of the tree below n.

treenode* extractrightmost( treenode** from );
   // Extract and remove the rightmost tree below *from.

void print( std::ostream& out, const treenode* n, unsigned int indent );
   // Print the tree as tree.

size_t height( const treenode* n );
   // Returns the height of the tree starting at n.

unsigned int log_base2( size_t s );


class map
{
   treenode* tr;

   using keytype = treenode::keytype;
   using valtype = treenode::valtype; 
      // Never change this line! If you want to change the type,
      // change it in treenode. 

public: 
   map( ) 
      : tr( nullptr ) 
   { } 

   map( const map& other );
   map( map&& other );
   map& operator = ( const map& other );
   map& operator = ( map&& other );

   ~map( );

   bool contains( const keytype& key ) const;

   bool insert( const keytype& key, const valtype& val );
      // Returns true if the insertion took place.

   bool erase( const keytype& key );
      // Returns true if erasure took place.

   valtype& at( const keytype& key );
   const valtype& at( const keytype& key ) const;
   valtype& operator[] ( const keytype& key );

   size_t size( ) const; 
   size_t height( ) const; 

   bool empty( ) const; 
      // Must work in constant time!

   void clear( );

   void checksorted( ) const;
      // Check if the tree is sorted, and throw an exception
      // if it is not. Call this function often to check your
      // trees, but make your final performance tests without it.  

   void print( std::ostream& out, unsigned int indent = 0 ) const;

};


inline std::ostream& operator << ( std::ostream& out, const map& mp )
{
   mp. print( out );
   return out; 
}

#endif

