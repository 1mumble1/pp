#include <iostream>

using namespace std;

int main()
{
    cout << "Enter string: ";
    string str;
    cin >> str;
    cout << "First symbol: " << str.front() << endl;
    cout << "Last symbol: " << str.back() << endl;

    return 0;
}
