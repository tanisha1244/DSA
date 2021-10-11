class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int inorder(Node* root,unordered_set<int> &s,int target)
    {
        if(root==NULL)
        return 0;
        if(inorder(root->left,s,target)==1)
        return 1;
        if(s.find(target-root->data)!=s.end())
        return 1;
        else
        s.insert(root->data);
        return inorder(root->right,s,target);
    }
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
     unordered_set<int> s;
    return inorder(root,s,target);
    }
};/O(n)