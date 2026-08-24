class Solution {
public:
  ListNode* deleteMiddle(ListNode* head) {
    if (head == NULL || head->next == NULL) return NULL;
    ListNode* cur = head;
    int len = 0;
    while (cur != NULL) {
      len++;
      cur = cur->next;
    }
    len = len / 2;
    cur = head;
    while (cur != NULL) {
      len--;
      if (len == 0) {
        ListNode* middleNode = cur->next;
        cur->next = cur->next->next;
        delete middleNode;
        break;
      }
      cur = cur->next;
    }
    return head;
  }
};


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
      if (head == NULL || head->next == NULL) return NULL;
      ListNode* slow = head;
      ListNode* fast = head;
      fast = fast->next->next;
      while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode* middleNode = slow->next;
      slow->next = slow->next->next;
      delete middleNode;
      return head;
    }
};
