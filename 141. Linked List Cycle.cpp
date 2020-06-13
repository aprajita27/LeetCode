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
        if(!head)
            return false;
        ListNode* temp;
        temp = head;
        
        while(temp) {
            head = head -> next;
            if(temp -> next && temp -> next -> next)
                temp = temp -> next -> next;
            else 
                return false;
            
            if(temp == head)
                return head;
        }
        return false;
    }
};
