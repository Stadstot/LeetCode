class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* first = nullptr;
        ListNode* current = nullptr;
        while ((l1 != nullptr) || (l2 != nullptr)) {
            ListNode* temp = nullptr;
            if ((l1 != nullptr) && (l2 != nullptr)) {
                if (l1->val < l2->val) {
                    temp = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    temp = new ListNode(l2->val);
                    l2 = l2->next;
                }
            } else {
                if (l1 != nullptr) {
                    temp = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    temp = new ListNode(l2->val);
                    l2 = l2->next;
                }
            }
            if (current != nullptr) {
                current->next = temp;
                current = current->next;
            } else {
                current = temp;
                first = temp;
            }
        }
        return first;
    }
};