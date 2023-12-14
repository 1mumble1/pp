#include <vector>
#include <iostream>

int main()
{
    std::vector<std::vector<int>> sourceVector{
        { 0, 1, 2, 3, 4 },
        { 1, 2, 3, 4, 5 },
        { 2, 3, 4, 5, 6 },
        { 3, 4, 5, 6, 7 }
    };

    for (int i = 0; i < sourceVector.size(); i++) {
        std::vector<int> lowerVector = sourceVector[i];
        for (int j = 0; j < lowerVector.size(); j++) {
            std::cout << lowerVector[j] << ' ';
        }
        std::cout << '\n';
    }
}