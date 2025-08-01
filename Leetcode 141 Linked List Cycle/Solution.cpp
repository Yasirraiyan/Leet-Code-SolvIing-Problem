/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
{
        ListNode* slow=head;
        ListNode* fast=head;
        bool cycle=false;
        while(fast&&fast->next)
            {
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast)
                {
                    cycle=true;
                    break;
                }
            }
        return cycle;
    }
};
