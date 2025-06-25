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
        vector<ListNode*>v1;
        while(!st.empty())
            {
                ListNode* top=st.top();
               // v.push_back(top);
               
                count++;
                if(count!=n)
                {
                    v1.push_back(top);
                        }
                st.pop();
                
            }
        vector<ListNode*>v2;
        for(int j=v1.size()-1;j>=0;j--)
            {
                v2.push_back(v1[j]);
            }
        if(v2.empty())return nullptr;
        //reverse(v.begin(),v.end());
        ListNode* headd=(v2[0]);
        ListNode* curr=headd;
        for(int i=1;i<v2.size();i++)
            {
  //  curr=new ListNode(v[i]);
                curr->next=v2[i];
                
                curr=curr->next;
            }
        curr->next=nullptr;
        return headd;
    }
};
