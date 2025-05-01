
// #include <random>
// #include <algorithm>
// #include <iostream>

// #include "map.h"

// #if 1

// void test_string_int( )
// {
//    std::cout << "STRING <==> INT\n";

//    map d;
//    std::cout << "Empty: " << d.empty() << "\n";
//    std::cout << "Size: " << d.size() << "\n";
//    std::cout << "Height: " << d.height() << "\n";

//    d.insert("Perez", 11);
//    std::cout << "Insert: " << d.contains("Perez") << "\n";
//    std::cout << "Insert duplicate: " << !d.insert("Perez", 2) << "\n";
//    std::cout << "Size: " << (d.size() == 1) << "\n";

//    d["Yuki"] = 22;
//    d["Max"] = 33;
//    std::cout << "[]: " << (d["Yuki"] == 22) << "\n";
//    std::cout << "Size []: " << (d.size() == 3) << "\n";

//    std::cout << "At Drei: " << (d.at("Max") == 33) << "\n";

//    const map& const_d = d;
//    std::cout << "Const at Yuki: " << (const_d.at("Yuki") == 2) << "\n";

//    std::cout << "Before erase:\n" << d << "\n";
//    std::cout << "Erase: " << d.erase("Yuki") << "\n";
//    std::cout << "After erase:\n" << d << "\n";
//    d.checksorted();

//    d["Lewis"] = 44;
//    d["Carlos"] = 55;
//    std::cout << "Size: " << (d.size() == 4) << "\n";
//    std::cout << "Height: " << (d.height() <= 4) << "\n";

//    map d_copy(d);
//    d_copy["Perez"] = 10;
//    std::cout << "Copy: " << (d_copy["Perez"] == 10) << "\n";
//    std::cout << "Original: " << (d["Perez"] == 1) << "\n";

//    map d_assign;
//    d_assign = d;
//    std::cout << "Size: " << (d_assign.size() == d.size()) << "\n";

//    map d_move(std::move(d));
//    std::cout << "Move: " << d.empty() << "\n";
//    std::cout << "Size: " << (d_move.size() == 4) << "\n";

//    map d_move_assign;
//    d_move_assign["Temp"] = 0;
//    d_move_assign = std::move(d_move);
//    std::cout << "Move assign: " << d_move.empty() << "\n";
//    std::cout << "Moved assign size: " << (d_move_assign.size() == 4) << "\n";

//    d_move_assign.clear();
//    std::cout << "Clear: " << d_move_assign.empty() << "\n";

// }

// // map deutsch( )
// // {
// //    map res;
// //    res[ "Null" ] = 0;
// //    res[ "Eins" ] = 1;
// //    res[ "Zwei" ] = 2;
// //    res[ "Drei" ] = 3;
// //    res[ "Vier" ] = 4;
// //    res[ "Fuenf" ] = 5;
// //    res[ "Sechs" ] = res[ "fuenf" ];
// //    res[ "Sechs" ] ++;
// //    res[ "Sieben" ] = 7;
// //    res[ "Acht" ] = res[ "sieben" ] + 1;
// //    res[ "Neun" ] = 9;
// //    res[ "Zehn" ] = res. at( "neun" );

// //    auto res2 = std::move( res );
// //    res = std::move( res2 );
// //    return res;
// // }

// // void test_string_int( )
// // {
// //    auto d = deutsch( );
// //    d. at( "zehn" ) ++; 
// //    std::cout << d << "\n";
// //    std::cout << d. size( ) << "\n";
// //    std::cout << d. height( ) << "\n";
// // }

// #endif

// #if 0
// void test_int_string() {
//    std::cout << "INT <==> STRING\n";

//    map d;
//    std::cout << "Empty map: " << d.empty() << "\n";
//    std::cout << "Size: " << d.size() << "\n";
//    std::cout << "Height: " << d.height() << "\n";

//    d.insert(1, "Max Verstappen");
//    std::cout << "Insert: " << d.contains(1) << "\n";
//    std::cout << "Insert duplicate: " << !d.insert(1, "Senna") << "\n";
//    std::cout << "Size: " << (d.size() == 1) << "\n";

//    d[2] = "Webber";
//    d[5] = "Vettel";
//    std::cout << "[]: " << (d[2] == "Webber") << "\n";
//    std::cout << "Size []: " << (d.size() == 3) << "\n";

