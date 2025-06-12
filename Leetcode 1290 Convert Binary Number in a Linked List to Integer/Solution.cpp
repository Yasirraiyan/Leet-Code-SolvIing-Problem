/*  current = current->next;
        }
        rettruct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/

class Solution 
{
public:
    int getDecimalValue(ListNode* head) 
    {
       int ans=0;
       vector<int> vec;
       while(head!=nullptr)
{
  vec.push_back(head->val);
   head=head->next;
}    
for(int i=0;i<vec.size();i++)
{
  ans+=vec[i]*pow(2,vec.size()-i-1);
}
return ans;
}
};
