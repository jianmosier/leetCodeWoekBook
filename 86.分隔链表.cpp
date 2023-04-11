/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=21902
 *
 * [86] 分隔链表
 */

// @lc code=start
/* *
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode dummyHead(-1);
        dummyHead.next = head;
        ListNode* keyPtr = &dummyHead;
        ListNode* lastPtr = &dummyHead;
        ListNode* ptr = dummyHead.next;

        while(ptr->val < x){
            if(ptr->next == nullptr) return dummyHead.next;
            lastPtr = ptr;
            keyPtr = ptr;
            ptr = ptr->next;
        }

        for(; ptr != nullptr; lastPtr = ptr, ptr = ptr->next){
            if(ptr->val < x ){
                lastPtr->next = ptr->next;
                ptr->next = keyPtr->next;
                keyPtr->next = ptr;

                ptr = lastPtr;
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


