vector<string> generate(int N)
{
    vector<string>ans;
    ans.push_back("1");
    queue<string>q;
    q.push("1");
    while(ans.size()<N){
        string k=q.front();
        q.pop();
        ans.push_back(k+'0');
        if(ans.size()==N) break;
        q.push(k+'0');
        q.push(k+'1');
        ans.push_back(k+'1');
    }
    return ans;
    
	// Your code here
}
