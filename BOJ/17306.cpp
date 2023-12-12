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
    int cld[I_SZ],sz,cv,act;
    tn() {
        vld=0;
        sz=cv=act=0;
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
            tr[nd].act++;
            tr[nd].cld[c]=nxt;
        }
        _add(str, tr[nd].cld[c], idx+1);
    }

    void go(int nd) {
        tr[nd].sz=1;
        tr[nd].cv=tr[nd].vld;
        for (int i=0; i<I_SZ; i++) {
            int nxt=tr[nd].cld[i];
            if (nxt==-1) continue;
            go(nxt);
            tr[nd].sz+=tr[nxt].sz;
            tr[nd].cv+=tr[nxt].cv;
        }
    }

    pii ok(int cur) {
        if (tr[cur].act!=1) return {0,-1};
        int nxt;
        if (tr[cur].cld[0]!=-1) nxt=tr[cur].cld[0];
        else nxt=tr[cur].cld[1];
        
        return {tr[cur].cv==tr[nxt].cv,nxt};
    }
    int qry() {
        go(0);
        int i=0;
        for (i=0; ok(i).F; i=ok(i).S);
        return tr[i].sz;
    }

    trie() {add_nd();}
    void add(string &str) {_add(str,0,0);}  
};

int N;
trie T;

int main() {
    fio();
    cin>>N;
    for (int i=0; i<N; i++) {
        ll x; cin>>x;
        string s;
        while (x) {
            s+=(x%2ll+'0');
            x/=2ll;
        }
        reverse(all(s));
        T.add(s);
    }

    cout<<T.qry();
    return 0;
}