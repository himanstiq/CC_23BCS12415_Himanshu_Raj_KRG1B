class Solution3 {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> next;
        for (int i = 0; i < nums.size()-1; i++)
            next.push_back((nums[i] + nums[i+1]) % 10);
        return triangularSum(next);
    }
};
