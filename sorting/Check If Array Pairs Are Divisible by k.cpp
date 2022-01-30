class Solution {
public:
    bool canArrange(vector<int>& arr, int k) { 
        unordered_map<int,int>umap;
        for(int i=0;i<arr.size();i++){
            umap[((arr[i]%k)+k)%k]++;
        }
        if(umap[0]%2) return false;
        if(k%2==0 && umap[k/2]%2) return false;
        for(auto i=1;i<k;i++){
            if(umap[i]!=umap[k-i]) return false;
        }
        return true;
    }
};
