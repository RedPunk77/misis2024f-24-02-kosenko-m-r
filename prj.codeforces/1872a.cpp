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


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //fstream file("C:\\Users\\Макар\\Desktop\\liberal.txt");
    ll t;
    cin>>t;
    while(t--) {
        double a, b, x;
        cin>>a>>b>>x;
        if (a==b) {
            cout<<0<<"\n";
            continue;
        }
        double m = abs(a-b)/2;
        if (x > m) {
            cout<<1<<"\n";
            continue;
        }
        else cout<<ceil(m/x)<<"\n";
        
    }

    return 0;
}
