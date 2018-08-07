#include"include/queue.h"
#include<thread>
#include<iostream>
#include<chrono>
using namespace std;
void fun1(threadsafe_queue<int> *q)
{
	     this_thread::sleep_for(chrono::seconds(2));
         q->push(1);
         q->push(2);
         this_thread::sleep_for(chrono::seconds(2));
         q->push(2018);
}
void fun2(threadsafe_queue<int>* q)
{
       auto val=q->wait_and_pop();
       cout<<*val<<endl;
       val=q->wait_and_pop();
       cout<<*val<<endl;
       val =q->wait_and_pop();
       cout<<*val<<endl;
}
int main()
{
     threadsafe_queue<int> q;
     thread th(fun1,&q);
     thread th2(fun2,&q);
     th.join();
     th2.join();
     return  0;
}
