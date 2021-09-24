class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        for(char c:s){m[c]++;}
        priority_queue<pair<int,char>>q;
        for(auto mp: m)
        {
            q.push(make_pair(mp.second,mp.first));  //fequency,char
        }
        string r;
        pair<int,char>top1,next;
        while(!q.empty())
        {
            top1=q.top();
            q.pop();
            r+=top1.second;
            if(!q.empty())
            {
                next=q.top();
                q.pop();
                r+=next.second;
                if(next.first-1>0)
                {
                    q.push(make_pair(next.first-1,next.second));
                }
                
            }
             if(top1.first-1>0)
                {
                    q.push(make_pair(top1.first-1,top1.second));
                }
            
        }
        for(int i=0;i<r.length()-1;i++)
        {
            if(r[i]==r[i+1]){return "";}
        }
        return r;
    }
};