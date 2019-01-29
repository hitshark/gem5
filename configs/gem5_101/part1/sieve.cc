#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

size_t sieve_method(size_t N) {
    vector<bool> flag(N, true);
    for (auto i = 2; i < N; i++) {
        if (flag[i]) {
            for (auto j = i*i; j < N; j+=i) {
                flag[j] = false;
            }
        }
    }
    size_t num = std::count_if(
            flag.begin(), flag.end(), [](bool x) {return x;});
    return (num - 2);
}

int main()
{
    size_t N = 10;
    size_t num = sieve_method(N);
    std::cout<<"result: "<<num<<std::endl;

    return 0;
}
