
#include "string.h"
#include <utility>


csci152::string::string( ) noexcept
{ }


csci152::string::string( string&& s ) noexcept
{ }


csci152::string&
csci152::string::operator = ( csci152::string&& s ) noexcept
{
}

void csci152::string::ensure_capacity( size_t c ) 
{
   if( cap < c )
   {
      if( cap == 0 )
      {

      }
      else
      {
         // size_t new_cap = c + 1000;
         size_t new_cap = c * 2;
         // size_t new_cap = c * 3;
 
      }
   }
}


csci152::string::~string( ) noexcept
{
}


void csci152::string::push_back( char c )
{
}

void csci152::string::pop_back( )
{
}

void csci152::string::clear( )
{
}


size_t csci152::string::size( ) const
{
}

bool csci152::string::empty( ) const
{
}


void csci152::string::push_back( const char* s )
{
}


