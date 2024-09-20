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
using ull = uint64_t;
using ll = int64_t;
using ui = uint32_t;
using ush = uint16_t;
const ll INF = 1e18;
const double EPS = 1e-12;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //fstream file("C:\\Users\\Макар\\Desktop\\liberal.txt");
    ll t, a;
    cin >> t;
    while (t--) {
        cin >> a;
        ll x = a % 10;
        ll y = (a / 10) % 10;
        ll z = (a / 100) % 10;
        ll w = (a / 1000);
        ll c = bool(x) + bool(y) + bool(z) + bool(w);
        cout << c << "\n";
        if (w != 0) cout << w * 1000 << " ";
        if (z != 0) cout << z * 100 << " ";
        if (y != 0) cout << y * 10 << " ";
        if (x != 0) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
