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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummyHead(-1);
        dummyHead.next = head;
        ListNode* keyPtr = &dummyHead;
        ListNode* lastPtr = &dummyHead;
        ListNode* ptr = head;

        // 寻找第一个大于或等于x的节点，作为插入点
        while (ptr != nullptr && ptr->val < x) {
            keyPtr = ptr;
            lastPtr = ptr;
            ptr = ptr->next;
        }

        // 遍历链表，将小于x的节点移动到插入点
        while (ptr != nullptr) {
            if (ptr->val < x) {
                // 删除ptr指向的节点
                lastPtr->next = ptr->next;

                // 将ptr指向的节点插入到keyPtr之后
                ptr->next = keyPtr->next;
                keyPtr->next = ptr;

                // 更新keyPtr和ptr
                keyPtr = keyPtr->next;
                ptr = lastPtr->next;
            } else {
                lastPtr = ptr;
                ptr = ptr->next;
            }
        }

        return dummyHead.next;
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


