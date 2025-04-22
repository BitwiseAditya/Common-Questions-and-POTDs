/* Tower of Hanoi */

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char destination)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Move n-1 disks from source to helper
    towerOfHanoi(n - 1, source, destination, helper);

    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Move n-1 disks from helper to destination
    towerOfHanoi(n - 1, helper, source, destination);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "Steps to solve Tower of Hanoi with " << n << " disks:\n";
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
