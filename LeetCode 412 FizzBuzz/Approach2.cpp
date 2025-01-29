As amar array return chaise ami 1 ta array crate kori vector<ans>
  std::vector<std::string> answer;
 answer.reserve(n);// eta die reserve rakhi jayga ans push er jonno.
tarpor for loop chalai given array r upor
condition check
for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
               answer.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                answer.push_back("Fizz");
               
            } else if (i % 5 == 0) {
               
                answer.push_back("Buzz");
            } else {
                answer.push_back(std::to_string(i));
            }
        }
pura array print chaise so,
  for (const auto& str : answer) {
            std::cout << str << std::endl;
        }
return kori ans.
