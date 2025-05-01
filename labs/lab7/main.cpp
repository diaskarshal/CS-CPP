
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
 
   timetable tab( std::string( "map using sorted keys" ));

   for( size_t s = 1000; s < 512 * 1000; s = 2 * s )
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

      const bool mustsort = true;
      if( mustsort )
         sort( keys. begin( ), keys. end( ));

      map testmap;
      // std::map< std::string, std::string > testmap;

      timer tt;
      size_t nr_insertions = 0;
      size_t nr_contained = 0;
      size_t nr_deletions = 0;

      for( size_t i = 0; i != keys. size( ); ++ i )
      {
         if( i & 1 )
         {
            std::string value = reverse( keys[i] ) + keys[i];
            nr_insertions += testmap. insert( keys[i], value );
            // nr_insertions += testmap. insert( { keys[i], value } ). second;
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

/*
unsorted


for( size_t s = 100; s < 32768 * 1000; s = 2 * s )
std::unordered_map< std::string, std::string > testmap;

Performance table of map using unsorted keys (inputsize/runtime in seconds): ~O(n) overall, avg O(1) per operation
     100/2.1070e-05     200/2.5848e-05     400/5.0956e-05     800/9.4798e-05     1600/1.6936e-04     3200/3.3081e-04     6400/7.7381e-04     12800/1.5463e-03     25600/4.2572e-03     51200/6.0902e-03     102400/1.7588e-02     204800/3.8222e-02     409600/8.1172e-02     819200/2.1462e-01     1638400/5.8187e-01     3276800/1.3945e+00     6553600/3.0914e+00     13107200/6.5233e+00     26214400/1.3516e+01

totaltime 2.5472e+01
the results are aligned with the theoretical expectations

---

for( size_t s = 100; s < 16384 * 1000; s = 2 * s )
std::map< std::string, std::string > testmap;

Performance table of map using unsorted keys (inputsize/runtime in seconds): ~O(nlog(n)), more roughly ~O(n)
     100/2.8043e-05     200/4.7790e-05     400/1.0289e-04     800/2.2108e-04     1600/4.9771e-04     3200/1.0157e-03     6400/2.2269e-03     12800/6.5345e-03     25600/8.4928e-03     51200/2.1851e-02     102400/4.9679e-02     204800/9.8423e-02     409600/2.2870e-01     819200/7.2744e-01     1638400/2.0772e+00     3276800/4.6103e+00     6553600/1.1437e+01     13107200/2.5643e+01

totaltime 4.4913e+01
the results are aligned with the theoretical expectations,

---

for( size_t s = 100; s < 16384 * 1000; s = 2 * s )
map testmap;

Performance table of map using unsorted keys (inputsize/runtime in seconds): ~O(nlog(n)), more roughly ~O(n)
     100/1.9637e-05     200/3.5296e-05     400/7.9300e-05     800/1.8649e-04     1600/3.8058e-04     3200/9.0483e-04     6400/2.0012e-03     12800/5.0401e-03     25600/9.4415e-03     51200/2.1297e-02     102400/4.8411e-02     204800/9.7075e-02     409600/2.3464e-01     819200/6.2013e-01     1638400/1.6123e+00     3276800/4.1615e+00     6553600/1.0842e+01     13107200/2.6631e+01

totaltime 4.4286e+01
the results are aligned with the theoretical expectations,

<---->
sorted


for( size_t s = 100; s < 32768 * 1000; s = 2 * s )
std::unordered_map< std::string, std::string > testmap;

Performance table of map using sorted keys (inputsize/runtime in seconds): O(n)
     100/2.3755e-05     200/2.6991e-05     400/8.9529e-05     800/1.3219e-04     1600/1.9101e-04     3200/3.4897e-04     6400/6.8095e-04     12800/2.0108e-03     25600/2.3226e-03     51200/5.3601e-03     102400/1.4729e-02     204800/2.7167e-02     409600/7.8633e-02     819200/2.1331e-01     1638400/5.6809e-01     3276800/1.3380e+00     6553600/3.0521e+00     13107200/6.5009e+00     26214400/1.3493e+01

totaltime 2.5297e+01
the results are aligned with the theoretical expectations,

---

for( size_t s = 100; s < 65536 * 1000; s = 2 * s )
std::map< std::string, std::string > testmap;

Performance table of map using sorted keys (inputsize/runtime in seconds): seems like O(n) than O(nlog(n))
     100/2.8454e-05     200/3.9696e-05     400/9.2396e-05     800/1.7145e-04     1600/3.6896e-04     3200/7.7137e-04     6400/1.6778e-03     12800/4.1025e-03     25600/6.6025e-03     51200/1.5215e-02     102400/3.1978e-02     204800/5.2303e-02     409600/1.0994e-01     819200/2.1552e-01     1638400/4.6078e-01     3276800/9.5289e-01     6553600/2.0155e+00     13107200/4.1710e+00     26214400/8.6326e+00     52428800/1.7793e+01

totaltime 3.4465e+01
the results are aligned with the theoretical expectations, yet inserting sorted keys appears faster than inserting random keys for std::map at larger sizes

---

for( size_t s = 100; s < 256 * 1000; s = 2 * s )
map testmap;

Performance table of map using sorted keys (inputsize/runtime in seconds): O(n^2)
     100/2.3855e-05     200/5.4613e-05     400/1.9306e-04     800/6.7525e-04     1600/2.5785e-03     3200/1.1670e-02     6400/3.4400e-02     12800/1.1916e-01     25600/4.2566e-01     51200/1.6579e+00     102400/6.6353e+00     204800/2.7057e+01

totaltime 3.5945e+01

*/
