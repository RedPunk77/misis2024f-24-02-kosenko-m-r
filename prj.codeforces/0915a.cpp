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
	ll n = 0, k = 0;
	cin >> n >> k;
	vll buckets(n);
	for (int i = 0; i < n; ++i) cin >> buckets[i];
	ll min = INF;
	for (int i = n - 1; i > -1; --i) {
		if (k % buckets[i] == 0) {
			if (k / buckets[i] < min) {
				min = k / buckets[i];
			}
		}
	}
	cout << min << '\n';
	return 0;
}
