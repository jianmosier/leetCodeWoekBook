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
        //定义大小哑节点，大小滑动指针
        ListNode smallHead(-1);
        ListNode* smallPtr;
        ListNode bigHead(-1);
        ListNode* bigPtr;
        smallPtr = &smallHead;
        bigPtr = &bigHead;
        //定义遍历前当滑动指针
        ListNode* ptr = head;
        //walk through the Head
        for(;ptr!=nullptr; ptr = ptr->next){
            if(ptr->val<x){
                smallPtr->next = ptr;
                smallPtr = smallPtr->next;
            }
            else{
                bigPtr->next = ptr;
                bigPtr = bigPtr->next;
            }
        }
        bigPtr->next = nullptr;
        smallPtr->next = bigHead.next;
        return smallHead.next;
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


