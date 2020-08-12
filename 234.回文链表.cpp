/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        while (head2) {
            ListNode* post = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = post;
        }
        while (prev) {
            if (head->val != prev->val) return false;
            head = head->next;
            prev = prev->next;
        } 
        return true;
    }
};
// @lc code=end

