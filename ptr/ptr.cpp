#include<iostream>
#include<memory>
using namespace std;
int main()
{
    int *a=new int(10);
    int *b=a;
    cout<<a<<"  "<<b<<endl;
    cout<<&a<<"  "<<&b<<endl;
    shared_ptr<int>p;
    return 0;
}
