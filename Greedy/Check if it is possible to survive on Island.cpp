#include <iostream>
using namespace std;

int main() {
	int s,n,m;
	cin>>s>>n>>m;
	if(n<m)
	{
	    cout<<"no";
	}
	else{
	    int y=n/m;
	    y=y+1;
	    if(y%7==0)
	    {
	        cout<<"no";
	    }
	    else{
	         int days = (m * s) / n;
        if (((m * s) % n) != 0)
            days++;
	        cout<<"yes"<<days;
	    }
	}
	return 0;
}