#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
bool comp(int a,int b){
    if(mp[a]>mp[b]) return true;
    else{ 
        if(mp[a]==mp[b]){
            if(a<b) return true;
        }
        return false;
    }
}
int main()
 {
     int t;
     cin>>t;
     while(t--){
         mp.clear();
         int n;
         cin>>n;
         int*arr=new int[n];
         for(int i=0;i<n;i++){
             cin>>arr[i];
             mp[arr[i]]++;
         }
         sort(arr,arr+n,comp);
         for(int i=0;i<n;i++) cout<<arr[i]<<" ";
         cout<<endl;
     }
	//code
	return 0;
}
