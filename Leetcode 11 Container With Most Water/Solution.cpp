class Solution 
{
public:
    int maxArea(vector<int>& height)
    {
        int left=0;
        int right=height.size()-1;
        vector<int>v;
        int a;
        int maxArea=0;
        while(left<=right&&right<height.size())
            {
            a=min(height[left],height[right])*(right-left);
                if(maxArea<a)
                {
                    maxArea=a;;
                }
                if(height[left]<height[right])
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        return maxArea;
    }
};
