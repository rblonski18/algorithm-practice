// Add Two Numbers
//
// Two numbers are given as values in a linked list, stored
// in reverse order (250 is 0->5->2). Add them together and
// return the sum in the same format. 
// 
// Since the numbers are in reverse order, dealing with carry
// digits becomes much easier. Construct a new linked list. 
// parse through l1 & l2, adding digits together, factoring in 
// carry digits. When either reaches null, it's possible there
// are numbers in l1 or l2 remaining -> we add what's left of
// those onto the linked list, and any carry digit. That's it. 
// Time complexity: O(m + n) (lengths of l1 & l2)
// Space complexity: O(max(m + n)) 


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode result;
        ListNode* holder = &result;
        int carry = 0;
        
        while(l1 && l2) {
            int num = l1->val + l2->val;
            holder->next = new ListNode((num % 10 + carry) % 10);
            carry = (num + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
            holder = holder->next;
        }
        
        while(l1) {
            holder->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
            holder = holder->next;
        }
        
        while(l2) {
            holder->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
            holder = holder->next;
        }
        
        if(carry) {
            holder->next = new ListNode(1);
        }
        
        return result.next;
    }
};