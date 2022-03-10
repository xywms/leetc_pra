/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
       if(head == nullptr) {
           return nullptr;
       }
        ListNode* a = head;
        ListNode* b = head;
        for(int i = 0;i < k ;i++) {
            if(b == nullptr) {
                return head;
            }
            b = b->next;
        }
        //反转a和b之间的链表
        ListNode* newhead = reversed(a , b);
         // 递归反转后续链表并连接起来
        a->next = reverseKGroup(b, k);
        return newhead;
    }
    //反转a到b之间的链表之迭代
    ListNode* reverse(ListNode* a,ListNode* b) {
        ListNode* pre = nullptr;
        ListNode* cur = a;
        while(cur != b) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    //反转a到b之间的链表之递归
    ListNode* reversed(ListNode* a,ListNode* b) {
        if(a->next == b) {
            return a;
        }
        ListNode* newhead = reversed(a->next,b);
        a->next->next = a;
        a->next = nullptr;
        return newhead;
    }
};