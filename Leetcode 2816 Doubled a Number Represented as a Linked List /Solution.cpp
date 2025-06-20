class Solution 
{
public:
    ListNode* doubleIt(ListNode* head) 
    {
             vector<int>reserve;
        while(head!=nullptr)
            {
                reserve.push_back(head->val);
                head=head->next;
            }
        long long gen=0;
        //for(int i=0;i<reserve.size();i++)
   int carry=0;
        vector<int>result;
        for(int i=reserve.size()-1;i>=0;i--)
            {
            int  sum=reserve[i]*2+carry;
                result.push_back(sum%10);
                carry=sum/10;
            }
         
             
        if(carry>0)
        {
            result.push_back(carry);
        }
        
        reverse(result.begin(),result.end());
        ListNode* headd=new ListNode(result[0]);ListNode* current=headd;
       for(int j=1;j<result.size();j++)
           {
               
               
               current->next=new ListNode(result[j]);
               current =current->next;
           }
        return headd;
    }
    
}; 
