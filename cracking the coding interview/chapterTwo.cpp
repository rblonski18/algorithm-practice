// chapter two of CTCI -> linked lists

// problem 2.1
// write a method to remove duplicates from a linked list.
// my idea is quite simple - as we iterate through, add 
// elements to a hashmap, upon reaching new element, 
// query hashmap to see if we've passed it, if so, move
// this nodes "next" pointer to the next node's next 
// pointer

class Solution2_1 {
	Node* removeDuplicates(Node* head) {

		Node* runner = null;

		unordered_set<int> hashmap;

		// you would never remove the head, so we don't worry
		// about that case - how can the first element be a 
		// duplicate? 

		head -> 1 -> 2 -> 1 -> 2 -> null

		while(head != null) {
			if(hashmap.find(head.data) != hashmap.end()) { // duplicate
				runner.next = head.next;
			} else {
				hashmap.insert(runner.next.data);;
				runner = head
			}
			head = head.next;
		}

		return head;
	}
}

// problem 2.2
// implement an algorithm to find the kth to last 
// element of a singly linked list. 
// my initial idea is to send a runner through to 
// count the number of elements in the list, then
// subtract the k from the total elements to find 
// the "index" (position) of the element that I
// need, and to return that element upon reaching it.
//
// not like the solutions in the book, but it 
// runs in O(n) time and has O(1) space complexity,
// which is the same as the optimal solutions 
// presented, and it makes more sense to me. 

head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null __ k=3

class Solution2_2 {
	int returnKthElement(Node* head, int k) {

		Node* runner = head;

		int numNodes = 0;

		while(runner != null) {
			numNodes++;
			runner = runner.next;
		}

		int elementPosition = numNodes - k;

		if(elementPosition < 0) return -1;

		runner = head;

		while(elementPosition != 0) {
			runner = runner.next;
			elementPosition--;
		}

		return runner.data;

	}
}

// problem 2.3
//
// implement an algorithm to delete a node
// in the middle of a linked list - it will
// not be the first or the last node. 
// 
// I wouldn't have figured this out on my own;
// all the more reason for preparation. the trick
// is to copy the data from the current node to the 
// next node, and to move the pointers accordingly. 
// technically the actual node we selected isn't
// removed, but the data is. 

class Solution2_3 {
	void removeMiddleNode(Node* middle) {
		if(middle == null) return;
		if(middle.next == null) {
			middle = null;
			return;
		}
		middle.data = middle.next.data;
		middle.next = middle.next.next;
	}
}
