class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int max_needed=1;
    	int required=1;
    	int i=1,j=0;
    	while(i<n&&j<n)
    	{
    	    if(arr[i]>dep[j])
    	    {
    	        j++;
    	        max_needed--;
    	    }
    	    else if(arr[i]<=dep[j])
    	    {
    	        i++;
    	        max_needed++;
    	    }
    	    required=max(max_needed,required);
    	}
    	return required;
    }
};
//time complexity:O(nlogn)+O(n)
  Space :O(1)