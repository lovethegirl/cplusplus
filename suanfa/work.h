#include<iostream>
#include<vector>
#include<string>
#include<thread>
#include<mutex>
#include<string.h>
#include <assert.h>
using namespace std;
void insertsort(int *a,int len)
{
	for(int i=1;i<len;++i)
	{
		int tmp=a[i];
		int j=i-1;
		for(;j>=0&&a[j]>tmp;--j)
		{
			a[j+1]=a[j];
		}
		a[j+1]=tmp;

	}
}


void fastsort(int *a,int first,int end)
{
	    if(first>=end)
	    	return;
	    int s=first;
	    int e=end;
	    int tmp=a[first];
	    while(s<e)
	    {
	        while(s<e&&a[e]>=tmp)
	        	--e;
	        a[s]=a[e];
	        while(s<e&&a[s]<=tmp)
	        	++s;
	        a[e]=a[s];
	    }
	    a[s]=tmp;
	    fastsort(a,first,s-1);
	    fastsort(a,s+1,end);
}
void merge (int *a,int *b,int start,int mid,int end)
{
	int i=start;
	int j=mid+1;
	int k=start;
	while(i!=mid+1&&j!=end+1)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i!=mid+1)
		b[k++]=a[i++];
	while(j!=end+1)
		b[k++]=a[j++];
	for(int w=start;w<=end;++w)
		a[w]=b[w];
}

void mergesort(int *a,int *b,int start,int end)
{
	if(start>=end)
		return;
	int mid=start+(end-start)/2;
	mergesort(a,b,start,mid);
	mergesort(a,b,mid+1,end);
	merge(a,b,start,mid,end);
}
class A
{
private:
	A()
	{ p=nullptr;}
private:
	static A *p;
public:
	static  mutex mx;
	static A * getA()
	{
           if(p==nullptr)
           {
           	     mx.lock();
                  if(p==nullptr)
                  {
                  	p=new A();
                  }
                 mx.unlock();
            }
            return p;

	}
};
char* strcpy_(char *  dst,char *src)
{
	 assert(src!=NULL);
	 char *p=dst;
	 while(*src!='\0')
	 	*p++=*src++;
	 *p='\0';
	 return dst;
}
void adjust(int *a,int len,int index)
{
	int left=index*2+1;
	int right=index*2+2;
	int maxindex=index;
	if(left<len&&a[left]>a[maxindex])
		maxindex=left;
	if(right<len&&a[right]>a[maxindex])
		maxindex=right;
	if(index!=maxindex)
	{
		int tmp=a[index];
		a[index]=a[maxindex];
		a[maxindex]=tmp;
		adjust(a,len,maxindex);
	}
}
void heapsort(int *a,int len)
{
	for(int i=(len)/2-1;i>=0;--i)
	{
		adjust(a,len,i);
	}
	for(int j=len-1;j>0;--j)
	{
		int  tmp=a[j];
		a[j]=a[0];
		a[0]=tmp;
		adjust(a,j,0);
	}
}

void maopao(int *a,int len)
{
	for(int i=0;i<len-1;++i)
	{
		for(int j=0;j<len-1-i;++j)
		{
			if(a[j]>a[j+1])
			{
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
}
void selectsort(int *a,int len)
{
	for(int i=0;i<len-1;++i)
	{
		int tmp=i;
		for(int j=i+1;j<len;++j)
		{
			if(a[tmp]>a[j])
			{
				tmp=j;
			}
		}
		if(tmp!=i)
		{
			int t=a[tmp];
			a[tmp]=a[i];
			a[i]=t;
		}
	}
}
