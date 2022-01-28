class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int,int>umap;
        int sum=0;
        for(int i=0;i<a.size();i++){
            umap[a[i]]++;
        }
        for(auto i=umap.begin();i!=umap.end();i++){
            sum+=ceil(ceil(i->second)/ceil(i->first+1))*(i->first+1);
        }
        return sum;
    }
};
