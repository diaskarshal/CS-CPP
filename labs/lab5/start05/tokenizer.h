
#ifndef TOKENIZER_ 
#define TOKENIZER_  

#include <iostream>
#include <optional>
#include "filereader.h" 
#include "symbol.h"

// This is the tokenizer for lab exercise 5 (calculator). 

class tokenizer
{
   lexing::filereader source;
   std::optional< symbol > lookahead;

public:
   tokenizer( ) = delete;

   tokenizer( lexing::filereader&& source ) noexcept
      : source( std::move( source ))
   { }

   void consume( );
      // Consume the current lookahead. This means that
      // getlookahead( ) will get a new symbol from the input,
      // when it is called the next time. 
      // Don't clear a sym_eof, or sym_filebad.

   const symbol& getsymbol( );
      // Not a const method, because we may read from the
      // input source if no symbol is present. 
      // If we have a symbol, we return it, otherwise we read a symbol. 
      // I am general against calling functions 'getX', but in this case
      // it is reasonable, becaues the lookahead really needs
      // to come from somewhere else.

   void test( );
      // Keep on reading symbols and printing them, until
      // sym_eof is encountered.

   void print( std::ostream& out ) const;
};

inline std::ostream& operator << ( std::ostream& out, const tokenizer& tok )
{
   tok. print( out ); return out;
}

#endif

