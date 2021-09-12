#include <bits/stdc++.h>
using namespace std;
void selectionsort(int a[],int n)
{ int min,i,j,temp;
 for(i=0;i<n;i++)
 { min=i;
  for(j=i+1;j<n;j++)
   { if(a[j]<a[min])
      {min=j;}}
      	temp=a[min];
      	a[min]=a[i];
      	a[i]=temp;
	
 	
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
selectionsort( a, n);
printarray(a,n);
return 0;	
	
}
