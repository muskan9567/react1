class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        

        int curr = 0;
        int sum = accumulate(begin(nums),end(nums), 0);
        int n = nums.size();
        vector<int>result(n);

        for(int i=0; i<n; i++){
            int leftsum = curr;
            curr+=nums[i];

            int rightsum = sum-curr;
            result[i]=abs(rightsum-leftsum);

        }
        return result;
    }
};