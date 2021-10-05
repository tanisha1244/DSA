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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(root==0)return(ans);
        s.push(root);
        while(!s.empty()){
            TreeNode * temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            if(temp->left!=0)s.push(temp->left);
            if(temp->right!=0)s.push(temp->right);
            
        }
        reverse(ans.begin(),ans.end());
        return(ans);
    }
};