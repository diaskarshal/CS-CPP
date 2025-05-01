
#include "map.h"

// Should be copied from assignment 3:

int case_insensitive_cmp::operator( )

( const std::string& s1, const std::string& s2 ) const{

size_t minlen = s1.length() < s2.length() ? s1.length() : s2.length();

for(size_t i = 0; i < minlen; i++){

int diff = std::tolower(s1[i]) - std::tolower(s2[i]);

if(diff != 0) return diff;

}

return s1.length() - s2.length();

}

// must be written:

size_t case_insensitive_hash::operator( ) ( const std::string& s ) const{

// for(char c : s){

// tolower(c);

// }

// return 0;

size_t h = 0;

for (unsigned char c : s)

h = h * 131u + std::tolower(c);

return h;

}

size_t map::wrap( size_t pos ) const{

if(pos >= table.size()) pos -= table.size();

return pos;

}

size_t map::exactposition( const keytype& key ) const{

keyhash hash;

return hash(key) % table.size();

}

size_t map::minpow3( size_t sz ){

size_t p = 3;

while(p < sz) p *= 3;

return p;

}

size_t map::find( const keytype& key, size_t pos ) const{

keycmp cmp;

size_t dist = 0;

while(1){

size_t cur_pos = wrap(pos + dist);

if(table[cur_pos].isempty()) return dist;

if(table[cur_pos].dist < dist) return dist;

if(cmp(table[cur_pos].key, key) == 0) return dist;

dist++;

}

}

void map::insert_shift_up( size_t pos, cell& c ){

while(!c.isempty()){

if(table[pos].isempty()){

table[pos] = std::move(c);

c.clear();

} else if(table[pos].dist < c.dist) std::swap(table[pos], c);

if(!c.isempty()){

pos = wrap(pos + 1);

c.dist++;

if(c.dist >= table.size()) throw std::logic_error("logic error");

}

}

}

bool map::contains( const keytype& key ) const{

size_t pos = exactposition(key);

size_t dist = find(key, pos);

pos = wrap(pos + dist);

return !table[pos].isempty() && table[pos].dist == dist && keycmp()(table[pos].key, key) == 0;

}

bool map::insert( const keytype& key, const valtype& val ){

size_t pos = exactposition(key);

size_t dist = find(key, pos);

pos = wrap(pos + dist);

if(!table[pos].isempty() && table[pos].dist == dist) return 0;

if(rehash_needed(truesize + 1)){

rehash(truesize + 1);

pos = exactposition(key);

dist = find(key, pos);

pos = wrap(pos + dist);

}

cell new_cell(key, val, dist);

insert_shift_up(pos, new_cell);

truesize++;

return 1;

}

void map::rehash( size_t sz ){

size_t new_sz = minpow3(sz / max_load_factor);

map new_map(max_load_factor, new_sz);

for(const auto& c : table) if(!c.isempty()) new_map.insert(c.key, c.val);

*this = std::move(new_map);

}

const map::valtype& map::at( const keytype& key ) const{

size_t pos = exactposition(key);

size_t dist = find(key, pos);

pos = wrap(pos + dist);

if(!table[pos].isempty() && table[pos].dist == dist) return table[pos].val;

throw std::out_of_range("key is not present");

}

map::valtype& map::at( const keytype& key ){

size_t pos = exactposition(key);

size_t dist = find(key, pos);

pos = wrap(pos + dist);

if(!table[pos].isempty() && table[pos].dist == dist) return table[pos].val;

throw std::out_of_range("key is not present");

}

map::valtype& map::operator[] ( const keytype& key ){

size_t pos = exactposition(key);

size_t dist = find(key, pos);

pos = wrap(pos + dist);

if(table[pos].isempty() || table[pos].dist != dist || keycmp()(table[pos].key, key) != 0){

insert(key, valtype());

pos = exactposition(key);

dist = find(key, pos);

pos = wrap(pos + dist);

}

return table[pos].val;

// if(!contains(key)) insert(key, valtype{});

// return at(key);

}

bool map::erase( const keytype& key ){

size_t pos = exactposition( key );

size_t dist = find( key, pos );

pos = wrap( pos + dist );

if(table[pos].isempty() || table[pos].dist != dist) return 0;

table[pos].clear();

truesize--;

size_t pos2 = wrap(pos + 1);

while(!table[pos2].isempty() && table[pos2].dist != 0){

table[pos] = std::move(table[pos2]);

table[pos].dist--;

pos = pos2;

pos2 = wrap(pos2 + 1);

}

table[pos].clear();

return 1;

}

