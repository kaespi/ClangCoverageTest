#include <cov1/cov1_b.h>

namespace cov1
{

std::string concatStr(int a, int b)
{
    std::string c{""};

    const auto toStr = [](int x) {
        if (x >= 0) {
            return std::to_string(x);
        } else {
            const auto absX = -x;
            return "m" + std::to_string(absX);
        }
    };

    if (a == 0 && b == 0) {
        c = "00";
    } else {
        const auto s1 = toStr(a);
        const auto s2 = toStr(b);
        c = s1 + s2;
    }

    return c;
}

}  // namespace cov1
