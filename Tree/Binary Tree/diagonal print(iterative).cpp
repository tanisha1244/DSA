vector<int> diagonal(Node *root)
{
   // your code here
   queue<Node*>q;
   vector<int>v;
   q.push(root);
   while(!q.empty())
   {
       Node *temp=q.front();
       q.pop();
       while(temp)
       {
           v.push_back(temp->data);
           if(temp->left){q.push(temp->left);}
           temp=temp->right;
       }
   }
   return v;
}//O(N)