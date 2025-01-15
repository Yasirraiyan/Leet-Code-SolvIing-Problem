#include <iostream>

using namespace std;

pair<bool, int> is_factorial_divisible_by_10(int n) {
    int count = 0;
    

    int factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;

        // Check if factorial is divisible by 10 during calculation
        while (factorial % 10 == 0) {
            count++;
            factorial /= 10; 
        }
    }

    // Return true if count > 0, indicating trailing zeros
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    


        cout << "The factorial of " << n << " is divisible by 10 with " << result.second << " trailing zeros." << endl;
     

    return 0;
}
