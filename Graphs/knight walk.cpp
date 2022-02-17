class Solution {
public:
	int minStepToReachTarget(vector<int>&pos, vector<int>&pos1, int N){
	    // Code here
	    
	    queue<vector<int>>q;
	    pos.push_back(0);
	    q.push(pos);
	    vector<int>row(N+1,0);
	    vector<vector<int>>board(N+1,row);
	    int ans=INT_MAX;
	    while(!q.empty()){
	        auto pos2 = q.front();
	        q.pop();
	        if(pos1[0]==pos2[0] && pos1[1]==pos2[1]) return pos2[2];
	        if(pos2[0]+2<=N && pos2[1]+1<=N && board[pos2[0]+2][pos2[1]+1]==0){
	            board[pos2[0]+2][pos2[1]+1]=1;
	            vector<int>temp{pos2[0]+2,pos2[1]+1,pos2[2]+1};
	            q.push(temp);
	        }
	        if(pos2[0]+2<=N && pos2[1]-1>=0 && board[pos2[0]+2][pos2[1]-1]==0){
	            board[pos2[0]+2][pos2[1]-1]=1;
	            vector<int>temp{pos2[0]+2,pos2[1]-1,pos2[2]+1};
	            q.push(temp);
	        }
	        if(pos2[0]-2>=0 && pos2[1]+1<=N && board[pos2[0]-2][pos2[1]+1]==0){
	            board[pos2[0]-2][pos2[1]+1]=1;
	            vector<int>temp{pos2[0]-2,pos2[1]+1,pos2[2]+1};
	            q.push(temp);
	        }
	        if(pos2[0]-2>=0 && pos2[1]-1>=0 && board[pos2[0]-2][pos2[1]-1]==0){
	            board[pos2[0]-2][pos2[1]-1]=1;
	            vector<int>temp{pos2[0]-2,pos2[1]-1,pos2[2]+1};
	            q.push(temp);
	        }
	        if(pos2[0]+1<=N && pos2[1]+2<=N && board[pos2[0]+1][pos2[1]+2]==0){
	            board[pos2[0]+1][pos2[1]+2]=1;
	            vector<int>temp{pos2[0]+1,pos2[1]+2,pos2[2]+1};
	            q.push(temp);
	        }
	        if(pos2[0]-1>=0 && pos2[1]+2<=N &&  board[pos2[0]-1][pos2[1]+2]==0){
	            board[pos2[0]-1][pos2[1]+2]=1;
	            vector<int>temp{pos2[0]-1,pos2[1]+2,pos2[2]+1};
	            q.push(temp);
	        }
	        if(pos2[0]+1<=N && pos2[1]-2>=0 && board[pos2[0]+1][pos2[1]-2]==0){
	            board[pos2[0]+1][pos2[1]-2]=1;
	            vector<int>temp{pos2[0]+1,pos2[1]-2,pos2[2]+1};
	            q.push(temp);
	        }
	        if(pos2[0]-1>=0 && pos2[1]-2>=0 && board[pos2[0]-1][pos2[1]-2]==0){
	            board[pos2[0]-1][pos2[1]-2]=1;
	            vector<int>temp{pos2[0]-1,pos2[1]-2,pos2[2]+1};
	            q.push(temp);
	        }
	    }
	    return ans;
	}
};
