#include <cstdio>
#include <random>

#include "gem5/m5ops.h"

int main()
{
    const int N = 1000;
    double x[N], y[N], alpha = 0.5;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1,2);

    for (int i = 0; i < N; i++) {
        x[i] = dis(gen);
        y[i] = dis(gen);
    }

    m5_dump_reset_stats(0, 0);
    for (int i = 0; i < N; i++) {
        y[i] = alpha * x[i] + y[i];
    }
    m5_dump_reset_stats(0, 0);

    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += y[i];
    }

    printf("sum: %lf\n", sum);
    return 0;
}
