class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        int low = 0;
        int high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Map 1D index 'mid' back to 2D matrix coordinates (row, col)
            int r = mid / n;
            int c = mid % n;

            if (mat[r][c] == target) {
                return true;
            } else if (mat[r][c] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};

