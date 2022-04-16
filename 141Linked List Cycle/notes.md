## Solution 1 :

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map <ListNode * , bool> hashtable ;
        
        ListNode * temp = head ; 
        while(temp != NULL){
            if(hashtable.count(temp) != 0){
                return true ;
                
            }
            hashtable[temp] = true ;
            temp = temp->next ;
            
        }
        return false ;
    }
};
```

## Solution 2 :

*Floyd's Cycle Finding Algorithm*
>Note - Code from disscusion 

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
	
		// if head is NULL then return false;
        if(head == NULL)
            return false;
        
		// making two pointers fast and slow and assignning them to head
        ListNode *fast = head;
        ListNode *slow = head;
        
		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        
		// if traversal reaches to NULL this means no cycle.
        return false;
    }
};
```