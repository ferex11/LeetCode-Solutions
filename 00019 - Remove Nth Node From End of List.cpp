// Brute Force Approach

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == 0) return NULL;
    int len = 0;
    ListNode* curNode = head;
    while (curNode != NULL) {
      len++;
      curNode = curNode->next;
    }
    if (len == n) {
      ListNode* newHead = head->next;
      delete head;
      return newHead;
    }
    int res = len - n;
    curNode = head;
    while (curNode != NULL) {
      res--;
      if (res == 0) break;
      curNode = curNode->next;
    }
    ListNode* deleteNode = curNode->next;
    curNode->next = curNode->next->next;
    delete deleteNode;
    return head;
  }
};

// Optimal Approach

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curNode = head;
        ListNode* fast = head;
        while (n--) {
            fast = fast->next;
        }
        if (fast == NULL) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* slow = head;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* NthNode = slow->next;
        slow->next = slow->next->next;
        delete NthNode;
        return head;
    }
};
