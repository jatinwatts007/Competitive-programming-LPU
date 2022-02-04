#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    vector<int>v;
    vector<int>ans;
    for(long long i=0;i<n-1;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    ans.push_back(n);
    ans.push_back(v[v.size()-1]);
    int count=v[v.size()-1];
    while(count>1){    //1 2 3 4 5
        ans.push_back(v[count-2]);
        count=v[count-2];
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
   return 0;
}
