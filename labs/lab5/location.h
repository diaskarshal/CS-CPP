
#ifndef LOCATION_
#define LOCATION_

// A location in the input. It is just a 
// line number and a column.

struct location
{
   unsigned int linenumber;
   unsigned int column;

   location( ) noexcept
      : linenumber(0),
        column(0)
   { }

   location( unsigned int linenumber, unsigned int column )
      : linenumber( linenumber ),
        column( column )
   { }

};

inline std::ostream& operator << ( std::ostream& out, location loc )
{
   out << ( loc. linenumber + 1 ) << "/" << ( loc. column + 1 ); 
      // Convert programmer's counting to laymans' counting. 
      // (Technically, they should be different types.) 
   return out;
}

#endif

