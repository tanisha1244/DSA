class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int target2 = target - (nums[i]+nums[j]);
                
                int start = j+1;
                int end = n-1;
                while(start<end)
                {
                    int sum2 = nums[start] + nums[end];
                    if(sum2<target2) start++;
                    
                    else if(sum2>target2) end--;
                    
                    else
                    {
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[start];
                        quad[3] = nums[end];
                        res.push_back(quad);
                        
                        while(start<end && nums[start]==quad[2]) start++;
                        
                        while(end>start && nums[end]==quad[3]) end--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) j++;
                
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};