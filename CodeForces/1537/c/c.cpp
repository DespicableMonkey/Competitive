/**
 * author: DespicableMonkey
 * created: 06.18.2021 09:35:02
 * Potatoes FTW!
 **/ 

#include <algorithm>
#include<bits/stdc++.h>
#if LOCAL
    #include <DespicableMonkey/Execution_Time.h>
    #include <DespicableMonkey/Debug.h>
#endif

using namespace std;

#define pb push_back
#define f first
#define s second
#define my_brain_hurts int T = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

using ll = int64_t;
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T, class U> T cdiv(T a, U b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

inline namespace CP {
    inline namespace IO {
        void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
        void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
        void FastIO() { cin.tie(nullptr)->sync_with_stdio(0); }
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
        #define putr(s) return put(s), 0
    }
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (2e5+5); //Check the limits idiot
int N;
int a[MX];
int ans1[MX];
int ans2[MX];

int solve(int l) {
    int ind1 = 0, dif = INF;
    FOR(i, 0, N-1) {
        if(l==1) {
            if(abs(a[i] - a[i+1]) < dif) {
                        dif = abs(a[i] - a[i+1]);
                        ind1 = i;
                    }
        } else {
            if(abs(a[i] - a[i+1]) <= dif) {
                        dif = abs(a[i] - a[i+1]);
                        ind1 = i;
            }
        }
    }

    (l==1?ans1:ans2)[0] = a[ind1];
    (l==1?ans1:ans2)[N-1] = a[ind1+1];
    queue<int> l1, l2;

    FOR(i, 0, N) {
        if(i==ind1||i == ind1+1) continue;
        if(a[i] > a[ind1]) l1.push(a[i]);
        else l2.push(a[i]);
    }

    int op = 1;
    while(!empty(l1))
        (l==1?ans1:ans2)[op++] = l1.front(), l1.pop();
    while(!empty(l2))
        (l==1?ans1:ans2)[op++] = l2.front(), l2.pop();


    int cnt =0 ;
    FOR(i, 0, N-1)
        if((l==1?ans1:ans2)[i] < (l==1?ans1:ans2)[i+1])
            ++cnt;
    return cnt;
}

int test_case(int test_case = 0) {
    cin >> N;
    FOR(i, 0, N) cin >> a[i];

    sort(a, a+N);


    int s1 = solve(1);
    int s2 = solve(2);
    if(s1 > s2) {
        FOR(i, 0, N)
            cout << ans1[i] << ' ' ;
            cout << '\n';
    } else {
        FOR(i, 0, N)
            cout << ans2[i] << ' ';
            cout << '\n';
    }

    


    return 0;
}

int main () {
    CP::IO::SetIO();
    CP::IO::FastIO();

    #if LOCAL
        CP::IO::setIn("in1.txt");
        CP::ExecTime::use_clock();
        debug = true;
    #endif
    my_brain_hurts
    cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        if (debug) { cerr << "\033[33m" << "\n[Test #" << (tt) << "]\n" << "\033[0m"; }
        test_case(tt);
    }

    #if LOCAL
        CP::ExecTime::log_time(0);
    #endif

    return 0;
}