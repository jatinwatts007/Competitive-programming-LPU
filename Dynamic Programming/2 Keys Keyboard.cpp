class Solution {
public:
    int dp[1001][1001];
    int helper(int n,int x,bool copy,int copied){
        if(x>n) return INT_MAX-100;
        if(x==n) return dp[x][copy]=0;
        if(dp[x][copied]!=-1) return dp[x][copy];
        int ans=INT_MAX;
        if(!copy){
            int l = helper(n,2*x,false,0);
            int y = helper(n,2*x,true,x);
            ans=2+min(l,y);
        }else{
            int z = 1 + helper(n,copied+x,true,copied);
            int m = 1+ helper(n,copied+x,false,0);
            ans=min(ans,min(z,m));
        }
        return dp[x][copied]=ans;
    }
    int minSteps(int n) {
        if(n==1) return 0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
            dp[i][j]=-1;
        }
        return helper(n,1,false,0);
    }
};
