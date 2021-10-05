vector<int> diagonal(Node *root)
{
   // your code here
vector<int> diagonalVals;
    if (!root)
        return diagonalVals;
 
    queue<Node*> leftQueue;
    Node* node = root;
 
    while (node) {
 
        
        diagonalVals.push_back(node->data);
        
        if (node->left)
            leftQueue.push(node->left);
 
        if (node->right)
            node = node->right;
 
        else {
            
            if (!leftQueue.empty()) {
                node = leftQueue.front();
                leftQueue.pop();
            }
            else {
                
                node = NULL;
            }
        }
    }
    return diagonalVals;
 
}//O(n)