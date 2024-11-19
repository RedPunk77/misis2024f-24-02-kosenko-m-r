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
            ll n, m;
            cin >> n >> m; 
            vector<string> s(n); 
            for (int j = 0; j < n; ++j) {
                cin >> s[j];
            }
            ll minx = INF;
            ll miny = INF;
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < m; ++y) {
                    if (s[x][y] == 'R') {
                        minx = min(minx, ll(x));
                        miny = min(miny, ll(y));
                    }
                }
            }
            if (minx < INF && s[minx][miny] == 'R') {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
        return 0;
    }
