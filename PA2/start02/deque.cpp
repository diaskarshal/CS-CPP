
#include "deque.h"
#include <utility>

void deque::check_invariant( ) const
{
   if( deq_size == 0 )
   {
      if( deq_front )
         throw std::logic_error( "size == 0, but front != nullptr" );
      if( deq_back )
         throw std::logic_error( "size == 0, but back != nullptr" );
   }
   else
   {
      size_t truesize = 0;

      if( deq_front -> prev )
         throw std::logic_error( "prev of front not nullptr " );
      if( deq_back -> next )
         throw std::logic_error( "next of back not nullptr" );

      for( auto p = deq_front; p; p = p -> next ) 
      {
         // If p has a next, its prev must be p.
         // If p has no next, p must be the back of the deque. 

         if( p -> next )
         {
            if( p -> next -> prev != p )
               throw std::logic_error( "prev or next is wrong" );
         }
         else
         {
            if( p != deq_back )
               throw std::logic_error( "deq_back is wrong" );
         } 
         ++ truesize;
      } 

      if( truesize != deq_size )
         throw std::logic_error( "deq_size is wrong" ); 
   }
}


deque::deque( ) noexcept
{ }



void deque::push_back( const valtype& val )
{
}

void deque::pop_back( )
{
}

const deque::valtype& deque::back( ) const
{
}

deque::valtype& deque::deque::back( )
{
}

// front methods:

void deque::push_front( const valtype& val ) 
{  
}

void deque::pop_front( )
{
}


const deque::valtype& deque::front( ) const
{
}

deque::valtype& deque::deque::front( )
{
}

void deque::print( std::ostream& out ) const
{
}


deque::deque( const deque& q )
{
}

deque::deque( std::initializer_list< valtype > init )
   : deque( ) 
{
}

deque:: ~deque( ) 
{
}


void deque::reset_front( size_t s )
{
}

void deque::reset_back( size_t s )
{
}


const deque& deque::operator = ( const deque& q )
{
}

size_t deque::size( ) const 
{
}

bool deque::empty( ) const
{
}


deque::deque( deque&& q ) noexcept
{ }


const deque& deque::operator = ( deque&& q ) noexcept
{
}


