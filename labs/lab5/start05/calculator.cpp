
#include <cmath>
#include <map>
#include <vector>
#include <optional>
#include <utility>

#include "tokenizer.h"
#include "syntax_error.h"

using varmap = std::map< std::string, double > ;

std::ostream& operator << ( std::ostream& out, const varmap& mp )
{
   out << "Variables:\n";
   for( const auto& v : mp )
      out << "      " << v. first << "   =   " << v. second << "\n";
   return out;
}


// Read the input until the next semicolon.
// This needs to be done after an error.

void next_semicolon( tokenizer& inp )
{
   while( inp. getsymbol( ). tp != sym_semicolon &&
          inp. getsymbol( ). tp != sym_eof )
   {
      inp. consume( );
   }
   if( inp. getsymbol( ). tp != sym_eof )
      inp. consume( );
}

double factorial( unsigned int n ){
   double res = 1;

   for(unsigned int i = 2; i <= n; i++){
      res *= i;
   }
   
   return res;
}

int make_int( double d ){
   constexpr double close = 1.0E-8;
   double rounded = std::round(d);
   
   if(std::fabs(d - rounded) >= close)
      throw std::runtime_error("d is not close to an int");
   
   return (int)rounded;
}

double appl( symtype tp, const std::vector< double > & args ){
   switch(tp){
      case sym_plus:
         if(args.size() != 2) throw std::runtime_error("addition needs 2 args");
         return args[0] + args[1];
      case sym_minus:
         if(args.size() != 2) throw std::runtime_error("substraction needs 2 args");
         return args[0] - args[1];
      case sym_times:
         if(args.size() != 2) throw std::runtime_error("multiplication needs 2 args");
         return args[0] * args[1];
      case sym_div:
         if(args.size() != 2) throw std::runtime_error("division needs 2 args");
         if(args[1] == 0) throw std::runtime_error("division by zero");
         return args[0] / args[1];
      case sym_mod:
         if(args.size() != 2) throw std::runtime_error("modulo needs 2 args");
         if(args[1] == 0) throw std::runtime_error("modulo by zero");
         return std::fmod(args[0], args[1]);
      case sym_pow:
         if(args.size() != 2) throw std::runtime_error("power needs 2 args");
         return std::pow(args[0], args[1]);
      case sym_sqrt:
         if(args.size() != 1) throw std::runtime_error("sqrt needs 1 arg");
         if(args[0] <0 ) throw std::runtime_error("sqrt arg cannot be < 0");
         return std::sqrt(args[0]);
      case sym_abs:
         if(args.size() != 1) throw std::runtime_error("abs needs 1 arg");
         return std::fabs(args[0]);
      case sym_sin:
         if(args.size() != 1) throw std::runtime_error("sin needs 1 arg");
         return std::sin(args[0]);
      case sym_cos:
         if(args.size() != 1) throw std::runtime_error("cos needs 1 arg");
         return std::cos(args[0]);
      case sym_tan:
         if(args.size() !=1 ) throw std::runtime_error("tan needs 1 arg");
         return std::tan(args[0]);
      case sym_asin:
         if(args.size() != 1) throw std::runtime_error("asin needs 1 arg");
         if(args[0] < -1 || args[0] > 1) throw std::runtime_error("asin arg out of [-1,1] range");
         return std::asin(args[0]);
      case sym_acos:
         if(args.size() !=1 ) throw std::runtime_error("acos needs 1 arg");
         if(args[0] < -1 || args[0] > 1) throw std::runtime_error("acos arg out of [-1,1] range");
         return std::acos(args[0]);
      case sym_atan:
         if(args.size() !=1 ) throw std::runtime_error("atan needs 1 arg");
         return std::atan(args[0]);
      case sym_log:
         if(args.size() != 1) throw std::runtime_error("log needs 1 arg");
         if(args[0] <= 0) throw std::runtime_error("log arg cannot be <= 0");
         return std::log(args[0]);
      case sym_exp:
         if(args.size() != 1) throw std::runtime_error("exp needs 1 arg");
         return std::exp(args[0]);
      default:
         throw std::runtime_error("no such function");
   }
}

double eval_sum( tokenizer& inp, const varmap& );
double eval_product( tokenizer& inp, const varmap& );
double eval_prefix( tokenizer& inp, const varmap& );
double eval_postfix( tokenizer& inp, const varmap& );
double eval_pow( tokenizer& inp, const varmap& );
double eval_function( tokenizer& inp, const varmap& );

double eval_sum( tokenizer& inp, const varmap& variables ){
   double res = eval_product(inp, variables);
   
   while(true){
      symbol s = inp.getsymbol();
      if(s.tp == sym_plus || s.tp == sym_minus){
         inp.consume();
         double next = eval_product(inp, variables);
         res = appl(s.tp, {res, next});
      } else break;
   }

   return res;
}

double eval_product( tokenizer& inp, const varmap& variables ){
   double res = eval_prefix(inp, variables);
   
   while(true){
      symbol s = inp.getsymbol();
      if(s.tp == sym_times || s.tp == sym_div || s.tp == sym_mod){
         inp.consume();
         double next = eval_prefix(inp, variables);
         res = appl(s.tp, {res, next});
      } else break;
   }

   return res;
}