void map::clear( ){

for(auto& c : table) c.clear();

truesize = 0;

}

void map::cell::print( std::ostream& out ) const

{

if( isempty( ))

out << "(empty)";

else

out << key << "/" << val << " (" << dist << ")";

}

double map::average_dist( ) const

{

// Contrary to our principles:

if( truesize == 0 )

return 0.0;

double sum = 0.0;

for( const auto& c : table )

{

if( !c. isempty( ))

sum += c. dist;

}

return sum / truesize;

}

double map::standarddev() const

{

if( truesize == 0 )

return 0.0;

double sum = 0.0;

double av = average_dist();

for( const auto& c : table )

{

if( !c. isempty( ))

{

double dif = c. dist - av;

sum += dif*dif;

}

}

return sqrt( sum / truesize );

}

void map::print( std::ostream& out ) const

{

out << "hashmap( max_load_factor = " << max_load_factor;

out << ", size = " << truesize;

out << ", capacity = " << table. size( ) << " ):\n";

for( size_t pos = 0; pos != table. size( ); ++ pos )

{

if( !table[ pos ]. isempty( ))

out << pos << " : " << table[ pos ] << "\n";

}

}

void map::checkinvariants( ) const

{

if( table. size( ) < 3 )

throw std::logic_error( "table size too small" );

size_t i = 0;

for( const auto& t : table )

{

if( !t. isempty( ))

++ i;

}

if( i != truesize )

{

std::cout << i << " / truesize = " << truesize << "\n";

throw std::logic_error( "variable truesize does not hold the true size" );

}

if( i > table. size( ) * max_load_factor )

throw std::logic_error( "load factor > max_load_factor" );

for( size_t pos = 0; pos != table. size( ); ++ pos )

{

if( !table[ pos ]. isempty( ))

{

size_t p = exactposition( table[ pos ]. key );

size_t d = 0;

// p is the true position where table[ pos ] should be.

while( p != pos )

{

if( table[p]. isempty( ))

{

std::cout << "cell " << pos << " should have been at " << p << "\n";

throw std::logic_error( "there is an empty cell" );

}

if( d > table[p]. dist )

{

std::cout << "cell " << pos << " should have been at " << p << "\n";

throw std::logic_error( "its displacement is bigger" );

}

p = wrap( p + 1 );

++ d;

}

if( table[ pos ]. dist != d )

{

std::cout << pos << " : " << table[ pos ];

std::cout << " has wrong dist field\n";

std::cout << exactposition( table[ pos ]. key ) << "\n";

throw std::runtime_error( "distance is wrong" );

}

}

}

} 

#include "map.h"

// Should be copied from assignment 3: 

int case_insensitive_cmp::operator( ) 
      ( const std::string& s1, const std::string& s2 ) const{
   size_t minlen = s1.length() < s2.length() ? s1.length() : s2.length();

   for(size_t i = 0; i < minlen; i++){
      int diff = std::tolower(s1[i]) - std::tolower(s2[i]);
      if(diff != 0) return diff;
   }

   return s1.length() - s2.length();
}


// must be written:

size_t case_insensitive_hash::operator( ) ( const std::string& s ) const{
   // for(char c : s){
   //    tolower(c);
   // }
   // return 0;
   size_t h = 0;
   for (unsigned char c : s)
      h = h * 131u + std::tolower(c);
   return h;
}

size_t map::wrap( size_t pos ) const{
   if(pos >= table.size()) pos -= table.size();
   return pos;
}

size_t map::exactposition( const keytype& key ) const{
   keyhash hash;
   return hash(key) % table.size();
}

size_t map::minpow3( size_t sz ){
   size_t p = 3;
   while(p < sz) p *= 3;
   return p;
}

// size_t map::find( const keytype& key, size_t pos ) const{
//    keycmp cmp;
//    size_t d = 0;

//    while(d < table.size()){
//       size_t cur_pos = wrap(pos + d);

//       if(!table[cur_pos].isempty() && cmp(table[cur_pos].key, key) == 0) return d;
//       if(table[cur_pos].isempty() || table[cur_pos].dist < d) return d;

