#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T info;
   Node<T>* sig;
};

template <typename T>
Node<T>* add(Node<T>*& p,T e)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = NULL;

   if( p!=NULL )
   {
      Node<T>* q = p;
      while(q->sig!=NULL)
      {
         q = q->sig;
      }
      q->sig  = nuevo;
   }
   else
   {
      p = nuevo;
   }

   return nuevo;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{
   Node<T>* q = p;
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = q;
   p = nuevo;
   return p;
}

template <typename T, typename K>
T remove(Node<T>*& p,K k,int cmpTK(T,K))
{
   T t;

   Node<T>* q = p;
   Node<T>* d = NULL;

   while(cmpTK(q->info, k)!=0)
   {
      d = q;
      q = q->sig;
   }

   t = q->info;
   d->sig = q->sig; 
   delete q;


   return t;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   T t;

   Node<T>* q = p;
   t = q->info;
   p = p->sig;

   delete q;

   return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p,K k,int cmpTK(T,K))
{
   Node<T>* q = p;
   if(p != NULL)
   {
      while( cmpTK(q->info,k)!=0&&q->sig!=NULL )
      {
         q = q->sig;
      }
      if( cmpTK(q->info,k)!=0 )
      {
         q = NULL;
      }
   }

   return q;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))
{
   Node<T>* nuevo = new Node<T>();
   Node<T>* n = p;
   Node<T>* ant = NULL;
   while( n != NULL and cmpTT(n->info, e) < 0 )
   {
      ant = n;
      n = n->sig;
   }
   if( n == NULL )
   {
      nuevo = add<T>(p,e);
   }
   if( p->sig == NULL or n == p)
   {
      nuevo->info = e;
      nuevo->sig = n;
      p = nuevo;
      ant = nuevo;
   }
   else
   {
      nuevo->info = e;
      nuevo->sig = n;
      ant->sig = nuevo;
   }

   return nuevo;
}


template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
   Node<T>* q = p;
   enc = true;
   if(q == NULL)
   {
        enc = false;
        return add<T>(p,e);
   }
   while(q->sig != NULL && cmpTT(q->info, e)!= 0)
   {
      q = q->sig;
   }
   if(cmpTT(q->info, e)!= 0)
   {
      q = orderedInsert<T>(p, e, cmpTT);
      enc = false;
   }

   return q;
}

template <typename T>
void sort(Node<T>*& p,int cmpTT(T,T))
{
   Node<T>* q = p;
   Node<T>* d = NULL;

   while(q != NULL)
   {
      orderedInsert(d, q->info, cmpTT);
      q = q->sig;
   }
   q = p;
   p = d;
   delete q;
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   return p==NULL? true: false;
}

template <typename T>
void free(Node<T>*& p)
{
   p = NULL;
}

template <typename T>
Node<T>* push(Node<T>*& p,T e)
{
   return addFirst<T>(p,e);
}

template <typename T>
T pop(Node<T>*& p)
{
   return removeFirst<T>(p);
}

template <typename T>
Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e)
{
   if(p == NULL)
   {
      add<T>(p, e);
      q = p;
   }
   else
   {
      add<T>(p, e);
      q = q->sig;
   }
   return q;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q,T e)
{
   if(q == NULL)
   {
      Node<T>* x = add<T>(q, e);
      q->sig = q;
      return x;
   }

   Node<T>* d = new Node<T>();
   d->info = e;
   d->sig = NULL;

   if(q->sig == NULL)
   {
      d->sig = q;
      q->sig = d;
      q = d;
   }
   else
   {
      d->sig = q->sig;
      q->sig = d;
      q = d;
   }
   return d;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   return removeFirst(p);
}

template <typename T>
T dequeue(Node<T>*& q)
{
   Node<T>* d = q->sig;
   T t = d->info;
   q->sig = d->sig;
   delete d;
   return t;
}


#endif
