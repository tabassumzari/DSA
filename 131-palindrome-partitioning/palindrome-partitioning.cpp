// class Solution {
// public:
//     int n;
    
//     bool isPalindrome(string &s, int l, int r) {
        
//         while(l < r) {
//             if(s[l] != s[r])
//                 return false;
//             l++;
//             r--;
//         }
        
//         return true;
        
//     }
    
//     void backtrack(string &s, int idx, vector<string> curr, vector<vector<string>> &result) {
        
//         if(idx == n) {
//             result.push_back(curr);
//             return;
//         }
        
        
//         for(int i = idx; i<n; i++) {
            
//             if(isPalindrome(s, idx, i)) {
                
//                 curr.push_back(s.substr(idx, i-idx+1));
                
//                 backtrack(s, i+1, curr, result);
                
//                 curr.pop_back();
                
//             }
            
//         }
        
//     }
    
//     vector<vector<string>> partition(string s) {
//         n = s.length();
//         vector<vector<string>> result;
//         vector<string> curr;
        
//         backtrack(s, 0, curr, result);
        
//         return result;
        
//     }
// };



//AC
class Solution{
public:
    bool isPalin(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2; 
    }

    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans){
        if(s.size()==0){
            ans.push_back(partitions);
            return;
        }

        for(int i=0; i<s.size(); i++) {
            string part = s.substr(0, i+1);

            if(isPalin(part)) { 
                partitions.push_back(part);
                getAllParts(s.substr(i+1), partitions, ans);
                partitions.pop_back();
            }

        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s,partitions,ans);
        return ans;
    }
};