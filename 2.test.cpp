#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode *p = &dummy;
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    
    return dummy.next;
}

ListNode* createList(const vector<int>& nums) {
    ListNode dummy(0);
    ListNode *p = &dummy;
    
    for (int num : nums) {
        p->next = new ListNode(num);
        p = p->next;
    }
    
    return dummy.next;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> num1 = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    vector<int> num2 = {5, 6, 4};
    ListNode *l1 = createList(num1);
    ListNode *l2 = createList(num2);
    
    ListNode *result = addTwoNumbers(l1, l2);
    printList(result);
    
    return 0;
}
