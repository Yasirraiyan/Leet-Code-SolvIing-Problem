class Solution 
{
public:
    bool isOneBitCharacter(vector<int>& bits)
     {
        int slow=0;
        int fast=0;
        bool one=false;
        while(slow<bits.size()&&fast<bits.size())
        {
            if(bits[slow]==1)
            {
                slow+=2;
            }
        else if(bits[slow]==0&&slow<bits.size()-1)
            {
                slow++;
            }
            if(slow==bits.size()-1&&bits[slow]==0)
            {
                one=true;
                break;
            }
           
        }
        return one;
    }
};
