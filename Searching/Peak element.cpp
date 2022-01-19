class Solution {
public:
    
    int findPeakElement(vector<int>& arr) {
        if(arr.size()==1) return 0;
        int l=0,r = arr.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(mid==0 && arr[mid]>arr[mid+1]) return mid;
            else if((mid==arr.size()-1) && arr[mid]>arr[mid-1]) return mid;
            else if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;
            else if(arr[mid]<arr[mid+1]) l=mid+1;
            else r=mid-1;
        }
        return -1;
        
    }
};
