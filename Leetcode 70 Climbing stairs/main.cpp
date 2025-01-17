class Solution 
public: 
int sumDivisors(int n) 
{ 
int sum = 0;
int count = 0;
for (int i = 1; i <= n; i++)
  { 
    if (n % i == 0) 
    { 
      sum += i; 
    } count++; 
  } 
return count; 
}// Returning count, though this method is typically used for sum of divisors }
