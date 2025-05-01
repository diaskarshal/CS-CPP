
#include <iostream>
#include <vector>

#include "timetable.h"
#include "sorting.h"
#include "string.h"
#include "timer.h"
 
int main( int argc, char* argv[] )
{
 
#if 1
   timetable heap_times( "heapsort" );
   timetable quick_times( "quicksort from library" );
   timetable bubble_times( "bubblesort" );
   timetable insertion_times( "insertion sort" );

   // My experience from earlier, similar tasks is that doubling
   // is much more informative than adding a fixed step.

   for( size_t s = 2000; s < 40000; s *= 2 ) 
   { 
      std::vector<int> test = randomvector(10); 

      { 
         auto v = test; timer t; heap_sort(v); 
         heap_times. insert( s, t. time( )); 
         std::cout << v << "\n";
      }

      {
         auto v = test; timer t; quick_sort(v); 
         quick_times. insert( s, t. time( ));
         std::cout << v << "\n";
      }

      {
         auto v = test; timer t; bubble_sort(v); 
         bubble_times. insert( s, t. time( ));
         std::cout << v << "\n";
      }
 
      {
         auto v = test; timer t; insertion_sort(v); 
         insertion_times. insert( s, t. time( ));
         std::cout << v << "\n";
      }
   }

   std::cout << heap_times << "\n";
   std::cout << quick_times << "\n";
   std::cout << bubble_times << "\n";
   std::cout << insertion_times << "\n";
   std::cout << "this is the total time: ";
   std::cout << heap_times.totaltime( ) + quick_times.totaltime( ) + 
                bubble_times.totaltime( ) + 
                insertion_times.totaltime( ) << "\n";

#endif

#if 1
   std::cout << "\n";
   std::cout << "measuring performance of string operations\n";

   timetable string_times( "string with multiplying/adding ensure_capacity" );
  
   unsigned int start = 1000000; 
   for( size_t s = start; s < 32 * start; s *= 2 )
   {
      timer t;
      csci152::string str; 
      for( size_t i = 0; i != s; ++ i )  
         str. push_back( 'a' + ( i % 26 ));

      while( str. size( ))
         str. pop_back( ); 
      
      string_times. insert( s, t. time( )); 
   }

   std::cout << string_times << "\n";
#endif

   return 0; 
}

 
