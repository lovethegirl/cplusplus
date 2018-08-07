#ifndef _TEST_H_
#define _TEST_H_
#include<iostream>
using namespace std;
template<typename T>
T oper(T a,T b)
{
    return a>b?a:b;
}

template<class T>
class test
{
   private:
       T *a;
   public:
   test(T t);
   ~test();
   void show();
};
template<class T>
test<T>::test(T t)
{
    a=new T(t);
    cout<<*a<<endl;
    cout<<"init"<<endl;
}
template<class T>
test<T>::~test()
{
    delete a;
    cout<<"uninit"<<endl;
}
template<class T>
void test<T>::show()
{
    cout<<a<<endl;
}
#endif
