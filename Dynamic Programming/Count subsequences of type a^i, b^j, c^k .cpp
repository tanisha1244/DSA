class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        int a=0;
        int ab=0;
        int abc=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')
            {
               a = ((2*a%1000000007)%1000000007 + 1)%1000000007;
            }
            if(s[i]=='b'){
                 ab = ((2*ab%1000000007)%1000000007 + a)%1000000007;
            }
            if(s[i]=='c'){
                 abc = ((2*abc%1000000007)%1000000007 + ab)%1000000007;
            }
        }
        return abc;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends