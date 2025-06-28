class Solution 
{
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
{
        vector<int>reserve;
        while(head!=nullptr)
        {
          reserve.push_back(head->val);
          head=head->next;
        }
        unordered_set<int>set1;
        
          for(int i=0;i<nums.size();i++)
          {
             set1.insert(nums[i]);
          }
          vector<int>choose;
          for(int j=0;j<reserve.size();j++)
         {
          if(set1.find(reserve[j])==set1.end())
          {
            choose.push_back(reserve[j]);
          }
         }
           if (choose.empty()) return nullptr;

         ListNode* headd=new ListNode(choose[0]);
         ListNode* curr=headd;
         for(int k=1;k<choose.size();k++)
         {
          curr->next=new ListNode(choose[k]);
          curr=curr->next;
         }
         return headd;
    }
};