//    std::cout << "At 3: " << (d.at(5) == "Vettel") << "\n";

//    const map& const_d = d;
//    std::cout << "Const: " << (const_d.at(1) == "Max Verstappen") << "\n";

//    std::cout << "Before erase:\n" << d << "\n";
//    std::cout << "Erase: " << d.erase(2) << "\n";
//    std::cout << "After erase:\n" << d << "\n";
//    d.checksorted();

//    d[44] = "Hamilton";
//    d[55] = "Sainz";
//    std::cout << "Size: " << (d.size() == 4) << "\n";
//    std::cout << "Height: " << (d.height() <= 4) << "\n";

//    map d_copy(d);
//    d_copy[1] = "Max";
//    std::cout << "Copy: " << (d_copy[1] == "Max") << "\n";
//    std::cout << "Original: " << (d[1] == "Max Verstappen") << "\n";

//    map d_assign;
//    d_assign = d;
//    std::cout << "Size: " << (d_assign.size() == d.size()) << "\n";

//    map d_move(std::move(d));
//    std::cout << "Move: " << d.empty() << "\n";
//    std::cout << "Size: " << (d_move.size() == 4) << "\n";

//    map d_move_assign;
//    d_move_assign[0] = "Norris";
//    d_move_assign = std::move(d_move);
//    std::cout << "Move assign: " << d_move.empty() << "\n";
//    std::cout << "Moved assign size: " << (d_move_assign.size() == 4) << "\n";

//    d_move_assign.clear();
//    std::cout << "Clear: " << d_move_assign.empty() << "\n";
// }

// // void test_int_string( ) 
// // {
// //    // They are shuffled, to obtain a balanced tree: 

// //    map elements;
// //    elements[1] = "Hydrogen";
// //    elements[3] = "Lithium";
// //    elements[2] = "Helium";
// //    elements[10] = "Neon";
// //    elements[5] = "Boron";
// //    elements[26] = "Iron";
// //    elements[4] = "Beryllium";
// //    elements[7] = "Nitrogen";
// //    elements[8] = "Oxygen";
// //    elements[9] = "Fluorine";
// //    elements[92] = "Uranium";
// //    elements[82] = "Lead";
// //    elements[11] = "Sodium";
// //    elements[6] = "Carbon";
// //    elements[16] = "Sulfur";
// //    elements[19] = "Potassium";
// //    elements[84] = "Polonium";
  
// //    std::cout << elements << "\n";
// // }

// #endif

// #if 0

// void test_string_string( )
// {
//    std::cout << "STRING <==> STRING\n";

//    map d;
//    std::cout << "Empty map: " << d.empty() << "\n";
//    std::cout << "Size: " << d.size() << "\n";
//    std::cout << "Height: " << d.height() << "\n";

//    d.insert("WAW", "Warsaw Chopin Airport");
//    std::cout << "Insert: " << d.contains("WAW") << "\n";
//    std::cout << "Insert duplicate: " << !d.insert("WAW", "Duplicate") << "\n";
//    std::cout << "Size: " << (d.size() == 1) << "\n";

//    d["FRA"] = "Frankfurt Airport";
//    d["JFK"] = "JFK Airport";
//    std::cout << "[]: " << (d["FRA"] == "Frankfurt Airport") << "\n";
//    std::cout << "Size []: " << (d.size() == 3) << "\n";

//    std::cout << "At JFK: " << (d.at("JFK") == "JFK Airport") << "\n";

//    const map& const_d = d;
//    std::cout << "Const: " << (const_d.at("FRA") == "Frankfurt Airport") << "\n";

//    std::cout << "Before erase:\n" << d << "\n";
//    std::cout << "Erase: " << d.erase("FRA") << "\n";
//    std::cout << "After erase:\n" << d << "\n";
//    d.checksorted();

//    d["LAX"] = "Los Angeles Airport";
//    d["NRT"] = "Narita Airport";
//    std::cout << "Size: " << (d.size() == 4) << "\n";
//    std::cout << "Height: " << (d.height() <= 4) << "\n";

//    map d_copy(d);
//    d_copy["WAW"] = "Warsaw new";
//    std::cout << "Copy: " << (d_copy["WAW"] == "Warsaw new") << "\n";
//    std::cout << "Original: " << (d["WAW"] == "Warsaw Chopin Airport") << "\n";

