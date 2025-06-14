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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        unordered_map<int,int>freq;
        vector<ListNode*>reserve;
        while(head!=nullptr)
        {
             reserve.push_back(head);
             freq[head->val]++;
             head=head->next;
          
        }
       
        vector<ListNode*>choice;
         for(auto node:reserve)
        {
          if(freq[node->val]==1)
         {
          choice.push_back(node);
         }
        }
       sort(choice.begin(), choice.end(), [](ListNode* a, ListNode* b) 
       {
    return a->val < b->val;
});
        if (choice.empty()) return nullptr;

        ListNode* newHead=new ListNode(choice[0]->val);
        ListNode* current=newHead;
        for(int j=1;j<choice.size();j++)
        {
           current->next=new ListNode(choice[j]->val);
           current=current->next;
           
        }
        return newHead;
    }
};
