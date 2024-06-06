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
    vector<TreeNode*> solve(int l, int r){
        vector<TreeNode*> ans;
        if(l > r){
            ans.push_back(NULL);
            return ans;
        }

        

        for(int i=l; i<=r; i++){
            vector<TreeNode*> leftSubtrees = solve(l, i-1);
            vector<TreeNode*> rightSubtrees = solve(i+1, r);

            for(int j=0; j<leftSubtrees.size(); j++){
                for(int k=0; k<rightSubtrees.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSubtrees[j];
                    root->right = rightSubtrees[k];
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }


    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};