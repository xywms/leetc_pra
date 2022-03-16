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
    ListNode* swapPairs(ListNode* head) {
    //递归
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    //新的头节点
    ListNode* newhead = head->next;
    //一节点连接递归返回的结果节点
    head->next = swapPairs(newhead->next);
    //二节点成为新的头节点，它的后驱节点为原头节点head
    newhead->next = head;
    return newhead;
    }
};
