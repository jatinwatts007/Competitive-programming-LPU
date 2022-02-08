#include <bits/stdc++.h>
using namespace std;
int dp[100][100001];
int helper(int * v,int * wt,int value,int i,int n){
    if(i>=n) return 0;
    if(dp[i][value]!=-1) return dp[i][value];
    int ans = helper(v,wt,value,i+1,n);
    if(wt[i]<=value)
        ans = max(ans,helper(v,wt,value-wt[i],i+1,n)+v[i]);
    return dp[i][value] = ans;

}
int main()
{
    int n;
    int value;
    cin>>n>>value;
    int * v = new int [n];
    int * wt = new int [n];
    for(int i=0;i<n;i++){
        cin>>wt[i]>>v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=value;j++) dp[i][j]=-1;
    }
    cout<<helper(v,wt,value,0,n);

   return 0;
}
