#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> answer; // Create a vector of size n+1
            answer.reserve(n);// Reserve space for n elements to avoid reallocation
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
               answer.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                answer.push_back("Fizz");
                //answer[i] = "Fizz";
            } else if (i % 5 == 0) {
                //answer[i] = "Buzz";
                answer.push_back("Buzz");
            } else {
                answer.push_back(std::to_string(i));
            }
        }

        //for (int i = 1; i <= n; ++i) {
        //    std::cout << answer[i] << std::endl;
        //}
        for (const auto& str : answer) {
            std::cout << str << std::endl;
        }

        return answer;
    }
};
