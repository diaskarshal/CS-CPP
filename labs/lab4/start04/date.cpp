
#include "date.h"

bool date::isleapyear( unsigned int y )
{
}

// This is called 'anonymous namespace'. It prevents that 
// the names are passed to the linker.
// All the tables start with an unused element, because we don't
// use 0 for counting months.

namespace
{
   // Tables start with an unused 0, because we start counting months at 1.

   const unsigned int normalyear[] = 
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   const unsigned int leapyear[] = 
      { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // Table starts with an empty string, because we start counting months at 1.

   const char* const monthnames[] = 
      { "", "january", "february", "march", "april",
        "may", "june", "july", "august", "september",
        "october", "november", "december" };
}

bool date::ispossible( unsigned int year, unsigned int month, unsigned int day )
{
}

void date::print_usa( std::ostream& out ) const
{
}

void date::print_euro( std::ostream& out ) const
{
}

bool date::operator == ( date other ) const
{
}

bool date::operator <= ( date other ) const
{
}

unsigned int date::daysinyear( unsigned int y )
{
}

unsigned int date::daysinmonth( unsigned int y, unsigned int m )
{
}

unsigned int date::days1jan( ) const
{
}

void date::setdays1jan( unsigned int nrdays ) 
{
}
 
date& date::operator += ( int diff )
{
}

int date::operator - ( const date& other ) const
{
}

namespace
{
   const char *weekdays[] =
      { "sunday", "monday", "tuesday", "wednesday",
        "thursday", "friday", "saturday" };
}

const char* date::getweekday( ) const
{
}

