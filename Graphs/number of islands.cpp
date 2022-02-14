class Solution {
public:
    void dfs(vector<vector<char>>&g,int i,int j){
        g[i][j] = '0';
        if(i-1>=0 && g[i-1][j]=='1') dfs(g,i-1,j);
        if(i+1<g.size() && g[i+1][j]=='1') dfs(g,i+1,j);
        if(j-1>=0 && g[i][j-1]=='1') dfs(g,i,j-1);
        if(j+1<g[0].size() && g[i][j+1]=='1') dfs(g,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};
