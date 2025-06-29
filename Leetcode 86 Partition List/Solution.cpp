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
    ListNode* partition(ListNode* head, int x) {
        vector<int>v1;
        vector<int>v2;
        while(head!=nullptr)
        {
          if(head->val<x)
          {
            v1.push_back(head->val);
          }
          if(head->val>=x)
          {
            v2.push_back(head->val);
          }
          head=head->next;
        }
        vector<int>v3;
        for(int i=0;i<v1.size();i++)
        {
          v3.push_back(v1[i]);
        }
        for(int j=0;j<v2.size();j++)
        {
          v3.push_back(v2[j]);
        }
        if(v3.size()==0)
        return nullptr;
        ListNode* newHead=new ListNode(v3[0]);
        ListNode* curr=newHead;
        for(int k=1;k<v3.size();k++)
        {
          curr->next=new ListNode(v3[k]);
          curr=curr->next;
        }
        return newHead;
    }
};