//       d++;
//    }

//    return d;
// }
size_t map::find( const keytype& key, size_t pos ) const{
   keycmp cmp;
   size_t dist = 0;

   while(1){
      size_t cur_pos = wrap(pos + dist);

      if(table[cur_pos].isempty()) return dist;
      if(table[cur_pos].dist < dist) return dist;
      if(cmp(table[cur_pos].key, key) == 0) return dist;

      dist++;
   }

}

void map::insert_shift_up( size_t pos, cell& c ){
   while(!c.isempty()){
      if(table[pos].isempty()){
         table[pos] = std::move(c);
         c.clear();
      } else if(table[pos].dist < c.dist) std::swap(table[pos], c);

      if(!c.isempty()){
         pos = wrap(pos + 1);
         c.dist++;
         if(c.dist >= table.size()) throw std::logic_error("logic error");
      }
   }
}

bool map::contains( const keytype& key ) const{
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   return !table[pos].isempty() && table[pos].dist == dist && keycmp()(table[pos].key, key) == 0;
   // return !table[pos].isempty() && table[pos].dist == dist;
}

bool map::insert( const keytype& key, const valtype& val ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   if(!table[pos].isempty() && table[pos].dist == dist) return 0;
   // if(!table[pos].isempty() && table[pos].dist == dist && keycmp()(table[pos].key, key) == 0) return 0;;

   if(rehash_needed(truesize + 1)){
      rehash(truesize + 1);
      pos = exactposition(key);
      dist = find(key, pos);
      pos = wrap(pos + dist);
   }

   cell с(key, val, dist);
   insert_shift_up(pos, с);
   truesize++;

   return 1;
}

void map::rehash( size_t sz ){
   size_t new_sz = minpow3(sz / max_load_factor);
   map new_map(max_load_factor, new_sz);
   for(const auto& c : table) if(!c.isempty()) new_map.insert(c.key, c.val);
   *this = std::move(new_map);
}

const map::valtype& map::at( const keytype& key ) const{
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   if(!table[pos].isempty() && table[pos].dist == dist) return table[pos].val;

   throw std::out_of_range("key is not present");
}

map::valtype& map::at( const keytype& key ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   if(!table[pos].isempty() && table[pos].dist == dist) return table[pos].val;

   throw std::out_of_range("key is not present");
}

map::valtype& map::operator[] ( const keytype& key ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);

   if(table[pos].isempty() || table[pos].dist != dist || keycmp()(table[pos].key, key) != 0){
      insert(key, valtype());
      pos = exactposition(key);
      dist = find(key, pos);
      pos = wrap(pos + dist);
   }

   return table[pos].val;
   // if(!contains(key)) insert(key, valtype{});
   // return at(key);
}

bool map::erase( const keytype& key ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   // if(!table[pos].isempty() && table[pos].dist == dist) return 0;
   if(!table[pos].isempty() || table[pos].dist == dist) return 0;

   table[pos].clear();
   truesize--;

   size_t pos2 = wrap(pos + 1);

   while(!table[pos2].isempty() && table[pos2].dist != 0){
      table[pos] = std::move(table[pos2]);
      table[pos].dist--;
      pos = pos2;
      pos2 = wrap(pos2 + 1);
   }

   table[pos].clear();//??

   return 1;
}

void map::clear( ){
   for(auto& c : table) c.clear();
   truesize = 0;
}

void map::cell::print( std::ostream& out ) const
{
   if( isempty( ))
      out << "(empty)";
   else
      out << key << "/" << val << "      (" << dist << ")";
}

double map::average_dist( ) const
{
   // Contrary to our principles:

   if( truesize == 0 )
      return 0.0;

   double sum = 0.0;
   for( const auto& c : table )
   { 
      if( !c. isempty( ))
         sum += c. dist;
   }

   return sum / truesize;
}

double map::standarddev() const
{
   if( truesize == 0 )
      return 0.0;

   double sum = 0.0;
   double av = average_dist();

   for( const auto& c : table )
   {
      if( !c. isempty( ))
      {
         double dif = c. dist - av;
         sum += dif*dif;
      }
   }

   return sqrt( sum / truesize );
}

