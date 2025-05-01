
#ifndef SYNTAX_ERROR_
#define SYNTAX_ERROR_

#include <stdexcept>
#include <string_view>
#include <optional> 
#include <iostream>

#include "location.h"

struct syntax_error 
{
   std::string explanation;
   location loc;

   syntax_error( std::string_view explanation, 
                 location loc ) 
      : explanation( std::string( explanation )),
        loc( loc ) 
   { }

   void print( std::ostream& out ) const 
   {
      out << explanation; 
      out << " at location " << loc; 
   }

};

inline 
std::ostream& operator << ( std::ostream& out, const syntax_error& e )
{
   e. print( out ); return out;
}

#endif

