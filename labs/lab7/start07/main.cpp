
#include <random>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

#include "map.h"
#include "timetable.h"
#include "timer.h"

// Make a string, using letters as digits.

std::string makestring( unsigned int x, const char* letters )
{
   unsigned int len = 0;
   while( letters[ len ] )
      ++ len;

   if( len < 2 )
      throw std::logic_error( "makestring: too few letters" );

   ++ x;

   std::string res;
   while( x )
   {
      unsigned int i = x % len;
      x /= len;

      res += letters[i];
   }
   return res;
}

std::vector< std::string >
randomstrings( size_t k, const char* letters )
{
   std::vector< std::string > res;
   for( size_t i = 0; i != k; ++ i )
   {
      res. push_back( makestring( rand( ) % ( 3 * k ), letters ));
   }
   return res;
}

std::string reverse( std::string s )
{
   auto p1 = s. begin( );
   auto p2 = s. end( );

   while( p1 + 1 < p2 )
   {
      -- p2;
      std::swap( *p1, *p2 );
      ++ p1;
   }

   return s;
}


int main( int argc, char* argv[ ] )
{
   // We are testing the performance of three implementations of
   // the map AST where both the key type and the value type are
   // std::string. These are
   //    Your own tree-based implementation of map.
   //    std::map in the STL (uses red/black trees).
   //    std::unordered_map in the STL (uses hashing with closed addressing).
   // We will be using the standard comparison on strings 
   // (i.e. case sensitive).

   // In addition, we check the effect of sorting on performance.
   // This gives a total of 6 combinations to be tested.
 
   timetable tab( std::string( "map using unsorted keys" ));

   for( size_t s = 1000; s < 4096 * 1000; s = 2 * s )
   {
      std::cout << "----------------------------------------\n";

      const char* alphabet = "abcdefghijklmnopqrstuvwxyz"; 
      std::vector< std::string > keys = randomstrings( s, alphabet );

      //  Turn on if you want to see the test vector.

      const bool i_want_to_see_the_test_vector = false;
      if( i_want_to_see_the_test_vector )
      {
         std::cout << "keys: ";
         for( const auto& k : keys )
            std::cout << k << " ";
         std::cout << "\n";
      }

      const bool mustsort = false;
      if( mustsort )
         sort( keys. begin( ), keys. end( ));

      // map testmap;
      std::unordered_map< std::string, std::string > testmap;

      timer tt;
      size_t nr_insertions = 0;
      size_t nr_contained = 0;
      size_t nr_deletions = 0;

      for( size_t i = 0; i != keys. size( ); ++ i )
      {
         if( i & 1 )
         {
            std::string value = reverse( keys[i] ) + keys[i];
            // nr_insertions += testmap. insert( keys[i], value );
            nr_insertions += testmap. insert( { keys[i], value } ). second;
         }
      }

      // Next we check presence of all of them:

      for( size_t i = 0; i != keys. size( ); ++ i )
      {
         if( testmap. contains( keys[i] ))
            ++ nr_contained;
      }

      if( nr_insertions != testmap. size( ))
         throw std::logic_error( "size differs from reported nr insertions" );
    
      // First we delete the keys that are on an index divisible by 3:

      for( size_t i = 0; i != keys. size( ); ++ i )
      {
         if( i % 3 == 0 ) 
            nr_deletions += testmap. erase( keys[i] );
      }

      // Next we delete everything:

      for( size_t i = 0; i != keys. size( ); ++ i )
      {
         nr_deletions += testmap. erase( keys[i] );
      }

      tab. insert( s, tt. time( ));
 
      std::cout << "number of insertions " << nr_insertions << "\n";
      std::cout << "number of deletions " << nr_deletions << "\n";

      if( nr_insertions != nr_deletions )
         throw std::logic_error( "insert or remove works incorrectly" );
   }

   std::cout << tab << "\n";
   std::cout << "totaltime " << tab. totaltime( ) << "\n";

}