//    map d_assign;
//    d_assign = d;
//    std::cout << "Size: " << (d_assign.size() == d.size()) << "\n";

//    map d_move(std::move(d));
//    std::cout << "Move: " << d.empty() << "\n";
//    std::cout << "Size: " << (d_move.size() == 4) << "\n";

//    map d_move_assign;
//    d_move_assign["Temp"] = "Temporary";
//    d_move_assign = std::move(d_move);
//    std::cout << "Move assign: " << d_move.empty() << "\n";
//    std::cout << "Moved assign size: " << (d_move_assign.size() == 4) << "\n";

//    d_move_assign.clear();
//    std::cout << "Clear: " << d_move_assign.empty() << "\n";
// }

// // void test_string_string( )
// // {
// //    map airports; 
// //    airports[ "WAW" ] = "Warsaw Chopin Airport";
// //    airports[ "FRA" ] = "Frankfurt Rhein/Main Airport, Germany";
// //    airports[ "JFK" ] = "John F. Kennedy International Airport, New York";
// //    airports[ "NQZ" ] = "Nursultan Nazarbayev International Airport, Astana";
// //    airports[ "LAX" ] = "Los Angeles Internatinoal Airport";
// //    airports[ "LHR" ] = "Heathrow Airport, London"; 
// //    airports. insert( "AMS", "Amsterdam Aiport Schiphol, Amsterdam" ); 
// //    airports[ "NRT"] = "Tokiyo-Narita International Airport"; 

// //    std::cout << airports. at( "nrt" ) << "\n";
// //    airports. erase( "lax" );

// //    std::cout << airports << "\n";
// // }

// #endif

// #if 0

// void test_int_int( )
// {
//    std::cout << "INT <==> INT\n";

//    map d;
//    std::cout << "Empty map: " << d.empty() << "\n";
//    std::cout << "Size: " << d.size() << "\n";
//    std::cout << "Height: " << d.height() << "\n";

//    d.insert(1, 11);
//    std::cout << "Insert: " << d.contains(1) << "\n";
//    std::cout << "Size: " << (d.size() == 1) << "\n";

//    d[2] = 22;
//    d[3] = 33;
//    std::cout << "[]: " << (d[2] == 22) << "\n";
//    std::cout << "Size []: " << (d.size() == 3) << "\n";

//    std::cout << "At 3: " << (d.at(3) == 33) << "\n";

//    const map& const_d = d;
//    std::cout << "Const: " << (const_d.at(2) == 22) << "\n";

//    std::cout << "Before erase:\n" << d << "\n";
//    std::cout << "Erase: " << d.erase(2) << "\n";
//    std::cout << "Erase: " << !d.erase(2) << "\n";
//    std::cout << "After erase:\n" << d << "\n";
//    d.checksorted();

//    d[4] = 44;
//    d[5] = 55;
//    std::cout << "Size: " << (d.size() == 4) << "\n";
//    std::cout << "Height: " << (d.height() <= 4) << "\n";

//    map d_copy(d);
//    d_copy[1] = 10;
//    std::cout << "Copy: " << (d_copy[1] == 10) << "\n";
//    std::cout << "Original: " << (d[1] == 11) << "\n";

//    map d_assign;
//    d_assign = d;
//    std::cout << "Size: " << (d_assign.size() == d.size()) << "\n";

//    map d_move(std::move(d));
//    std::cout << "Move: " << d.empty() << "\n";
//    std::cout << "Size: " << (d_move.size() == 4) << "\n";

//    map d_move_assign;
//    d_move_assign[0] = 0;
//    d_move_assign = std::move(d_move);
//    std::cout << "Move assign: " << d_move.empty() << "\n";
//    std::cout << "Moved assign size: " << (d_move_assign.size() == 4) << "\n";

//    d_move_assign.clear();
//    std::cout << "Clear: " << d_move_assign.empty() << "\n";
// }

// // void test_int_int( )
// // {
// //    map d2d;

// //    d2d. insert( 100, 200 );
// //    std::cout << d2d. contains( 100 ) << "\n";

// //    d2d. insert( 15, 16 );
// //    d2d. insert( -1, 4 );
// //    d2d[ 100 ] = 50;
// //    ++ d2d[ 100 ];
// //    d2d[ 10 ];
// //    ++ d2d. at( 10 ); 
// //    d2d. erase( 10 );
// //    d2d[ 50 ] = 50;
// //    std::cout << d2d. erase( 15 ) << "\n";

