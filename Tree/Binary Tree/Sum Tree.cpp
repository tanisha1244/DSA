struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false

class Solution
{  bool p=false;
    int dfs(Node *root)
    { if(root==NULL)
    {
        return 0;
    }
    int sum=root->data;
    int k=0;
    int l=dfs(root->left);
    int r=dfs(root->right);
    if(l!=0){ k=k+l;}
    if(r!=0){k+=r;}
    if(k==0||sum==k){
        p=true;
    }
    else{
        p=false;
    }
    return l+r+sum;
        
    }
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
          dfs(root);
          return p;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout <<ob.isSumTree(root) << endl;
    }
    return 1;
}  // } Driver Code Ends