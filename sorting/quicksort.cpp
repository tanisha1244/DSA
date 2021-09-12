#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partation(int a[],int low,int high)
{ int pivot=a[high];
int j;
int i=low-1;
for(j=low;j<=high-1;j++)
{
	if(a[j]<pivot)
	  {
	  	i++;
	  	swap(&a[i],&a[j]);
	  }
}
swap(&a[i+1],&a[high]);
return (i+1);
}
void quicksort(int a[],int low,int high)
{ int pi;
 if(low<high)
          {
             pi=partation(a,low,high);
          
quicksort(a,low,pi-1);
quicksort(a,pi+1,high);
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
quicksort( a, 0,n-1);
printarray(a,n);
return 0;	
	
}
