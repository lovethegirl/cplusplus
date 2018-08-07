#include<iostream>
#include"test.h"
using namespace std;


int main()
{
   cout<<oper(10,11)<<endl;
   cout<<oper("av","ab")<<endl;
   test<int> *tmp=new test<int>(10);
   tmp->show();
   delete tmp;
   return 0;
}
