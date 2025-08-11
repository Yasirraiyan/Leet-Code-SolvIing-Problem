class Solution 
{
public:
    bool validMountainArray(vector<int>& arr) 
    {
        bool increase=false;
        bool decrease=false;
        bool mountain;
        if(arr.size()<3)
        {
          mountain=false;
        }
        else
        {
          for(int i=0;i<arr.size()-1;i++)
          {
            if(i+1<arr.size())
            {
            if(arr[i]==arr[i+1])
            {
              mountain=false;
              break;
            }
            else if(arr[i]>arr[i+1])
            {
              decrease=true;
              if(!increase)
              {
                mountain=false;
                break;
              }
              mountain=decrease;
            }
            else
            {
              if(decrease)
              {
                mountain=false;
                break;
              }
              increase=true;
              mountain=increase;
            }
          }
          }
        }
          if(!increase||!decrease)
          {
            mountain=false;
          }
          
        
        return mountain;
    }
};
