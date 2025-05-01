
#include "deque.h"
#include <utility>

int main( int argc, char* argv [] )
{

#if 1

   deque q8;
   std::cout << q8. deq_size << "\n";

   q8. push_back( 1 );
   q8. push_front( 2 );
   q8. push_front( 3 );
   q8. push_front( 4 );

   q8 = q8;
   std::cout << "self-assignment: " << q8 << "\n\n\n";
   
   deque q;
   std::cout << "defaul constr: " << (q.size() == 0) << " " << q.empty() << "\n";

   q.push_back(1);
   q.push_back(2);
   q.push_back(3);
   
   std::cout << "push back: " << (q.size() == 3) << " " << q << "\n";

   q.pop_back();
   std::cout << "pop back: " << (q.size() == 3) << " " << q.size() << " " << q << "\n";

   std::cout << "back const: " <<(q.back() == 2) << " " << q.back() << "\n";

   q.back() = 10;
   std::cout << "back non const: " << (q.back() == 10) << " " << q << "\n";

   q.push_front(5);
   std::cout << "push front: " << (q.size() == 3) << " " << q << "\n";

   q.pop_front();
   std::cout << "pop front: " << (q.size() == 2) << " " << q.size() << q << "\n";

   deque q2(q);
   std::cout << "copy constr: " << (q2.size() == q.size()) << " " << q2 << "\n";

   deque q3 = {5, 6, 7, 8};
   std::cout << "initializer list: " << (q3.size() == 4) << " " << q3 << "\n";

   q3.reset_front(2);
   std::cout << "reset front: " << (q3.size() == 2)<< " " << q3 << "\n";

   q3.reset_back(1);
   std::cout << "reset back: " << (q3.size() == 1)<< " " << q3 << "\n";

   deque q4;
   q4 = q3;
   std::cout << "copy assignment: " <<(q4.size() == q3.size())<< " " << q4 << "\n";

   std::cout << "size : " << (q4.size() == 1) << " " << q4.size() << "\n";

   std::cout << "empty: " << (!q4.empty()) << " " << q4 << "\n";
   q4.pop_front();
   std::cout << "empty: " << (!q4.empty()) << " " << q4 << "\n";

   deque q5(std::move(q4));
   std::cout << "move constr: " << (q4.size() == 0) << " " << q5 << "\n";

   deque q6;
   q6 = std::move(q5);
   std::cout << "move assignment: " << (q5.size() == 0) << " " << q6 << "\n";
 
#else
   std::cout << price(1000) << " " << 1000_kzt << " " << 1000_tt << "\n";

   std::cout << 5 * 500_kzt << "\n";
   std::cout << 300_tt + 400_kzt << "\n";
   std::cout << ( 250_tt == 200_tt + 50_tt ) << "\n";
   std::cout << order( "tiramisu", 1790_tt ) << "\n";
   std::cout << order( "medowik", 1590_tt, 3 ) << "\n";

   deque q;
   q. push_back( { "espresso", 750_tt } );
   std::cout << q << "\n";
   q. push_back( { "esterhazy", 1690_kzt } );
   std::cout << q << "\n"; 
   q. push_back( { "latte macchiato", 1170_tt, 2 } );
   std::cout << q << "\n";

   while( q. size( ) > 3 )
   {
      auto s = std::move( q. front( ));
      std::cout << s << "\n";
      q. pop_front( );
   }

   deque many_orders = 
      {  { "cake", 500_tt }, { "cappuccino", 1170_tt }, 
         { "pavlova", 1990_tt }} ;

   q = many_orders;

   while( q. size( ))
   {
      std::cout << q. front( ) << "\n";
      q. pop_front( );
   }
#endif

   return 0;
}



