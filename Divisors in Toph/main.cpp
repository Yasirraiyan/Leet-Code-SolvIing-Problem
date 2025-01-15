#include <iostream>

using namespace std;

int main() {
    int A;
    cin >> A;
    if((0 < A) && (A < 100))
    {
        for(int i = 1; i <= A; i++)  // Start the loop from 1 to avoid division by zero
        {
            if(A % i == 0)
            {
                cout << i << endl;
            }
        }
    }

    return 0;
}