// //    std::cout << d2d << "\n";
// // }

// #endif

// int main( int argc, char* argv[ ] )
// {
//    test_string_int( );
//    // test_string_string( );
//    // test_int_int( ); 
//    // test_int_string( );
// }



#include <random>
#include <algorithm>
#include <iostream>

#include "map.h"

#if 1

void test_string_int( )
{
   std::cout << "STRING <==> INT\n";

   map d;
   std::cout << "Empty: " << d.empty() << "\n";
   std::cout << "Size: " << d.size() << "\n";
   std::cout << "Height: " << d.height() << "\n";

   d.insert("Perez", 11);
   std::cout << "Insert: " << d.contains("Perez") << "\n";
   std::cout << "Insert duplicate: " << !d.insert("Perez", 2) << "\n";
   std::cout << "Size: " << (d.size() == 1) << "\n";

   d["Yuki"] = 22;
   d["Max"] = 33;
   std::cout << "[]: " << (d["Yuki"] == 22) << "\n";
   std::cout << "Size []: " << (d.size() == 3) << "\n";

   std::cout << "At Drei: " << (d.at("Max") == 33) << "\n";

   const map& const_d = d;
   std::cout << "Const at Yuki: " << (const_d.at("Yuki") == 2) << "\n";

   std::cout << "Before erase:\n" << d << "\n";
   std::cout << "Erase: " << d.erase("Yuki") << "\n";
   std::cout << "After erase:\n" << d << "\n";
   d.checksorted();

   d["Lewis"] = 44;
   d["Carlos"] = 55;
   std::cout << "Size: " << (d.size() == 4) << "\n";
   std::cout << "Height: " << (d.height() <= 4) << "\n";

   map d_copy(d);
   d_copy["Perez"] = 10;
   std::cout << "Copy: " << (d_copy["Perez"] == 10) << "\n";
   std::cout << "Original: " << (d["Perez"] == 1) << "\n";

   map d_assign;
   d_assign = d;
   std::cout << "Size: " << (d_assign.size() == d.size()) << "\n";

   map d_move(std::move(d));
   std::cout << "Move: " << d.empty() << "\n";
   std::cout << "Size: " << (d_move.size() == 4) << "\n";

   map d_move_assign;
   d_move_assign["Temp"] = 0;
   d_move_assign = std::move(d_move);
   std::cout << "Move assign: " << d_move.empty() << "\n";
   std::cout << "Moved assign size: " << (d_move_assign.size() == 4) << "\n";

   d_move_assign.clear();
   std::cout << "Clear: " << d_move_assign.empty() << "\n";

}

// map deutsch( )
// {
//    map res;
//    res[ "Null" ] = 0;
//    res[ "Eins" ] = 1;
//    res[ "Zwei" ] = 2;
//    res[ "Drei" ] = 3;
//    res[ "Vier" ] = 4;
//    res[ "Fuenf" ] = 5;
//    res[ "Sechs" ] = res[ "fuenf" ];
//    res[ "Sechs" ] ++;
//    res[ "Sieben" ] = 7;
//    res[ "Acht" ] = res[ "sieben" ] + 1;
//    res[ "Neun" ] = 9;
//    res[ "Zehn" ] = res. at( "neun" );

//    auto res2 = std::move( res );
//    res = std::move( res2 );
//    return res;
// }

// void test_string_int( )
// {
//    auto d = deutsch( );
//    d. at( "zehn" ) ++; 
//    std::cout << d << "\n";
//    std::cout << d. size( ) << "\n";
//    std::cout << d. height( ) << "\n";
// }

#endif

