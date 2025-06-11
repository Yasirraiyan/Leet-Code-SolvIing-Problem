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
    ListNode* removeElements(ListNode* head, int val) 
    {
     stack<ListNode*> st1;
     while(head!=nullptr)
 {
    if(head->val!=val)
    {
        st1.push(head);
    
    }
    head=head->next;
 }
 ListNode* newHead=nullptr;
 while(!st1.empty())
 {
    ListNode*head=st1.top();
    st1.pop();
    head->next=newHead;
    newHead=head;
 }
 return newHead;
    }
};

