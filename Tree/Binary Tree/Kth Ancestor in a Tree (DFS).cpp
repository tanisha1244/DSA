int traverse(Node* r,int &k,int &node,int &ans){
    if(r==NULL||ans!=-1) return -1;
    int lt=traverse(r->left,k,node,ans);
    int rt=traverse(r->right,k,node,ans);
    if(r->data==node)  return 1;
    int val=max(lt,rt);
    if(val==k) ans=r->data;
    return val!=-1?val+1:-1;
}
int kthAncestor(Node *root, int k, int node)
{
    int ans=-1;
    traverse(root,k,node,ans);
    return ans;
}