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
    ll t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ll c = 0;
        string s;
        cin >> s;
        //if (count(s.begin(), s.end(), 'W') == n) cout << 0 << "\n";
        for (int i = 0; i <n; ++i) {
            if (s[i] == 'B') {
                ++c;
                i += k - 1;
            }
        }
        cout << c << "\n";
    }
    return 0;
}
