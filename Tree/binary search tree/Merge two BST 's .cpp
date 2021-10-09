class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inOrder(Node *root, vector<int> &v){
        if(!root)
            return;
        inOrder(root->left, v);
        v.push_back(root->data);
        inOrder(root->right, v);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> v1;
       vector<int> v2;
       inOrder(root1, v1);
       inOrder(root2, v2);
       vector<int> v(v1.size()+v2.size());
       std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
       return v;
    }
};
