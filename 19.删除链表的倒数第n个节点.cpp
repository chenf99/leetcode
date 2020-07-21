/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int length = 0;
        while (tmp) {
            length++;
            tmp = tmp->next;
        }
        int index = length - n, count = 1;
        tmp = head;
        while (tmp && count < index) {
            tmp = tmp->next;
            count++;
        }
        ListNode* node;
        if (index > 0) {
            node = tmp->next;
            tmp->next = node->next;
        }
        else {
            node = head;
            head = head->next;
        }
        delete node;
        return head;
    }
};
// @lc code=end

