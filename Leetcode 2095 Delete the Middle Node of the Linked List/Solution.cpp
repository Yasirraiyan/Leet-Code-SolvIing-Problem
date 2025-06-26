class Solution
{
public:
    ListNode* deleteMiddle(ListNode* head)
    {
        vector<int>v;
        if(head==nullptr||head->next==nullptr)
        {
            return nullptr;
        }
        while(head!=nullptr)
            {
                v.push_back(head->val);
                head=head->next;
            }
        int low=0;
        //int high=v.size()-1;
        int mid=(low+v.size())/2;
        vector<int>choose;
        for(int i=0;i<v.size();i++)
            {
                if(i!=mid)
                {
                    choose.push_back(v[i]);
                }
            }
        ListNode* headd=new ListNode(choose[0]);
        ListNode* curr=headd;
        for(int j=1;j<choose.size();j++)
            {
                curr->next=new ListNode(choose[j]);
                curr=curr->next;
            }
        return headd;
    }
};
