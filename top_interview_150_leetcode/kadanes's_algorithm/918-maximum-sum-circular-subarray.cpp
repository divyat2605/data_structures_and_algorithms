class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum = 0;
        int currmaxsum = 0, currminsum =0;
        int maxsum = nums[0];
        int minsum = nums[0];
        for (int i =0;i<nums.size();i++){
            currmaxsum = max(currmaxsum + nums[i], nums[i]);
            maxsum = max(currmaxsum, maxsum);
            currminsum = min(currminsum+nums[i], nums[i]);
            minsum = min(currminsum,minsum);
            totalsum = totalsum+ nums[i];
        }
        int normalsum = maxsum;
        int circularsum = totalsum -minsum;
        if (minsum == totalsum){
            return normalsum;
        }
        return max(normalsum,circularsum);
    }
};
//o(n) - time
//o(1) - space