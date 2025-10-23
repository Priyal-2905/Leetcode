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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){return {};}
        queue<TreeNode *> q;
        vector<vector<int>> res;

        q.push(root);
        
        while(q.empty() == false){
            int count = q.size();
            vector<int> temp;

            for(int i = 0;i < count;i++){
                TreeNode* curr =  q.front();
                temp.push_back(curr->val);
                q.pop();

                if(curr->left != nullptr){ q.push(curr->left); }
                if(curr->right != nullptr){ q.push(curr->right); } 
                
            }
            res.push_back(temp);
        }
        return res;
    }
};