double eval_prefix( tokenizer& inp, const varmap& variables ){
   int sign = 1;

   while(true){
      symbol s = inp.getsymbol();
      if(s.tp == sym_minus){
         inp.consume();
         sign = -sign;
      } else if(s.tp == sym_plus){
         inp.consume();
      } else if(s.tp == sym_deg){
         inp.consume();
         double val = eval_prefix(inp, variables);
         return val * 180.0 / 3.141592653589793238462643383279;
      } else break;
   }

   return sign * eval_postfix(inp, variables);
}

double eval_postfix( tokenizer& inp, const varmap& variables ){
   double res = eval_pow(inp, variables);

   while(true){
      symbol s = inp.getsymbol();
      if(s.tp == sym_fact){
         inp.consume();
         res = factorial(make_int(res));
      } else if(s.tp == sym_deg){
         inp.consume();
         res = res * 3.141592653589793238462643383279 / 180.0;
      } else break;
   }

   return res;
}

double eval_pow( tokenizer& inp, const varmap& variables ){
   double res = eval_function(inp, variables);
   symbol s = inp.getsymbol();

   if(s.tp == sym_pow){
      inp.consume();
      double exponent = eval_pow(inp, variables);
      res = appl(sym_pow, {res, exponent});
   }
   
   return res;
}

double eval_function( tokenizer& inp, const varmap& variables ){
   symbol s = inp.getsymbol();

   if(s.tp == sym_num){
      double val = s.get_double();
      inp.consume();
      return val;
   } else if(s.tp == sym_var){
      std::string v = s.get_string();
      inp.consume();

      if(!variables.contains(v)) throw std::runtime_error("unknown variable " + v);
      
      return variables.at(v);
   } else if(s.tp == sym_lpar){
      inp.consume();
      double res = eval_sum(inp, variables);
      
      if(inp.getsymbol().tp != sym_rpar)
         throw syntax_error("expected ')'", inp.getsymbol().loc);
      
      inp.consume();
      return res;
   } else if(s.tp == sym_sin || s.tp == sym_cos || s.tp == sym_tan ||
             s.tp == sym_asin || s.tp == sym_acos || s.tp == sym_atan ||
             s.tp == sym_log || s.tp == sym_exp || s.tp == sym_sqrt ||
             s.tp == sym_abs){
      symtype f = s.tp;
      inp.consume();
      
      if(inp.getsymbol().tp != sym_lpar)
         throw syntax_error("expected '(' after function ", inp.getsymbol().loc);
      
      inp.consume();
      std::vector<double> args;
      
      if(inp.getsymbol().tp != sym_rpar){
         while(true){
            args.push_back(eval_sum(inp, variables));
            if(inp.getsymbol().tp == sym_comma) inp.consume();
            else break;
         }
      }
      
      if(inp.getsymbol().tp != sym_rpar)
         throw syntax_error("missing ')' after function ", inp.getsymbol().loc);
      
      inp.consume();
      return appl(f, args);
   }
   
   throw syntax_error("syntax error", s.loc);
}

int main( int argc, char *argv[] )
{

   lexing::filereader file( &std::cin, "stdin" );
   auto inp = tokenizer( std::move( file ));

   if constexpr ( false )
   {
      std::cout << "testing the tokenizer\n";
      inp. test( );
      return 0;
   }

   varmap variables;
   variables[ "e" ] = 2.7182818284590452353602874713526;
   variables[ "pi" ] = 3.141592653589793238462643383279;

   std::optional< double > result;

   while( true )
   {
      try
      {
         std::cout << ":- "; flush( std::cout );

         switch( inp. getsymbol( ). tp )
         {
         case sym_variables:
            inp. consume( );
            std::cout << variables; 
            break;
         case sym_eof:
         case sym_quit:
            std::cout << "quitting\n";
            return 0;
         case sym_store:
            {
               inp. consume( );
               if( inp. getsymbol( ). tp != sym_var )
               {
                  throw syntax_error( "expected a variable", 
                                      inp. getsymbol( ). loc );
               } 
               auto id = inp. getsymbol( ). get_string( );
               inp. consume( );

               if( !result. has_value( ))   
                  std::cout << "no result to store\n";
               else
               {
                  std::cout << "stored " << result. value( );
                  std::cout << " in " << id << "\n";
                  variables[ id ] = result. value( );
               }
               break;
            } 
         default:
            result = eval_sum( inp, variables );
            std::cout << "result: " << result. value( ) << "\n";
            break;
         }

         if( inp. getsymbol( ). tp != sym_semicolon )
         {
            throw syntax_error( "semicolon expected", 
                                inp. getsymbol( ). loc );
         }
         else
            inp. consume( );

      }
      catch( const std::logic_error& e )
      {
         std::cout << e. what( ) << "\n";
         return 0;
            // Because it is a programmer error.
      }
      catch( const syntax_error& e )
      {
         std::cout << e << "\n";
         next_semicolon( inp );
      }
      catch( const std::runtime_error& e )
      {
         std::cout << e. what( ) << "\n";
         next_semicolon( inp );
      }
      catch( const std::bad_variant_access& e )
      {
         std::cout << e. what( ) << "\n";
         std::cout << "(this means that you tried to get an attribute from a ";
         std::cout << "symbol, that it does not have)\n";
         return 0; 
            // It is a programmer error. 
      }
   }
   return 0;
}
