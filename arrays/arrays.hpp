#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
   arr[len] = e;
   len++;
   return len;
}

template <typename T> 
void insert(T arr[],int& len,T e,int p)
{
   for( int i = len-1; i>p; i-- )
   {
      arr[i+1] = arr[i];
   }
   arr[p] = e;
   len++;
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret = arr[p];
   for(int i=p+1;i<len;i++)
   {
      arr[i-1] = arr[i];
   }
   len--;
   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
   int x=-1;
   for(int i=0;i<len;i++)
   {
      if(cmpTK(arr[i],k)==0)
      {
         return i;
      }
   }
   return x;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   int i = 0;
   while( i<len and cmpTT(arr[i],e)<0 )
   {
      i++;
   }
   insert<T>(arr,len,e,i);

   return i;
}

template<typename T>
void Swap(T *p, T *q)
{
   T temp;
   temp = *p;
   *p = *q;
   *q = temp;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   for(int i=0; i<len; i++)
   {
      for(int j=0; j<len-1; j++)
      {
         if(cmpTT(arr[j],arr[j+1])>0)
         {
            swap(arr[j],arr[j+1]);
         }
      }
   }
}

#endif
