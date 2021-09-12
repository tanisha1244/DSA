#include <bits/stdc++.h>
using namespace std;
void insertionsort(int a[],int n)
{ int key,i,j;
 for(i=0;i<n;i++)
 { key=a[i];
  j=i-1;
   while(j>=0&&a[j]>key)
   {
   	 a[j+1]=a[j];
   	 j=j-1;
   }
 	a[j+1]=key;
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
insertionsort( a, n);
printarray(a,n);
return 0;	
	
}
