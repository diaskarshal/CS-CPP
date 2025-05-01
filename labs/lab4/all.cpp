
#include <iostream>

#include "date.h"

int main( int argc, char* argv [ ] )
{
   /* 2 */
   // date d1 = date( 2001, 2, 29 );
   std::cout << date::ispossible( 2001, 2, 29 ) << "\n";
   std::cout << date::ispossible( 2000, 2, 29 ) << "\n";
   std::cout << date::ispossible( 2024, 4, 31 ) << "\n";

   std::cout << date::ispossible( 2048, 10, 31 ) << "\n";
   std::cout << date::ispossible( 0, 2, 29 ) << "\n";
   std::cout << date::ispossible( -3, 2, 29 ) << "\n";
   std::cout << date::ispossible( 1, 2, 29 ) << "\n";
   
   /* 3 */
   auto d = date( 1991, 12, 16 );
   d. print_euro( std::cout ); std::cout << '\n';
   d. print_usa( std::cout ); std::cout << '\n';

   std::cout << (date( 1995, 3, 8 ) == date( 1995, 3, 8 )) << " " << (date( 1995, 3, 8 ) <= date( 1995, 3, 9 )) << " " << (date( 1995, 3, 8 ) <= date( 1995, 3, 7 )) << "\n";
   d = date(0, 1, 1);
   d.print_euro(std::cout); std::cout << "\n";

   /* 4 */
   date d1 = date( 1995, 3, 8 );
   date d2 = date( 1995, 3, 8 );
   std::cout << (d1 == d2) << " " << (d1 <= d2) << " " << (d2 <= d1) << "\n";
   // // Must print 1 1 1

   d1 = date( 2000, 5, 12 );
   d2 = date( 2000, 3, 7 );
   std::cout << (d1 == d2) << " " << (d1 <= d2) << " " << (d2 <= d1) << "\n";
   // // Must print 0 0 1

   d1 = date( 1991, 3, 8 );
   d2 = date( 1990, 5, 12 );
   std::cout << (d1 == d2) << " " << (d1 <= d2) << " " << (d2 <= d1) << "\n";
   // // Must print 0 0 1

   /* 5 */
   std::cout << "\n";
   std::cout << ( d1 == d2 ) << " " << ( d1 != d2 ) << "\n";
   std::cout << ( d1 < d2 ) << " " << ( d1 > d2 ) << "\n";
   std::cout << "\n";

   /* 7 */
   std::cout << date( 2024,12,31 ). days1jan( ) << "\n";
   std::cout << date( 2024,1,1 ). days1jan( ) << "\n";
   std::cout << date( 2021,3,8 ). days1jan( ) << "\n";
   std::cout << "\n";

   /* 8 */
   for( unsigned int i = 0; i < 365; ++ i )
   {
      date d1 = { 1992, 1, 1 };
      date d2 = d1; 
      d2. setdays1jan(i);
      if( d2. days1jan( ) != i )
         throw std::logic_error( "something went wrong with day counting" );
   }

   /* 9 */
   unsigned int totaldays = 0;
   for( unsigned int i = 0; i < 10000; ++ i )
   {
      totaldays += date::daysinyear(i);
   }
   std::cout << "average length of year = " << totaldays / 10000.0 << '\n';
   // Astronomically correct is 365.2422 

   std::cout << "\n\n";

   std::cout << "Astana has been called Nursultan for ";
   std::cout << date( 2022, 9, 17 ) - date( 2019, 3, 23 ) << " days\n";

   std::cout << "The DDR has existed for ";
   std::cout << date( 1990, 10, 3 ) - date( 1949, 10, 7 ) << " days\n";

   // Turn this on for thorough testing: 

   if constexpr( true )
   {
      date startdate = { 1991, 12, 16 };
      for( int i1 = -1000; i1 != 1000; ++ i1 )
      {
         for( int i2 = -1000; i2 != 1000; ++ i2 ) 
         {
            auto d1 = startdate + i1;
            auto d2 = startdate + i2;
        
            if( d1 - startdate != i1 || startdate - d1 != -i1 )
               throw std::logic_error( "problem with d1" );
            if( d2 - startdate != i2 || startdate - d2 != -i2 )
               throw std::logic_error( "problem with d2" );
            if( d2 - d1 != i2 - i1 )
               throw std::logic_error( "difference is wrong" );
         } 
      }
   }

   std::cout << date( 1900, 1, 1 ). getweekday( ) << "\n";
      // Monday. 
   std::cout << date( 2025, 2, 26 ). getweekday( ) << "\n";
      // date of Quiz 2, Wednesday. 
   std::cout << date( 1959, 2, 3 ). getweekday( ) << "\n";
      // the day the music died, Tuesday. 

   std::cout << date( 1969, 7, 20 ). getweekday( ) << "\n";
      // First moon landing, Sunday. 
   std::cout << date( 1991, 12, 16 ). getweekday( ) << "\n";
      // Independence of Kazakhstan, Monday. 
   std::cout << date( 1961, 4, 12 ). getweekday( ) << "\n\n";
      // Space flight of Yuri Gagarin, Wednesday. 
   std::cout << date( 1, 1, 1 ). getweekday( ) << "\n";

   std::cout << date( 1, 1, 1 ) - 1 << "\n";

   return 0;
}


