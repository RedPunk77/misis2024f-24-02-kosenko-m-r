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
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iterator>
#include <cmath>
#include <numeric>
#include <random>
#include <chrono>

using namespace std;
using vll = vector <long long>;
using vll2 = vector <vll>;
using chv = vector <char>;
using chv2 = vector <chv>;
using ull = uint64_t;
using ll = int64_t;
using ui = uint32_t;
using ush = uint16_t;
const ll INF = 1e18;
const double EPS = 1e-12;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        vll2 a(2, vll(2));
        for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j)  cin >> a[i][j];
        ll cnt = a[0][0] + a[0][1] + a[1][0] + a[1][1];
        if (cnt == 0) cout << 0 << "\n";
        else if (cnt == 4)  cout << 2 << "\n";
        else cout << 1 << "\n";
    }
    return 0;
}
