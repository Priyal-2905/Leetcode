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
    
    void flatten(TreeNode* root) {
        if(root == nullptr){return;}

        queue<TreeNode*> q;
        preorder(root,q);
        q.pop();

        while(!q.empty()){
            root->right = q.front();
            root->left = nullptr;
            q.pop();
            root = root->right;
        }
        
    }
    void preorder(TreeNode* root,queue<TreeNode *> &q){
        if(root == nullptr){return;}
        q.push(root);
        preorder(root->left,q);
        preorder(root->right,q);
    }
};
