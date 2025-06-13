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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
      vector<ListNode*> v1;
        while(list1!=nullptr)
        {
          v1.push_back(list1);
          list1=list1->next;
        }
        while(list2!=nullptr)
        {
          v1.push_back(list2);
          list2=list2->next;
        }
        sort(v1.begin(),v1.end(),[](ListNode* a,ListNode* b)
        {
          return a->val<b->val;
        });
        if(v1.empty()) return nullptr;
        ListNode* newhead=v1[0];//new ListNode(v1[0]);
        ListNode* current=newhead;
        for(int i=1;i<v1.size();i++)
        {
          current->next= v1[i];//new ListNode(v1[i]);
          current=current->next;
        }
        current->next=nullptr;
        return newhead;
}
    
};
