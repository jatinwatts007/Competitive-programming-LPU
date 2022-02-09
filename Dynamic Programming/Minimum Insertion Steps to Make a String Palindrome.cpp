class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        string b=s;
        reverse(b.begin(),b.end());
        
        int t[n+1][n+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0||j==0)
                    t[i][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s[i-1]==b[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);

            }
        }
        
        return (s.size()-t[n][n]);
        
    }
};




class Solution {
public:
    int dp[501][501];
    int helper(string s, string k,int i,int j){
        if(i>=s.length() || j>=s.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=-1;
        if(s[i]==k[j]){
            ans=1+helper(s,k,i+1,j+1);
        }else ans = max(helper(s,k,i+1,j),helper(s,k,i,j+1));
        return dp[i][j]=ans;
    }
    int minInsertions(string s) {
       string k ="";
        for(int i=0;i<s.length();i++){
            k+=s[i];
        }
        reverse(k.begin(),k.end());
        for(int i=0;i<=s.length();i++){
            for(int j=0;j<=s.length();j++)
                dp[i][j]=-1;
        }
        int x = helper(s,k,0,0);
        return s.length()-x;
    }
};
