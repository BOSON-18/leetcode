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
int findLength(ListNode* temp){
    int count = 0;

    while(temp){
        temp=temp->next;
        count++;
    }

    return count;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next|| k==0) return head;

        int length = findLength(head);

        k = k%length;
        if(k==0) return head;
        int count = length - k;

        ListNode* temp =head;

        for(int i=1;i<count;i++) temp=temp->next;

        ListNode* newHead = temp->next;

        temp->next = NULL;

        temp=newHead;

        while(temp->next) temp=temp->next;

        temp->next = head;
        
        head = newHead;

        return head;
        
    }
};