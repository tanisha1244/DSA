#include<bits/stdc++.h>
using namespace std;
class mystack{
	public:
		int data;
		mystack *next;
};
mystack* newnode(int d)
{
	mystack *a=new mystack();
	a->data=d;
	a->next=NULL;
}
int isempty(mystack *node){
	return !node;
}
void push(mystack** node,int data)
{
	mystack* temp=newnode(data);
	temp->next=*node;
    *node=temp;
	cout<<temp->data<<endl;	
}
int pop(mystack** node)
{
	if(isempty(*node))
	{
		return INT_MIN;
	}
	mystack *temp=*node;
	*node=(*node)->next;
	int x=temp->data;
	free(temp);
	return x;
}

int main()
{
	mystack*root=NULL;
	push(&root,45);
	int r=pop(&root);
	cout<<r;
}
