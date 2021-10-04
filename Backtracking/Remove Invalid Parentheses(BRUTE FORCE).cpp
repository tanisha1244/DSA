class Solution {
public:
     vector<string> r;
    unordered_map<string,int> mp;
    int minremoval(string s)
    {
        stack<char>s1;
        int i=0;
        while(i<s.length())
        {
            if(s[i]=='(')
            {
                s1.push('(');
                
            }
            else if(s[i]==')'){
                if(!s1.empty()&&s1.top()=='(')
                {
                    s1.pop();
                }
                else{
                    s1.push(')');
                }
                
            }
            i++;
        }
        return s1.size();
    }
    void isvalid(string s,int minre)
    {  if(mp[s] != 0)
            return;
        else
            mp[s]++;
       
        if(minre==0)
        {
            int minrem=minremoval(s);//check if after every possible removal is this a valig string or not;
            if(minrem==0)
            {
                r.push_back(s);
                return;
            }
        }
        for(int i=0;i<s.length();i++)
        {
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            isvalid(left+right,minre-1);
        }
        return;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        isvalid(s, minremoval(s));
        return r;
        
    }
};//time:O(2^N)