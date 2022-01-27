#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long sum=0;
    for(long long i=0;i<n;i++){
        sum=sum+(arr[i]*i)-(arr[i]*((n-i)-1));
    }
    cout<<sum<<endl;
   return 0;
}
