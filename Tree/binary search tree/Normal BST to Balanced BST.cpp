/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// Your are required to complete this function
// function should return root of the modified BST
void inorder_bst(Node* root, vector<int>&v){
   if(!root) return;
   inorder_bst(root->left,v);
   v.push_back(root->data);
   inorder_bst(root->right,v);
}
Node* make_balanced(int start,int end,vector<int>v){
   if(start>end) return NULL;
   int mid=(start+end)/2;
   Node* root=new Node (v[mid]);
   root->left=make_balanced(start,mid-1,v);
   root->right=make_balanced(mid+1,end,v);
   return root;
}
Node* buildBalancedTree(Node* root)
{
// Code here
vector<int>v;
inorder_bst(root,v);
int h=v.size();
return make_balanced(0,h-1,v);
}
/O(N)