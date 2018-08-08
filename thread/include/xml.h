#include<iostream>
#include<thread>
#include<chrono>
#include <mutex>
#include <memory>
#include<cstring>
#include<condition_variable>
#include<unistd.h>
using namespace std;
class WorkXml_2
{
private:
	char buf[1000];
	mutex m_mutex;
	bool istrue;
	condition_variable signal;
public:
	WorkXml_2(){
		istrue=false;
	}
	~WorkXml_2(){}
	void loadData()
	{
		  cout<<"  start load data"<<endl;
		  // std::this_thread::sleep_for(std::chrono::milliseconds(100));
		  unique_lock<mutex>lk(m_mutex);
		  for(int i=0;i<5;++i)
		  {
			  sleep(1);
			  cout<<"wait "<<i<<"s"<<endl;
		  }
		  memcpy(buf,"i am dv",10);
		  cout<<buf<<endl;
		  cout<<"load data sucessful"<<endl;
		  istrue=true;
         signal.notify_one();
	}
	bool clstrue()
	{
		return istrue;
	}
	void mainTask()
	{
		 cout<<"do the main handtask\n"<<endl;
		 unique_lock<mutex>lk(m_mutex);
		 signal.wait(lk, bind(&WorkXml_2::clstrue,this));
		 cout<<buf<<endl;
		 cout<<"processing data"<<endl;
	}
};
