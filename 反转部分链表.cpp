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
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        //记第m-1个位置为pre
        //记第n+1个位置结束
       // write code here
        ListNode* neww = new ListNode(0);
        neww->next = head;
        ListNode* pre = neww;
        //还是把链表分割开来吧
        for(int i = 1;i < m;i++) {
            pre = pre->next;
        }
        //right节点
        ListNode* right = pre;
        for(int i = m;i <= n;i++) {
            right = right->next;
        }
        //3.截取出一个子链表
         ListNode* left = pre->next;
         ListNode* cur = right->next;
        //4.切断
        pre->next = nullptr;
        right->next = nullptr;
        //5.子链表反转
        reverse(left);
        //5.将子链表重新连接，想清楚顺序，要跳一下
         pre->next = right;
        left->next = cur;
        return neww->next;
    }
    //这个函数改变了什么？
        void reverse (ListNode* head) {
            ListNode* pre = nullptr;
            ListNode* cur = head;
            while(cur != nullptr) {
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            
        }
};