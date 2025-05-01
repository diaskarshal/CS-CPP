
#include <random>
#include <algorithm>
#include <iostream>

#include "map.h"

#if 0

map deutsch( )
{
   map res;
   res[ "Null" ] = 0;
   res[ "Eins" ] = 1;
   res[ "Zwei" ] = 2;
   res[ "Drei" ] = 3;
   res[ "Vier" ] = 4;
   res[ "Fuenf" ] = 5;
   res[ "Sechs" ] = res[ "fuenf" ];
   res[ "Sechs" ] ++;
   res[ "Sieben" ] = 7;
   res[ "Acht" ] = res[ "sieben" ] + 1;
   res[ "Neun" ] = 9;
   res[ "Zehn" ] = res. at( "neun" );

   auto res2 = std::move( res );
   res = std::move( res2 );
   return res;
}

void test_string_int( )
{
   auto d = deutsch( );
   d. at( "zehn" ) ++; 
   std::cout << d << "\n";
   std::cout << d. size( ) << "\n";
}

#endif

#if 0

void test_int_string( ) 
{
   // They are shuffled, to obtain a balanced tree: 

   map elements;
   elements[1] = "Hydrogen";
   elements[3] = "Lithium";
   elements[2] = "Helium";
   elements[10] = "Neon";
   elements[5] = "Boron";
   elements[26] = "Iron";
   elements[4] = "Beryllium";
   elements[7] = "Nitrogen";
   elements[8] = "Oxygen";
   elements[9] = "Fluorine";
   elements[92] = "Uranium";
   elements[82] = "Lead";
   elements[11] = "Sodium";
   elements[6] = "Carbon";
   elements[16] = "Sulfur";
   elements[19] = "Potassium";
   elements[84] = "Polonium";
  
   std::cout << elements << "\n";
}

#endif

#if 1

void test_string_string( )
{
   map airports; 
   airports[ "WAW" ] = "Warsaw Chopin Airport";
   airports[ "FRA" ] = "Frankfurt Rhein/Main Airport, Germany";
   airports[ "JFK" ] = "John F. Kennedy International Airport, New York";
   airports[ "NQZ" ] = "Nursultan Nazarbayev International Airport, Astana";
   airports[ "LAX" ] = "Los Angeles Internatinoal Airport";
   airports[ "LHR" ] = "Heathrow Airport, London"; 
   airports. insert( "AMS", "Amsterdam Aiport Schiphol, Amsterdam" ); 
   airports[ "NRT"] = "Tokiyo-Narita International Airport"; 

   std::cout << airports. at( "nrt" ) << "\n";
   airports. erase( "lax" );

   std::cout << airports << "\n";
}

#endif

#if 0

void test_int_int( )
{
   map d2d;

   d2d. insert( 100, 200 );
   std::cout << d2d. contains( 100 ) << "\n";

   d2d. insert( 15, 16 );
   d2d. insert( -1, 4 );
   d2d[ 100 ] = 50;
   ++ d2d[ 100 ];
   d2d[ 10 ];
   ++ d2d. at( 10 ); 
   d2d. erase( 10 );
   d2d[ 50 ] = 50;
   std::cout << d2d. erase( 15 ) << "\n";

   std::cout << d2d << "\n";
}

#endif


int main( int argc, char* argv[ ] )
{
   // test_string_int( );
   test_string_string( );
   // test_int_int( ); 
   // test_int_string( );
}


