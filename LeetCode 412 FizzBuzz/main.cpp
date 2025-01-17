class Solution {
public:
    string fizzBuzz(int n) 
{
       

        for (int i = 1; i <= n; ++i) 
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                answer[i] = "FizzBuzz";
            } 
            else if (i % 3 == 0)
            {
                answer[i] = "Fizz";
            } 
            else if (i % 5 == 0)
            {
                answer[i] = "Buzz";
            }
            else
            {
                answer[i] = std::to_string(i);
            }
        }

        for (int i = 1; i <= n; ++i) 
        {
            std::cout << answer[i] << std::endl;
        }

        return answer[];
    }
};
