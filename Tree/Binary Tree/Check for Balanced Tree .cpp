class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int fun(Node* root,bool &h)
    {
        if(!root)
        {
            return 0;
        }
        if(h==false)
        {
            return 0;
        }
        int l=fun(root->left,h);
    
        int r=fun(root->right,h);
        if(abs(l-r)>1)
        {
            h=false;
        }
        return max(l,r)+1;
    }
    
    bool isBalanced(Node *root)
    {
       bool h=true;
        fun(root,h);
        return h;
    }
};