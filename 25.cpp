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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int cur = 0;
        ListNode *left = head, *new_head = NULL, *new_tail = NULL;
        while (head) {
            ListNode* tmp = head->next;
            if (++cur == k) {
                head->next = NULL;
                ListNode* p = reverseList(left);
                if (!new_head) new_head = p;
                else new_tail->next = p;
                left->next = tmp;
                new_tail = left;
                left = tmp;
                cur = 0;
            }
            head = tmp;
        }
        return new_head;
    }
private:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *left = NULL, *cur = head;
        while (cur) {
            ListNode* right = cur->next;
            cur->next = left;
            left = cur;
            cur = right;
        }
        return left;
    }
};