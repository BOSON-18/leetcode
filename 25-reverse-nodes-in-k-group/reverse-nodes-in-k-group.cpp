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
    ListNode* findK(ListNode* temp, int k) {
        k--;
        while (temp && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp;
    }
    ListNode* reverse(ListNode* temp) {

        ListNode* prev = NULL;
        while (temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *KNode = NULL, *temp = head, *prevNode = NULL,
                 *nextNode = NULL;

        while (temp) {

            KNode = findK(temp, k);

            if (!KNode) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }

            nextNode = KNode->next;
            KNode->next = NULL;

            reverse(temp);

            if (temp == head)
                head = KNode;
            else
                prevNode->next = KNode;

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};