/**
 * author: DespicableMonkey
 * created: 06.13.2021 23:20:39
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#if LOCAL
    #include <DespicableMonkey/Execution_Time.h>
    #include <DespicableMonkey/Debug.h>
#endif

using namespace std;

typedef int64_t ll;

#define pb push_back
#define f first
#define s second
#define x first
#define y second

#define my_brain_hurts int T = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> T cdiv(T a, T b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

[[maybe_unused]] const int MOD = 1'000'000'007;
[[maybe_unused]] const double EPS = (1e-9);
[[maybe_unused]] const int INF = 2'000'000'000; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
[[maybe_unused]] const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

inline namespace CP {
    inline namespace IO {
        void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
        void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
        void FastIO() {
            cin.tie(nullptr)->sync_with_stdio(0);
            std::cout << std::fixed << std::showpoint;
            std::cout << std::setprecision(14);
        }
        void SetIO(string s = "", string t = "") {
            cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
            if(sz(t)) setIn(s), setOut(t);
            else if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
        }
    }
    inline namespace Output {
        bool debug = 0;
        string operator+(string str, int num){return str + ts(num);}
        string operator+(int num, string str) { return str + ts(num); }
        string to_string(const char* s) { return string(s);}
        #if !defined LOCAL
            #define dbg(...)
        #endif
        template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
        template<class T> void put(T s) { cout << s << '\n'; }
    }
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

[[maybe_unused]] const int MX = (2e5+5);


void test_case([[maybe_unused]] int test_case = 0) {
    string s; cin >> s;
    string ans = " ";

    int N = sz(s);
    ans[0] = s[0];
    int last = 0;
    FOR(i, 1, N) {
        int ok = 0;
        if(!ok && last > 0 && ans[last-1] == s[i]) ok = 1, last = last-1;
        if(!ok && last < sz(ans) - 1 && ans[last+1] == s[i]) ok = 1, last = last + 1;

        if(!ok && count(ans.begin(), ans.end(), s[i]) != 0) {
            put("NO");
            return;
        }

        if(!ok && last == sz(ans) - 1) {
            last = sz(ans);
            ans.pb(s[i]);
            ok = 1;
        }

        if(!ok && last == 0) {
            last = 0;
            ans = s[i] + ans;
            ok = 1;
        }
        if(!ok) {
            put("NO");
            return;
        }

        dbg(ans, i, ok);
    } 

    put("YES");
    for(char i = 'a'; i <= 'z'; ++i)
        if(count(ans.begin(), ans.end(), i) == 0)
            ans.pb(i);
    put(ans);
   
}

int main () {
    CP::IO::SetIO();
    CP::IO::FastIO();

    #if LOCAL
        //CP::IO::setIn("in1.txt");
        CP::ExecTime::use_clock();
        debug = true;
    #endif
    my_brain_hurts
    cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        //cout << "Case #" << tt << ": ";
        if (debug) { cerr << "\033[33m" << "\n[Test #" << (tt) << "]\n" << "\033[0m"; }
        test_case(tt);
    }

    #if LOCAL
        CP::ExecTime::log_time(0);
    #endif

    return 0;
}