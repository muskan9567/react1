class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 0);
        int leftSum = 0;
        int rightSum = 0;

        for (int x : nums) {
            rightSum += x;
        }

        for (int i = 0; i < n; i++) {
            rightSum -= nums[i];
            ans[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }

        return ans;
    }
};