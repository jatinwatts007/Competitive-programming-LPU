class Solution {
public:
    int binary(vector<int>&arr,int l,int r,int x){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid]==x) return mid;
            else if(arr[mid]>x) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        if(arr.size()==1){
            if(arr[0]==target) return 0;
            else return -1;
        } 
       int l=0;
        int r=arr.size()-1;
        int index=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(mid==0 && arr[mid]>arr[mid+1]){
                index=mid;
                break;
            }
            else if(mid==arr.size()-1 && arr[mid]>arr[0]) {
                index=mid;
                break;
            }
            else if(mid==0 && arr[mid]<arr[mid+1])l=mid+1;
            else if(mid == arr.size()-1 && arr[mid]<arr[0]) r=mid-1;
            else if(arr[mid]>arr[mid-1] && arr[mid]>arr[(mid+1)]){
                index=mid;
                break;
            }
            else if(arr[mid]<arr[l])r=mid-1;
            else l=mid+1;
            
            
        }
        if(target>=arr[0] && arr[index]>=target) return binary(arr,0,index,target);
        else return binary(arr,index+1,arr.size()-1,target);
    }
};