void map::print( std::ostream& out ) const
{
   out << "hashmap( max_load_factor = " << max_load_factor;
   out << ", size = " << truesize;
   out << ", capacity = " << table. size( ) << " ):\n";

   for( size_t pos = 0; pos != table. size( ); ++ pos )
   {
      if( !table[ pos ]. isempty( ))
         out << pos << " :    " << table[ pos ] << "\n";
   }
}

void map::checkinvariants( ) const
{
   if( table. size( ) < 3 )
      throw std::logic_error( "table size too small" );
 
   size_t i = 0;
   for( const auto& t : table )
   {
      if( !t. isempty( ))
         ++ i;
   }

   if( i != truesize )
   {
      std::cout << i << " / truesize = " << truesize << "\n"; 
      throw std::logic_error( "variable truesize does not hold the true size" );
   }

   if( i > table. size( ) * max_load_factor )
      throw std::logic_error( "load factor > max_load_factor" ); 

   for( size_t pos = 0; pos != table. size( ); ++ pos )
   {
      if( !table[ pos ]. isempty( )) 
      {
         size_t p = exactposition( table[ pos ]. key );
         size_t d = 0;
            // p is the true position where table[ pos ] should be.
 
         while( p != pos )
         {
            if( table[p]. isempty( ))
            {
               std::cout << "cell " << pos << " should have been at " << p << "\n";
               throw std::logic_error( "there is an empty cell" ); 
            }

            if( d > table[p]. dist )
            {
               std::cout << "cell " << pos << " should have been at " << p << "\n";
               throw std::logic_error( "its displacement is bigger" ); 
            }

            p = wrap( p + 1 );
            ++ d; 
         }

         if( table[ pos ]. dist != d )
         {
            std::cout << pos << " : " << table[ pos ];
            std::cout << " has wrong dist field\n";
            std::cout << exactposition( table[ pos ]. key ) << "\n";
            throw std::runtime_error( "distance is wrong" );
         }

      }
   }
}


#include "map.h"

// Should be copied from assignment 3: 

int case_insensitive_cmp::operator( ) 
      ( const std::string& s1, const std::string& s2 ) const{
    size_t minlen = s1.length() < s2.length() ? s1.length() : s2.length();

    for(size_t i = 0; i < minlen; i++){
        int diff = std::tolower(s1[i]) - std::tolower(s2[i]);
        if(diff != 0) return diff;
    }

    return s1.length() - s2.length();
}


// must be written:

size_t case_insensitive_hash::operator( ) ( const std::string& s ) const{
   // for(char c : s){
   //    tolower(c);
   // }
   // return 0;
    size_t h = 0;
    for (unsigned char c : s)
        h = h * 131u + std::tolower(c);
    return h;
}

size_t map::wrap( size_t pos ) const{
    if(pos >= table.size()) pos -= table.size();
    return pos;
}

size_t map::exactposition( const keytype& key ) const{
    keyhash hash;
    return hash(key) % table.size();
}

size_t map::minpow3( size_t sz ){
    size_t p = 3;
    while(p < sz) p *= 3;
    return p;
}

// size_t map::find( const keytype& key, size_t pos ) const{
//    keycmp cmp;
//    size_t d = 0;

//    while(d < table.size()){
//       size_t cur_pos = wrap(pos + d);

//       if(!table[cur_pos].isempty() && cmp(table[cur_pos].key, key) == 0) return d;
//       if(table[cur_pos].isempty() || table[cur_pos].dist < d) return d;

//       d++;
//    }

//    return d;
// }
size_t map::find( const keytype& key, size_t pos ) const{
    keycmp cmp;
    size_t dist = 0;

    while(1){
        size_t cur_pos = wrap(pos + dist);

        if(table[cur_pos].isempty()) return dist;
        if(table[cur_pos].dist < dist) return dist;
        if(cmp(table[cur_pos].key, key) == 0) return dist;

        dist++;
    }
}

void map::insert_shift_up( size_t pos, cell& c ){
    while(!c.isempty()){
        if(table[pos].isempty()){
            table[pos] = std::move(c);
            c.clear();
        } else if(table[pos].dist < c.dist) std::swap(table[pos], c);

        if(!c.isempty()){
            pos = wrap(pos + 1);
            c.dist++;
            if(c.dist >= table.size()) throw std::logic_error("logic error");
        }
    }
}

