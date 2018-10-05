/*
Reverse Nodes in k-Group

Given a linked list, reverse the nodes of a linked list k at a time 
and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.

*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //在merge的过程中实现reverse
    ListNode* reverse_merge(ListNode* head1, ListNode* head2) {
        ListNode* head = head2;
        while (head2->next != NULL) head2 = head2->next;
        head2->next = head1;
        return head;
    }
    //反转一段链表
    ListNode* reverse_List(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *left = head, *right = head->next;
        while (left != NULL && right != NULL && right->next != NULL) {
            left = left->next;
            right = right->next->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = left->next;
        left->next = NULL;
        ListNode* list1 = reverse_List(head1);
        ListNode* list2 = reverse_List(head2);
        return reverse_merge(list1, list2);
    }
    //先把整段链表分解成每k个一段，再对每一段进行反转，最后连接起来
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;//用于计算一段链表的长度
        ListNode* tmp = head;
        ListNode* curr_head = head;//用作小段链表的头
        ListNode* curr_tail = NULL;//当前已完成反转部分链表的尾

        ListNode* result_head = NULL;

        while (tmp != NULL) {
            count++;
            if (count == k) {
                ListNode* remaining = tmp->next;
                tmp->next = NULL;
                curr_head = reverse_List(curr_head);//反转小段链表
                if (result_head == NULL) result_head = curr_head;
                if (curr_tail != NULL) curr_tail->next = curr_head;
                while (curr_head->next != NULL) {
                    curr_head = curr_head->next;
                }
                curr_tail = curr_head;
                curr_head = remaining;
                tmp = remaining;
                count = 0;
            }
            else tmp = tmp->next;
        }
        //输入的链表长度不是k的倍数时会剩下未反转的部分链表
        if (count != 0 && curr_tail != NULL) curr_tail->next = curr_head;
        //输入的k大于链表长度的情况
        else if (count != 0 && curr_tail == NULL) return head;
        return result_head;
    }
};