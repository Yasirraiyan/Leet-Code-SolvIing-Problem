class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        unordered_set<ListNode*> set1;
        ListNode* ans=nullptr;
        while(headA!=nullptr)
            {
                set1.insert(headA);
                headA=headA->next;
            }
       while(headB!=nullptr)
           {
               if(set1.find(headB)!=set1.end())
               {
                   ans=headB;
                   break;
               }
               headB=headB->next;
           }
        return ans;
    }
};
