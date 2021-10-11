class Solution
{vector<int> v;
   private:
   void bstToArray(Node*root)
   {
       if(root == NULL)
       return;
       bstToArray(root->left);
       v.push_back(root->data);
       bstToArray(root->right);
   }
    public:
    int kthLargest(Node *root, int k)
    {
        //Your code here
         bstToArray(root);
   int i = v.size()-k;
    int ans = v[i];
     return ans ;
    }
};

// O(N)
