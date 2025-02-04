#include<vector>
class Solution {
public:
 bool isPrime(int num) 
 {
        if (num <= 1) 
        return false;
        if (num <= 3)
         return true;
        if (num % 2 == 0 || num % 3 == 0) 
        return false;
        for (int i = 5; i * i <= num; i += 6) 
        {
            if (num % i == 0 || num % (i + 2) == 0) 
            return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int count=0;
        int prime;
        vector<int>primes;
       int largestPrime = 0;
      for(int i=0;i<nums.size();i++)  
      {
        for(int j=0;j<nums.size();j++)
        {
            if(i==j||(i+j==nums.size()-1))
            {
                 if (isPrime(nums[i][j])) {
                        prime = nums[i][j];
                        primes.push_back(prime);
                    }
            }
        }
      } 
        if (!primes.empty()) 
        {
            largestPrime = primes[0];
            for (int prime : primes) 
            {
                if (prime > largestPrime)
                 {
                    largestPrime = prime;
                }
            }
        }
         return largestPrime;
    }
};
