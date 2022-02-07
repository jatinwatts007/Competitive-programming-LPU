class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>v;
        while(n>0){
            v.push_back(n%10);
            n/=10;
        }
        int size = v.size();
        reverse(v.begin(),v.end());
        int i,j;
        for(i=size-2;i>=0;i--){
            if(v[i]<v[i+1]) break;
        }
        if(i<0) return -1;
        for(j=size-1;j>i;j--){
            if(v[j]>v[i]) break;
        }
        swap(v[i],v[j]);
        reverse(v.begin()+(i+1),v.end());
        n=0;
        for(int i=0;i<size;i++){
            if(i==size-1 && n>214748364) return -1;
            if(i==size-1 && n==214748364 && v[size-1]>7) return -1;
            n*=10;
            n+=v[i];
        }
        return n;
    }
};
