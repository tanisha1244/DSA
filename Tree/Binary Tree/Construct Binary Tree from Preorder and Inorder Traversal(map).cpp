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
   TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
	map<int, int> m;
	for(int i=0; i<in.size(); i++) m[in[i]] = i;
	TreeNode* root = helper(pr, 0, pr.size()-1, in, 0, in.size()-1, m);
	return root;
}

TreeNode* helper(vector<int>& pr, int preStart, int preEnd, vector<int>& in, int inStart, int inEnd, map<int, int>& m){
	if(preStart > preEnd || inStart > inEnd) return NULL;
	TreeNode* root = new TreeNode(pr[preStart]);

	int rootIdx = m[root->val];

	int numsOnLeft = rootIdx - inStart;
	root-> left = helper(pr, preStart+1, preStart+numsOnLeft, in, inStart, rootIdx-1, m);
	root-> right = helper(pr, preStart+1+numsOnLeft, preEnd, in, rootIdx+1, inEnd, m);

	return root;
}
};//tc==sc=O(N)