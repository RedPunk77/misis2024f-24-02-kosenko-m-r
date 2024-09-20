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
    ll t, n;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        vll a(1000);
        for (int i = 0; i<n; ++i) {
            ll m;
            cin >> m;
            ++a[m];
        }
        ll j = 1;
        for (int i = 0; i < x;)
        {
            if (a[j] == 0)
            {
                a[j]++;
                i++;
            }
            j++;
        }

        ll i = 1;
        for (i; i < 1000; i++) {
            if (a[i] == 0) break;
        }
        cout << i - 1 << "\n";
    }
    return 0; 
}
