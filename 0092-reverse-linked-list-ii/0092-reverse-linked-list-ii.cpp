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
    ListNode* reverseBetween(ListNode* head, int l, int r) {

        if(l==r) return head;

        ListNode *left=NULL,*right=NULL,*left_prev=NULL,*right_next=NULL;
        ListNode *temp = head,*prev=NULL;

        int c = 0;

        while(temp!=NULL && (!left || !right)){
            c++;

            if(c == l){
                left = temp;
                left_prev = prev;
            }
            if(c == r){
                right = temp;
                right_next = temp->next;
            }
            prev = temp;
            temp = temp->next;
        }

        temp = left; prev = right_next;
        ListNode *nn=left;

        while(temp != right_next){
            nn = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nn;
        }

        if(left_prev == NULL) return right;

        left_prev->next =  right;
        return head;
    }
};