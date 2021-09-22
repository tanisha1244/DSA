class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int platform[2361] = {0};
    int requiredPlatform = 1;
    for (int i = 0; i < n; i++) {
        ++platform[arr[i]];
 
        --platform[dep[i] + 1];
    }
 

    for (int i = 1; i < 2361; i++) {
 
        platform[i] = platform[i] + platform[i - 1];
        requiredPlatform = max(requiredPlatform, platform[i]);
    }
    return requiredPlatform;
    }
};

//time complexity:O(n);