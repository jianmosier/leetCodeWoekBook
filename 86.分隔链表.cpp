/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=21902
 *
 * [86] 分隔链表
 */

// @lc code=start
/* *
 * Definition for singly-linked list. */
/* struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    ListNode less_head(0), more_head(0);  // 创建两个临时链表的虚拟头节点
    ListNode *less_ptr = &less_head, *more_ptr = &more_head;

    while (head != nullptr) {
        if (head->val < x) {
            less_ptr->next = head;
            less_ptr = head;
        } else {
            more_ptr->next = head;
            more_ptr = head;
        }
        head = head->next;
    }

    less_ptr->next = more_head.next;  // 将两个临时链表连接起来
    more_ptr->next = nullptr;         // 设置尾节点的next指针为nullptr

    return less_head.next;            // 返回结果链表的头节点
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */


