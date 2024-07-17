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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};

        map<int, map<int, vector<int>>> mp;
        queue<pair<pair<int, int>, TreeNode*>> q;

        q.push({{0, 0}, root});

        while(!q.empty()){
            int level = q.front().first.first;
            int vertical = q.front().first.second;

            TreeNode* node = q.front().second;

            q.pop();

            mp[vertical][level].push_back(node->val);

            if(node->left) q.push({{level+1, vertical-1}, node->left});
            if(node->right) q.push({{level+1, vertical+1}, node->right});
        }

        vector<vector<int>> ans;

        for(auto it1 = mp.begin(); it1 != mp.end(); it1++){
            vector<int> temp;
            for(auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++){
                sort(it2->second.begin(), it2->second.end());

                for(int i=0; i<it2->second.size(); i++){
                    temp.push_back(it2->second[i]);
                }
            }

            ans.push_back(temp);
        }

        return ans;

    }
};