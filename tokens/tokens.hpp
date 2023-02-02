#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s, char sep)
{
   int i = 0,j = 1;

   while( i<length(s) )
   {
      s[i]==sep?j++:j;
      i++;
   }
   s==""?j = 0:j;

   return j;
}

void addToken(string& s, char sep, string t)
{
   length(s)==0?s = t:s = s+sep+t;
}

string getTokenAt(string s, char sep, int i)
{
   int x = indexOfN(s,sep,i);
   int y = indexOfN(s,sep,i+1);
   s = substring(s,x+1,y);
   return s;
}

void removeTokenAt(string& s, char sep, int i)
{
   string r = "",t = "";
      for( int l = 0; l<=(tokenCount(s,sep))-1; l++ )
      {
         r = getTokenAt(s,sep,l);
         if( l!=i )
         {
            addToken(t,sep,r);

         }
      }
      s = t;
}

void setTokenAt(string& s, char sep, string t, int i)
{
   string x = substring(s,indexOfN(s,sep,i+1));
   string y = substring(s,0,indexOfN(s,sep,i));
   addToken(y,sep,t);
   s = y+x;
}

int findToken(string s, char sep, string t)
{
   int l = 0;
   bool r = true;
   while( r and (l<=(tokenCount(s,sep)-1)) )
   {
      string c = getTokenAt(s,sep,l);
      c==t?r = false:r;

      l++;

   }
   l = l-1;
   if( getTokenAt(s,sep,l)!=t )
   {
      l = -1;
   }
   return l;
}

#endif
