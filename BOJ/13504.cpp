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
const int MAX = 101010; // PLZ CHK!

const int I_SZ=2; // 입력으로 들어오는 문자의 종류
struct tn {
    bool vld;
    int cld[I_SZ];
    tn() {
        vld=0;
        for (int i=0; i<I_SZ; i++) cld[i]=-1;
    }
};

struct trie {
    vector<tn> tr;

    int add_nd() {
        tn t;
        tr.pb(t);
        return sz(tr)-1;
    }

    int ci(char c) { // 입력으로 들어오는 문자 분류
        return (int)(c-'0');
    }

    void _add(string &str, int nd, int idx) {
        if (idx==sz(str)) {
            tr[nd].vld=1;
            return;
        }

        int c=ci(str[idx]);

        if (tr[nd].cld[c]==-1) {
            int nxt=add_nd();
            tr[nd].cld[c]=nxt;
        }
        _add(str, tr[nd].cld[c], idx+1);
    }

    bool exist(string &str) {
        int cur=0;
        for (int i=0; i<sz(str); i++) {
            int c=ci(str[i]);
            
            if (tr[cur].cld[c]==-1) return 0;
            cur=tr[cur].cld[c];
        }
        return tr[cur].vld;
    }

    int qry(string &str, int nd, int idx) {
        if (idx==sz(str)) return 0;

        int c=ci(str[idx]);
        if (tr[nd].cld[!c]!=-1) {
            int nxt=tr[nd].cld[!c];
            return (1<<(31-idx))+qry(str, nxt, idx+1);
        }
        else {
            int nxt=tr[nd].cld[c];
            return qry(str, nxt, idx+1);
        }
    }

    trie() {add_nd();}
    void add(string &str) {_add(str,0,0);}  
};


void solve() {
    int n;
    cin>>n;

    int p=0, ans=0;
    trie tr;
    
    string s(32, '0');
    tr.add(s);

    for (int i=0; i<n; i++) {
        int x; 
        cin>>x;

        p^=x;
        bitset<32> b(p);
        s=b.to_string();
        ans=max(ans, tr.qry(s,0,0));
        tr.add(s);
    }
    cout<<ans<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}