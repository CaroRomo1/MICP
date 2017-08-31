#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

// Reverse function
ListNode* reverse(ListNode *head) {
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nxt;
    while(curr != NULL) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    
    return prev;
}

bool isPalindrome(ListNode *head) {
    // Check for NULL
    if(head == NULL) {
        throw invalid_argument("NULL VALUE");
    }
    
    // Check is only 1 element
    if(head->next == NULL){
        return true;
    }
    
    // Use two pointers to get to the center
    ListNode *prev = head;
    ListNode *slow = head;
    ListNode *fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    // For odd length cases
    if (fast != NULL){
        slow = slow->next;
    }
    
    // Reverse the second half of the Linked List
    ListNode* second = reverse(slow);
    
    // Compare
    while(head != NULL && second != NULL) {
        if(head->val != second->val) {
            return false;
        }
        head = head->next;
        second = second->next;
    }
    
    return true;
}
