#include<bits/stdc++.h>
using namespace std;
int main(){
     int t;
     cin>>t;
     while(t--){
      int n;
      cin>>n;
      string s;
      cin>>s;
      int bal=0;
      int ans=0;
      for(int i=0;i<s.length();i++)
       {
         if(s[i]=='('){bal++;}
         else{bal--;}
          if(bal<0){bal=0;
                    ++ans;}
         }
       cout<<ans<<endl;
   }
 return 0;
}
          