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

bool f(int n) {
    int x = n % 10;
    int y = (n / 10) % 10;
    int z = (n / 100) % 10;
    int t = (n / 1000);
    if ((x == y) || (x == z) || (x == t) || (y == z) || (z == t) || (y == t)) {
        return false;
    }
    else return true;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //fstream file("C:\\Users\\Макар\\Desktop\\liberal.txt");
    ll a;
    cin >> a;
    ++a;
    while (!f(a)) {
        ++a;
    }
    cout << a;
    return 0;
}
