#include"include/queue.h"
#include "include/xml.h"
void fun1(threadsafe_queue<int> *q)
{
       cout<<"fun1"<<endl;
	     this_thread::sleep_for(chrono::seconds(2));
         q->push(1);
         q->push(2);
         this_thread::sleep_for(chrono::seconds(2));
         q->push(2018);
}
void fun2(threadsafe_queue<int>* q)
{
       cout<<"fun2"<<endl;
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
    // WorkXml_2 work;
    // thread th1(&WorkXml_2::mainTask,&work);
    // thread th2(&WorkXml_2::loadData,&work);
    // th1.join();
    // th2.join();
     return  0;
}
