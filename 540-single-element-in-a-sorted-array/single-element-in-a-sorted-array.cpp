class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            // mid ^ 1 gives mid+1 if mid is even, and mid-1 if mid is odd.
            // If the pair matches, we are on the correct left side of the single element.
            if (nums[mid] == nums[mid ^ 1]) {
                st = mid + 1;
            } else {
                end = mid; // Single element is at mid or to the left
            }
        }

        return nums[st];
    }
};



//TLE 


// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();

//         if(n == 1) return nums[0];

//         int st = 0, end = n-1;
//         while(st <= end) {
//             int mid = st + (end - st) / 2;

//             if(mid == 0 && nums[0] != nums[1]) return nums[mid];
//             if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[mid];

//             if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];

//             if(mid % 2 == 0) {   //even
//                 if(nums[mid -1] == nums[mid]){ //left
//                         end = mid - 1;
//                 } else {   //right
//                         st = mid + 1;
//                 }
//             } else {   //odd
//                     if(nums[mid-1] == nums[mid]) { // right
//                         st = mid + 1;
//                     }
//             }
//         }
//         return -1;
//     }
// };