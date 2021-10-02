class Solution {
public:
    int fork(string s, int k, char c) {
        int n = s.size(), ans = 0;
        int l=0,ct=0;
        for (int i = 0; i < n; i += 1) {
                if (s[i] == c){ct += 1;}
              
                  while (ct>k) {
                      if (s[l] == c) ct -= 1;
                    l+= 1;
                }
            ans = max(ans, i - l+1);
    }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
         return max(fork(answerKey, k, 'T'), fork(answerKey, k, 'F'));
        
    }
};//sliding window O(n)