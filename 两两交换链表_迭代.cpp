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
    //迭代
    //构造虚拟头节点
    ListNode* neww = new ListNode(-1);
    neww->next = head;
    ListNode* pre = neww;
    //注意循环条件基于pre
    while(pre->next != nullptr && pre->next->next != nullptr) {
        //将两个节点都分离出来
        ListNode* node1 = pre->next;
        ListNode* node2 = pre->next->next;
        //前置节点连上新的头节点
        pre->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        //移动两位，准备下一次交换
        pre = node1;

    }
    return neww->next; 
    }
};
