class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
{
      //  vector<ListNode*>reserve;
       vector<ListNode*>v1;
        vector<ListNode*>v2;
        int index=1;
        while(head!=nullptr)
        {
          if(/*head->val*/index%2==0)
          {
           v1.push_back(head);
          }
            if(/*head->val*/index%2!=0)
          {
           v2.push_back(head);
          }
          head=head->next;
          index++;
        }
       
        vector<ListNode*>vf;
        for(int j=0;j<v2.size();j++)
        {
          vf.push_back(v2[j]);
        }
        for(int k=0;k<v1.size();k++)
        {
          vf.push_back(v1[k]);
        }
        if (vf.empty()) return nullptr; 
        ListNode* headd=(vf[0]);
        ListNode* curr=headd;
        for(int i=1;i<vf.size();i++)
        {
          curr->next=vf[i];
          curr=curr->next;
        }
        curr->next=nullptr;
  return headd;
    }
};
