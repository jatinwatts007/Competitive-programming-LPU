#include <bits/stdc++.h>
using namespace std;
bool comp(pair<string,int>p1,pair<string,int>p2){
    return p1.second > p2.second;
}
int main()
{
    int n,m;
    cin>>n>>m;
   vector<vector<pair<string,int>>>v(m+1);
    for(int i=0;i<n;i++){
        string k;
        cin>>k;
        int index,value;
        cin>>index>>value;
        v[index].push_back({k,value});
    }
    for(int i=1;i<=m;i++)
    sort(v[i].begin(),v[i].end(),comp);
    for(int i=1;i<=m;i++){
        if(v[i].size()==2){
            cout<<v[i][0].first<<" "<<v[i][1].first<<endl;
        }else if(v[i][1].second==v[i][2].second) cout<<"?"<<endl;
        else cout<<v[i][0].first<<" "<<v[i][1].first<<endl;
    }
   return 0;
}