#if 0
void test_int_string() {
   std::cout << "INT <==> STRING\n";

   map d;
   std::cout << "Empty map: " << d.empty() << "\n";
   std::cout << "Size: " << d.size() << "\n";
   std::cout << "Height: " << d.height() << "\n";

   d.insert(1, "Max Verstappen");
   std::cout << "Insert: " << d.contains(1) << "\n";
   std::cout << "Insert duplicate: " << !d.insert(1, "Senna") << "\n";
   std::cout << "Size: " << (d.size() == 1) << "\n";

   d[2] = "Webber";
   d[5] = "Vettel";
   std::cout << "[]: " << (d[2] == "Webber") << "\n";
   std::cout << "Size []: " << (d.size() == 3) << "\n";

   std::cout << "At 3: " << (d.at(5) == "Vettel") << "\n";

   const map& const_d = d;
   std::cout << "Const: " << (const_d.at(1) == "Max Verstappen") << "\n";

   std::cout << "Before erase:\n" << d << "\n";
   std::cout << "Erase: " << d.erase(2) << "\n";
   std::cout << "After erase:\n" << d << "\n";
   d.checksorted();

   d[44] = "Hamilton";
   d[55] = "Sainz";
   std::cout << "Size: " << (d.size() == 4) << "\n";
   std::cout << "Height: " << (d.height() <= 4) << "\n";

   map d_copy(d);
   d_copy[1] = "Max";
   std::cout << "Copy: " << (d_copy[1] == "Max") << "\n";
   std::cout << "Original: " << (d[1] == "Max Verstappen") << "\n";

   map d_assign;
   d_assign = d;
   std::cout << "Size: " << (d_assign.size() == d.size()) << "\n";

   map d_move(std::move(d));
   std::cout << "Move: " << d.empty() << "\n";
   std::cout << "Size: " << (d_move.size() == 4) << "\n";

   map d_move_assign;
   d_move_assign[0] = "Norris";
   d_move_assign = std::move(d_move);
   std::cout << "Move assign: " << d_move.empty() << "\n";
   std::cout << "Moved assign size: " << (d_move_assign.size() == 4) << "\n";

   d_move_assign.clear();
   std::cout << "Clear: " << d_move_assign.empty() << "\n";
}

// void test_int_string( ) 
// {
//    // They are shuffled, to obtain a balanced tree: 

//    map elements;
//    elements[1] = "Hydrogen";
//    elements[3] = "Lithium";
//    elements[2] = "Helium";
//    elements[10] = "Neon";
//    elements[5] = "Boron";
//    elements[26] = "Iron";
//    elements[4] = "Beryllium";
//    elements[7] = "Nitrogen";
//    elements[8] = "Oxygen";
//    elements[9] = "Fluorine";
//    elements[92] = "Uranium";
//    elements[82] = "Lead";
//    elements[11] = "Sodium";
//    elements[6] = "Carbon";
//    elements[16] = "Sulfur";
//    elements[19] = "Potassium";
//    elements[84] = "Polonium";
  
//    std::cout << elements << "\n";
// }

#endif

#if 0

void test_string_string( )
{
   std::cout << "STRING <==> STRING\n";

   map d;
   std::cout << "Empty map: " << d.empty() << "\n";
   std::cout << "Size: " << d.size() << "\n";
   std::cout << "Height: " << d.height() << "\n";

   d.insert("WAW", "Warsaw Chopin Airport");
   std::cout << "Insert: " << d.contains("WAW") << "\n";
   std::cout << "Insert duplicate: " << !d.insert("WAW", "Duplicate") << "\n";
   std::cout << "Size: " << (d.size() == 1) << "\n";

   d["FRA"] = "Frankfurt Airport";
   d["JFK"] = "JFK Airport";
   std::cout << "[]: " << (d["FRA"] == "Frankfurt Airport") << "\n";
   std::cout << "Size []: " << (d.size() == 3) << "\n";

   std::cout << "At JFK: " << (d.at("JFK") == "JFK Airport") << "\n";

   const map& const_d = d;
   std::cout << "Const: " << (const_d.at("FRA") == "Frankfurt Airport") << "\n";

   std::cout << "Before erase:\n" << d << "\n";
   std::cout << "Erase: " << d.erase("FRA") << "\n";
   std::cout << "After erase:\n" << d << "\n";
   d.checksorted();

   d["LAX"] = "Los Angeles Airport";
   d["NRT"] = "Narita Airport";
   std::cout << "Size: " << (d.size() == 4) << "\n";
   std::cout << "Height: " << (d.height() <= 4) << "\n";

   map d_copy(d);
   d_copy["WAW"] = "Warsaw new";
   std::cout << "Copy: " << (d_copy["WAW"] == "Warsaw new") << "\n";
   std::cout << "Original: " << (d["WAW"] == "Warsaw Chopin Airport") << "\n";

   map d_assign;
   d_assign = d;
   std::cout << "Size: " << (d_assign.size() == d.size()) << "\n";

   map d_move(std::move(d));
   std::cout << "Move: " << d.empty() << "\n";
   std::cout << "Size: " << (d_move.size() == 4) << "\n";

   map d_move_assign;
   d_move_assign["Temp"] = "Temporary";
   d_move_assign = std::move(d_move);
   std::cout << "Move assign: " << d_move.empty() << "\n";
   std::cout << "Moved assign size: " << (d_move_assign.size() == 4) << "\n";

   d_move_assign.clear();
   std::cout << "Clear: " << d_move_assign.empty() << "\n";
}

