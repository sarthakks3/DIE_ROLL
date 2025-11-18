#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    int f = 0, n = 1;
    cout << "****************DIE ROLL****************\n";
    cout << "Enter No. of faces on the dice: ";
    cin >> f;
    cout << "Enter No. of DICE(1-3): ";
    cin >> n;

    srand(time(NULL));

    switch(n){
        case 1:
        {
            int num = (rand() % f) + 1;
            cout << "Final Result:\n";
            cout << num << endl;
            break;
        }

        case 2:
        {
            int num1 = (rand() % f) + 1;
            int num2 = (rand() % f) + 1;
            cout << "Final Result:\n";
            cout << num1 << endl << num2 << endl;
            break;
        }

        case 3:
        {
            int num1 = (rand() % f) + 1;
            int num2 = (rand() % f) + 1;
            int num3 = (rand() % f) + 1;
            cout << "Final Result:\n";
            cout << num1 << endl << num2 << endl << num3 << endl;
            break;
        }

        default:
            cout << "Enter No. between (1-3)\n";
            break;
    }

    return 0;
}
