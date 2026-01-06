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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        int res = 0,maxi = INT_MIN,level = 1;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int curr_sum = 0;

            for(int i = 0;i < size;i++){
                TreeNode *t = q.front();
                curr_sum += t->val;
                q.pop();

                if(t->left)
                    q.push(t->left);
                
                if(t->right)
                    q.push(t->right);
            }

            if(curr_sum > maxi){
                maxi = curr_sum;
                res = level;
            }
            level++;
        }
        return res;
    }
};
