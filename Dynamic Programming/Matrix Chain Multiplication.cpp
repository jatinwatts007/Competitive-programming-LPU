class Solution{
public:
    int dp[101][101];
    int helper(int arr[],int i,int j){
        if(i==j-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j-1;k++){
            int x = helper(arr,i,k+1)+helper(arr,k+1,j)+(arr[i]*arr[k+1]*arr[j]);
            ans=min(ans,x);
        }
        
        return dp[i][j]=ans;
        
        
    }
    int matrixMultiplication(int N, int arr[])
    {
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++) dp[i][j]=-1;
        }
        return helper(arr,0,N-1);
        // code here
    }
};
