bool compare(vector<int>v1,vector<int>v2){
    if(v1[0]<v2[0]) return true;
    return false;
}

int knapsack(vector<vectot<int>>v,int A){
    sort(v.begin(),v.end(),compare);
    for(int i=1;i<v.size();i++){
        v[i][1]=v[i][1]+v[i-1][1];
    }
    int ans=0;
    for(int i=0;i<v.size();i++){
        if(i==0){
            ans=v[i][1];
        }else{
            int max1=b[i][1];
            for(int j=i-1;j>=0;j--){
                if(v[j][0]>(v[i][0]-A)){
                    max1 = max1-v[j][0];
                    break;
                }
            }
            ans=max(max1,ans);
        }
    }
    return ans;
}
