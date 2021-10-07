/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
     Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL||root->data==n1||root->data==n2)
       {
           return root;
       }
       Node *left=lca(root->left ,n1 ,n2 );
       Node *right=lca(root->right ,n1 ,n2 );
       if(left==NULL)
       {
           return right;
       }
       else if(right==NULL)
       {
           return left;
       }
       return root;
       
    }
    int height (Node *root, int x)
    {
        if(root==NULL)
		return 0;

    	if(root->data==x)
		return 0;
        queue<Node*>qt;
        qt.push(root);
        int level=0;
        while(!qt.empty())
        {
            int s=qt.size();
            while(s--)
            {
                Node *t=qt.front();
                qt.pop();
                if(t->data==x)
                {
                    return level;
                }
                if(t->left!=NULL){qt.push(t->left);}
                if(t->right!=NULL){qt.push(t->right);}
                
            }
            level++;
        }
        return level;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node *r=lca(root,a,b);
        int q=height(r,a);
        int c=height(r,b);
        return q+c;
    }
};//O(N)