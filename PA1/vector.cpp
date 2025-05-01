
#include "vector.h"
namespace csci152{

     size_t vector::minpow2( size_t x ){
          size_t c = 1;
          while(c < x)
               c *= 2;
          return c;
     }

     void vector::reallocate( size_t c ){
          size_t new_cap = minpow2(c);
          if (new_cap == cap) 
               return;
          basetype * new_heap = new basetype[new_cap];

          for(size_t i = 0; i < sz; i++)
               new_heap[i] = heap[i];

          delete[] heap;
          heap = new_heap;
          cap = new_cap;
     }

     vector::vector() : sz(0), cap(1), heap(new basetype[cap]){ }

     vector::vector( const vector& other ) : sz(other.size()), cap(minpow2(sz)), heap(new basetype[cap]){
          for(size_t i = 0; i < sz; i++)
               heap[i] = other[i];
     }

     vector& vector::operator = ( const vector& other ){
          if(this != &other){
               delete[] heap;
               sz = other.sz;
               cap = other.cap;
               heap = new basetype[cap];

               for(size_t i = 0; i < sz; i++)
                    heap[i] = other[i];
          }
          return * this;
     }

     vector::~vector( ){
          delete[] heap;
     }

     vector::vector(std::initializer_list<basetype> values) : sz(0), cap(minpow2(values.size())), heap(new basetype[cap]){
          for(basetype val : values)
               heap[sz++] = val;
     }

     void vector::push_back( const basetype& val ){
          if(sz == cap)
               reallocate(cap * 2);
          heap[sz++] = val;
     }

     basetype& vector::operator[]( size_t i ){
          if(i >= sz)
               throw std::out_of_range("Bad Index");
          return heap[i];
     }

     const basetype& vector::operator[]( size_t i ) const{
          if(i >= sz)
               throw std::out_of_range("Bad Index");
          return heap[i];
     }

     basetype& vector::at( size_t i ){
          if(i >= sz)
               throw std::out_of_range("Bad Index");
          return heap[i];
     }

     const basetype& vector::at( size_t i ) const{
          if(i >= sz)
               throw std::out_of_range("Bad Index");
          return heap[i];
     }

     basetype& vector::front( ){
          // if(sz == 0)
          //      throw std::out_of_range("Vector is empty");
          return heap[0];
     }

     const basetype& vector::front( ) const{
          // if(sz == 0)
          //      throw std::out_of_range("Vector is empty");
          return heap[0];
     }

     basetype& vector::back( ){
          // if(sz == 0)
          //      throw std::out_of_range("Vector is empty");
          return heap[sz - 1];
     }

     const basetype& vector::back( ) const{
          // if(sz == 0)
          //      throw std::out_of_range("Vector is empty");
          return heap[sz - 1];
     }

     void vector::pop_back( ){
          // if(sz == 0)
          //      throw std::logic_error("vector is empty");
          basetype * new_heap = new basetype[cap];

          for(size_t i = 0; i < sz - 1; i++)
               new_heap[i] = heap[i];

          delete[] heap;
          heap = new_heap;
          sz--;
     }

     void vector::reserve( size_t c ){
          if(cap < c){
               size_t reserve_cap = minpow2(c);
               basetype * reserve_heap = new basetype[reserve_cap];
               
               for(size_t i = 0; i < sz; i++){
                    reserve_heap[i] = heap[i];
               }
               
               delete[] heap;
               heap = reserve_heap;
               cap = reserve_cap;
          }
     }

     void vector::shrink( ){
          size_t new_cap = minpow2(sz);
          if(new_cap < cap)
               reallocate(new_cap);
     }

     void vector::insert( size_t i, const basetype& val ){
          // if(i > sz) 
          //      throw std::out_of_range("Bad Index");
          if(sz == cap)
               cap *= 2;

          basetype * new_heap = new basetype[cap];
          bool checker = 0;
          
          for(size_t index = 0; index <= sz; index++){
               if(index == i){
                    checker = 1;
                    new_heap[i] = val;
               }
               else{
                    if(checker)
                         new_heap[index] = heap[index - 1];
                    else
                         new_heap[index] = heap[index];
               }
          }

          delete[] heap;
          heap = new_heap;
          sz++;
     }

     void vector::erase( size_t i ){
          // if(i >= sz)
          //      throw std::out_of_range("Bad Index");

          for(size_t j = i; j < sz - 1; j++)
               heap[j] = heap[j + 1];

          sz--;
     }

     void vector::print( std::ostream& out ) const{
          out << '[';

          for(size_t i = 0; i < sz; i++){
               out << heap[i];
               if(i < sz - 1)
                    out << ", ";
          }

          out << ']';
     }

}