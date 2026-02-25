#include<bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool calculate(TreeNode* root, long long l, long long r){
        if(!root) return true;
        if(root->val < r && root->val > l){
         return calculate(root->left, l, root->val) &&
          calculate(root->right, root->val, r);
        }
    return false;
    }
    bool isValidBST(TreeNode* root) { 
        long long min=LLONG_MIN;
        long long max=LLONG_MAX;  
        return calculate(root, min, max);
    }
};
int main(){
    return 0;
}