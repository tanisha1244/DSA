#include <bits/stdc++.h>
using namespace std;
void createheap(int a[],int n,int i)
{ int largest=i; 
int l=(2*i)+1;
int r=(2*i)+2;
if(l<n&&a[l]>a[largest])
   { largest=l;
   }
if(r<n&&a[r]>a[largest])
   { largest=r;
   }
if(largest!=i)
   { swap(a[i],a[largest]);
    createheap(a,n,largest);
   }
}
void heapsort(int a[],int n)
{
	int last=(n/2)-1;//lastnode without leaf
	for(int i=last;i>=0;i--)
	{ 
		createheap( a, n, i);
		
	}
	for(int i=n-1;i>=0;i--)
	{swap(a[0],a[i]);
		createheap( a, i, 0);
	}
}
void printarray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
int main()
{ int i,n,a[1000];
 cin>>n;
 for(i=0;i<n;i++)
 {cin>>a[i];
 }
heapsort( a, n);
printarray(a,n);
return 0;	
	
}
