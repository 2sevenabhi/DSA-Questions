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
    
        ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        if (head->next->next == NULL) {
            ListNode *newHead = head->next;
            newHead->next = head;
            head->next = NULL;
            return newHead;
        }
        
        ListNode *cur = head->next;
        ListNode *newHead = head->next;
        ListNode *tmp = NULL;
        ListNode *tmp2 = NULL;
        // swap the next two node, catch the currentNode as prev till the end
        while (cur && cur->next && cur->next->next) {
            if (cur->next->next->next)
                tmp = cur->next->next->next;
            else
                tmp = NULL;
            tmp2 = cur->next->next;
            cur->next->next->next = cur->next;
            cur->next->next = tmp;
            cur->next = tmp2;
            cur = cur->next->next;
        }
        //Lastly, swap the first two
        tmp = head->next->next;
        head->next->next = head;
        head->next = tmp;
        
        return newHead;
    }
    
};