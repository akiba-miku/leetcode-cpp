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

// 注释
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 字节， 美团
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return ;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l1 = head, *l2 = slow->next;
        slow->next = nullptr;

        l2 = reverse(l2);
        merge(l1, l2);
    }

    ListNode *reverse(ListNode *l) {
        ListNode *pre = nullptr, *cur = l;
        while(cur) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;;
    }
    
    void merge(ListNode *l1, ListNode *l2) {
        while(l1 && l2) {
            ListNode *n1 = l1->next;
            ListNode *n2 = l2->next;
            l1->next = l2;
            l2->next = n1;
            l1 = n1;
            l2 = n2;
        }
    }
};