bool map::contains( const keytype& key ) const{
    size_t pos = exactposition(key);
    size_t dist = find(key, pos);
    pos = wrap(pos + dist);
    return !table[pos].isempty() && table[pos].dist == dist && keycmp()(table[pos].key, key) == 0;
    // return !table[pos].isempty() && table[pos].dist == dist;
}

bool map::insert( const keytype& key, const valtype& val ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   if(!table[pos].isempty() && table[pos].dist == dist) return 0;
   // if(!table[pos].isempty() && table[pos].dist == dist && keycmp()(table[pos].key, key) == 0) return 0;;

   if(rehash_needed(truesize + 1)){
      rehash(truesize + 1);
      pos = exactposition(key);
      dist = find(key, pos);
      pos = wrap(pos + dist);
   }

   cell с(key, val, dist);
   insert_shift_up(pos, с);
   truesize++;

   return 1;
}

void map::rehash( size_t sz ){
   size_t new_sz = minpow3(sz / max_load_factor);
   map new_map(max_load_factor, new_sz);
   for(const auto& c : table) if(!c.isempty()) new_map.insert(c.key, c.val);
   *this = std::move(new_map);
}

const map::valtype& map::at( const keytype& key ) const{
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   if(!table[pos].isempty() && table[pos].dist == dist) return table[pos].val;

   throw std::out_of_range("key is not present");
}

map::valtype& map::at( const keytype& key ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   if(!table[pos].isempty() && table[pos].dist == dist) return table[pos].val;

   throw std::out_of_range("key is not present");
}

map::valtype& map::operator[] ( const keytype& key ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);

   if(table[pos].isempty() || table[pos].dist != dist || keycmp()(table[pos].key, key) != 0){
      insert(key, valtype());
      pos = exactposition(key);
      dist = find(key, pos);
      pos = wrap(pos + dist);
   }

   return table[pos].val;
   // if(!contains(key)) insert(key, valtype{});
   // return at(key);
}

bool map::erase( const keytype& key ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   // if(!table[pos].isempty() && table[pos].dist == dist) return 0;
   if(table[pos].isempty() || table[pos].dist != dist) return 0;

   table[pos].clear();
   truesize--;

   size_t pos2 = wrap(pos + 1);

   while(!table[pos2].isempty() && table[pos2].dist != 0){
      table[pos] = std::move(table[pos2]);
      table[pos].dist--;
      pos = pos2;
      pos2 = wrap(pos2 + 1);
   }

   table[pos].clear();//??

   return 1;
}

void map::clear( ){
   for(auto& c : table) c.clear();
   truesize = 0;
}

void map::cell::print( std::ostream& out ) const
{
   if( isempty( ))
      out << "(empty)";
   else
      out << key << "/" << val << "      (" << dist << ")";
}

double map::average_dist( ) const
{
   // Contrary to our principles:

   if( truesize == 0 )
      return 0.0;

   double sum = 0.0;
   for( const auto& c : table )
   { 
      if( !c. isempty( ))
         sum += c. dist;
   }

   return sum / truesize;
}

double map::standarddev() const
{
   if( truesize == 0 )
      return 0.0;

   double sum = 0.0;
   double av = average_dist();

   for( const auto& c : table )
   {
      if( !c. isempty( ))
      {
         double dif = c. dist - av;
         sum += dif*dif;
      }
   }

   return sqrt( sum / truesize );
}

void map::print( std::ostream& out ) const
{
   out << "hashmap( max_load_factor = " << max_load_factor;
   out << ", size = " << truesize;
   out << ", capacity = " << table. size( ) << " ):\n";

   for( size_t pos = 0; pos != table. size( ); ++ pos )
   {
      if( !table[ pos ]. isempty( ))
         out << pos << " :    " << table[ pos ] << "\n";
   }
}

