class Solution {
public:
    bool row(vector<vector<char>>&b,int i,int j,char value){
        for(int k=0;k<9;k++){
            if( k!=j && b[i][k]==value) return false;
        }
      //  cout<<"k"<<" ";
        return true;
    }
    bool col(vector<vector<char>>&b,int i,int j,char value){
        for(int k=0;k<9;k++){
            if(k!=i && b[k][j]==value) return false;
        }
      //  cout<<"i"<<" ";
        return true;
    }
    bool box(vector<vector<char>>&b,int i,int j,char value){
        int m=(i/3)*3;
        int n=(j/3)*3;
        for(int k=m;k<m+3;k++){
            for(int l=n;l<n+3;l++){
                if(k!=i && l!=j && b[k][l]==value) return false;
            }
        }
       // cout<<"l"<<" ";
        return true;
    }
    
    bool helper(vector<vector<char>>&b,int i,int j){
        if(i==8 && j==8){
            if(b[i][j]!='.') return true;
            for(int k=1;k<=9;k++){
               b[i][j]=k+'0';
                if(row(b,i,j,b[i][j]) && col(b,i,j,b[i][j]) && box(b,i,j,b[i][j])){
                    return true;
                }
            }
            b[i][j]='.';
            return false;
        }
        if(b[i][j]!='.') return helper(b,i+((j+1)/9),(j+1)%9);
        for(int k=1;k<=9;k++){
            bool check=false;
            if(row(b,i,j,k+'0') && col(b,i,j,k+'0') && box(b,i,j,k+'0')){
                b[i][j]=k+'0';
                check = helper(b,i+((j+1)/9),(j+1)%9);
            }
            if(check) return true;
            else b[i][j]='.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0); 
    }
};
