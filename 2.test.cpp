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

long long listToSum(ListNode* list){
    long long sum1 = 0;
    for (int i = 0; list != nullptr; i++, list = list->next) {
        sum1 = sum1 + list->val * std::pow(10,i);
    } 
    return sum1;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    long long sum = listToSum(l1) + listToSum(l2);
    ListNode dummyNode(-1);
    ListNode* ptr = &dummyNode;
    
    if (sum / 10 == 0) {
        ptr->next = new ListNode(sum);
        return dummyNode.next;
    }
    for (int j = 0; sum / 10 > 0; sum = sum / 10) {
        ptr->next = new ListNode(sum % 10);
        ptr = ptr->next;
    }
    ptr->next = new ListNode(sum);
    return dummyNode.next;
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
