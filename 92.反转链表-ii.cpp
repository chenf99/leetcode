/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next) return head;
        ListNode* cur = head;
        int count = 0;
        ListNode *left = NULL, *right = NULL, *tmp_head = NULL;
        if (m == 1) {
            tmp_head = head;
        }
        while (cur) {
            count++;         
            if (count == m - 1) {
                left = cur ;
                tmp_head = left->next;
            }
            else if (count == n) {
                right = cur->next;
                cur->next = NULL;
                if (left) left->next = reverseList(tmp_head);
                else head = reverseList(tmp_head);
                tmp_head->next = right;
                break;
            }
            cur = cur->next;
        }
        return head;
    }
private:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
};
// @lc code=end

