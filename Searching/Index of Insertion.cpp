#include <iostream>
using namespace std;
int binarySearch(int * arr, int l, int r, int x,int n)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
	if(mid-1>=0 && arr[mid]>x && arr[mid-1]<x) return mid;
	if(mid==n && arr[mid]<x) return mid+1;
	if(mid==0 && arr[mid]>x) return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x,n);
        return binarySearch(arr, mid + 1, r, x,n);
    }
    return -1;
}
int main() {
    // your code goes her
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int t;
	cin>>t;
	while(t--){
		int value;
		cin>>value;
		cout<<binarySearch(arr,0,n-1,value,n-1)<<endl;
	}
    return 0;
}
