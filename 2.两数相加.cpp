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
    long long listToNum(ListNode* list){
        long long sum=0;
        for(int i=0; list!=nullptr; i++,list = list->next){
            sum = sum + list->val*std::pow(10,i);
        }
        return sum;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //caution large number
        long long sum = listToNum(l1) + listToNum(l2);
        ListNode dummyNode(-1);
        ListNode* ptr = &dummyNode;
        // caution new node add method
        if(sum/10 == 0){
            ptr->next = new ListNode(sum);
            return dummyNode.next;
        }
        for(int j=0; sum/10 > 0; ptr = ptr->next, sum = sum/10){
            ptr->next = new ListNode(sum%10);
        }
        ptr = new ListNode(sum);
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

