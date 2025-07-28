class MyStack 
{
public:
    stack<int>st;
    MyStack() 
{
        
    }
    
    void push(int x) 
{
        st.push(x);
    }
    
    int pop() 
    {

        int top=-1;
        if(st.empty()) return top;
        if(!st.empty())
        {
            top=st.top();
            st.pop();
        }
        return top;
    }
    
    int top() 
    {
        int ans=-1;
        if(!st.empty())
        {
             ans=st.top();
        }
        return ans;
    }
    
    bool empty() 
{
        if(st.empty()) return true;
        else 
            return false;
    }
};
