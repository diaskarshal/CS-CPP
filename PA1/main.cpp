
#include "vector.h"

int main( int argc, char* argv[] ){

#if 1
   // csci152::vector vect = { 0,1,2};
   // std::cout << "vect : " << vect << " size = " << vect.size() << " cap = " << vect.capacity() << "\n"; 
   // csci152::vector vect1 = vect;
   // csci152::vector vect2 = vect1;
   // csci152::vector vect3 = { 55, 44};
   // vect1 = vect3;
   // std::cout << "vect1 : " << vect1 << " size = " << vect1.size() << " cap = " << vect1.capacity() << "\n"; 
   // std::cout << "vect2 : " << vect2 << " size = " << vect2.size() << " cap = " << vect2.capacity() << "\n"; 
   // std::cout << "vect3 : " << vect3 << " size = " << vect3.size() << " cap = " << vect3.capacity() << "\n"; 

   // for( double d = 6; d < 10; ++ d ){
   //    try{
   //       vect. insert( 2, d );
   //    }catch(const std::out_of_range& err){
   //       std::cout << err.what() << "\n";
   //       return 0;
   //    }
   // }
   // std::cout << "vect : " << vect << " size = " << vect.size() << " cap = " << vect.capacity() << "\n"; 

   // // for( double d = 6; d < 10; ++ d )
   // //    vect. erase(4);
   // // std::cout << "vect : " << vect << " size = " << vect.size() << " cap = " << vect.capacity() << "\n"; 

   // vect.pop_back();
   // vect.pop_back();
   // vect.pop_back();
   
   // vect.shrink();
   // std::cout << "vect : " << vect << " size = " << vect.size() << " cap = " << vect.capacity() << "\n"; 
   csci152::vector vect2 = {100};

   vect2.push_back(50);
   vect2.push_back(200);

   std::cout << "vect2 : " << vect2 << " size = " << vect2.size() << " cap = " << vect2.capacity() << "\n";

   // std::cout << "vect[0] = " << vect[0] << vect.at(0) << vect.front() << "\n";
   // std::cout << "vect[0] = " << vect[vect.size() - 1] << vect.at(vect.size() - 1) << vect.back() << "\n";
   vect2.reserve(44);

   std::cout << "vect2 : " << vect2 << " size = " << vect2.size() << " cap = " << vect2.capacity() << "\n";

   vect2.shrink();
   std::cout << "vect2 : " << vect2 << " size = " << vect2.size() << " cap = " << vect2.capacity() << "\n";

   // std::cout << "vect2 after vect2 = vect : " << vect << "\n";

   // vect = vect;
   // // ??? vect[3] = vect[-100] + 99;
   // std::cout << "vect after vect = vect : " << vect << "\n";

   // std::cout << "vect: " << vect << "\n";
   // std::cout << "vect2: " << vect2 << "\n";

   // vect3 = vect2;

   // std::cout << "vect3 after vect3 = vect2 : " << vect3 << "\n";

   // std::cout << "vect : " << vect << "\n";
   // std::cout << "vect2 : " << vect2 << "\n";
   // std::cout << "vect3 : " << vect3 << "\n";

   // while( vect. size( ) > 5 )
   //    vect. erase(3);
   // std::cout << vect << "\n";

   return 0;

#else
   csci152::vector vect = { "fremd", "bin", "ich", "eingezogen" };

   vect.reserve(50);
   std::cout << "size = " << vect.size() << " size = " << vect. capacity( ) << "\n";

   // vect. push_back( "fremd" );
   // vect. push_back( "ich" );
   // vect. push_back( "wieder" );

   // std::cout << vect << "\n";
   // std::cout << vect. capacity( ) << "\n";

   // vect. insert( 5, "zieh" );
   // std::cout << vect. capacity( ) << "\n";

   // vect. erase(4);
   // std::cout << vect. capacity( ) << "\n";

   // vect. push_back( "aus" );
   // std::cout << vect. capacity( ) << "\n";

   // std::cout << vect << "\n";
   // vect. pop_back();
   // std::cout << vect.size() << " " << vect. capacity( ) << "\n";

   // std::cout << vect << "\n";

   // vect.erase(0);
   // vect.erase(0);
   // vect.erase(0);
   // vect.erase(0);
   // vect.erase(0);
   vect.shrink();
   std::cout << "size = " << vect.size() << " size = " << vect. capacity( ) << "\n";
   // std::cout << vect.size() << " " << vect. capacity( ) << "\n";

   // std::cout << vect << "\n";
   
   // try{
   //    std::cout << vect.at(-1) << "\n";
   // }catch(const std::out_of_range& err){
   //    std::cout<<"ouch";
   // }
   // csci152::vector v;
   // std::cout << v[0];
   // std::cout << v.at(0);

   // try{
   //  csci152::vector v;
   //  std::cout << v.at(0);
   // }catch (const std::out_of_range& e){
   //    std::cerr << e.what() << std::endl;
   // }

      return 0;

#endif

   return 0;
}