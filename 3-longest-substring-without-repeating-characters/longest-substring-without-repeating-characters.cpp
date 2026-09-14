class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Map to store the last seen index of each character
        vector<int> lastPos(256, -1);
        
        int maxLength = 0;
        int left = 0; // Left boundary of the sliding window

        for (int right = 0; right < s.length(); right++) {
            char currChar = s[right];

            // If character was seen inside current window, jump left boundary
            if (lastPos[currChar] >= left) {
                left = lastPos[currChar] + 1;
            }

            // Update last seen position of current character
            lastPos[currChar] = right;

            // Calculate current window length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};