
// #include "map.h"

// int case_insensitive_cmp::operator( ) 
//       ( const std::string& s1, const std::string& s2 ) const{
//    size_t minlen = s1.length() < s2.length() ? s1.length() : s2.length();

//    for(size_t i = 0; i < minlen; i++){
//       int diff = std::tolower(s1[i]) - std::tolower(s2[i]);
//       if(diff != 0) return diff;
//    }

//    return s1.length() - s2.length();
// }

// const treenode* find( const treenode* n, const treenode::keytype& key ){
//    treenode::keycmp cmp;

//    while(n != nullptr){
//       int f = cmp(n->key, key);
//       if(f == 0) return n;
//       else if(f > 0) n = n->left;
//       else n = n->right;
//    }

//    return nullptr;
// }

// treenode** find( treenode** n, const treenode::keytype& key ){
//    treenode::keycmp cmp;

//    while(*n != nullptr){
//       int f = cmp((*n)->key, key);
//       if(f == 0) return n;
//       else if(f > 0) n = &((*n)->left);
//       else n = &((*n)->right);
//    }

//    return n;
// }

// size_t size( const treenode* n ){
//    if(n == nullptr) return 0;
//    return size(n->left) + size(n->right) + 1;
// }

// size_t height( const treenode* n ){
//    if(n == nullptr) return 0;
//    return (height(n->left) > height(n->right) ? height(n->left) : height(n->right)) + 1;
// }

// void deallocate( treenode* n ){
//    if(n == nullptr) return;
//    deallocate(n->left);
//    deallocate(n->right);
//    delete n;
// }

// treenode* makecopy( const treenode* n ){
//    if(n == nullptr) return nullptr;
//    treenode *copy = new treenode(n->key, n->val, makecopy(n->left), makecopy(n->right));
//    return copy;
// }


// // Step to the right as long as possible. When we get
// // stuck, we are in the rightmost node. Remove it, and
// // return it. (Don't delete it.)
// // *from cannot be the empty tree.

// treenode* extractrightmost( treenode** from )
// {
//    while( (*from) -> right )
//       from = & (*from) -> right;

//    treenode* n = *from;
//    *from = (*from) -> left;
//    return n;
// }

// void print( std::ostream& out, const treenode* n, unsigned int indent )
// {

//    for( unsigned int i = 0; i != indent; ++ i )
//       out << "|  "; 
//    if(n)
//    {
//       out << ( n -> key ) << " / " << ( n -> val ) << "\n";
//       print( out, n -> left, indent + 1 );
//       print( out, n -> right, indent + 1 ); 
//    }
//    else
//       out << "#\n"; 
// }


// // Both the upperbound and the lowerbound are strict.
// // We use pointers, so that they can be absent. 
// // Of course, this is a tasteless way of dealing with partiality.

// void checkbetween( const treenode* n, 
//                    const treenode::keytype* lowerbound, 
//                    const treenode::keytype* upperbound ) 
// {
//    treenode::keycmp cmp;

//    while(n) 
//    {
//       if( lowerbound && cmp( *lowerbound, n -> key ) >= 0 ) 
//       {
//          std::cout << "key " << ( n -> key );
//          std::cout << " is not above lower bound " << *lowerbound << "\n";
//          throw std::runtime_error( "tree not correct" ); 
//       }

//       if( upperbound && cmp( *upperbound, n -> key ) <= 0 ) 
//       {
//          std::cout << "key " << ( n -> key );
//          std::cout << "is not below upperbound " << *upperbound << "\n";
//          throw std::runtime_error( "tree not correct" );  
//       }

//       checkbetween( n -> left, lowerbound, &( n -> key ));
//       lowerbound = & ( n -> key );
//       n = n -> right;
//    }
// } 


// unsigned int log_base2( size_t s ){
//    unsigned int c = 0;

//    while(s > 1){
//       s /= 2;
//       c++;
//    }

//    return c;
// }
 
// bool map::insert( const keytype& key, const valtype& val ){
//    treenode** loc = ::find(&tr, key);
//    if(*loc != nullptr) return false;
//    *loc = new treenode(key, val);
//    return true;
// }

// bool map::contains( const keytype& key ) const{
//    return ::find(tr, key) != nullptr;
// }

