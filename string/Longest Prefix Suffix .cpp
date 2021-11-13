class Solution {
   vector<int> prefix(string &s) {
       int n = s.size();
       vector<int> lps(n, 0);
       for (int i = 1; i < n; i++) {
           int j = lps[i - 1];
           while (j > 0 && s[i] != s[j]) {
               j = lps[j - 1];
           }
           if (s[i] == s[j]) j++;
           lps[i] = j;
       }
       return lps;
   }

public:
   int lps(string &s) {
       // Your code goes here
       vector<int> lps = prefix(s);
       return lps[s.size() - 1];
   }
};