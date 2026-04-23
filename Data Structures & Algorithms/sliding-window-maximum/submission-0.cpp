class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            heap.push({nums[i], i});
            // cout << heap.top().first << endl; 
            if (heap.size() >= k) {
                while (!heap.empty() && heap.top().second < (i+1 - k)) {
                    cout << i << " - " << k << " = " << i+1 - k  << endl;
                    cout << "Heap top: " << heap.top().first << " " << heap.top().second << endl;    
                    heap.pop();
                }
                res.push_back(heap.top().first);
            }
        }

        return res;
    }
};
