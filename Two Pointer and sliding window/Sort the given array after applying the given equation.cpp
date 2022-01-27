long long solver(long long a,long long b,long long c,long long x){
    return (a*(x*x))+(b*x)+c;}

vector<long long> sortArray(vector<long long>arr, int n, long long A, long long B, long long C){
    //complete the function here
    vector<long long>ans(n,0);
    long long idx=n-1;
    long long i=0,j=n-1;
    if(A>=0){
        while(i<=j){
            long long x = solver(A,B,C,arr[i]);
            long long y = solver(A,B,C,arr[j]);
            if(x>y) {ans[idx]=x;i++;idx--;}
            else {ans[idx]=y,j--;idx--;}
        }
    }else{
        idx=0;
       while(i<=j){
            long long x = solver(A,B,C,arr[i]);
            long long y = solver(A,B,C,arr[j]);
            if(x>y) {ans[idx]=y;j--;idx++;}
            else {ans[idx]=x,i++;idx++;}
        } 
    }
    return ans;
}
