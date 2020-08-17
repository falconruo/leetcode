/**
 * 334. Increasing Triplet Subsequence
 * 
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

   Formally the function should:

      Return true if there exists i, j, k
      such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.

   Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

   Example 1:

   Input: [1,2,3,4,5]
   Output: true

   Example 2:

   Input: [5,4,3,2,1]
   Output: false
   */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        // base case: less than 3 elements in array
        if (len < 3) return false;
        
        // m1 = minimal element
        // m2 = second minial element
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        // there are 3 case for any num in nums[i]:
        // 1. num > m2
        // 2. num < m1
        // 3. m1 <= num <= m2
        for (int i = 0; i < len; ++i) {
            if (nums[i] > m2) // found the increasing subsequence
                return true;
            else if (nums[i] < m1)
                m1 = nums[i];
            else if (nums[i] > m1 && nums[i] < m2)
                m2 = nums[i];
        }
        return false;
    }
};
