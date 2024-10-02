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
    ll t, k, n;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vll a(n);
        ll c = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] >= k) s += a[i];
            else {
                if (s != 0 && a[i] == 0) {
                    c++;
                    s--;
                }
            }
        }
        cout << c << "\n";
    }
    return 0;
}
