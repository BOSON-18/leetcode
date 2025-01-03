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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Brute Force
        // Traversing each

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummyNode = new ListNode();
        ListNode* temp = dummyNode;

        while (temp1 && temp2) {
            // Compare and move on
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        while (temp1) {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
        while (temp2) {
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }
};