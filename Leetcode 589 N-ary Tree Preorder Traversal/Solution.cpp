class Solution 
{
public:
    vector<int> preorder(Node* root) 
    {
       vector<int>v;
      if (root == nullptr) return v;
        stack<Node*>st;
        st.push(root);
       
        while(!st.empty())
        {
          Node* top=st.top();
          if(top!=nullptr)
          {
            v.push_back(top->val);
            st.pop();
          }
         for(int i=top->children.size()-1;i>=0;i--)
         {
          st.push(top->children[i]);
         }
        }
        return v;
    }
};
