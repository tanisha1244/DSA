#include <bits/stdc++.h>
using namespace std;
void bubblesort(int a[],int n)
{ int key,i,j;
 for(i=0;i<n;i++)
 {
   for(j=i+1;j<n;j++)
   { if(a[j]<a[i])
     { key=a[i];
   	  a[i]=a[j];
   	   a[j]=key;
   	 }
 }
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
bubblesort( a, n);
printarray(a,n);
return 0;	
	
}
