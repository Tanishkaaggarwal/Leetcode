class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            unordered_set<int> distinct_elements;
            for (int j = i; j < n; ++j) {
                distinct_elements.insert(nums[j]);
                int count = distinct_elements.size();
                totalSum += count * count;
            }
        }
        
        return totalSum;
    }
};