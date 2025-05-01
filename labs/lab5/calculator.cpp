
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


double factorial( unsigned int n )
   { }


// Throw an exception if d is not close to an int:

int make_int( double d )
   { }


double appl( symtype tp, const std::vector< double > & args )
   { }


double eval_sum( tokenizer& inp, const varmap& );
double eval_product( tokenizer& inp, const varmap& );
double eval_prefix( tokenizer& inp, const varmap& );
double eval_postfix( tokenizer& inp, const varmap& );
double eval_pow( tokenizer& inp, const varmap& );
double eval_function( tokenizer& inp, const varmap& );
   // We need all these forward declarations, because
   // some functions call functions that come later. 

double eval_sum( tokenizer& inp, const varmap& variables )
{ }

double eval_product( tokenizer& inp, const varmap& variables )
{ }

double eval_prefix( tokenizer& inp, const varmap& variables )
{ }

double eval_postfix( tokenizer& inp, const varmap& variables )
{ }

double eval_pow( tokenizer& inp, const varmap& variables )
{ }

double eval_function( tokenizer& inp, const varmap& variables )
{ }


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

