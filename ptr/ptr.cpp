#include<iostream>
#include<memory>
#include<thread>
using namespace std;
void task(shared_ptr<int>a)
{
    shared_ptr<int>p(a);
    cout<<"task thread:"<<p.use_count()<<endl;
    cout<<"删除"<<endl;
    //shared_ptr<int>p1(p,[]{delet})
}
int main()
{
    shared_ptr<int>p(new int(10));
    cout<<"main thread:"<<p.use_count()<<endl;
    thread th(task,p);
    cout<<"main thread:"<<p.use_count()<<endl;
    th.join();
    cout<<"main thread :"<<p.use_count()<<endl;
    cout<<*p<<endl;
    return 0;
}
