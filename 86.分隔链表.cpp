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
        ListNode* keyPtr;
        ListNode* ptr;
        ListNode* lastPtr;
        lastPtr = head;
        if(lastPtr->next == nullptr){
            return lastPtr;
        }
        ptr = lastPtr->next;
        while(ptr->val < x){
            keyPtr = ptr;
            lastPtr = ptr; 
            ptr = ptr->next;
        }
        for(; ptr->next != nullptr; lastPtr = ptr, ptr = ptr->next){
            if(ptr->val < x){
                ListNode* tempPtr;
                lastPtr->next = ptr->next;

                tempPtr = keyPtr->next;
                keyPtr->next = ptr;
                ptr->next = tempPtr;
                
                keyPtr = keyPtr->next;
                ptr = lastPtr;
            }

        }
    return head;
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


