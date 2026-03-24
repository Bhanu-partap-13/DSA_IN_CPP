#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int<int>> ans;
        if(!root) return ans;
        bool lefttoRight = true;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level(n);
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                int index = lefttoRight > i : n-1-i;

                level[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lefttoRight = !lefttoRight;
            ans.push_back(level);
        }
}
};