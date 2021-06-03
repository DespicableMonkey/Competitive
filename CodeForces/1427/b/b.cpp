/**
 * author: DespicableMonkey
 * created: 06.02.2021 23:46:17
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>

using namespace std;

typedef int64_t ll;

using pii = pair<int, int>;
using pll = pair<long long, long long>;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
#define pb push_back
#define f first
#define s second

#define nl '\n'
#define CoMpIlAtIoN_ErRoR_oN_TeSt_CaSe_69420 int T = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FR(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = a; i >= b; --i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)
#define each(a,x) for (auto& a: x)

template<typename T, typename U> using p = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
const int MOD = 1'000'000'007;
const int INF = 2'000'000'000;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

namespace CP {
    inline namespace IO {
        void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
        void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
        void FastIO() {
            cin.tie(nullptr)->sync_with_stdio(0);
            std::cout << std::fixed << std::showpoint;
            std::cout << std::setprecision(14);
        }
        void setIO(string s = "") {
            cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
            if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
        }
        void setIO(string s, string t) {
            setIn(s);
            setOut(t);
        }
    }
    inline namespace ExecTime {
        #define cur_t std::chrono::high_resolution_clock::now() /* 64 mil =  ~1 second */
        auto _start_time = cur_t;
        bool use = 0;
        void use_clock() { use = 1; }
        void log_time(bool start = true) {
            if(use) {
                if(!start) {
                    auto _stop_time = cur_t;
                    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(_stop_time - _start_time);
                    cerr << '\n' << "[Time: " << to_string(duration.count()) << " ms] " << '\n' << '\n';
                }
                else
                    _start_time = cur_t;
            }
        }
    }
}
inline namespace Output {
    void ff() {  fflush(stdout); }
    bool debug = 0;
    const string RESET = "\033[0m", GREEN="\033[32m", BLACK="\033[30m", RED="\033[31m", YELLOW="\033[33m";    
    #define dbg1(arg) {if(debug){cerr << GREEN << " [" << #arg << ": " << arg << "] " << RESET << '\n';}}
    #define dbg2(arg, arg2) {if(debug){cerr << GREEN << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << "] " << RESET << '\n';}}
    #define dbg3(arg, arg2, arg3) {if(debug){cerr << GREEN << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << "] " << RESET << '\n';}}
    #define dbg4(arg, arg2, arg3, arg4) {if(debug){cerr << GREEN << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << ", " << #arg4 << ": " << arg4 << "] " << RESET << '\n';}}
    #define dbg5(arg, arg2, arg3, arg4, arg5) {if(debug){cerr << GREEN << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << ", " << #arg4 << ": " << arg4 << ", " << #arg5 << ": " << arg5 << "] " << RESET << '\n';}}
    #define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
    #define dbg(...) GET_MACRO(__VA_ARGS__, dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)
    void lower(std::string& s){transform(s.begin(), s.end(), s.begin(), ::tolower);}
    template<typename T, typename U> ostream& operator<<(ostream& is, pair<T, U> &v){is << "(" << v.first << " " << v.second << ")"; return is;}
    template<class T> void outv(vector<T> v) {
    for(T& i : v) cout << i << " "; cout << '\n'; }
    template<class T> void outarr(T a[], int N) {
        for(int i = 0; i < N; ++i) cout << a[i] << " "; cout << '\n'; }
    template<class T> void put(T s) {
        cout << s << '\n'; }
}
int N;
struct pred { bool operator()(const std::pair<int, int> &l, const std::pair<int, int> &r) { 
    return (l.s - l.f > r.s - r.f);
} };

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

template<class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */
bool fin(string s, char c) {
    for(char k : s)
        if(k == c) return 1;
    return 0;
}
void solve() {
    int K;
    string s;
    cin >> N >> K >> s;
    if(!fin(s, 'L')) {
        put(N*2-1); return;
    }
    if(!fin(s, 'W')) {
        put(K==0?0:K * 2 - 1);
        return;
    }
    priority_queue<pii, vt<pii>, pred> open;
    for(int i = 0; i < N - 1; ++i) {
        if(s[i] == 'W' && s[i+1] == 'L') {
            int x = ++i;
            while(s[i] != 'W' && i < N) ++i;
            if(s[i] == 'W' && i != N) open.push({x, i-1});
            --i;
        }
    }
    while(K>0 && !empty(open)) {
        auto x = open.top(); open.pop();
        if(s[x.f-1] == 'W') {
            for(int i = x.f; i <= x.s && K > 0; ++i) {
                s[i] = 'W'; --K;
            }
        } else {
            for(int i = x.s; i >= x.f && K > 0; --i) {
                s[i] = 'W'; --K;
            } 
        }
    }
    for(int i = 0; i < N && K > 0; ++i){
        if(s[i] == 'W') {
            for(int j = i-1; j >= 0 && K > 0; --j) {
                s[j] = 'W';
                --K;
            }
            break;
        }
    }
    for(int i = N-1; i >= 0 && K > 0; --i){
        if(s[i] == 'W')  {
            for(int j = i+1; j < N && K > 0; ++j) {
                 s[j] = 'W';
                 --K;
            }
            break;
        }
    }

    int score = 0;
    FOR(i, 0, N) {
        if(i != 0 && s[i-1] == 'W' && s[i] == 'W') score += 2;
        else if(s[i] == 'W') ++score;
    }
    dbg(s);
    put(score);


}

int main () {
    CP::IO::setIO();
    CP::IO::FastIO();

    #if LOCAL
        //CP::IO::setIn("in1.txt");
        CP::ExecTime::use_clock();
        debug = true;
    #endif

    CoMpIlAtIoN_ErRoR_oN_TeSt_CaSe_69420
    cin >> T;

    for(int tt = 1; tt <= T; ++tt){
        //cout << "Case #" << tt << ": ";
        if (debug) { cout << YELLOW << "\n[Test #" << (tt) << "]\n" << RESET; }
        solve();
    }

    CP::ExecTime::log_time(0);
    return 0;
}