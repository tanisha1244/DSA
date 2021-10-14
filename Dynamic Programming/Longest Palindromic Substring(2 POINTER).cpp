class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int maxlen = 1;
        int b = 0;
        int e = 0;
        // odd length palindromes = will have same center
        for(int c=0; c<n; c++){
            for(int i=c,j=c; (i>=0 && j<n); i--,j++){
                if(s[i]!=s[j]) break;
                int len = j-i+1;
                if(len>maxlen){
                    b=i; e=j; maxlen=len;
                }
            }
        }
        // even length palindromes = will have adjacent centers
        for(int c=0; c<n; c++){
            for(int i=c,j=c+1; (i>=0 && j<n); i--,j++){
                if(s[i]!=s[j]) break;
                int len = j-i+1;
                if(len>maxlen){
                    b=i; e=j; maxlen=len;
                }
            }
        }
        return s.substr(b,maxlen);
    }
};//O(N^2)