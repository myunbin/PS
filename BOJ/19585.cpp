#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(), x.rend()
#define cmprs(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define endl "\n"
#define sp " "
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define rz resize
#define sz(a) (int)(a.size())
#define clr(a) a.clear()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 4040; // PLZ CHK!

const int I_SZ=26; // 입력으로 들어오는 문자의 종류
struct tn {
    bool vld;
    vector<pii> ch;
    tn() {
        vld=0;
    }
};

struct trie {
    vector<tn> tr;
    int p;

    int add_nd() {
        return (p++);
    }

    int ci(char c) { // 입력으로 들어오는 문자 분류
        return (int)(c-'a');
    }

    void _add(string &str, int nd, int idx) {
        if (idx==sz(str)) {
            tr[nd].vld=1;
            return;
        }

        int c=ci(str[idx]);
        bool ok=0;
        for (auto [x,y]:tr[nd].ch) {
            if (x==c) {
                _add(str, y, idx+1);
                ok=1;
                break;
            }
        }
        
        if (!ok) {
            int nw=add_nd();
            tr[nd].ch.emplace_back(c,nw);
            tr[nd].ch.shrink_to_fit();
            _add(str, nw, idx+1);
        }
    }

    void _exist(string &str, int nd, int idx, vector<int> &ret) {
        if (tr[nd].vld) ret[idx]=1;

        if (idx==sz(str)) {
            return;
        }

        int c=ci(str[idx]);
        for (auto [x,y]:tr[nd].ch) {
            if (x==c) {
                _exist(str, y, idx+1, ret);
                return;
            }
        }
    }

    trie() {
        p=0;
        tr.resize(9000001);
        add_nd();
    }
    void add(string &str) {_add(str,0,0);}  
    void exist(string &str, vector<int> &ret) {_exist(str,0,0,ret);}
};

int C,N;
string A[MAX],B[MAX];
trie cl, nm;

int main() {
    fio();
    cin>>C>>N;
    for (int i=0; i<C; i++) {
        cin>>A[i];
        cl.add(A[i]);
    }
    for (int i=0; i<N; i++) {
        cin>>B[i];
        reverse(all(B[i]));
        nm.add(B[i]);
    }

    int Q;
    cin>>Q;
    while (Q--) {
        string s; cin>>s;
        vector<int> r1(sz(s)+1), r2(sz(s)+1);
        
        cl.exist(s, r1);
        reverse(all(s));
        nm.exist(s, r2);

        bool ok=0;
        for (int i=1; i<sz(s); i++) {
            if (r1[i] && r2[sz(s)-i]) {
                ok=1;
                break;
            }
        }

        cout<<(ok?"Yes\n":"No\n");
    }

    return 0;
}