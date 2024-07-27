class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k == 0)
            return {};
        vector<int> result;
        priority_queue<pair<int, int>>
            maxHeap; // Max-heap to store the elements and their indices

        for (int i = 0; i < nums.size(); ++i) {
            maxHeap.push({nums[i], i});

            // Remove elements that are outside the current window
            while (maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }

            // Record the maximum of the current window
            if (i >= k - 1) {
                result.push_back(maxHeap.top().first);
            }
        }

        return result;
    }
};