// map::valtype& map::at( const keytype& key ){
//    treenode** loc = ::find(&tr, key); 
//    if(*loc == nullptr) throw std::out_of_range("not found");
//    return (*loc)->val;
// }

// const map::valtype& map::at( const keytype& key ) const{
//    const treenode* node = ::find(tr, key); 
//    if(node == nullptr) throw std::out_of_range("not found");
//    return node->val;
// }

// map::valtype& map::operator [] ( const keytype& key ){
//    treenode** loc = ::find(&tr, key); 
//    if(*loc == nullptr) *loc = new treenode(key, valtype());
//    return (*loc)->val;
// }

// bool map::erase( const keytype& key ){
//    treenode** loc = ::find(&tr, key);
//    if(*loc == nullptr) return false;
   
//    treenode* del = *loc;
//    if(del->left == nullptr){
//       *loc = del->right;
//       delete del;
//       return true;
//    } else if(del->right == nullptr){
//       *loc = del->left;
//       delete del;
//       return true;
//    } else{
//       treenode* rightmost = ::extractrightmost(&(del->left));
//       del->key = rightmost->key;
//       del->val = rightmost->val;
//       delete rightmost;
//       return true;
//    }
// }

// size_t map::size( ) const{
//    return ::size(tr);
// }

// size_t map::height( ) const{
//    return ::height(tr);
// }

// bool map::empty( ) const{
//    return tr == nullptr;
// }

// map:: ~map( ){
//    ::deallocate(tr);
// }

// void map::clear( ){
//    ::deallocate(tr);
//    tr = nullptr;
// }

// map::map( const map& other ){
//    tr = ::makecopy(other.tr); 
// }

// map::map( map&& other ) : tr(other.tr){
//    other.tr = nullptr;
// }

// map& map::operator = ( const map& other ){
//    if(this == &other) return *this;
//    ::deallocate(tr);
//    tr = ::makecopy(other.tr);
//    return *this; 
// }

// map& map::operator = ( map&& other ){
//    ::deallocate(tr);
//    tr = other.tr;
//    other.tr = nullptr;
//    return *this;
// }

// void map::checksorted( ) const
// {
//    ::checkbetween( tr, nullptr, nullptr );
// }

// void map::print( std::ostream& out, unsigned int indent ) const
// {
//    ::print( out, tr, indent );
// }


#include "map.h"

int case_insensitive_cmp::operator( ) 
      ( const std::string& s1, const std::string& s2 ) const{
   size_t minlen = s1.length() < s2.length() ? s1.length() : s2.length();

   for(size_t i = 0; i < minlen; i++){
      int diff = std::tolower(s1[i]) - std::tolower(s2[i]);
      if(diff != 0) return diff;
   }

   return s1.length() - s2.length();
}

const treenode* find( const treenode* n, const treenode::keytype& key ){
   treenode::keycmp cmp;

   while(n != nullptr){
      int f = cmp(n->key, key);
      if(f == 0) return n;
      else if(f > 0) n = n->left;
      else n = n->right;
   }

   return nullptr;
}

treenode** find( treenode** n, const treenode::keytype& key ){
   treenode::keycmp cmp;

   while(*n != nullptr){
      int f = cmp((*n)->key, key);
      if(f == 0) return n;
      else if(f > 0) n = &((*n)->left);
      else n = &((*n)->right);
   }

   return n;
}

size_t size( const treenode* n ){
   if(n == nullptr) return 0;
   return size(n->left) + size(n->right) + 1;
}

size_t height( const treenode* n ){
   if(n == nullptr) return 0;
   return (height(n->left) > height(n->right) ? height(n->left) : height(n->right)) + 1;
}

void deallocate( treenode* n ){
   if(n == nullptr) return;
   deallocate(n->left);
   deallocate(n->right);
   delete n;
}

treenode* makecopy( const treenode* n ){
   if(n == nullptr) return nullptr;
   treenode *copy = new treenode(n->key, n->val, makecopy(n->left), makecopy(n->right));
   return copy;
}


// Step to the right as long as possible. When we get
// stuck, we are in the rightmost node. Remove it, and
// return it. (Don't delete it.)
// *from cannot be the empty tree.

