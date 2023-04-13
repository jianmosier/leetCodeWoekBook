/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=21906
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.*/

/* struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyNode(-1);
        ListNode* leftPtr;
        ListNode* rightPtr;
        ListNode* lastPtr;
        dummyNode.next = head;
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        leftPtr = head;
        rightPtr = leftPtr->next;
        lastPtr = &dummyNode;
        for(;leftPtr != nullptr && rightPtr != nullptr; leftPtr = rightPtr->next, rightPtr = leftPtr->next){
            leftPtr->next = rightPtr->next;
            lastPtr->next = rightPtr;
            rightPtr->next = leftPtr;

            ListNode* tempPtr;
            tempPtr = leftPtr;
            leftPtr = rightPtr;
            rightPtr = tempPtr;
            lastPtr = rightPtr;
            if(rightPtr->next == nullptr || rightPtr->next->next == nullptr){
                return dummyNode.next;
            }
        }
        return dummyNode.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

