#include <iostream>

using namespace std;

int main()
{
    cout << "Enter 1 string: ";
    string str1;
    cin >> str1;

    cout << "Enter 2 string: ";
    string str2;
    cin >> str2;

    (str1 != str2) ?
        cout << "Larger string: " << (str1.compare(str2) >= 0 ? str1 : str2) << endl :
        cout << "Strings are equal." << endl;
    return 0;
}
