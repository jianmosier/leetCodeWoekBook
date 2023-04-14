/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=21906
 *
 * [21] 合并两个有序链表
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
//Definition for singly-linked list.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode newHead(-1);
        ListNode *ptr3;
        ptr3 = newHead.next;   //can't connect ptr3 and newHead after ptr3 redirect

        while(list1!=nullptr&&list2!=nullptr){
            if(list1->val <= list2->val){
                ptr3 = list1;
                list1 = list1->next;
            }
            else{
                ptr3 = list2;
                list2 = list2->next;
            }
            ptr3 = ptr3->next;
        }
        if(list2!=nullptr){
            ptr3 = list2;
        }
        else if(list1!=nullptr){
            ptr3 = list1;
        }
        return newHead.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */

