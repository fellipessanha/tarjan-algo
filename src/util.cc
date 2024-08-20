#include <cstdlib>
#include <functional>
#include <utility>

std::pair<int, int> generate_random_pair(int n){
    int a = rand() % n, b = rand() % (n-1);
    if(a == b){
        return {a, n-1};
    }
    return {a, b};
}

template<typename T, typename V>
struct pairHash{
    std::size_t operator() (const std::pair<T, V>&p) const{
        return std::hash<T>()(p.first) ^ (std::hash<V>()(p.second) >> 1);
    }
};
