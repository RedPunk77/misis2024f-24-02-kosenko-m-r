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
	ll t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		ll n = 0;
		cin >> n;
		ll l = 1, p = 0;
		cin >> p;
		if (p == 1) {
			l += 1;
		}
		bool flag = true;
		for (int j = 1; j < n; ++j) {
			ll today = 0;
			cin >> today;
			if (today == 1) {
				if (p == 0) {
					l += 1;
				}
				else {
					l += 5;
				}
			}
			else {
				if (p == 0) {
					flag = false;
				}
			}
			p = today;
		}
		if (flag) {
			cout << l << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
	return 0;
}
