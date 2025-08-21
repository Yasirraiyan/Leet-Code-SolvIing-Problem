class MinStack 
{
public:
    stack<int>st;
    MinStack() 
    {
        
    }
    int findmin(vector<int>&v)
    {
        int min=v[0];
        for(int i=1;i<v.size();i++)
            {
                if(v[i]<min)
                {
                    min=v[i];
                }
            }
        return min;
    }
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        if(!st.empty()) st.pop();
    }
    
    int top()
    {
        if(st.empty()) return -1;
        int ans;
        if(!st.empty())
        {
            ans=st.top();
        }
        return ans;
    }
    
    int getMin() 
    {
        vector<int>v;
        if(st.empty()) return -1;
        while(!st.empty())
            {
                int top=st.top();
                st.pop();
                v.push_back(top);
            }
        int ans=findmin(v);
        for(int j=v.size()-1;j>=0;j--)
            {
                st.push(v[j]);
            }
        return ans;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
