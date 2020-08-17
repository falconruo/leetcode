/**
 * 442. Find All Duplicates in an Array
 * 
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

   Find all the elements that appear twice in this array.

   Could you do it without extra space and in O(n) runtime?

   Example:

   Input:
   [4,3,2,7,8,2,3,1]

   Output:
   [2,3]
   */

/**
 * 28 / 28 test cases passed.
	Status: Accepted
   Runtime: 100 ms, Your runtime beats 97.74 % of cpp submissions.
   Memory Usage: 33.6 MB, Your memory usage beats 91.01 % of cpp submissions.

*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return nums;
        vector<int> ans;

        // set the element to its negative value ( n * -1) if scaned 
        for (int i = 0; i < len; ++i) {
            int n = nums[i];
            if (nums[abs(n) - 1] < 0)
                ans.push_back(abs(n));
            else
                nums[abs(n) - 1] *= -1;
        }
        return ans;
    }
};