treenode* extractrightmost( treenode** from )
{
   while( (*from) -> right )
      from = & (*from) -> right;

   treenode* n = *from;
   *from = (*from) -> left;
   return n;
}

void print( std::ostream& out, const treenode* n, unsigned int indent )
{

   for( unsigned int i = 0; i != indent; ++ i )
      out << "|  "; 
   if(n)
   {
      out << ( n -> key ) << " / " << ( n -> val ) << "\n";
      print( out, n -> left, indent + 1 );
      print( out, n -> right, indent + 1 ); 
   }
   else
      out << "#\n"; 
}


// Both the upperbound and the lowerbound are strict.
// We use pointers, so that they can be absent. 
// Of course, this is a tasteless way of dealing with partiality.

void checkbetween( const treenode* n, 
                   const treenode::keytype* lowerbound, 
                   const treenode::keytype* upperbound ) 
{
   treenode::keycmp cmp;

   while(n) 
   {
      if( lowerbound && cmp( *lowerbound, n -> key ) >= 0 ) 
      {
         std::cout << "key " << ( n -> key );
         std::cout << " is not above lower bound " << *lowerbound << "\n";
         throw std::runtime_error( "tree not correct" ); 
      }

      if( upperbound && cmp( *upperbound, n -> key ) <= 0 ) 
      {
         std::cout << "key " << ( n -> key );
         std::cout << "is not below upperbound " << *upperbound << "\n";
         throw std::runtime_error( "tree not correct" );  
      }

      checkbetween( n -> left, lowerbound, &( n -> key ));
      lowerbound = & ( n -> key );
      n = n -> right;
   }
} 


unsigned int log_base2( size_t s ){
   unsigned int c = 0;

   while(s > 1){
      s /= 2;
      c++;
   }

   return c;
}
 
bool map::insert( const keytype& key, const valtype& val ){
   treenode** loc = ::find(&tr, key);
   if(*loc != nullptr) return false;
   *loc = new treenode(key, val);
   return true;
}

bool map::contains( const keytype& key ) const{
   return ::find(tr, key) != nullptr;
}

map::valtype& map::at( const keytype& key ){
   treenode** loc = ::find(&tr, key); 
   if(*loc == nullptr) throw std::out_of_range("not found");
   return (*loc)->val;
}

const map::valtype& map::at( const keytype& key ) const{
   const treenode* node = ::find(tr, key); 
   if(node == nullptr) throw std::out_of_range("not found");
   return node->val;
}

map::valtype& map::operator [] ( const keytype& key ){
   treenode** loc = ::find(&tr, key); 
   if(*loc == nullptr) *loc = new treenode(key, valtype());
   return (*loc)->val;
}

bool map::erase( const keytype& key ){
   treenode** loc = ::find(&tr, key);
   if(*loc == nullptr) return false;
   
   treenode* del = *loc;
   if(del->left == nullptr){
      *loc = del->right;
      delete del;
      return true;
   } else if(del->right == nullptr){
      *loc = del->left;
      delete del;
      return true;
   } else{
      treenode* rightmost = ::extractrightmost(&(del->left));
      del->key = rightmost->key;
      del->val = rightmost->val;
      delete rightmost;
      return true;
   }
}

size_t map::size( ) const{
   return ::size(tr);
}

size_t map::height( ) const{
   return ::height(tr);
}

bool map::empty( ) const{
   return tr == nullptr;
}

map:: ~map( ){
   ::deallocate(tr);
}

void map::clear( ){
   ::deallocate(tr);
   tr = nullptr;
}

map::map( const map& other ){
   tr = ::makecopy(other.tr); 
}

map::map( map&& other ) : tr(other.tr){
   other.tr = nullptr;
}

map& map::operator = ( const map& other ){
   if(this == &other) return *this;
   ::deallocate(tr);
   tr = ::makecopy(other.tr);
   return *this; 
}

map& map::operator = ( map&& other ){
   ::deallocate(tr);
   tr = other.tr;
   other.tr = nullptr;
   return *this;
}

void map::checksorted( ) const
{
   ::checkbetween( tr, nullptr, nullptr );
}

void map::print( std::ostream& out, unsigned int indent ) const
{
   ::print( out, tr, indent );
}