#include "date.h"

bool date::isleapyear( unsigned int y ){
   return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
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

bool date::ispossible( unsigned int year, unsigned int month, unsigned int day ){
   if(year >= 0 && isleapyear(year))
      return (month >= 1 && month <= 12) && (day >= 1 && day <= leapyear[month]);
   else if(year >= 0 && !isleapyear(year))
      return (month >= 1 && month <= 12) && (day >= 1 && day <= normalyear[month]);
   else
      return false;
}

void date::print_usa( std::ostream& out ) const{
   out << monthnames[month] << " " << day << " " << year;
}

void date::print_euro( std::ostream& out ) const{
   out << day << " " << monthnames[month] << " " << year;
}

bool date::operator == ( date other ) const{
   return month == other.month && day == other.day && year == other.year;
}

bool date::operator <= ( date other ) const{
   return year < other.year || (year == other.year && month < other.month) || (year == other.year && month == other.month && day <= other.day);
}

unsigned int date::daysinyear( unsigned int y ){
   if(isleapyear(y)) return 366;
   else return 365;
}

unsigned int date::daysinmonth( unsigned int y, unsigned int m ){
   if(isleapyear(y)) return leapyear[m];
   else return normalyear[m];
}

unsigned int date::days1jan( ) const{
   unsigned int days = day - 1;

   for(unsigned int i = 1; i < month; i++)
      days += daysinmonth(year, i);

   return days;
}

void date::setdays1jan( unsigned int nrdays ){
   unsigned int m = 1;
   
   while(m <= 12){
      unsigned int days = daysinmonth(year, m);
      if(nrdays < days){
         month = m;
         day = nrdays + 1;
         return;
      }
      else{
         nrdays -= days;
         m++;
      }
   }

}
 
date& date::operator += ( int diff ){
   diff += days1jan();
   
   while(diff < 0){
      year--;
      diff += daysinyear(year);
   }
   
   while(diff >= (int)daysinyear(year)){
      diff -= daysinyear(year);
      year++;
   }
   
   setdays1jan(diff);
   return * this;
}

int date::operator - ( const date& other ) const{
   int diff = days1jan() - other.days1jan();
   
   if(year > other.year){
      for(unsigned int y = other.year; y < year; y++)
         diff += daysinyear(y);
   }

   else if(year < other.year){
      for(unsigned int y = year; y < other.year; y++)
         diff -= daysinyear(y);
   }

   return diff;
}

namespace
{
   const char *weekdays[] =
      { "sunday", "monday", "tuesday", "wednesday",
        "thursday", "friday", "saturday" };
}

const char* date::getweekday( ) const{
   date start(2000, 1, 2);

   int diff = *this - start;
   int rmdr = diff % 7;

   if(rmdr < 0)
      rmdr += 7;

   return weekdays[rmdr];
}


#ifndef DATE_
#define DATE_

#include <iostream>
#include <stdexcept>

struct date
{
   unsigned int year;
   unsigned int month;
   unsigned int day;

   static bool isleapyear( unsigned int y );

   static bool 
   ispossible( unsigned int year, unsigned int month, unsigned int day ); 

   // We have to decide what to do, when 
   // the user is attempting to construct an ill-defined date.

   date( unsigned int year,
         unsigned int month,
         unsigned int day )
      : year( year ), month( month ), day( day )
   { 
#if 1
      if( !ispossible( year, month, day ))
         throw std::range_error( "tried to construct impossible date" ); 
#endif
   }

   void print_usa( std::ostream& out ) const;
   void print_euro( std::ostream& out ) const;

   static unsigned int daysinyear( unsigned int year );
   static unsigned int daysinmonth( unsigned int year, unsigned int month );

   unsigned int days1jan( ) const; 
      // Number of days since 1st of January in our year.

   void setdays1jan( unsigned int nrdays );
      // Set month and day to the nrdays-th day of our year.

   bool operator == ( date other ) const;
   bool operator <= ( date other ) const; 

   date& operator += ( int diff );
   int operator - ( const date& other ) const; 

   const char* getweekday( ) const; 

};

inline bool operator != ( const date& d1, const date& d2 ){
   return !(d1 == d2);
}

inline bool operator < ( const date& d1, const date& d2 ){
   return !(d2 <= d1);
}

inline bool operator > ( const date& d1, const date& d2 ){
   return !(d1 <= d2);
}

inline bool operator >= ( const date& d1, const date& d2 ){
   return d2 <= d1;
}

inline std::ostream& operator << ( std::ostream& out, const date& d ){
   d.print_usa(out);
   return out;
}

inline date& operator -= ( date& d, int x ) { return d += -x; }  
inline date operator + ( date d, int x ) { d += x; return d; }
inline date operator - ( date d, int x ) { d += -x; return d; }

#endif

