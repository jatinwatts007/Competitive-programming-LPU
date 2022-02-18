/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(map<pair<int,int>,vector<int>>&mp,TreeNode* root,int i,int j){
        if(root==NULL) return;
        pair<int,int>p;
        p.first=i;
        p.second=j;
        mp[p].push_back(root->val);
        helper(mp,root->left,i-1,j+1);
        helper(mp,root->right,i+1,j+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,vector<int>>mp;
        helper(mp,root,0,0);
        vector<vector<int>>v;
        for(auto i=mp.begin();i!=mp.end();){
            int x = i->first.first;
            vector<int>v1;
            while(i->first.first==x){
                sort(i->second.begin(),i->second.end());
                for(int j=0;j<i->second.size();j++)v1.push_back(i->second[j]);
                i++;
            }
            v.push_back(v1);
        }
        return v;
    }
};
