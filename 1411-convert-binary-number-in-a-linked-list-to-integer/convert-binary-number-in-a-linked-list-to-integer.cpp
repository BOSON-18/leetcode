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
    int getDecimalValue(ListNode* head) {
        // string str="";
        int result=0;

        while(head){
            // str.push_back(head->val);
            result = (result<<1) | head->val;
            cout<<"Result "<<result<<endl;

            head=head->next;
        }
        return result;
      

    //     int place=1;
    //     int n=str.size();
    //     int i=n-1;
    //     int power=0;

    // int ans=0;
    //     while(i>=0){
    //         ans+= str[i]*pow(2,power);
    //         power++;
    //         i--;
    //     }
    //     return ans;
    }
};