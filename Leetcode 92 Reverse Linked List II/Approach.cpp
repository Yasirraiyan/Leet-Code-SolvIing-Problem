ListNode* head2 = new ListNode(result[0]);
ListNode* current1 = head2;
for(int j = 1; j < result.size(); j++) {
    current1->next = new ListNode(result[j]);
    current1 = current1->next;
}
return head2;

➡️ এখানে নতুন লিস্ট তৈরি হচ্ছে result array থেকে।

🔹 Return হচ্ছে [1 → 4 → 3 → 2 → 5]


---

✅ কোড Accepted কেন?

Input linked list কে ভেঙে array তে এনেছো → ফলে random access পেয়েছো।

তারপরে reverse করেছো এবং নতুন linked list বানিয়েছো।

Although এটা one-pass না (linked list কে দুইবার traversal করা লাগছে: একবার array তে নেওয়া, পরে rebuild), কিন্তু এটি still correct এবং constraints অনুযায়ী efficient (O(n) time and space)।

তাই এই solution accepted হয়েছে।


Full Code:
------------

class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        
        vector<int>reserve1;
        while(head!=nullptr)
            {
                reserve1.push_back(head->val);
                head=head->next;
            }
        vector<int>reserve2;
        vector<int>reserve3;
        for(int i=0;i<reserve1.size();i++)
            {
                if(i<left-1)
                {
                   // if(i>=0&&i<=reserve1.size()-1)
                    {
                        reserve3.push_back(reserve1[i]);
                    }
                }
                if(i>=left-1&&i<=right-1)
                {
                    reserve2.push_back(reserve1[i]);
                }
            }
        reverse(reserve2.begin(),reserve2.end());
       // ListNode* head1=new ListNode(reserve2[0]);
        //ListNode* current=head1;
        vector<int>result;
        for(int j=0;j<reserve3.size();j++)
            {
                result.push_back(reserve3[j]);
            
            }
        for(int k=0;k<reserve2.size();k++)
            {
                result.push_back(reserve2[k]);
            }
        for(int i=right;i<reserve1.size();i++)
            {
                result.push_back(reserve1[i]);
            }
        if(result.empty())
        {
            return nullptr;
        }
        ListNode* head2=new ListNode(result[0]);
        ListNode * current1=head2;
        for(int j=1;j<result.size();j++)
            {
                current1->next=new ListNode(result[j]);
                current1=current1->next;
            }
        return head2;
    }
};