// void test_string_string( )
// {
//    map airports; 
//    airports[ "WAW" ] = "Warsaw Chopin Airport";
//    airports[ "FRA" ] = "Frankfurt Rhein/Main Airport, Germany";
//    airports[ "JFK" ] = "John F. Kennedy International Airport, New York";
//    airports[ "NQZ" ] = "Nursultan Nazarbayev International Airport, Astana";
//    airports[ "LAX" ] = "Los Angeles Internatinoal Airport";
//    airports[ "LHR" ] = "Heathrow Airport, London"; 
//    airports. insert( "AMS", "Amsterdam Aiport Schiphol, Amsterdam" ); 
//    airports[ "NRT"] = "Tokiyo-Narita International Airport"; 

//    std::cout << airports. at( "nrt" ) << "\n";
//    airports. erase( "lax" );

//    std::cout << airports << "\n";
// }

#endif

#if 0

void test_int_int( )
{
   std::cout << "INT <==> INT\n";

   map d;
   std::cout << "Empty map: " << d.empty() << "\n";
   std::cout << "Size: " << d.size() << "\n";
   std::cout << "Height: " << d.height() << "\n";

   d.insert(1, 11);
   std::cout << "Insert: " << d.contains(1) << "\n";
   std::cout << "Size: " << (d.size() == 1) << "\n";

   d[2] = 22;
   d[3] = 33;
   std::cout << "[]: " << (d[2] == 22) << "\n";
   std::cout << "Size []: " << (d.size() == 3) << "\n";

   std::cout << "At 3: " << (d.at(3) == 33) << "\n";

   const map& const_d = d;
   std::cout << "Const: " << (const_d.at(2) == 22) << "\n";

   std::cout << "Before erase:\n" << d << "\n";
   std::cout << "Erase: " << d.erase(2) << "\n";
   std::cout << "Erase: " << !d.erase(2) << "\n";
   std::cout << "After erase:\n" << d << "\n";
   d.checksorted();

   d[4] = 44;
   d[5] = 55;
   std::cout << "Size: " << (d.size() == 4) << "\n";
   std::cout << "Height: " << (d.height() <= 4) << "\n";

   map d_copy(d);
   d_copy[1] = 10;
   std::cout << "Copy: " << (d_copy[1] == 10) << "\n";
   std::cout << "Original: " << (d[1] == 11) << "\n";

   map d_assign;
   d_assign = d;
   std::cout << "Size: " << (d_assign.size() == d.size()) << "\n";

   map d_move(std::move(d));
   std::cout << "Move: " << d.empty() << "\n";
   std::cout << "Size: " << (d_move.size() == 4) << "\n";

   map d_move_assign;
   d_move_assign[0] = 0;
   d_move_assign = std::move(d_move);
   std::cout << "Move assign: " << d_move.empty() << "\n";
   std::cout << "Moved assign size: " << (d_move_assign.size() == 4) << "\n";

   d_move_assign.clear();
   std::cout << "Clear: " << d_move_assign.empty() << "\n";
}

// void test_int_int( )
// {
//    map d2d;

//    d2d. insert( 100, 200 );
//    std::cout << d2d. contains( 100 ) << "\n";

//    d2d. insert( 15, 16 );
//    d2d. insert( -1, 4 );
//    d2d[ 100 ] = 50;
//    ++ d2d[ 100 ];
//    d2d[ 10 ];
//    ++ d2d. at( 10 ); 
//    d2d. erase( 10 );
//    d2d[ 50 ] = 50;
//    std::cout << d2d. erase( 15 ) << "\n";

//    std::cout << d2d << "\n";
// }

#endif

int main( int argc, char* argv[ ] )
{
   test_string_int( );
   // test_string_string( );
   // test_int_int( ); 
   // test_int_string( );
}


