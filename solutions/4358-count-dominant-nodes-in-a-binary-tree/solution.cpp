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
    int solve(TreeNode* root,int &count){
        if(!root){
            return 0;
        }
        // if(!root->left && !root->right){
        //     count++;
        //     return root->val;
        // }

        int maxi = max(solve(root->left,count),solve(root->right,count));

        if(root->val >= maxi){
            maxi = root->val;
            count++;
        }
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        int count = 0;
        solve(root,count);
        return count;
    }
};
