//Aproach-1 (Using counter only)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {
        int n = stud.size();
        int arr[2] = {0};
        //arr[0] = count of student who like circular
        //arr[1] = count of student who like square
          
        for(int &x : stud)
            arr[x]++;
        
        for(int i = 0; i<n; i++) {
            if(arr[sand[i]] == 0) return n-i;
            arr[sand[i]]--;
        }
        
        return 0;
    }
};