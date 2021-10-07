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
        string solve(TreeNode* root, unordered_map<string,vector<TreeNode*>> &mp){
        if(!root) return "$";
        
        string s = "";
        
        if(!root->left && !root->right){
            s = to_string(root->val);
            mp[s].push_back(root);
            return s;
        }
        
        s += to_string(root->val) + " " + solve(root->left, mp) + solve(root->right, mp); 
        
        mp[s].push_back(root);
        
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector <TreeNode*> ans;
        unordered_map<string,vector<TreeNode*>> mp;
        solve(root, mp);
        
        for(auto i:mp){
            if(i.second.size() > 1)
                ans.push_back(i.second[0]);
        }
        
        return ans;
    }
        
};//O(N)
  //O(N)