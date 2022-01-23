#include <bits/stdc++.h>
using namespace std;
int helper(int *arr,int value,int n){
    int i=0,j=n-1;
    int count=0;
    while(i<j){
        if(arr[i]+arr[j]==value){
            count++;
            i++;
            j--;
        }
        else if(arr[i]+arr[j]>value) j--;
        else i++;
    }
    return count;
}
int main()
{
   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       int * arr = new int[n];
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       sort(arr,arr+n);
       int ans=0;
       for(int i=1;i<=100;i++){
           int temp = helper(arr,i,n);
           if(temp>ans) ans=temp;
       }
       cout<<ans<<endl;
   }
   return 0;
}
