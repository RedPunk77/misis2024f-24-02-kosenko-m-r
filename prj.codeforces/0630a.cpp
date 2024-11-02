#include <iostream>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <map>
#include <unordered_map>
#include <iterator>
#include <numeric>
#include <random>
#include <chrono>

#pragma GCC optimize("O3", "fast-math")
#pragma GCC target("avx2")

using namespace std;
using vll = vector <long long>;
using vll2 = vector <vll>;
using chv = vector <char>;
using ull = uint64_t;
using ll = int64_t;
using ui = uint32_t;
using ush = uint16_t;
const ll INF = 1e18;
const double EPS = 1e-12;

ll SUM(string a) {
    ll m = 0;
    for (int i = 0; i < size(a); ++i) {
        m += int(a[i]);
    }
    return m;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << 25;
}
