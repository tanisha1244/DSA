 vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>v;
        if(!root)return v;
        queue<pair<Node*,int>>q;
        map<int,int>m;
        q.push({root,0});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            Node* s=p.first;
            int x=p.second;
            if(m.find(x)==m.end())
            {
                m[x]=s->data;
            }
            if(s->left != NULL) q.push({s->left,x-1});
            if(s->right != NULL) q.push({s->right,x+1});
        }
        for(auto p:m)
        {
            v.push_back(p.second);
        }
        return v;
        
    }
