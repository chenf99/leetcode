/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 解法一:迭代
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (!head || !head->next) return head;
//         ListNode *left = NULL, *cur = head;
//         while (cur) {
//             ListNode* right = cur->next;
//             cur->next = left;
//             left = cur;
//             cur = right;
//         }
//         return left;
//     }
// };

// 解法二:递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
};
// @lc code=end

