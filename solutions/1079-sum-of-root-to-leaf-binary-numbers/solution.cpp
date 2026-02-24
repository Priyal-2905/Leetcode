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
    int binaryToInt(vector<int>& binary){
        int res = 0;
        for(int b : binary){
            res = res*2 + b;
        }
        return res;
    }

    void preorder(vector<int>& curr, TreeNode* root, int& res){
        if(!root) return;

        curr.push_back(root->val);

        if(!root->left && !root->right){
            res += binaryToInt(curr);
        } else {
            preorder(curr,root->left,res);
            preorder(curr,root->right,res);
        }

        curr.pop_back();
    }

    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        vector<int> curr;
        preorder(curr,root,res);
        return res;
    }
};
