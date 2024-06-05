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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        int sum = 0;

        q.push(root);
        q.push(new TreeNode(-1));

        bool isLastLevel = true;


        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val == -1){
                if(q.empty()) break;

                TreeNode* temp = new TreeNode(-1);
                q.push(temp);
                sum = 0;
            }
            else{
                sum += node->val;

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }
            
        }

        return sum;
    }
};