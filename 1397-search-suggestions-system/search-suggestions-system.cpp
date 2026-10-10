//Approach (Since, contraints are low, you can apply Binary Search (Lower bound))
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        int n = products.size();
        sort(begin(products), end(products));
        
        string prefix = "";
        for (char &ch : searchWord) {
            prefix.push_back(ch);
            
            // Search across the entire sorted array using binary search
            int start = lower_bound(products.begin(), products.end(), prefix) - products.begin();
            
            result.push_back({});
            
            for (int i = start; i < min(start + 3, n); i++) {
                // Ensure the product actually STARTS with the prefix
                if (products[i].rfind(prefix, 0) == 0) {
                    result.back().push_back(products[i]);
                } else {
                    break; // Stop once a product doesn't start with the prefix
                }
            }
        }
        
        return result;
    }
};