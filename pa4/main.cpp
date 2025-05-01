

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

#if 0 //string-int
   {
      map f1;
      f1["max"] = 1;
      f1["lando"] = 4;
      f1["charles"] = 16;
      f1["lewis"] = 44;
      f1["carlos"] = 55;
      f1["george"] = 63;
      f1["oscar"] = 81;
      std::cout << f1;

      f1.at("max") = 33;
      f1["oscar"] = 1;
      std::cout << f1.at("max") << " " << f1["oscar"] << "\n";

      f1.erase("george");
      try{
         f1["george"] = f1["carlos"] + f1.at("test");
      }
      catch (const std::out_of_range& e){
         std::cout << e.what() << "\n";
         f1["george"] = f1["carlos"] + f1.at("lewis");
      }
      std::cout << f1.at("george") << "\n";

      std::cout << f1.contains("sebastian");
      f1.checkinvariants(); 
   }
#endif

#if 0 // int-int
   {
      map f1;
      f1[1] = 454;
      f1[4] = 234;
      f1[11] = 206;
      f1[16] = 201;
      std::cout << f1;

      f1.at(1) += 25;
      std::cout << "max p1, now he has: " << f1.at(1) << " points\n";

      f1.erase(11);
      std::cout << "sergio DSQ, table is: " << f1.size() << "\n";

      f1[55] = f1.at(4) / 2;
      std::cout << "new driver carlos with " << f1[55] << " points\n";

      f1.checkinvariants();
   }
#endif

#if 0 //int-string
   {
      map f1;
      f1[1] = "Red Bull";
      f1[4] = "McLaren";
      f1[16] = "Ferrari";
      f1[63] = "Mercedes";
      std::cout << f1;

      f1[4] = "Red Bull";
      std::cout << "new transfer: " << f1[4] << "\n";

      std::cout << "is george in Mercedes? ";
      bool ans = f1.at(63) == "Mercedes";
      std::cout << ans << "\n";
      f1.checkinvariants();
   }
#endif

#if 0 // string-string
   { 

      map f1;
      f1["Monza"] = "Italy";
      f1["Silverstone"] = "UK";
      f1["Spa"] = "Belgium";
      f1["Monaco"] = "Monaco";
      std::cout << f1;

      std::cout << "monza in: " << f1.at("monza") << "\n";
      f1["SPA"] = "Kazakhstan";
      std::cout << "Spa is now in: " << f1.at("spa") << "\n";

      f1["MexicoCity"] = "Mexico";
      std::cout << "Mexico City in: " << f1["mexicocity"] << "\n";

      bool ans = f1.contains("nyc");
      std::cout << "is there a US circuit: " << ans << "\n";

      f1.checkinvariants();
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
}



