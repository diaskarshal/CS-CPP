
#ifndef SYMBOL_
#define SYMBOL_

#include <iostream>
#include <variant>

#include "location.h"

enum symtype {
    sym_whitespace, sym_comment, 
    sym_comma, sym_lpar, sym_rpar, sym_semicolon, 
    sym_store, sym_variables, sym_quit, 
    sym_plus, sym_minus, sym_times, sym_div, sym_mod, sym_pow,
    sym_fact, sym_deg,
    sym_sin, sym_cos, sym_tan, sym_exp, sym_log,
    sym_asin, sym_acos, sym_atan,
    sym_sqrt, sym_abs, 
    sym_num, sym_var, 
    sym_eof, sym_filebad, sym_garbage };

const char* getcstring( symtype tp );
   // Return a C-string representing tp, so that it can be printed.

inline std::ostream& operator << ( std::ostream& out, symtype tp )
   { return out << getcstring( tp ); }

struct symbol
{
   symtype tp;
   std::variant< std::monostate, double, std::string > attribute;
   location loc; 

   symbol( ) = delete; 

   symbol( symtype tp, location loc ) 
      : tp( tp ),
        loc( loc ) 
   { }

   symbol( symtype tp, double val, location loc )
      : tp( tp ),
        attribute( val ),
        loc( loc )
   { }

   symbol( symtype tp, const std::string& var, location loc )
      : tp( tp ),
        attribute( var ),
        loc( loc )
   { }

   symbol( symtype tp, std::string&& var, location loc )
      : tp( tp ),
        attribute( std::move( var )),
        loc( loc )
   { }

   double get_double( ) const
      { return std::get< double > ( attribute ); }

   const std::string& get_string( ) const
      { return std::get< std::string > ( attribute ); }
 
};

std::ostream& operator << ( std::ostream& out, const symbol& sym );

#endif

