/**
 * 61. Rotate List
 * 
 * Medium
 * 
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.

   Example 1:

   Input: 1->2->3->4->5->NULL, k = 2
   Output: 4->5->1->2->3->NULL
   Explanation:
   rotate 1 steps to the right: 5->1->2->3->4->NULL
   rotate 2 steps to the right: 4->5->1->2->3->NULL

   Example 2:

   Input: 0->1->2->NULL, k = 4
   Output: 2->0->1->NULL
   Explanation:
   rotate 1 steps to the right: 2->0->1->NULL
   rotate 2 steps to the right: 1->2->0->NULL
   rotate 3 steps to the right: 0->1->2->NULL
   rotate 4 steps to the right: 2->0->1->NULL
 */

/**
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 * 
 * 231 / 231 test cases passed.
	Status: Accepted
   Runtime: 4 ms, Your runtime beats 97.72 % of cpp submissions.
   Memory Usage: 11.2 MB, Your memory usage beats 97.40 % of cpp submissions.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        int len = 1;
        
        ListNode* tail = head;

        while (tail->next) {
            len++;
            tail = tail->next;
        }
        // connect the last node to the first node: head -> circle
        tail->next = head;
        // for the case that k > len -> loop
        int move = len - k % len;

        while (move > 0) {
            tail = tail->next;
            move--;
        }
        head = tail->next;
        // break the circle
        tail->next = nullptr;
        return head;
    }
};
