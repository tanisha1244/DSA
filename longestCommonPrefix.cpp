class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());
        string a=strs[0];
        int n=strs.size();
        string b=strs[n-1];
        string k="";
        int n1=a.length();
        int i=0;
        while(i<n1)
        {
            if(a[i]==b[i])
            {
                k=k+a[i];
                i++;
            }
            else{
                break;
            }
        }
        return k;
        
    }
};