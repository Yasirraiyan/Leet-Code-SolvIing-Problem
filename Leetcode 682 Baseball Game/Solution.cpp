#include <iostream>
#include <vector>
#include <stack>
class Solution 
{
public:
int calPoints(std::vector<std::string>& operations) 
{
   stack<int>st;
   int ans;
   int sum=0;
     for(int i=0;i<operations.size();i++)
   {
   if(operations[i]=="C")
    {
      if (!st.empty()) 
      st.pop();
    }
    else if(operations[i]=="D")
    {
      if(!st.empty())
      {
      st.push(2*st.top());
      }
    }
    else if(operations[i]=="+")
    {
   if(st.size()>=2)
   {
   int top1=st.top();
   st.pop();
   int top2=st.top();
   st.push(top1);
  int top3=top1+top2;
 st.push(top3);
 }
    }
   else
   {
    int val=std::stoi(operations[i]);
    if(val>=-30000&&val<=30000)
    {
      st.push(val);
    }
   }
   }
    while(!st.empty())
   {
    sum+=st.top();
    st.pop();
   }
    return sum;
}
};
