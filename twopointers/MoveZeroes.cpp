/* Two Pointers Question.
	Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
	Note that you must do this in-place without making a copy of the array.
	Input: nums = [0,1,0,3,12]
	Output: [1,3,12,0,0]
*/
// My Solution.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (l < r){
            if (nums[l] != 0){
                l++;
            }
            else{
                int k = l;
                while (k < r){
                    nums[k] = nums[k+1];
                    k++;
                }
                nums[r] = 0;
                r--;
            }
        }
    }
};


/*  Simple Solution :-
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
            }
        }        
    }
}; */
