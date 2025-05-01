
// Modern coding: We are going to center our code around types.
// Put different types in different files, and move the code to the type that
// they belong to (most)

// What is a type?
// simple view (old fashioned) : Type is defined by implementation.
// two things that have the same implementation, have the same type.
// In C if you define a type, you only define its implementation.

#include "phonebook.h"
#include <fstream>

int main( int argc, char* argv[] )
{
#if 0
   Name n( "CATO" );
   std::cout << n << "\n";

   n = Name( "van-beethoven" );
   std::cout << n << "\n";
   return 0;
#endif

   return 0; 
}

