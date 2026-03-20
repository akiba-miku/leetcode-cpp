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

 // 方法; Time O(kN)k是链表中最大长度, N是链表个数
 //      space O(1)
class Solution1 {
public:
    // 遍历链表数组，从左到右合并。
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for(auto &list : lists) {
            ans =  mergeTwoLists(ans, list);
        }
        return ans;
    }

    // 辅助方法: 合并两个链表
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy{};
        ListNode *cur = &dummy;
        while(l1&&l2){
            if(l1->val<l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1) {
            cur->next=l1;
        }
        if(l2) {
            cur->next=l2;
        }
        return dummy.next;
    }
};

// 优先级队列; 先从每个链表取头节点建立小根堆
// 然后依次取出拼成一个链表
class Solution2 {
public:
    ListNode *mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *l1, ListNode *l2)->bool{
            return l1->val>l2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(auto &node:lists){
            if(node) pq.push(node);
        }
        ListNode dummy{-1,nullptr};
        ListNode *tail = &dummy;
        while(!pq.empty()){
            ListNode *cur = pq.top();
            pq.pop();

            tail->next = cur;
            tail = tail->next;
            
            if(cur->next) pq.push(cur->next);
        }
        tail->next = nullptr;
        return dummy.next;
    }
};