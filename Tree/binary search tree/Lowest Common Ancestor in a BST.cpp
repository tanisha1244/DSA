Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(root==NULL) return NULL;
  if(root->data==n1||root->data==n2)
   return root;
   Node*Lca1= LCA(root->left,n1,n2);
   Node*Lca2= LCA(root->right,n1,n2);
   if(Lca1!=NULL&Lca2!=NULL)
    return root;
   if(Lca1)
    return Lca1;
   else
    return Lca2;
}


