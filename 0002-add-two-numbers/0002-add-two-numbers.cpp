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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *temp = res ; // taking an anser pointer 
        int sum = 0 ;
        while(l1 != NULL ||  l2 != NULL  ){
          if(l1 ){
            sum +=  l1->val ;
            l1 = l1->next ;
          }
          if(l2 != NULL){
            sum += l2->val ;
            l2 = l2->next ;
          }
          res->next = new ListNode(sum%10) ;
          res = res->next ;
          
          sum = sum > 9 ?  1 : 0 ; 
        }
      
       if(sum != 0){
         res->next = new ListNode(sum) ;
       }
      
      return temp->next ;
    }
};


// 8 9 9 9 0 0 0 1