class Solution {
public:
    int ans=-1;
    
    void Solve(TreeNode*root,int& k,int& count){
        if(!root)return;
        
        Solve(root->left,k,count);
        
        if(k==count){
            ans=root->val;
            count++;
            return;
        }
        else count++;
        
        Solve(root->right,k,count);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=1;
        Solve(root,k,count);
        return ans;
        
    }
};/O(n)