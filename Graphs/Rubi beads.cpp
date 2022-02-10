#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>>&v,vector<bool>&vis,int start,int n,int count){
    if(count==n){
        
        return start;
    }
    for(int i=0;i<v[start].size();i++){
        if(!vis[v[start][i]]){
            vis[v[start][i]]=true;
            
            count = dfs(v,vis,v[start][i],n,count+1);
        }
    }
    return count;
    
}
int main()
{
    int t,n;
    cin>>t>>n;
    vector<vector<int>>v(t+1);
    int start=-1;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(start==-1) start=x;
        v[x].push_back(y);
    }
    vector<bool>vis(t+1,false);
    vis[start] = true;
    cout<<dfs(v,vis,start,t,1);
    
    return 0;

}
