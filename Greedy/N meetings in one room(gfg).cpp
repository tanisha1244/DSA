class Solution{ 
    public:
   
    int maxMeetings(int s[], int f[], int n)
    {
        // Your code here
        vector<vector<int>>meet;
    for (int i = 0; i < n; i++)
    {
        vector<int>l(3);
        l[0]=f[i];
        l[1]=s[i];
        l[2]=i+1;
        meet.push_back(l);
    }
    sort(meet.begin(),meet.end());
    int c=1;
    int t=meet[0][0];
    for (int i = 1; i < n; i++) {
        if (meet[i][1] >t)
        {
           c++;
           t=meet[i][0];
        }
    }
 
    return c;
    }
};
