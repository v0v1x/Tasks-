#include <algorithm>
#include <string>

class ReversibleString {
public:
    ReversibleString(const std::string& s) : str(s) {}
    void Reverse() {
        std::reverse(str.begin(), str.end());
    }
    std::string ToString() const {
        return str;
    }
private:
    std::string str;
};
