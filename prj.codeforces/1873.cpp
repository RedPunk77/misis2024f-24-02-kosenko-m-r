///⠄⠄⠄⣾⣿⠿⠿⠶⠿⢿⣿⣿⣿⣿⣦⣤⣄⢀⡅⢠⣾⣛⡉⠄⠄⠄⠸⢀⣿⠄
///⠄⠄⢀⡋⣡⣴⣶⣶⡀⠄⠄⠙⢿⣿⣿⣿⣿⣿⣴⣿⣿⣿⢃⣤⣄⣀⣥⣿⣿⠄
///⠄⠄⢸⣇⠻⣿⣿⣿⣧⣀⢀⣠⡌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⣿⣿⣿⠄
///⠄⢀⢸⣿⣷⣤⣤⣤⣬⣙⣛⢿⣿⣿⣿⣿⣿⣿⡿⣿⣿⡍⠄⠄⢀⣤⣄⠉⠋⣰
///⠄⣼⣖⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⢇⣿⣿⡷⠶⠶⢿⣿⣿⠇⢀⣤
///⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣷⣶⣥⣴⣿⡗
///⢀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄
///⢸⣿⣦⣌⣛⣻⣿⣿⣧⠙⠛⠛⡭⠅⠒⠦⠭⣭⡻⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠄
///⠘⣿⣿⣿⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄⠹⠈⢋⣽⣿⣿⣿⣿⣵⣾⠃⠄
///⠄⠘⣿⣿⣿⣿⣿⣿⣿⣿⠄⣴⣿⣶⣄⠄⣴⣶⠄⢀⣾⣿⣿⣿⣿⣿⣿⠃⠄⠄
///⠄⠄⠈⠻⣿⣿⣿⣿⣿⣿⡄⢻⣿⣿⣿⠄⣿⣿⡀⣾⣿⣿⣿⣿⣛⠛⠁⠄⠄⠄
///⠄⠄⠄⠄⠈⠛⢿⣿⣿⣿⠁⠞⢿⣿⣿⡄⢿⣿⡇⣸⣿⣿⠿⠛⠁⠄⠄⠄⠄⠄
///⠄⠄⠄⠄⠄⠄⠄⠉⠻⣿⣿⣾⣦⡙⠻⣷⣾⣿⠃⠿⠋⠁⠄⠄⠄⠄⠄⢀⣠⣴
///⣿⣿⣿⣶⣶⣮⣥⣒⠲⢮⣝⡿⣿⣿⡆⣿⡿⠃⠄⠄⠄⠄⠄⠄⠄⣠⣴⣿⣿⣿
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

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, ans;
    cin >> t;
    while (t--) {
        ans = 0;
        chv2 a(10, chv(10));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (a[i][j] == 'X') {
                    if (i == j) ans += min(i+1, 10-i);
                    else {
                        if ((((i >= 0) && (i < 10)) && (j == 0 || j == 9)) || (((j >= 0) && (j < 10)) && (i == 0 || i == 9))) ans += 1;
                        else if ((((i >= 1) && (i < 9)) && (j == 1 || j == 8)) || (((j >= 1) && (j < 9)) && (i == 1 || i == 8))) ans += 2;
                        else if ((((i >= 2) && (i < 8)) && (j == 2 || j == 7)) || (((j >= 2) && (j < 8)) && (i == 2 || i == 7))) ans += 3;
                        else if ((((i >= 3) && (i < 7)) && (j == 3 || j == 6)) || (((j >= 3) && (j < 7)) && (i == 3 || i == 6))) ans += 4;
                        else if ((((i >= 4) && (i < 6)) && (j == 4 || j == 5)) || (((j >= 4) && (j < 6)) && (i == 1 || i == 5))) ans += 5;
                       // else if ((((i >= 1) && (i < 9)) && (j == 1 || j == 8)) || (((j >= 1) && (j < 9)) && (i == 1 || i == 8))) ans += 1;
                        //else if ((((i >= 1) && (i < 9)) && (j == 1 || j == 8)) || (((j >= 1) && (j < 9)) && (i == 1 || i == 8))) ans += 1;
                    }
                }
            }
        }
        cout << ans << "\n";

    }
    return 0;
}
