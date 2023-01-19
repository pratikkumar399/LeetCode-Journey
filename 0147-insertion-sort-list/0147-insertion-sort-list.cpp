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
    ListNode* insertionSortList(ListNode* head) {
        
      if(head == NULL || head->next == NULL){
        return head ;
      }
      
      // taking the next value of the head node 
      auto p = head->next ;
      // setting the value of the nextt of the head aas NULL 
      head->next = NULL ;
      
      while(p != NULL){
        // taking the next node that we have to insert 
        auto pNext = p->next ;
        auto q = head ;
        
        if(p ->val < q->val)
        {
          p->next = q ;
          head = p ; 
        }
        else{
          while(q != NULL  and q->next != NULL and q->next->val <= p->val){
            q= q->next ;
          }
          p->next = q->next ;
          q->next = p ;
          
        }
        
        p = pNext ;
      }
      
      
      return head ;
    }
};

