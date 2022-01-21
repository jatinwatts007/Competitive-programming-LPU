class Solution {
public:
    bool pal(string s){
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true; 
    }
    void helper(vector<vector<string>>&ans,vector<string>&v,string s,string k,int n){
        if(n>=s.length()){
            ans.push_back(v);
            return ;
        }
        for(int i=n;i<s.length();i++){
            k+=s[i];
            if(pal(k)){
                v.push_back(k);
                helper(ans,v,s,"",i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        helper(ans,v,s,"",0);
        return ans;
    }
};
