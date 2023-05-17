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
    int pairSum(ListNode* head) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //Reverse the second half
        ListNode* nextNode, *prev = nullptr;
        while(slow){
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        int maxSum = 0;
        while(prev){
            maxSum = max(maxSum, head->val + prev->val); 
            prev = prev->next; 
            head = head->next;
        }

        return maxSum;
    }
};