#include <cov1/cov1_a.h>

#include <array>
#include <cmath>
#include <stdexcept>
#include <string>

namespace cov1
{

int sqrtInt(const int x)
{
    int sqrtX = 0;

    static constexpr std::array<int, 5> sqrtTable{1, 4, 9, 16, 25};

    if (x < 0) {
        throw std::runtime_error(
            "negative integers don't have a square root (" + std::to_string(x) +
            ")");
    } else if (x <= sqrtTable.at(sqrtTable.size() - 1)) {
        for (sqrtX = 0; sqrtX < sqrtTable.size(); ++sqrtX) {
            if (x < sqrtTable.at(sqrtX)) {
                break;
            }
        }
    } else {
        sqrtX = static_cast<int>(std::sqrt(static_cast<double>(x)));
    }

    return sqrtX;
}

int absInt(const int x)
{
    int absX = 0;
    if (x > 0) {
        absX = x;
    } else {
        absX = -x;
    }
    return absX;
}

}  // namespace cov1
