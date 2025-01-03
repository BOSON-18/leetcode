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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int length=0;

        while(temp){
            length++;
            temp=temp->next;

        }
        length-=n;
//     cout<<"Length->"<<length;
//         if(length==0) return head->next;
// temp=head;

temp=head;
if(!length) return head->next;
       
       while(length){
        length--;
        if(length<=0) temp->next=temp->next->next;
        temp=temp->next;

       }

        return head;
        
    }
};