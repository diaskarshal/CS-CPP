
#include <random>
#include <algorithm>
#include <sstream>
#include <unordered_map>

#include "map.h"

std::vector< int > randomvector( size_t sz )
{
   std::vector< int > res;
   for( size_t i = 0; i != sz; ++ i )
   {
      res. push_back( rand( ) );
   }
   return res;
}


int main( int argc, char* argv[ ] )
{

#if 0
   {
      map deutsch;
      deutsch[ "null" ] = 0;
      std::cout << deutsch.at( "null" ) << "\n";
      deutsch[ "eins" ] = 1;
      std::cout << deutsch << "\n";
      deutsch[ "zwei" ] = 2;
      deutsch[ "drei" ] = 3;
      deutsch[ "vier" ] = 4;

      deutsch. insert( "fuenf", 5 );
      deutsch[ "fuenf" ] ++ ; 
      deutsch[ "sechs" ] = deutsch[ "fuenf" ];
      deutsch[ "sechs" ] ++; 
      deutsch[ "sieben" ] = 7;
      deutsch[ "acht" ] = deutsch[ "sieben" ] + 1;
      deutsch[ "neun" ] = 9;
      deutsch. erase( "acht" );
      deutsch. erase( "vier" );
      // deutsch[ "zehn" ] = deutsch. at( "neun" ) + 1;
      std::cout << deutsch << "\n";
      deutsch. checkinvariants( ); 
   }
#endif

#if 0
   {
      // Serious tests with int/int. 

      std::unordered_map< int, int > trusted; 
      map ours; 

      std::vector< std::pair< int, int >> values;
      for( unsigned int i = 0; i < 1000; ++ i )
         values. push_back( { rand( ), rand( ) } );

      for( unsigned int i = 0; i < values. size( ); ++ i )
      {
         if( i % 2 == 0 )
         {
            trusted[ values[i]. first ] = values[i]. second;
            ours[ values[i]. first ] = values[i]. second;
         }
      }

      for( unsigned int i = 0; i < values. size( ); ++ i )
      {
         if( trusted. contains( values[i]. first ) !=
             ours. contains( values[i]. first ))
            throw std::runtime_error( "contains" );

         if( trusted. contains( values[i]. first ) &&
             trusted. at( values[i]. first ) !=
             ours. at( values[i]. first ))
            throw std::runtime_error( "at" );
      }
 
      if( trusted. size( ) != ours. size( ))
         throw std::logic_error( "sizes differ" );
      std::cout << ours << "\n";
      ours. checkinvariants( ); 

      for( unsigned int i = 0; i < values. size( ); ++ i )
      {
         if( i % 3 == 0 )
         {
            bool b1 = trusted. erase( values[i]. first ); 
            bool b2 = ours. erase( values[i]. first );
            if( b1 != b2 )
               throw std::logic_error( "erasure failed" );
         }
      }

      for( unsigned int i = 0; i < values. size( ); ++ i )
      {
        if( trusted[ values[i]. first ] != 
            ours[ values[i]. first ] )
        {
           std::cout << "failure at " << values[i]. first << "\n";
           throw std::logic_error( "failed" ); 
        }
     }

     ours. checkinvariants( );
     std::cout << ours. size( ) << " " << trusted. size( ) << "\n";

   }
#endif

#if 1
   {
      map kazakh;
      kazakh[0] = "nol";
      kazakh[1] = "bir";
      kazakh[2] = "eki";
      kazakh[3] = "ush";
      kazakh[4] = "tort";
      kazakh[5] = "bes";
      kazakh[6] = "alty";
      kazakh[7] = "zheti";   
      kazakh[8] = "segiz";
      kazakh[9] = "togyz";
      kazakh[10] = "on";

      std::cout << kazakh << "\n";
      return 0;
   }
#endif

#if 0 
   { 
      // Tests for case insensitive map:

      map small;    // A small test map.

      small[ "the" ] = 4;
      std::cout << small[ "The" ] << "\n";

      small[ "notthere" ] ++ ;

      small. insert( "if", 2 ); 
      small[ "the" ] = 3;
      small[ "value" ] = 5;
      small. insert( "aaa", 4 );
      small. insert( "aAa", 4 );
      small. insert( "ccc", 2 );
      small. insert( "xyz", 2 );
      small. insert( "XYZ", 2 );
      small. insert( "ssss", 4 );

      std::cout << small. at( "xYZ" ) << "\n";
      small. at( "ssss" ) = 55;

      std::cout << small << "\n";
      std::cout << small. size( ) << "\n";

      map small3 = small; 
      small. clear( );
      std::cout << "this is the hash map after clear:\n" << small << "\n";
      std::cout << small3 << "\n";

      small = std::move( small3 );
      std::cout << "small3\n";
      std::cout << small3 << "\n";

      std::cout << small << "\n";
      std::cout << small. contains( "xx" ) << "\n";
      std::cout << small. at( "CCC" ) << "\n";
         // To contain or not to contain, that's the question. 
      small. checkinvariants( ); 
      return 0;
   }
#endif

}