void map::checkinvariants( ) const
{
   if( table. size( ) < 3 )
      throw std::logic_error( "table size too small" );
 
   size_t i = 0;
   for( const auto& t : table )
   {
      if( !t. isempty( ))
         ++ i;
   }

   if( i != truesize )
   {
      std::cout << i << " / truesize = " << truesize << "\n"; 
      throw std::logic_error( "variable truesize does not hold the true size" );
   }

   if( i > table. size( ) * max_load_factor )
      throw std::logic_error( "load factor > max_load_factor" ); 

   for( size_t pos = 0; pos != table. size( ); ++ pos )
   {
      if( !table[ pos ]. isempty( )) 
      {
         size_t p = exactposition( table[ pos ]. key );
         size_t d = 0;
            // p is the true position where table[ pos ] should be.
 
         while( p != pos )
         {
            if( table[p]. isempty( ))
            {
               std::cout << "cell " << pos << " should have been at " << p << "\n";
               throw std::logic_error( "there is an empty cell" ); 
            }

            if( d > table[p]. dist )
            {
               std::cout << "cell " << pos << " should have been at " << p << "\n";
               throw std::logic_error( "its displacement is bigger" ); 
            }

            p = wrap( p + 1 );
            ++ d; 
         }

         if( table[ pos ]. dist != d )
         {
            std::cout << pos << " : " << table[ pos ];
            std::cout << " has wrong dist field\n";
            std::cout << exactposition( table[ pos ]. key ) << "\n";
            throw std::runtime_error( "distance is wrong" );
         }

      }
   }
}


#include "map.h"

// Should be copied from assignment 3: 

int case_insensitive_cmp::operator( ) 
      ( const std::string& s1, const std::string& s2 ) const{
    size_t minlen = s1.length() < s2.length() ? s1.length() : s2.length();

    for(size_t i = 0; i < minlen; i++){
        int diff = std::tolower(s1[i]) - std::tolower(s2[i]);
        if(diff != 0) return diff;
    }

    return s1.length() - s2.length();
}


// must be written:

size_t case_insensitive_hash::operator( ) ( const std::string& s ) const{
   // for(char c : s){
   //    tolower(c);
   // }
   // return 0;
    size_t h = 0;
    for (unsigned char c : s)
        h = h * 131u + std::tolower(c);
    return h;
}

size_t map::wrap( size_t pos ) const{
    if(pos >= table.size()) pos -= table.size();
    return pos;
}

size_t map::exactposition( const keytype& key ) const{
    keyhash hash;
    return hash(key) % table.size();
}

size_t map::minpow3( size_t sz ){
    size_t p = 3;
    while(p < sz) p *= 3;
    return p;
}

// size_t map::find( const keytype& key, size_t pos ) const{
//    keycmp cmp;
//    size_t d = 0;

//    while(d < table.size()){
//       size_t cur_pos = wrap(pos + d);

//       if(!table[cur_pos].isempty() && cmp(table[cur_pos].key, key) == 0) return d;
//       if(table[cur_pos].isempty() || table[cur_pos].dist < d) return d;

//       d++;
//    }

//    return d;
// }
size_t map::find( const keytype& key, size_t pos ) const{
    keycmp cmp;
    size_t dist = 0;

    while(1){
        size_t cur_pos = wrap(pos + dist);

        if(table[cur_pos].isempty()) return dist;
        if(table[cur_pos].dist < dist) return dist;
        if(cmp(table[cur_pos].key, key) == 0) return dist;

        dist++;
    }
}

void map::insert_shift_up( size_t pos, cell& c ){
    while(!c.isempty()){
        if(table[pos].isempty()){
            table[pos] = std::move(c);
            c.clear();
        } else if(table[pos].dist < c.dist) std::swap(table[pos], c);

        if(!c.isempty()){
            pos = wrap(pos + 1);
            c.dist++;
            if(c.dist >= table.size()) throw std::logic_error("logic error");
        }
    }
}

bool map::contains( const keytype& key ) const{
    size_t pos = exactposition(key);
    size_t dist = find(key, pos);
    pos = wrap(pos + dist);
    return !table[pos].isempty() && table[pos].dist == dist;
    // return !table[pos].isempty() && table[pos].dist == dist;
}

bool map::insert( const keytype& key, const valtype& val ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   if(!table[pos].isempty() && table[pos].dist == dist) return 0;
   // if(!table[pos].isempty() && table[pos].dist == dist && keycmp()(table[pos].key, key) == 0) return 0;;

   if(rehash_needed(truesize + 1)){
      rehash(truesize + 1);
      pos = exactposition(key);
      dist = find(key, pos);
      pos = wrap(pos + dist);
   }

   cell с(key, val, dist);
   insert_shift_up(pos, с);
   truesize++;

   return 1;
}

void map::rehash( size_t sz ){
   size_t new_sz = minpow3(sz / max_load_factor);
   map new_map(max_load_factor, new_sz);
   for(const auto& c : table) if(!c.isempty()) new_map.insert(c.key, c.val);
   *this = std::move(new_map);
}

