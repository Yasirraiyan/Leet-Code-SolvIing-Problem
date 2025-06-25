class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
{
        stack<ListNode*>st;
        while(head!=nullptr)
            {
                st.push(head);
                head=head->next;
            }
        int count=0;
        vector<ListNode*>v;
        while(!st.empty())
            {
                ListNode* top=st.top();
               // v.push_back(top);
               
                count++;
                if(count!=n)
                {
                    v.push_back(top);
                        }
                st.pop();
                
            }
        if(v.empty())return nullptr;
        reverse(v.begin(),v.end());
        ListNode* headd=(v[0]);
        ListNode* curr=headd;
        for(int i=1;i<v.size();i++)
            {
  //  curr=new ListNode(v[i]);
                curr->next=v[i];
                
                curr=curr->next;
            }
        curr->next=nullptr;
        return headd;
    }
};
