#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T>
void write(FILE* f, T t)
{
   fwrite(&t, sizeof(T), 1, f);
}

template<typename T>
T read(FILE* f)
{
   T t;
   fread(&t, sizeof(T), 1, f);
   return t;
}

template<typename T>
void seek(FILE* f, int n)
{
   fseek(f,sizeof(T)*n,0);
}

template<typename T>
int fileSize(FILE* f)
{
   int i=0;
   seek<T>(f,0);
   read<T>(f);
   while(!feof(f))
   {
      i++;
      read<T>(f);
   }
   return i;
}

template<typename T>
int filePos(FILE* f)
{
   return (ftell(f)/sizeof(T));
}

#endif
