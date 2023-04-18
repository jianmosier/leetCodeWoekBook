#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 请将你的 addTwoNumbers 实现粘贴在这里
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

ListNode* vecToListNode(const vector<int>& vec) {
    ListNode dummyNode(-1);
    ListNode* ptr = &dummyNode;

    for (const int& val : vec) {
        ptr->next = new ListNode(val);
        ptr = ptr->next;
    }

    return dummyNode.next;
}

vector<int> listNodeToVec(ListNode* listNode) {
    vector<int> vec;

    while (listNode != nullptr) {
        vec.push_back(listNode->val);
        listNode = listNode->next;
    }

    return vec;
}

int main() {
    vector<int> num1 = {3,7};
    vector<int> num2 = {9,2};
    ListNode* l1 = vecToListNode(num1);
    ListNode* l2 = vecToListNode(num2);

    ListNode* result = addTwoNumbers(l1, l2);
    vector<int> resultVec = listNodeToVec(result);

    cout << "Result: ";
    for (int val : resultVec) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
