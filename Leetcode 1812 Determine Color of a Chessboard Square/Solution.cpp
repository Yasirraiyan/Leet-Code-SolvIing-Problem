class Solution 
{
public:
    bool squareIsWhite(string coordinates)
    {
        int sum=0;
        for(int i=0;i<coordinates.size();i++)
            {
                if(isdigit(coordinates[i]))
                {
                    sum+=coordinates[i]-'0';
                }
                else
                {
                    sum+=coordinates[i]-'a'+1;
                }
            }
        bool iswhite=false;
        if(sum%2!=0)
        {
            iswhite=true;
        }
        return iswhite;
    }
};
