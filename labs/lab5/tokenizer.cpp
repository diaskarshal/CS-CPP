
#include <stdexcept>

#include "tokenizer.h"

#include "dfa.h"


void tokenizer::consume( )
{
   if( lookahead. has_value( ) &&
       ( lookahead. value( ). tp == sym_eof ||
         lookahead. value( ). tp == sym_filebad ))
   {
      throw std::logic_error( "cannot clear when file is not readable" );
         // Reading beyond eof or filebad is UB. We are checking and
         // throwing an exception, not behave we have to, but because we
         // are nice. 
   }

   lookahead. reset( );
}

const symbol& tokenizer::getsymbol( )
{
   // static auto cls = buildclassifier( );
   static auto cls = 100;

   if( lookahead. has_value( ))
      return lookahead. value( );

restart:
   // We jump back to here if we see a whitespace. Use of goto's in
   // tokenizers is acceptable (even recommended).

   auto startpoint = location( source. line, source. column );
      // Start location of symbol that we are hoping to find.

   if( !source. has(1)) 
   {
      lookahead = symbol( sym_eof, startpoint );
      return lookahead. value( );
   }

   if( !source. good( ))
   {
      lookahead = symbol( sym_filebad, startpoint );
      return lookahead. value( );
   }

   auto p = readandclassify( cls, source );
   // std::cout << p. first << "/" << p. second << "\n";

   if( p. first == sym_whitespace || p. first == sym_comment )
   {
      source. commit( p. second );
      goto restart;
   }

   if( p. first == sym_num )
   {
      double d = std::stod( std::string( source. view( p. second ))); 
         // Why not possible from std::string_view ? 

      source. commit( p. second ); 
      lookahead = symbol( sym_num, d, startpoint ); 
      return lookahead. value( );
   }

   if( p. first == sym_var || p. first == sym_garbage )
   {
      if( p. second == 0 )
         p. second = 1;

      std::string id = std::string( source. view( p. second ));

      lookahead = symbol( p. first, std::move( id ), startpoint );
      source. commit( p. second );
      return lookahead. value( );
   }

   // Default is without attribute:

   source. commit( p. second );
   lookahead = symbol( p. first, startpoint );
   return lookahead. value( );
}

void tokenizer::test( )
{
   getsymbol( );
   std::cout << lookahead. value( ) << "\n";
   while( lookahead. value( ). tp != sym_eof &&
          lookahead. value( ). tp != sym_quit )
   {
      consume( ); 
      getsymbol( );
      std::cout << lookahead. value( ) << "\n";
   }
}

void tokenizer::print( std::ostream& out ) const
{
   out << "Source\n";
   out << "   " << source;
   if( lookahead. has_value( ))
      out << "   lookahead = " << lookahead. value( );
   else
      out << "   (no lookahead)";
}


