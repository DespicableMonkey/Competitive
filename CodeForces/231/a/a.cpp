#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <deque>
#include <bitset>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <random>
#include <initializer_list>
#include <ios>

using namespace std;

#define ll long long;

#define vi vector<int>
#define pb push_back

#define nl << endl;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

const int INF = 1000000000;
const int MOD = 1000000000;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int c = 0;
    while(N--) {
        int a,b,d;
        cin >> a >> b >> d;
        if(a+b+d >= 2)
            ++c;
    }
    cout << c;
}