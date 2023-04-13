/*
 * @lc app=leetcode.cn id=876 lang=cpp
 * @lcpr version=21906
 *
 * [876] 链表的中间结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode dummyNode(-1);
        dummyNode.next = head;
        ListNode* ptr = head;
        int len = 0;
        int keyNum = 0;
        for(; ptr!=nullptr; ptr = ptr->next, len++){}
        if(len<2){
            return head;
        }
        else{
            keyNum = len/2 + 1;
        }
        for(int j=1; j<keyNum; head = head->next, j++){}
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

 */

