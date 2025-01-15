class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        bool condition = false;  // Initialize condition with false

        for (int i = 1; i < num; i++)  // Loop should be till num-1 to exclude the number itself
        {
            if (num % i == 0) {
                sum += i;
            }
        }

        if (sum == num) {
            condition = true;
        }
        
        return condition;  // Ensure the function returns a value in all cases
    }
};
