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
    void reorderList(ListNode* head) {
        // Given a list
        // 1->2->3->4
        //0,1,2,3
        //make it 0,n-i,1,n-i

        // take a stack for storing purpose

        stack<ListNode*> st;

        ListNode* temp=head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        ListNode* curr=head;
        unordered_map<ListNode*,bool> vis;

      while(true){
        ListNode* last=st.top();
        st.pop();

        ListNode* front=curr->next;
        vis[curr]=true;
        if(vis[last]){
            // Cycle create hori traversal complete ho cvhuka 
            // Infonite loop ko break krne ke liye creak kro cycle
            curr->next=NULL;
            break;
        }
        curr->next=last;
        vis[last]=true;
        curr=curr->next;
        if(vis[front]){
            curr->next=NULL;
            break;
        }

        curr->next=front;
        curr=curr->next;
      }

        // return head;
        
    }
};