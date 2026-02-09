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
    void inorder(TreeNode* root,vector<int>& order){
        if(!root)return;
        inorder(root->left,order);
        order.push_back(root->val);
        inorder(root->right,order);
    }
    TreeNode* build(vector<int>& order,int low,int high){
        if(low > high)return nullptr;
        int mid = (high+low)/2;
        TreeNode* node = new TreeNode(order[mid]);
        node->left = build(order,low,mid-1);
        node->right = build(order,mid+1,high);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> order;
        inorder(root,order);
        return build(order,0,order.size()-1); 
    }
};
