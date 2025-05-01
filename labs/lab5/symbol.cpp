
#include "symbol.h"

const char* getcstring( symtype tp )
{
   switch( tp )
   {
   case sym_whitespace:    return "whitespace";
   case sym_comment:       return "comment";

   case sym_comma:         return "comma";
   case sym_lpar:          return "lpar";
   case sym_rpar:          return "rpar";
   case sym_semicolon:     return "semicolon";

   case sym_store:         return "store";
   case sym_variables:     return "variables";
   case sym_quit:          return "quit";

   case sym_plus:          return "plus";  
   case sym_minus:         return "minus"; 
   case sym_times:         return "times"; 
   case sym_div:           return "div"; 
   case sym_mod:           return "mod"; 
   case sym_pow:           return "pow";

   case sym_fact:          return "fact";
   case sym_deg:           return "deg";

   case sym_sin:           return "sin"; 
   case sym_cos:           return "cos";
   case sym_tan:           return "tan";    
   case sym_exp:           return "exp"; 
   case sym_log:           return "log";

   case sym_asin:          return "asin";
   case sym_acos:          return "acos";
   case sym_atan:          return "atan";

   case sym_sqrt:          return "sqrt"; 
   case sym_abs:           return "abs"; 
   case sym_num:           return "num"; 
   case sym_var:           return "var"; 

   case sym_eof:           return "eof"; 
   case sym_filebad:       return "filebad"; 
   case sym_garbage:       return "garbage";
   }

   return "???"; 
}


std::ostream& operator << ( std::ostream& out, const symbol & sym )
{
   out << "symbol( " << sym. loc << " : ";
   out << sym. tp;

   if( holds_alternative< double > ( sym. attribute ))
   {
      out << ", " << get< double > ( sym. attribute ) << " )";
      return out;
   }

   if( holds_alternative< std::string > ( sym. attribute ))
   {
      out << ", " << get< std::string > ( sym. attribute ) << " )";
      return out;
   }

   out << " )";
   return out;

}


