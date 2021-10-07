class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
         if(root == NULL)
        return true;
    
    // Count for leaves
    int count = 0;
    Node *temp;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        // If we got leaf and queue is not empty
        // means not all leaves at same level.
        if(count > 0)
            return false;
        int len = q.size();
        for(int i=0; i<len; i++) {
            temp = q.front();
            q.pop();
            // Checking for leaf
            if(temp->left == NULL && temp->right == NULL)
                count++;
            
            // Pushing the children in queue
            else{
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }
    return true;
    }
};
//O(N)