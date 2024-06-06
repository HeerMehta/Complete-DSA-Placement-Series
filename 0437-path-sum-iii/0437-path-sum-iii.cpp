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
    unordered_map<long, int> mp;
    int count = 0;

    void calculateSum(TreeNode* node, int targetSum, long sum){
        if(node == NULL) return;

        sum += node->val;

        if(sum == targetSum) count++;

        if(mp.find(sum-targetSum) != mp.end()){
            count += mp[sum - targetSum];
        } 

        mp[sum]++;

        calculateSum(node->left, targetSum, sum);
        calculateSum(node->right, targetSum, sum);

        mp[sum]--;

    }


    int pathSum(TreeNode* root, int targetSum) {
        calculateSum(root, targetSum, 0);

        return count;
    }
};