class Solution 
{
public:
    ListNode* insertionSortList(ListNode* head) 
{
        vector<int>v;
        while(head!=nullptr)
        {
          v.push_back(head->val);
          head=head->next;
        }
        sort(v.begin(),v.end());
        ListNode* newHead=new ListNode(v[0]);
        ListNode* curr= newHead;
        for(int i=1;i<v.size();i++)
        {
          curr->next= new ListNode(v[i]);
          curr=curr->next;
        }
        return newHead;
    }
};
