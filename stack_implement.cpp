#include<bits/stdc++.h>
#define int long long
#define MXI 1000000007LL
using namespace std;
class Stackarr
{
   int size;
   int * arr;
   int top;

public:
   Stackarr()
   {
      top = -1;
      size = 1000;
      arr = new int[size];
   }

   void push(int x)
   {
      arr[++top] = x;
   }
   int pop()
   {
      int x = arr[top--];
      return x;
   }
   int Top()
   {
      return arr[top];
   }
   int Size()
   {
      return top + 1;
   }
};
class Node
{
public:
   int data;
   Node* next;

public:
   Node(int data1 , Node* next1)
   {
      data = data1;
      next = next1;
   }
   Node(int data1)
   {
      data = data1;
      next = nullptr;
   }
};

class Stackll
{
   Node* top;
   int size = 0;

public:
   void push(int x)
   {
      Node* e = new Node(x);

      e->next = top;
      top = e;
      size++;
   }
   void pop()
   {
      top = top->next;
      size--;
   }
   int Size() 
   {
      return size;
   }
   int Top()
   {
      return top->data;
   }
};
int32_t main(){

   ios::sync_with_stdio(false); 
   cin.tie(NULL);

   Stackarr s;

   s.push(3);
   s.push(5);
   s.push(5);
   s.push(7);


   s.pop(); 
   cout << s.Top();

   return 0;
}