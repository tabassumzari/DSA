class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, longest = 0;

        for (int num : nums) {
            if (num == 1) {
                count++;
                longest = max(longest, count);
            } else {
                count = 0;
            }
        }

        return longest;
    }
};