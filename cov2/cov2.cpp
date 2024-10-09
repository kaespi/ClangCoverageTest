#include <cov1/cov1_a.h>
#include <cov2/cov2.h>

namespace cov2
{

int linearEval(const int x, const int offset, const int a, const int b)
{
    const auto absDelta = cov1::absInt(x - offset);

    return a + absDelta * b;
}

}  // namespace cov2
