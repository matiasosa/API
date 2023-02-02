#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int j=0;
   for(int i=0; s[i]!='\0';i++)
   {
      j=j+1;
   }
  return j;
}

int charCount(string s,char c)
{
   int j=0;
   for(int i=0;s[i]!='\0';i++)
   {
      if(s[i] == c)
      {
         j=j+1;
      }
   }
   return j;
}

string substring(string s,int d,int h)
{
   string z;
   while(d<h)
   {
      z=z+s[d];
      d++;
   }
   return z;
}

string substring(string s,int d) // ok
{
   string z;
   int i=0;

   while(i<length(s))
   {
      if(i<d)
      {
         i=i+1;
      }
      else
      {
         z = z+s[i];
         i=i+1;
      }
   }
   return z;
}

int indexOf(string s,char c) // ok
{
   int i=0;

   while(i <= length(s))
   {
      if(charCount(s, c) == 0)
      {
         i = -1;
         break;
      }
      if(s[i] == c)
      {
         break;
      }
      else
      {
         i=i+1;
      }

   }
   return i;
}

int indexOf(string s,char c,int offSet) // ok
{
   int i=0,j;
   bool x = true;
   while(i<length(s))
   {
      if(i>offSet && c == s[i])
      {
         j = i;
         x = false;
         break;
      }
      i=i+1;
   }
   if(x == true){
      j=-1;
   }

   return j;
}

int indexOf(string s,string toSearch) // ok
{
   int i=0, j=0;
   bool x=false;
   while(i<length(s))
   {
      if(s[i] == toSearch[j])
      {
         if(j == (length(toSearch)-1))
         {
            i = i-(length(toSearch)-1);
            x=true;
            break;
         }
         else
         {
            j=j+1;
         }
      }
      i=i+1;
   }
   if(x==false)
   {
      i=-1;
   }
   return i;
}

int indexOf(string s,string toSearch,int offset) // ok
{
   int i;
   string x;
   x = substring(s,offset);
   i = indexOf(x, toSearch)+ length(s)-length(x);
   return i;
}

int lastIndexOf(string s,char c)
{
   int i=0, z;
   string x;
   bool j = false;
   while(i<length(s))
   {
      x = substring(s,i);
      if(indexOf(x, c)>=0)
      {
         z = length(s)-length(x);
         j = true;
      }
      else
      {
         break;
      }
      i++;
   }
   if(j==false)
   {
      z = -1;
   }
   return z;
}

int indexOfN(string s,char c,int n)
{
   int i = 0;
      int r = -1;
      while( s[i]!='\0' )
      {
         if( s[i]==c and n!=0 )
         {
            n--;
            r = i;
         }
         i++;
      }
      if( n>0 )
      {
         r = length(s);
      }
      return r;
}

int charToInt(char c)
{
   int x = c;
   return x-48;
}

int intToChar(int i)
{
   char c = '0'+i;
   return c;
}

int getDigit(int n,int i)
{
   int j=0,m=n,k;
   while(j<i)
   {
      m = m/10;
      j++;
   }
   k=m-(m/10)*10;

   return k;
}

int digitCount(int n)
{
   int i=0;
   float j=n;
   while(j>=1)
   {
      j = j/10;
      i++;
   }
   return n<10? 1:i;
}

string intToString(int i)
{
   string todo="";
   int l = digitCount(i)-1;
   while(l>=0)
   {
      int d = getDigit(i,l);
      char t = intToChar(d);
      todo = todo+t;
      l--;
   }
   return todo;
}

int stringToInt(string s,int b) // ok
{
   int l = length(s);
   int i=l-1,j=0, n =0,resultado=0, k=0;

   while(i >= 0)
   {
      char c = s[i];
      n = charToInt(c);
      if(n>9)
      {
         n = charToInt(c)-7;
      }

      k = n * exp(b,j);
      resultado = resultado + k;
      i--;
      j++;
   }


   return resultado;
}

int stringToInt(string s) // ok
{
   return stringToInt(s,10);
}

string charToString(char c)
{
   string x = "";
   string s = x + c;

   return s;
}

char stringToChar(string s)
{
   char c = s[0];
   return c;
}

string stringToString(string s)
{
   return s;
}

string doubleToString(double d)
{//123,45
//   int k=0, j=0;
//   string ent = intToString(d);
//   int ent2 = stringToInt(ent);
//   double dec = d*10;
//   while(getDigit(dec,(digitCount(d))-1+k)!=0)
//   {
//      dec = dec * 10;
//      k++;
//   }
//   j = ent2*k;
//   string p = intToString(j);
//   ent = ent + '.' + p;
   return 0;

}

double stringToDouble(string s)
{
   return 1.1;
}

bool isEmpty(string s)
{
   if(s[0] == '\0')
   {
      return true;
   }
   return false;
}

bool startsWith(string s,string x)
{
   string a = substring(s,0,length(x));
   if(a == x)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool endsWith(string s,string x)
{
   string a = substring(s, (length(s)-length(x)));
   if(a == x)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool contains(string s,char c)
{
   return indexOf(s,c)>=0 ?  true : false;
}

string replace(string s,char oldChar,char newChar)
{
   int i=0;
   while(i<length(s))
   {
      if(s[i]==oldChar)
      {
         s[i] = newChar;
      }
      i++;
   }
   return s;
}

string insertAt(string s,int pos,char c)
{
   s[pos] = c;
   return s;
}

string removeAt(string s,int pos)
{
   string b = substring(s,0,pos);
   string c = substring(s,pos+1);

   return b+c;
}

string ltrim(string s)
{
   while(s[0] == ' ')
   {
      s = removeAt(s,0);
   }
   return s;
}

string rtrim(string s)
{// [hola   ] l = 7
   int i = length(s)-1;
   while(s[i] == ' ')
   {
      s = removeAt(s,i);
      i--;
   }
   return s;
}

string trim(string s)
{
   s = ltrim(s);
   s = rtrim(s);

   return s;
}

string replicate(char c,int n)
{
   int i=0;
   string s;
   while(i<n)
   {
      s = s+c;
      i++;
   }
   return s;
}

string spaces(int n)
{
   return replicate(' ',n);
}

string lpad(string s,int n,char c)
{
   string x = replicate(c, n - length(s));

   return x+s;
}

string rpad(string s,int n,char c)
{
   string x = replicate(c, n - length(s));
   return s+x;
}

string cpad(string s,int n,char c)
{
   int m = (n - length(s))/2;
   string x = replicate(c, m);

   return x+s+x;
}

bool isDigit(char c)
{
   return charToInt(c) > 9 ?  false: true;
}

bool isLetter(char c)
{
   int x = charToInt(c);
   return (x>=17 && x<=42) || (x>=49 && x<=74)? true:false;

}

bool isUpperCase(char c)
{
   return (charToInt(c)>=17 && charToInt(c)<=42);
}

bool isLowerCase(char c)
{
   return (charToInt(c)>=49 && charToInt(c)<=74);
}

char toUpperCase(char c)
{
   return c-32;
}

char toLowerCase(char c)
{
   return c+32;
}

#endif
