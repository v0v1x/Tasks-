#include <vector>

void appendVector(std::vector<int>& v1, std::vector<int>& v2) {
    v2.insert(v2.end(), v1.begin(), v1.end());
    v1.clear();
}
