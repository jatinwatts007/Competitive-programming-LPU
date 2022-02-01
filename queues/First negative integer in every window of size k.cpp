vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    vector<long long>ans;
    queue<long long int>q;
    for(int i=0;i<K;i++){
        if(A[i]<0) q.push(A[i]);
    }
    for(long long int i=0;i+K<=N;i++){
        if(q.empty()) ans.push_back(0);
        else ans.push_back(q.front());
        if(A[i]==q.front())q.pop();
        if(i+K<N && A[i+K]<0) q.push(A[i+K]);
        
        
    }
    return ans;
                                                 
 }
