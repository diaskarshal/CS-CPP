
#include "map.h"

int case_insensitive_cmp::operator( ) 
      ( const std::string& s1, const std::string& s2 ) const
{
   // Don't make copies of the strings! 
}

const treenode* find( const treenode* n, const treenode::keytype& key )
{
}

treenode** find( treenode** n, const treenode::keytype& key )
{
}

size_t size( const treenode* n )
{
}

size_t height( const treenode* n )
{
}

void deallocate( treenode* n )
{
}

treenode* makecopy( const treenode* n ) 
{
}


// Step to the right as long as possible. When we get
// stuck, we are in the rightmost node. Remove it, and
// return it. (Don't delete it.)
// *from cannot be the empty tree.

treenode* extractrightmost( treenode** from )
{
   while( (*from) -> right )
      from = & (*from) -> right;

   treenode* n = *from;
   *from = (*from) -> left;
   return n;
}

void print( std::ostream& out, const treenode* n, unsigned int indent )
{

   for( unsigned int i = 0; i != indent; ++ i )
      out << "|  "; 
   if(n)
   {
      out << ( n -> key ) << " / " << ( n -> val ) << "\n";
      print( out, n -> left, indent + 1 );
      print( out, n -> right, indent + 1 ); 
   }
   else
      out << "#\n"; 
}


// Both the upperbound and the lowerbound are strict.
// We use pointers, so that they can be absent. 
// Of course, this is a tasteless way of dealing with partiality.

void checkbetween( const treenode* n, 
                   const treenode::keytype* lowerbound, 
                   const treenode::keytype* upperbound ) 
{
   treenode::keycmp cmp;

   while(n) 
   {
      if( lowerbound && cmp( *lowerbound, n -> key ) >= 0 ) 
      {
         std::cout << "key " << ( n -> key );
         std::cout << " is not above lower bound " << *lowerbound << "\n";
         throw std::runtime_error( "tree not correct" ); 
      }

      if( upperbound && cmp( *upperbound, n -> key ) <= 0 ) 
      {
         std::cout << "key " << ( n -> key );
         std::cout << "is not below upperbound " << *upperbound << "\n";
         throw std::runtime_error( "tree not correct" );  
      }

      checkbetween( n -> left, lowerbound, &( n -> key ));
      lowerbound = & ( n -> key );
      n = n -> right;
   }
} 


unsigned int log_base2( size_t s )
{
}
 
bool map::insert( const keytype& key, const valtype& val )
{
}

bool map::contains( const keytype& key ) const
{
}

map::valtype& map::at( const keytype& key ) 
{ 
}

const map::valtype& map::at( const keytype& key ) const
{ 
}

map::valtype& map::operator [] ( const keytype& key ) 
{
}

bool map::erase( const keytype& key )
{
}

size_t map::size( ) const
{
}

size_t map::height( ) const
{
}

bool map::empty( ) const
{
}

map:: ~map( )
{
}

void map::clear( )
{
}

map::map( const map& other )
{ 
}

map::map( map&& other )
{ 
}

map& map::operator = ( const map& other )
{
}

map& map::operator = ( map&& other )
{
}

void map::checksorted( ) const
{
   ::checkbetween( tr, nullptr, nullptr );
}

void map::print( std::ostream& out, unsigned int indent ) const
{
   ::print( out, tr, indent );
}

