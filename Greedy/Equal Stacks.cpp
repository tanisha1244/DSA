int equalStacks(vector<int> stk1, vector<int> stk2, vector<int> stk3) {
     int s1=0,s2=0,s3=0;
    for(int i=0;i<stk1.size();i++)
    {
        s1=s1+stk1[i];
    }
     for(int i=0;i<stk2.size();i++)
    {
        s2+=stk2[i];
    }
     for(int i=0;i<stk3.size();i++)
    {
        s3+=stk3[i];
    }
    int t1=0,t2=0,t3=0;
    while(1)
    {
        if(t1==stk1.size()||t2==stk2.size()||t3==stk3.size())
        {
            return 0;
        }
        if(s1==s2&&s2==s3)
        {
            return s3;
        }
        if(s1>=s2&&s1>=s3)
        {
            s1-=stk1[t1++];
        }
        else if(s2>=s1&&s2>=s3)
        {
            s2-=stk2[t2++];
        }
        else if(s3>=s1&&s3>=s2)
        {
            s3-=stk3[t3++];
        }
    }

}