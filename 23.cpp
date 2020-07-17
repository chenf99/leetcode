/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    //合并两个有序链表
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        else if (list2 == NULL) return list1;
        ListNode* head = NULL;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }
        ListNode* tmp = head;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                head->next = list1;
                list1 = list1->next;
            }
            else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        if (list1 == NULL) head->next = list2;
        else head->next = list1;
        return tmp;
    }
    ListNode* mergelist(vector<ListNode*>& lists, int left, int right) {
        int mid = (left + right) / 2;
        if (left < right) {
            ListNode* list1 = mergelist(lists, left, mid);
            ListNode* list2 = mergelist(lists, mid + 1, right);
            ListNode* mergedList = merge(list1, list2);
            return mergedList;
        }
        return lists[left];
    }
public:
    //思路:先采用分治法把问题分成两个子问题(不断向下递归分解)，到最后一层得到的是单独的一条链表和两条链表
    //      合并两条链表为一条，向上递归继续合并
    //      思路很类似于归并排序
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        return mergelist(lists, 0, lists.size() - 1);
    }
};

int main() {
    //懒得写测试代码了...直接用的leetcode来测试
    //错的那两遍是因为没有考虑[] 和[[],[]]这种输入形式
    //会导致访问空指针的val，因此需要额外考虑
}