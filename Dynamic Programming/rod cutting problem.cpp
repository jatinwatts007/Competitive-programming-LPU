class Solution{
  public:
  int dp[1001];
    int helper(int price[],int length,int n){
        if(length==0) return 0;
        if(dp[length]!=-1) return dp[length];
        int ans=0;
        int x =0;
        for(int i=0;i<length;i++){
            x = price[i]+helper(price,length-(i+1),n);
            ans=max(ans,x);
        }
        return dp[length]=ans;
    }
    int cutRod(int price[], int n) {
        for(int i=0;i<=n;i++) dp[i]=-1;
        return helper(price,n,n);
        
    }
};
