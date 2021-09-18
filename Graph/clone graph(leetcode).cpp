class Solution {
    void dfs(Node* cur,Node* cop,vector<Node *>&vis)
    {
         vis[cop->val]=cop;
        for(auto currt:cur->neighbors)
        {
            if(vis[currt->val]==NULL)
            {
                Node * copp=new Node(currt->val);
                cop->neighbors.push_back(copp);
                dfs(currt,copp,vis);
            }
            else{
                (cop->neighbors).push_back(vis[currt->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        vector<Node *>vis(10000,NULL);
        Node* copy=new Node(node->val);
        vis[node->val]=copy;
        for(auto cur:node->neighbors)
        {
            if(vis[cur->val]==NULL)
            {
                Node * cop=new Node(cur->val);
                copy->neighbors.push_back(cop);
                dfs(cur,cop,vis);
            }
            else{
                (copy->neighbors).push_back(vis[cur->val]);
            }
        }
        return copy;
        
    }
};