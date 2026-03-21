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

 /** https://leetcode.cn/problems/swap-nodes-in-pairs/ */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* pre = &dummy;

        while (pre->next && pre->next->next) {
            ListNode* a = pre->next;
            ListNode* b = a->next;
            ListNode* nxt = b->next;

            a->next = nxt;
            b->next = a;
            pre->next = b;

            pre = a;
        }

        return dummy.next;
    }
};