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
    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL, *curr = node;

        while(curr != NULL){
            ListNode* next = curr -> next;

            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        int carry = 0;
        ListNode *temp = NULL, *head = NULL;

        while(l1 != NULL || l2 != NULL){
            int sum = carry;
            if(l1 != NULL){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum += l2 -> val;
                l2 = l2 -> next;
            }

            carry = sum / 10;
            sum = sum % 10;

            ListNode* hello = new ListNode(sum);
            if(head == NULL){
                head = hello;
                temp = head;
            }
            else{
                temp -> next = hello;
                temp = hello;
            }
        }

        if(carry > 0){
            ListNode* hello = new ListNode(1);
            temp -> next = hello;
            temp = hello;
        }

        head = reverse(head);
        return head;
    }
};