class MyQueue 
{
public:
    queue<int>q;
    MyQueue()
{
        
    }
    
    void push(int x) 
{
        q.push(x);
    }
    
    int pop() 
{
        int ans;
        int top=-1;
        if(!q.empty())
        {
            top=q.front();
            q.pop();
            //q.remove(top);
        }
      //  ans=top%st.size();
        return top;
    }
    
    int peek() 
{
        int front=q.front();
        
        return front;
    }
    
    bool empty()
{
        bool empty=false;
        if(q.empty()) empty=true;
         return empty;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
