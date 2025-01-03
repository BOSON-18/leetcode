/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //Brute Force 
    // Will use a map structure to store if the node visited or not
    // unordered_map<ListNode*,bool> mpp;

    // ListNode* temp=head;
    // while(temp){
    //     if(mpp[temp]) return true;
    //     mpp[temp]=true;
    //     temp=temp->next;
    // }

    // return false;

    // Now What if O(1) space???
    // Algoruthm-->Slow / Fast

    ListNode* slow=head;
    ListNode* fast=head;
    // Ek circle me Running kr rhe me aur nilay 
    // Deeshank Speed= x Nilay Speed= 2x
    // Obivously There will be a point when Deeshank will complete the first round Nilay will be completing his 2 round 
    // They are meeting because running in a circular grond
    // Deeshank Slow Nilay Fast

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow== fast) return true;

    }


       return false; 
    }
};