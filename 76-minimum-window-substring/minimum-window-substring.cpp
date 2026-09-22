class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || t.size() > s.size())
            return "";

        int freq[128] = {0};

        // Store frequency of characters needed from t
        for (char ch : t) {
            freq[ch]++;
        }

        int left = 0;
        int right = 0;

        int required = t.size();

        int minLength = INT_MAX;
        int startIndex = 0;

        while (right < s.size()) {

            // If this character was required
            if (freq[s[right]] > 0) {
                required--;
            }

            // Decrease frequency because character enters window
            freq[s[right]]--;

            right++;

            // When all characters of t are present
            while (required == 0) {

                // Update minimum window
                if (right - left < minLength) {
                    minLength = right - left;
                    startIndex = left;
                }

                // Remove left character from window
                freq[s[left]]++;

                // If removing it makes a required character missing
                if (freq[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX)
            return "";

        return s.substr(startIndex, minLength);
    }
};