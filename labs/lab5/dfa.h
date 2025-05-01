
// This code was generated automatically.
// Generator written by Hans de Nivelle and Dina Muktubayeva.

namespace
{
   template< typename S >
   std::pair< symtype, size_t > readandclassify( int triv, S& inp )
   {
      auto latest = std::make_pair< symtype, size_t > ( sym_garbage, 0 );
      if( !inp. has(1))
         return latest;
      char c = inp. peek(0);
      size_t i = 0;

   Q00:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 13:
      case 32:
         ++ i; goto Q01;
      case 33:
         ++ i; goto Q02;
      case 35:
         ++ i; goto Q03;
      case 37:
         ++ i; goto Q04;
      case 40:
         ++ i; goto Q05;
      case 41:
         ++ i; goto Q06;
      case 42:
         ++ i; goto Q07;
      case 43:
         ++ i; goto Q08;
      case 44:
         ++ i; goto Q09;
      case 45:
         ++ i; goto Q10;
      case 47:
         ++ i; goto Q11;
      case 48:
         ++ i; goto Q12;
      case 59:
         ++ i; goto Q14;
      case 95:
      case 98:
      case 114:
      case 117:
         ++ i; goto Q15;
      case 94:
         ++ i; goto Q16;
      case 97:
         ++ i; goto Q17;
      case 99:
         ++ i; goto Q18;
      case 100:
         ++ i; goto Q19;
      case 101:
         ++ i; goto Q20;
      case 104:
         ++ i; goto Q21;
      case 108:
         ++ i; goto Q22;
      case 113:
         ++ i; goto Q23;
      case 115:
         ++ i; goto Q24;
      case 116:
         ++ i; goto Q25;
      case 118:
         ++ i; goto Q26;
      case 34:
      case 36:
      case 46:
      case 58:
      case 96:
         return latest;
      }
      if( c >= 60 )
      {
         if( c >= 91 )
         {
            if( c >= 123 ) return latest;
            if( c >= 102 ) { ++ i; goto Q15; }
            if constexpr( true ) return latest;
         }
         else
         {
            if( c >= 65 ) { ++ i; goto Q15; }
            if constexpr( true ) return latest;
         }
      }
      else
      {
         if( c >= 49 ) { ++ i; goto Q13; }
         if( c >= 11 ) return latest;
         if( c >= 9 ) { ++ i; goto Q01; }
         if constexpr( true ) return latest;
      }
   Q01:
      latest. first = sym_whitespace; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 13 || c == 32 ) { ++ i; goto Q01; }
      if( c >= 11 ) return latest;
      if( c >= 9 ) { ++ i; goto Q01; }
      if constexpr( true ) return latest;
   Q02:
      latest. first = sym_fact; latest. second = i;
      return latest;
   Q03:
      latest. first = sym_eof; latest. second = i;
      return latest;
   Q04:
      latest. first = sym_mod; latest. second = i;
      return latest;
   Q05:
      latest. first = sym_lpar; latest. second = i;
      return latest;
   Q06:
      latest. first = sym_rpar; latest. second = i;
      return latest;
   Q07:
      latest. first = sym_times; latest. second = i;
      return latest;
   Q08:
      latest. first = sym_plus; latest. second = i;
      return latest;
   Q09:
      latest. first = sym_comma; latest. second = i;
      return latest;
   Q10:
      latest. first = sym_minus; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 48 ) { ++ i; goto Q12; }
      if( c >= 58 ) return latest;
      if( c >= 49 ) { ++ i; goto Q13; }
      if constexpr( true ) return latest;
   Q11:
      latest. first = sym_div; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 42 ) { ++ i; goto Q27; }
      if( c == 47 ) { ++ i; goto Q28; }
      if constexpr( true ) return latest;
   Q12:
      latest. first = sym_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 46 ) { ++ i; goto Q29; }
      if( c == 69 || c == 101 ) { ++ i; goto Q30; }
      if constexpr( true ) return latest;
   Q13:
      latest. first = sym_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 46:
         ++ i; goto Q29;
      case 69:
      case 101:
         ++ i; goto Q30;
      case 47:
         return latest;
      }
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q13; }
      if constexpr( true ) return latest;
   Q14:
      latest. first = sym_semicolon; latest. second = i;
      return latest;
   Q15:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q16:
      latest. first = sym_pow; latest. second = i;
      return latest;
   Q17:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 95:
      case 97:
         ++ i; goto Q15;
      case 98:
         ++ i; goto Q31;
      case 99:
         ++ i; goto Q32;
      case 115:
         ++ i; goto Q33;
      case 116:
         ++ i; goto Q34;
      case 96:
         return latest;
      }
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 100 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q18:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 111 ) { ++ i; goto Q35; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q19:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 101 ) { ++ i; goto Q36; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q20:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 120 ) { ++ i; goto Q37; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q21:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 97 ) { ++ i; goto Q38; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 98 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q22:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 111 ) { ++ i; goto Q39; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q23:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 117 ) { ++ i; goto Q40; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q24:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 95:
         ++ i; goto Q15;
      case 105:
         ++ i; goto Q41;
      case 113:
         ++ i; goto Q42;
      case 116:
         ++ i; goto Q43;
      case 96:
         return latest;
      }
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q25:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 97 ) { ++ i; goto Q44; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 98 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q26:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 97 ) { ++ i; goto Q45; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 98 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q27:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 42 ) { ++ i; goto Q46; }
      if constexpr( true ) { ++ i; goto Q27; }
   Q28:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 10 ) { ++ i; goto Q47; }
      if constexpr( true ) { ++ i; goto Q28; }
   Q29:
      latest. first = sym_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 69 || c == 101 ) { ++ i; goto Q30; }
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q29; }
      if constexpr( true ) return latest;
   Q30:
      latest. first = sym_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 43 || c == 45 ) { ++ i; goto Q48; }
      if( c == 44 ) return latest;
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q49; }
      if constexpr( true ) return latest;
   Q31:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 115 ) { ++ i; goto Q50; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q32:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 111 ) { ++ i; goto Q51; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q33:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 105 ) { ++ i; goto Q52; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q34:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 97 ) { ++ i; goto Q53; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 98 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q35:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 115 ) { ++ i; goto Q54; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q36:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 103 ) { ++ i; goto Q55; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q37:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 95:
         ++ i; goto Q15;
      case 105:
         ++ i; goto Q56;
      case 112:
         ++ i; goto Q57;
      case 96:
         return latest;
      }
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q38:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 108 ) { ++ i; goto Q56; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q39:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 103 ) { ++ i; goto Q58; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q40:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 105 ) { ++ i; goto Q56; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q41:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 110 ) { ++ i; goto Q59; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q42:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 114 ) { ++ i; goto Q60; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q43:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 111 ) { ++ i; goto Q61; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q44:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 110 ) { ++ i; goto Q62; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q45:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 114 ) { ++ i; goto Q63; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q46:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 42 ) { ++ i; goto Q46; }
      if( c == 47 ) { ++ i; goto Q47; }
      if constexpr( true ) { ++ i; goto Q27; }
   Q47:
      latest. first = sym_comment; latest. second = i;
      return latest;
   Q48:
      latest. first = sym_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q49; }
      if constexpr( true ) return latest;
   Q49:
      latest. first = sym_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q64; }
      if constexpr( true ) return latest;
   Q50:
      latest. first = sym_abs; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q51:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 115 ) { ++ i; goto Q65; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q52:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 110 ) { ++ i; goto Q66; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q53:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 110 ) { ++ i; goto Q67; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q54:
      latest. first = sym_cos; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q55:
      latest. first = sym_deg; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q56:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 116 ) { ++ i; goto Q68; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q57:
      latest. first = sym_exp; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q58:
      latest. first = sym_log; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q59:
      latest. first = sym_sin; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q60:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 116 ) { ++ i; goto Q69; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q61:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 114 ) { ++ i; goto Q70; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q62:
      latest. first = sym_tan; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q63:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 105 ) { ++ i; goto Q71; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q64:
      latest. first = sym_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q72; }
      if constexpr( true ) return latest;
   Q65:
      latest. first = sym_acos; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q66:
      latest. first = sym_asin; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q67:
      latest. first = sym_atan; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q68:
      latest. first = sym_quit; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q69:
      latest. first = sym_sqrt; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q70:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 101 ) { ++ i; goto Q73; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q71:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 97 ) { ++ i; goto Q74; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 98 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q72:
      latest. first = sym_num; latest. second = i;
      return latest;
   Q73:
      latest. first = sym_store; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q74:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 95:
      case 97:
         ++ i; goto Q15;
      case 98:
         ++ i; goto Q75;
      case 96:
         return latest;
      }
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 99 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q75:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 108 ) { ++ i; goto Q76; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q76:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 101 ) { ++ i; goto Q77; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q77:
      latest. first = sym_var; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 115 ) { ++ i; goto Q78; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   Q78:
      latest. first = sym_variables; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q15; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q15; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q15; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q15; }
         if constexpr( true ) return latest;
      }
   }
}

