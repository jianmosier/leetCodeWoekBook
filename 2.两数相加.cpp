/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=21906
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
// ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool addone = false;
        ListNode dummyNode(-1);
        ListNode* ptr = &dummyNode;
        for(;l1 != nullptr && l2 != nullptr; ptr = ptr->next, l1 = l1->next, l2 = l2->next){
            ptr->next = new ListNode((l1->val+l2->val + ((addone) ? 1 : 0))%10);
            addone = (l1->val + l2->val + addone >= 10) ? true :false;
        }
        if(l1 != nullptr || l2 != nullptr){
            ListNode* addPtr = (l1 != nullptr ? l1 : l2);
            ptr->next = addPtr;
            for(; addone == true; ptr = ptr->next ){
                if(ptr->next == nullptr){
                    ptr ->next = new ListNode(1);
                    return dummyNode.next;
                }
                addone = (ptr->next->val + 1 >= 10) ? true :false;
                ptr->next->val = (ptr->next->val + 1)%10;
            }
        }
        else{
            if(addone){
                ptr->next = new ListNode(1);
            }
        }  
        return dummyNode.next;
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */

