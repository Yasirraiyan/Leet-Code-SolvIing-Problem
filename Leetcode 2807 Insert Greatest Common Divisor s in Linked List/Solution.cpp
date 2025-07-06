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
 int findgcd(int a,int b)
 {
  while(b!=0)
  {
    int temp=a%b;
    a=b;
    b=temp;
  }
  return a;
 }
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        vector<int>v;
        while(head!=nullptr)
        {
          v.push_back(head->val);
          head=head->next;
        }
        for(int i=1;i<v.size();i+=2)
        {
          int g=findgcd(v[i-1],v[i]);
           v.insert(v.begin() + i, g);
        }
        if(v.size()==0)return nullptr;
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
