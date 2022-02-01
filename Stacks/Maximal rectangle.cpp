class Solution {
public:
    
    int helper(vector<int>&h){
        int curr=0;
        int ans=0;
        stack<int>s;
        for(int i=0;i<h.size();i++){
            while(!s.empty() && (h[s.top()])>(h[i])){
                int x = s.top();
                s.pop();
                if(s.empty()) curr=(h[x])*i;
                else curr = (h[x])*(i-(s.top())-1);
                ans=max(ans,curr);
            }
            s.push(i);
        }
        while(!s.empty()){
            int x = s.top();
            s.pop();
            if(s.empty()) curr=(h[x])*h.size();
            else curr=(h[x])*((h.size())-(s.top())-1);
            ans=max(ans,curr);
        }
        return ans;
    }
     int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> h(m);
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')   h[j]++;
                else h[j]=0;
            }
            ans=max(ans,helper(h));
        }
        
        return ans;
    }
};
