//Function to return a list containing elements of left view of the binary tree.
void leftviewre(Node *root,int level,vector<int>&re)
{
    if(root==NULL)return;
    if(re.size()==level){re.push_back(root->data);}
    leftviewre(root->left,level+1,re);
    leftviewre(root->right,level+1,re);
    
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>re;
   leftviewre(root,0,re);
   return re;
  
}