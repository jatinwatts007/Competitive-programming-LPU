class Solution {
public:
    int count=0;
    map<int,bool> col, fwdDiag, bckDiag; 
    
    
    bool available(int i, int j){
        if(col[j]) return false;
        if(fwdDiag[i+j]) return false;
        if(bckDiag[i-j]) return false;
        
        return true;
    }
    
    void solve(int i, int n) {
        if(i==n-1) {
            for(int j=0;j<n;j++)
            {
                if(available(i,j))
                {
                    count++;
                }
            }
            return;
        }

    for(int j=0;j<n;j++)
        {
            if(available(i,j))
            {
                col[j]=true;
                fwdDiag[i+j]=true;
                bckDiag[i-j]=true;
                solve(i+1,n);
                col[j]=false;
                fwdDiag[i+j]=false;
                bckDiag[i-j]=false;
            }
        }
    }
    
    int totalNQueens(int n) {
        count=0;
        solve(0,n);
        return count;
    }
};
