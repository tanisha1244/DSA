/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
Node* inpre(Node* root){
   Node* temp=root->left;
   while(temp->right)
    temp=temp->right;
   return temp;
}
Node* insuc(Node* root){
   Node* temp=root->right;
   while(temp->left)
   temp=temp->left;
   return temp;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
if(!root) return;
if(root->key==key){
   if(root->left)
   pre=inpre(root);
   if(root->right)
   suc=insuc(root);
   return;
}
if(key<root->key){
   suc=root;
   findPreSuc(root->left,pre,suc,key);
}
else if(key>root->key){
       pre=root;
   findPreSuc(root->right,pre,suc,key);
}

}//O(H)