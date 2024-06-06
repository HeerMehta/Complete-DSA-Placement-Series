class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<int> degree(n, 0);
        vector<vector<int>> graph(n);

        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> leaves;

        for(int i=0; i<n; i++){
            if(degree[i] == 1) leaves.push(i);
        }

        int currentNodes = n;

        while(currentNodes > 2){
            int leafCount = leaves.size();
            currentNodes -= leafCount;

            for(int i=0; i<leafCount; i++){
                int leaf = leaves.front();
                leaves.pop();

                for(auto node: graph[leaf]){
                    if(--degree[node] == 1) leaves.push(node);
                }
            }
        }

        vector<int> ans;

        while(!leaves.empty()){
            ans.push_back(leaves.front());
            leaves.pop();
        }

        return ans;
    }
};