const map::valtype& map::at( const keytype& key ) const{
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   if(!table[pos].isempty() && table[pos].dist == dist) return table[pos].val;

   throw std::out_of_range("key is not present");
}

map::valtype& map::at( const keytype& key ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   if(!table[pos].isempty() && table[pos].dist == dist) return table[pos].val;

   throw std::out_of_range("key is not present");
}

map::valtype& map::operator[] ( const keytype& key ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);

   if(table[pos].isempty() || table[pos].dist != dist){
      insert(key, valtype());
      pos = exactposition(key);
      dist = find(key, pos);
      pos = wrap(pos + dist);
   }

   return table[pos].val;
   // if(!contains(key)) insert(key, valtype{});
   // return at(key);
}

bool map::erase( const keytype& key ){
   size_t pos = exactposition(key);
   size_t dist = find(key, pos);
   pos = wrap(pos + dist);
   // if(!table[pos].isempty() && table[pos].dist == dist) return 0;
   if(table[pos].isempty() || table[pos].dist != dist) return 0;

   table[pos].clear();
   truesize--;

   size_t pos2 = wrap(pos + 1);

   while(!table[pos2].isempty() && table[pos2].dist != 0){
      table[pos] = std::move(table[pos2]);
      table[pos].dist--;
      pos = pos2;
      pos2 = wrap(pos2 + 1);
   }

   table[pos].clear();//??

   return 1;
}

void map::clear( ){
   for(auto& c : table) c.clear();
   truesize = 0;
}

void map::cell::print( std::ostream& out ) const
{
   if( isempty( ))
      out << "(empty)";
   else
      out << key << "/" << val << "      (" << dist << ")";
}

double map::average_dist( ) const
{
   // Contrary to our principles:

   if( truesize == 0 )
      return 0.0;

   double sum = 0.0;
   for( const auto& c : table )
   { 
      if( !c. isempty( ))
         sum += c. dist;
   }

   return sum / truesize;
}

double map::standarddev() const
{
   if( truesize == 0 )
      return 0.0;

   double sum = 0.0;
   double av = average_dist();

   for( const auto& c : table )
   {
      if( !c. isempty( ))
      {
         double dif = c. dist - av;
         sum += dif*dif;
      }
   }

   return sqrt( sum / truesize );
}

void map::print( std::ostream& out ) const
{
   out << "hashmap( max_load_factor = " << max_load_factor;
   out << ", size = " << truesize;
   out << ", capacity = " << table. size( ) << " ):\n";

   for( size_t pos = 0; pos != table. size( ); ++ pos )
   {
      if( !table[ pos ]. isempty( ))
         out << pos << " :    " << table[ pos ] << "\n";
   }
}

void map::checkinvariants( ) const
{
   if( table. size( ) < 3 )
      throw std::logic_error( "table size too small" );
 
   size_t i = 0;
   for( const auto& t : table )
   {
      if( !t. isempty( ))
         ++ i;
   }

   if( i != truesize )
   {
      std::cout << i << " / truesize = " << truesize << "\n"; 
      throw std::logic_error( "variable truesize does not hold the true size" );
   }

   if( i > table. size( ) * max_load_factor )
      throw std::logic_error( "load factor > max_load_factor" ); 

   for( size_t pos = 0; pos != table. size( ); ++ pos )
   {
      if( !table[ pos ]. isempty( )) 
      {
         size_t p = exactposition( table[ pos ]. key );
         size_t d = 0;
            // p is the true position where table[ pos ] should be.
 
         while( p != pos )
         {
            if( table[p]. isempty( ))
            {
               std::cout << "cell " << pos << " should have been at " << p << "\n";
               throw std::logic_error( "there is an empty cell" ); 
            }

            if( d > table[p]. dist )
            {
               std::cout << "cell " << pos << " should have been at " << p << "\n";
               throw std::logic_error( "its displacement is bigger" ); 
            }

            p = wrap( p + 1 );
            ++ d; 
         }

         if( table[ pos ]. dist != d )
         {
            std::cout << pos << " : " << table[ pos ];
            std::cout << " has wrong dist field\n";
            std::cout << exactposition( table[ pos ]. key ) << "\n";
            throw std::runtime_error( "distance is wrong" );
         }

      }
   }
}
