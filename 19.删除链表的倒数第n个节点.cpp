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
// 解法一
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* tmp = head;
//         int length = 0;
//         while (tmp) {
//             length++;
//             tmp = tmp->next;
//         }
//         int index = length - n, count = 1;
//         tmp = head;
//         while (tmp && count < index) {
//             tmp = tmp->next;
//             count++;
//         }
//         ListNode* node;
//         if (index > 0) {
//             node = tmp->next;
//             tmp->next = node->next;
//         }
//         else {
//             node = head;
//             head = head->next;
//         }
//         delete node;
//         return head;
//     }
// };

// 解法二
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        ListNode* dummyhead = new ListNode(-1, head);
        ListNode *left = dummyhead, *right = dummyhead;
        int count = 0;
        for (int i = 0; i < n; ++i) right = right->next;
        while (right->next) {
            right = right->next;
            left = left->next;
        }
        ListNode* tmp = left->next;
        left->next = tmp->next;
        delete tmp;
        head = dummyhead->next;
        delete dummyhead;
        return head;
    }
};
// @lc code=end

