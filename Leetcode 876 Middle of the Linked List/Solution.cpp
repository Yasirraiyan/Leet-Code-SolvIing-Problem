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
class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        int low=0;
        vector<ListNode*>reserve;
        while(head!=nullptr)
            {
                reserve.push_back(head);
                head=head->next;
            }
        int high=reserve.size()-1;
        int mid;
        if(reserve.size()%2!=0)
        {
           mid=reserve.size()/2;
               
            
        }
        else
        {
            mid=(reserve.size()+1)/2;
        }
        
    
        return reserve[mid];
    }
};
