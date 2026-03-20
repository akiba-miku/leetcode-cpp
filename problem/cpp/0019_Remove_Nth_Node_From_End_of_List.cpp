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

// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //快慢指针
        ListNode *dummy = new ListNode(-1);
        ListNode *fast = dummy;
        dummy->next = head;
        for(int i=0;i<=n;i++) {
            fast=fast->next;
        }      
        ListNode *slow = dummy;
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        // 清除dummy & 待删除节点
        fast = slow->next;
        slow->next = slow->next->next;
        delete fast;
        fast = dummy->next;
        delete dummy;
        return fast;
    }
};