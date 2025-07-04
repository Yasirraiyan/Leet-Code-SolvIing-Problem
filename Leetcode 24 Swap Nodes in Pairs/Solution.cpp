 * Definition for singly-linked list.
 * struct ListNode
   {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution 
{
public:
void swap(int &a,int &b)
{
  int temp=a;
  a=b;
  b=temp;
}
    ListNode* swapPairs(ListNode* head) 
    {
        vector<int>v;
        while(head!=nullptr)
        {
          v.push_back(head->val);
          head=head->next;
        }
        for(int i=0;i+1<v.size();i+=2)
        {
          swap(v[i],v[i+1]);
        }
         if(v.empty()) return nullptr;
        ListNode* newHead=new ListNode(v[0]);
        ListNode* curr=newHead;
      
        for(int j=1;j<v.size();j++)
        {
          curr->next=new ListNode(v[j]);
          curr=curr->next;
        }
        return newHead;
    }
};
