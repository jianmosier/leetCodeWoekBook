#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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

        while(ptr != nullptr && ptr->val < x){
            lastPtr = ptr;
            keyPtr = ptr;
            ptr = ptr->next;
        }

        for(; ptr != nullptr; lastPtr = ptr, ptr = ptr->next){
            if(ptr->val < x ){
                lastPtr->next = ptr->next;
                ptr->next = keyPtr->next;
                keyPtr->next = ptr;

                keyPtr = ptr;
                ptr = lastPtr;
            }
        }
        return dummyHead.next;
    }
};

// 创建链表
ListNode* createLinkedList(const std::initializer_list<int>& init_list) {
    ListNode dummyHead(-1);
    ListNode* tail = &dummyHead;

    for (int value : init_list) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    return dummyHead.next;
}

// 打印链表
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = createLinkedList({1, 4, 3, 0, 2, 5, 2});

    Solution solution;
    ListNode* partitionedHead = solution.partition(head, 3);

    printLinkedList(partitionedHead);

    return 0;
}
