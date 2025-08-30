class Solution 
{
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) 
    {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int move=0;
        for(int j=0;j<seats.size();j++)
        {
           move+=abs(seats[j]-students[j]);
        }
        return move;
    }
};
