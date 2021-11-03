class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> ans;
        int n = nums.size();
        if(n<4)
            return ans;
        
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<pair<int,int>>> m;    //key->SUM...Value->(i,j) pair of index where i<j
        //Store all sum pairs in map
        for(int i=0;i<n-1;++i)
            for(int j=i+1;j<n;++j)
                m[nums[i]+nums[j]].push_back(make_pair(i,j));
        
        for(int i=0;i<n-1;++i) {
            if(i>0 and nums[i]==nums[i-1])  continue;
            for(int j=i+1;j<n;++j) {
                if(j>i+1 and nums[j]==nums[j-1])  continue;
                int sum = target-nums[i]-nums[j];
                if(m.find(sum)!=m.end()) {
                    for(auto it: m[sum])    {
                        int k=it.first;
                        int l=it.second;
                        if(k>j) {   //Maintain the increasing order of index (i,j,k,l).....i<j<k<l
                            //Skip invalid cases
                            if(!ans.empty() and ans.back()[0]==nums[i] and ans.back()[1]==nums[j] and ans.back()[2]==nums[k] and ans.back()[3]==nums[l])
                                continue;
                            vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};