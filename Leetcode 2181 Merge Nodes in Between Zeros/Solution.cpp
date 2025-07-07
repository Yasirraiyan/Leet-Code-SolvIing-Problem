  Definition for singly-linked list.
 struct ListNode 
{
      int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution 
{
public:
    ListNode* mergeNodes(ListNode* head) 
    {
      vector<int>v;
        while(head!=nullptr)
        {
               v.push_back(head->val);
               head=head->next;
        }
        vector<int>vv;
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
           
        
          if(v[i]==0&&sum>0)
          {
            vv.push_back(sum);
            sum=0;
          }
          else
          {
            sum+=v[i];
          }
        }
          if(vv.empty()) return nullptr;
         
        ListNode* newHead=new ListNode(vv[0]);
        ListNode* curr=newHead;
       
        for(int j=1;j<vv.size();j++)
        {
          curr->next=new ListNode(vv[j]);
          curr=curr->next;
        } 
        return newHead;
    }
};
