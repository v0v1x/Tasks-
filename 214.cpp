#include <iostream>
#include <map>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::map<std::string, int> m;

    for (int i = 0; i < N; ++i) {
        std::string key;
        int value;
        std::cin >> key >> value;
        m[key] = value;
    }

    for (const auto& pair : m) {
        std::cout << pair.first << "-" << pair.second << std::endl;
    }

    return 0;
}
