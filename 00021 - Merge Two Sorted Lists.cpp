// Brute Foces Approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        while (list1 != NULL) {
            arr.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != NULL) {
            arr.push_back(list2->val);
            list2 = list2->next;
        }
        sort(arr.begin(), arr.end());
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        for (int val : arr) {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
        return dummyNode->next;
    }
};

// Optimal Approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL)
            return NULL;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curNode = dummyNode;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                curNode->next = temp1;
                curNode = temp1;
                temp1 = temp1->next;
            } else {
                curNode->next = temp2;
                curNode = temp2;
                temp2 = temp2->next;
            }
        }
        if (temp1)
            curNode->next = temp1;
        if (temp2)
            curNode->next = temp2;
        return dummyNode->next;
    }
};
