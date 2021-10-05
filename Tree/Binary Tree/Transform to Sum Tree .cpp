class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int addtree(Node *root)
    {
        if(root==NULL)
        {
            return 0;
            
        }
        int org=root->data;
        root->data=addtree(root->left)+addtree(root->right);
        return   root->data+org;
        
    }
    void toSumTree(Node *node)
    {
        // Your code here
        addtree(node);
        
    }
};