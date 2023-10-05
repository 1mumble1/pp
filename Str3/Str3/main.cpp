#include <iostream>

using namespace std;

int main()
{
    cout << "Enter string: ";
    string str;
    cin >> str;
    int index = 0;
    while (index != 6)
    {
        cout << "Choose what you want to do with string:" << endl;
        cout << "1. insert" << endl;
        cout << "2. erase" << endl;
        cout << "3. replace" << endl;
        cout << "4. find" << endl;
        cout << "5. new string" << endl;
        cout << "6. exit" << endl;

        cin >> index;

        string str1;
        int pos;
        int count;

        switch (index)
        {
            case 1:
                cout << "Position where insert: ";
                cin >> pos;
                cout << "What insert: ";
                cin >> str1;
                cout << "Your new string: " << str.insert(pos, str1) << endl;
                break;
            case 2:
                cout << "Position where erase: ";
                cin >> pos;
                cout << "How many erase: ";
                cin >> count;
                cout << "Your new string: " << str.erase(pos, count) << endl;
                break;
            case 3:
                cout << "Position where replace: ";
                cin >> pos;
                cout << "How many replace: ";
                cin >> count;
                cout << "What insert: ";
                cin >> str1;
                cout << "Your new string: " << str.replace(pos, count, str1) << endl;
                break;
            case 4:
                cout << "What find: ";
                cin >> str1;
                cout << "Index: " << str.find(str1) << endl;
                break;
            case 5:
                cout << "Enter string: ";
                cin >> str;
                break;
        }
    }
    return 0;
}