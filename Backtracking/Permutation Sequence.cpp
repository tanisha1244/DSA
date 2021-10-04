class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>fact(n);
        vector<int>nums;
        nums.push_back(1);
        fact[0]=1;
        for(int i=1;i<n;i++){
            fact[i]=fact[i-1]*i;
            nums.push_back(i+1);
        }
        k--;
        string ans="";
        for(int i=n-1;i>=0 ;i--){
            int index=k/fact[i];
            k-=index*fact[i];
            ans+=nums[index]+'0';
            nums.erase(nums.begin()+index);
        }
        return ans;
        
    }
};