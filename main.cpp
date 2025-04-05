#include "scooter.h"
using namespace std;
using namespace Aaa;

int main() {
    Scooter* arr = nullptr;
    int count = 0;
    arr = load(count);
    int n;
    do {
        cout << ("---------------------------------------\n") << endl;
        cout << ("Menu for Scooter Rental:\n") << endl;
        cout << ("1 Add a new scooter\n") << endl;
        cout << ("2 Show all scooters\n") << endl;
        cout << ("3 Delete a scooter\n") << endl;
        cout << ("4 Edit a scooter\n") << endl;
        cout << ("5 Search for a scooter\n") << endl;
        cout << ("6 Exit\n") << endl;
        cout << ("---------------------------------------\n") << endl;
        cin >> n;
        switch (n) {
        case 1:
            arr = create(count);
            break;
        case 2:
            show(arr, count);
            break;
        case 3:
            add(&arr, &count);
            break;
        case 4:
            del(arr, &count);
            break;
        case 5:
            edit(arr, count);
            break;
        case 6:
            search(arr, count);
            break;
        case 0:
            cout << "Chao" << endl;
            save(arr, count);
            delete[] arr;
            break;
        default:
            cout << "xd\n";
        }
    } while (n != 0);
    return 0;
}
