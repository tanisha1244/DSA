/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* getnode(int val)
    {
        TreeNode* newnode=new TreeNode;
        newnode->val=val;
        newnode->left=newnode->right=NULL;
        return newnode;
            
    }
    int construct_BST(vector<int> &preorder,int n,int pos,TreeNode *curr,int left,int right)
    {
        if(pos==n || preorder[pos]<left || preorder[pos]>right) //Boundary case
            return pos;
        
        if(preorder[pos]<curr->val)     //Insert in left-subtree
        {
            curr->left = getnode(preorder[pos]);
            pos += 1;
            pos = construct_BST(preorder,n,pos,curr->left,left,curr->val-1);
        }
        
        if(pos==n || preorder[pos]<left || preorder[pos]>right)
            return pos;
        
        //Insert in right-subtree
        curr->right = getnode(preorder[pos]);
        pos += 1;
        pos = construct_BST(preorder,n,pos,curr->right,curr->val+1,right);
        return pos;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n= preorder.size();
        if(n==0)
        {
            return NULL;
        }
        TreeNode *root=getnode(preorder[0]);
        if(n==1)
        {
            return root;
        }
          construct_BST(preorder,n,1,root,INT_MIN,INT_MAX);
        return root;
        
        
    }
};//o(n)