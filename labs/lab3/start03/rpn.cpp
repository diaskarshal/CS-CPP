
#include "printstack.h" 
#include "rpn_error.h"
#include "input.h"

#include <cmath>
// ./rpn < test1.rpn
// Apply an operator with zero arguments: 
// 3.1415926535897932
// 2.7182818284590452
static constexpr bool show = false;

double apply0( inputtype op )
{
   if constexpr( show ) 
      std::cout << "applying " << op << "\n";

   // (your code)
   // double pi = 3.1415926535897932;
   // double e = 2.7182818284590452;

   if(op == inp_e)
      return 2.7182818284590452;
   else if(op == inp_pi)
      return 3.1415926535897932;

   throw std::logic_error( "unknown 0-ary operator" );
}

// Apply an operator with one argument:

double apply1( inputtype op, double d1 )
{
   if constexpr( show ) 
      std::cout << "applying " << op << " on " << d1 << "\n";

   // (your code)
   if(op == inp_exp)
      return exp(d1);

   else if(op == inp_log)
      return log(d1);

   else if(op == inp_sqrt)
      return sqrt(d1);

   else if(op == inp_sin)
      return sin(d1);

   else if(op == inp_cos)
      return cos(d1);

   else if(op == inp_tan)
      return tan(d1);

   else if(op == inp_abs)
      return abs(d1);

   throw std::logic_error( "unknown unary operator" );
      // this is a message to the implementer of rpn, so it can be a bit rude. 
}

// Apply an operator with two arguments:

double apply2( inputtype op, double d1, double d2 )
{
   if constexpr( show ) 
      std::cout << "applying " << op << " on " << d1 << " and " << d2 << "\n";

   // (your code)
   if(op == inp_plus)
      return d1 + d2;

   else if(op == inp_minus)
      return d1 - d2;

   else if(op == inp_times)
      return d1 * d2;

   else if(op == inp_div)
      return d1 / d2;

   else if(op == inp_mod)
      return d1 - static_cast<long int> (( d1 / d2 )) * d2;

   else if(op == inp_pow)
      return pow(d1, d2);

   throw std::logic_error( "unknown binary operator" );
}

// Evaluate an expression in RPN:

double eval( lexing::filereader& inp )
{
   std::stack<double> st;

   while( true )
   {
      std::pair< inputtype, size_t > p = read( inp );

      // Obtain a pair containing the type of input with its length.
      // The characters are stored in a buffer inside inp. 
      // They can be obtained by calling inp. get(i).

      if constexpr( show )
         std::cout << "input: " << p. first << "/" << inp. view( p. second ) << "\n";

      switch( p. first )
      {
      case inp_e:
      case inp_pi:
         st. push( apply0( p. first ));
         break;

      case inp_num:
         // Translate contents of buffer into double : 

         st. push( std::stod( std::string( inp. view( p. second ))));
         break;

      case inp_sin:
      case inp_cos:
      case inp_tan:
      case inp_exp:
      case inp_log:
      case inp_sqrt:
      case inp_abs:
         {
            if( st. size( ) < 1 )
            {
               throw rpn_error(
                  std::string( "unary operator " ) +
                  cstring( p. first ) + ": no number on stack",
                                 inp. line, inp. column );
            }

            double d1 = st. top( ); st. pop( );
            st. push( apply1( p. first, d1 ));
         }
         break;

      case inp_plus:
      case inp_minus:
      case inp_times:
      case inp_div:
      case inp_mod:
      case inp_pow:
         {
            if( st. size( ) < 2 )
            {
               throw rpn_error(
                  std::string( "binary operator " ) +
                  cstring( p. first ) + ": less than two numbers on stack",
                  inp. line, inp. column );
            }

            double d2 = st. top( ); st. pop( );
            double d1 = st. top( ); st. pop( );

            st. push( apply2( p. first, d1, d2 ));
         }
         break;
      case inp_whitespace:
      case inp_comment:
         break;

      case inp_end:
         if( st. size( ) == 0 )
         {
            throw rpn_error( "no value to return",
                    inp. line, inp. column );
         }
         if( st. size( ) > 1 )
         {
            std::cout << "(ended with more than one value on the stack)\n";
         }

         return st. top( );

      case inp_ident:
         throw rpn_error( "unknown identifier", inp. line, inp. column );

      default:
         throw rpn_error( std::string( "cannot handle " ) +
                          cstring( p. first ), inp. line, inp. column );
      }

      // Only print stack after change:

      if( p. first != inp_whitespace && p. first != inp_comment )
         std::cout << st << "\n";

      inp. commit( p. second );
   }

   return st. top( );
}


int main( int argc, char *argv[] )
{
   lexing::filereader inp( &std::cin, "stdin" );

   try
   {
      std::cout << "evaluating rpn:\n";
      double res = eval( inp );

      std::cout << "result: " << res << "\n";
   }
   catch( const std::logic_error& e )
   {
      std::cout << e. what( ) << "\n";
   }
   catch( const std::runtime_error& e )
   {
      std::cout << e. what( ) << "\n";
   }
   catch( const rpn_error& e )
   {
      std::cout << e << "\n";
   }
   return 0;
}


