// delete nth from last node in singly linked list
//
// my idea: have a runner go through the list and
// tally the total elements in the list. 
// then, subtract the n from number of nodes
// and you have the position that the element
// to be removed is in. Stop at the node before it
// and change that node's next pointer. 

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
        
        ListNode* runner = head;

		int numNodes = 0;

		while(runner != nullptr) {
			numNodes++;
			runner = runner->next;
		}

		int elementPosition = numNodes - n;

		if(elementPosition < 0) return head;
        
        if(elementPosition == 0) return head->next;

		runner = head;

		while(elementPosition > 1) {
			runner = runner->next;
			elementPosition--;
		}
        
    
        runner->next = runner->next->next;
        
        return head;
        
    }
};