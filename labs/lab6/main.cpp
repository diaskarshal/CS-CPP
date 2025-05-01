
#include <iostream>
#include <vector>

#include "timetable.h"
#include "sorting.h"
#include "string.h"
#include "timer.h"
 
int main( int argc, char* argv[] )
{
 
#if 0
   timetable heap_times( "heapsort" );
   timetable quick_times( "quicksort from library" );
   timetable bubble_times( "bubblesort" );
   timetable insertion_times( "insertion sort" );

   // My experience from earlier, similar tasks is that doubling
   // is much more informative than adding a fixed step.

   for( size_t s = 2000; s < 200000; s *= 2 ) 
   { 
      std::vector<int> test = randomvector(s); 

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
/*
   Performance table of heapsort (inputsize/runtime in seconds):
      2000/1.3847e-04     4000/3.0335e-04     8000/7.0818e-04     16000/9.4642e-04     32000/2.0729e-03     64000/5.5584e-03     128000/1.1006e-02

   Performance table of quicksort from library (inputsize/runtime in seconds):
      2000/8.9157e-05     4000/1.5883e-04     8000/3.4294e-04     16000/1.0476e-03     32000/1.4755e-03     64000/3.1727e-03     128000/6.7728e-03

   Performance table of bubblesort (inputsize/runtime in seconds):
      2000/3.4322e-03     4000/1.6545e-02     8000/5.4705e-02     16000/1.7638e-01     32000/8.3227e-01     64000/4.1513e+00     128000/1.7918e+01

   Performance table of insertion sort (inputsize/runtime in seconds):
      2000/1.4959e-03     4000/6.1110e-03     8000/2.1567e-02     16000/8.5006e-02     32000/2.6075e-01     64000/1.0037e+00     128000/3.8159e+00

   this is the total time: 2.8381e+01

   heapsort: nlogn
   quicksort:nlogn
   bubblesort:n^2
   insertion sort:n^2
*/

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

/*
   +1000  k=2
   measuring performance of string operations
   Performance table of string with multiplying/adding ensure_capacity (inputsize/runtime in seconds):
     1000000/1.8536e-01     2000000/5.6099e-01     4000000/2.2710e+00     8000000/1.0546e+01     16000000/5.3236e+01

   *2     k=1
   measuring performance of string operations
   Performance table of string with multiplying/adding ensure_capacity (inputsize/runtime in seconds):
     1000000/3.4260e-03     2000000/7.2813e-03     4000000/1.2056e-02     8000000/1.6209e-02     16000000/3.2531e-02

   *3     k=1
   measuring performance of string operations
   Performance table of string with multiplying/adding ensure_capacity (inputsize/runtime in seconds):
     1000000/2.0031e-03     2000000/3.1975e-03     4000000/5.4148e-02     8000000/4.2621e-02     16000000/3.2526e-02
*/
#endif

   return 0; 
}

 
