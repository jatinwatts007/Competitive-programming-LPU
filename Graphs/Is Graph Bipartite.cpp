class Solution {
public:
    
    bool dfs(int node,vector<int>&filler,int color,vector<vector<int>>&graph){
        if(filler[node]!=0 && filler[node]!=color) return false;
        filler[node]=color;
        int fill = color==1?2:1;
        bool temp=true;
        for(int i=0;i<graph[node].size();i++){
            if(filler[graph[node][i]]==fill) continue;
            else if(filler[graph[node][i]]!=0 && filler[graph[node][i]]!=fill) return false;
            else filler[graph[node][i]]=fill;
            temp=dfs(graph[node][i],filler,fill,graph);
            if(temp==false) return temp;
         }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>filler(graph.size(),0);
        bool ans=true;
        for(int i=0;i<graph.size();i++){
            if(filler[i]==0) 
                ans = ans && dfs(i,filler,1,graph);
        }
        for(int i=0;i<filler.size();i++) cout<<filler[i]<<" ";
        cout<<endl;
        return ans;
    }
};
