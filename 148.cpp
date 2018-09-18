/*
Sort List
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
private:
    ListNode* mergeSort(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *left = head, *right = head->next;
        while (left != NULL && right != NULL && right->next != NULL) {
            left = left->next;
            right = right->next->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = left->next;
        left->next = NULL;
        ListNode* list1 = mergeSort(head1);
        ListNode* list2 = mergeSort(head2);
        return merge(list1, list2);
    }
    //合并两个有序链表
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (head1 == NULL) return head2;
        else if (head2 == NULL) return head1;
        ListNode* head = NULL;
        if (head1->val < head2->val) {
            head = head1;
            head1 = head1->next;
        }
        else {
            head = head2;
            head2 = head2->next;
        }
        ListNode* temp = head;
        while (head1 != NULL && head2 != NULL) {
            if (head1->val < head2->val) {
                temp->next = head1;
                head1 = head1->next;
            }
            else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        if (head1 == NULL) temp->next = head2;
        else temp->next = head1;
        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};