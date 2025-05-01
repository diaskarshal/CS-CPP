
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

deque::deque( ) noexcept : deq_size(0), deq_front(nullptr), deq_back(nullptr)
{ }

void deque::push_back( const valtype& val ){
   node * new_node = new node(val);

   if(deq_size == 0){
      deq_front = new_node;
      deq_back = new_node;
   }

   else{
      new_node->prev = deq_back;
      deq_back->next = new_node;
      deq_back = new_node;
   }

   ++deq_size;
}

void deque::pop_back( ){
   if(deq_size == 1){
      delete deq_back;
      deq_back = nullptr;
      deq_front = nullptr;
   }

   else{
      node * temp = std::exchange(deq_back, deq_back->prev);
      deq_back->next = nullptr;
      delete temp;
   }

   --deq_size;
}

const deque::valtype& deque::back( ) const{
   return deq_back->val;
}

deque::valtype& deque::back( ){
   return deq_back->val;
}

// front methods:

void deque::push_front( const valtype& val ){
   node * new_node = new node(val);

   if(deq_size == 0){
      deq_front = new_node;
      deq_back = new_node;
   }

   else{
      new_node->next = deq_front;
      deq_front->prev = new_node;
      deq_front = new_node;
   }

   ++deq_size;  
}

void deque::pop_front( ){
   if(deq_size == 1){
      delete deq_front;
      deq_back = nullptr;
      deq_front = nullptr;
   }

   else{
      node * temp = std::exchange(deq_front, deq_front->next);
      deq_front->prev = nullptr;
      delete temp;
   }

   --deq_size;
}


const deque::valtype& deque::front( ) const{
   return deq_front->val;
}

deque::valtype& deque::front( ){
   return deq_front->val;
}

void deque::print( std::ostream& out ) const{
   if(deq_size == 0)
      out << "[ ]";
   
   else{
      out << "[ ";
      node * temp = deq_front;

      for(size_t i = 0; i < deq_size; i++){
         out << temp->val;
         if(i < deq_size - 1)
               out << ", ";
         temp = temp->next;
      }
      
      out << " ]";
   }
}

deque::deque( const deque& q ) : deque(){
   for(node * temp = q.deq_front; temp != nullptr; temp = temp->next)
      push_back(temp->val);
}

deque::deque( std::initializer_list< valtype > init ) : deque( ){
   for(const valtype& elem : init)
      push_back(elem);
}

deque:: ~deque( ){
   while(deq_front != nullptr){
      node * temp = std::exchange(deq_front, deq_front->next);
      delete temp;
   }

   deq_back = nullptr;
   deq_size = 0;
}

void deque::reset_front( size_t s ){
   while(deq_size > s)
      pop_front();
}

void deque::reset_back( size_t s ){
   while(deq_size > s)
      pop_back();
}

const deque& deque::operator = ( const deque& q ){
   /* inefficient */

   // if(this == &q)
   //    return * this;

   // while(deq_size > 0)
   //    pop_back();

   // node * temp = q.deq_front;

   // while(temp != nullptr){
   //    push_back(temp->val);
   //    temp = temp->next;
   // }

   // return * this;
   
   /* efficient */

   if(this == &q)
      return * this;

   node * ptr_this = deq_front;
   node * ptr_q = q.deq_front;

   while(ptr_this != nullptr && ptr_q != nullptr){
      ptr_this->val = ptr_q->val;
      ptr_this = ptr_this->next;
      ptr_q = ptr_q->next;
   }

   while(ptr_q != nullptr){
      push_back(ptr_q->val);
      ptr_q = ptr_q->next;
   }

   while(deq_size > q.deq_size){
      pop_back();
   }

   return * this;
}

size_t deque::size( ) const{
   return deq_size;
}

bool deque::empty( ) const{
   return deq_size == 0;
}

deque::deque(deque&& q) noexcept
   :  deq_size( q. deq_size ),
      deq_front( q. deq_front ),
      deq_back( q. deq_back )
   {
      q. deq_size = 0;
      q. deq_front = nullptr;
      q. deq_back = nullptr;
   }

const deque& deque::operator=(deque&& q) noexcept{
   clear();

   deq_size = std::exchange(q.deq_size, 0);
   deq_front = std::exchange(q.deq_front, nullptr);
   deq_back = std::exchange(q.deq_back, nullptr);

   return * this;
}



