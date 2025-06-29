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
    ListNode* sortList(ListNode* head) 
{
        vector<int>v;
        while(head!=nullptr)
        {
          v.push_back(head->val);
          head=head->next;
        }
        sort(v.begin(),v.end());
        if(v.size()==0)
        return nullptr;
        ListNode* newHead=new ListNode(v[0]);
        ListNode* curr=newHead;
        for(int i=1;i<v.size();i++)
        {
          curr->next=new ListNode(v[i]);
          curr=curr->next;
        }
        return newHead;
    }
};
