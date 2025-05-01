
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

