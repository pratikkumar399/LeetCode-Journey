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
  
  // reversing a linked list
  // so basically the concept is that we have to copy the nodes of the given list and store that in another list
  // 
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL ;
        ListNode *curr = head ; 
        while(curr != NULL){
            ListNode *forward = curr->next ;
            curr->next =prev ;
            prev = curr ;
            curr =forward ;
        }
        return prev ;
    }
};