#include <iostream>
#include <set>
#include <iterator>

int main()
{
    const int AddElement = 1;
    const int DeleteElement = 2;
    const int Exit = 3;

    std::set<int> sourceSet;
    int userChoose = 0;
    while (userChoose != Exit)
    {
        std::cout << "Choose what you want to do with set:\n";
        std::cout << "1. insert \n";
        std::cout << "2. erase \n";
        std::cout << "3. exit \n";

        std::cin >> userChoose;

        int tempElement;

        switch (userChoose)
        {
        case AddElement:
            std::cin >> tempElement;
            sourceSet.insert(tempElement);
            break;
        case DeleteElement:
            std::cin >> tempElement;
            sourceSet.erase(tempElement);
            break;
        }
        std::copy(sourceSet.begin(), sourceSet.end(), ostream_iterator<int>(cout, " "));
    }
    return 0;
}