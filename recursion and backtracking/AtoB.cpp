#include <bits/stdc++.h>
using namespace std;
vector<int>v;
bool helper(int a,int b){
    if(a==b){v.push_back(a); return true;}
    if(a>b) return false;
    if(b%10==1){
        if(helper(a,b/10)){
            v.push_back(b);
            return true;
        }
        return false;
    }
    if(b%2==0){
        if(helper(a,b/2)){
            v.push_back(b);
            return true;
        }
    }
    return false;
}
int main()
{
   int a,b;
   cin>>a>>b;
   if(a>b){
       cout<<"No";
       return 0;
   }
   if(helper(a,b)){
       cout<<"YES"<<endl;
       cout<<v.size()<<endl;
      for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
      }
   }else cout<<"NO";
   return 0;
}
