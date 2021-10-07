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
     int i=0;
    
    TreeNode* buildTree(vector<int>& pre, vector<int>in, int s, int n)
    {
        if(s>=n)
            return NULL;
        
        TreeNode* root = new TreeNode(pre[i]);
        int j;
        for(j=s; j<n; j++)
        {
            if(pre[i] == in[j])
                break;
        }
        i++;
        
        root->left=buildTree(pre, in, s, j);
        root->right=buildTree(pre, in, j+1, n);
        return root;
    }
    
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n=preorder.size();
        return buildTree(preorder, inorder, 0, n);
    }
};//O(N*N)