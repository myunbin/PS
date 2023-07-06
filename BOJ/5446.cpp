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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

struct tn {
    bool vld, del, val;
    int cld[63];
    tn() {
        vld=0;
        del=0;
        val=1;
        for (int i=0; i<63; i++) cld[i]=-1;
    }
};

struct trie {
    vector<tn> tr;
    int ans=0;

    int add_nd() {
        tn t;
        tr.pb(t);
        return sz(tr)-1;
    }

    void _add(string &str, int nd, int idx, bool d) {
        if (idx==sz(str)) {
            tr[nd].vld=1;
            tr[nd].del=d;
            tr[nd].val=d;
            return;
        }

        int c;
        if ('A'<=str[idx] && str[idx]<='Z') c=str[idx]-'A';
        else if ('a'<=str[idx] && str[idx]<='z') c=str[idx]-'a'+26;
        else if (str[idx]=='.') c=52;
        else c=str[idx]-'0'+53;

        if (tr[nd].cld[c]==-1) {
            int nxt=add_nd();
            tr[nd].cld[c]=nxt;
        }
        _add(str, tr[nd].cld[c], idx+1,d);
    }

    bool exist(string &str) {
        int cur=0;
        for (int i=0; i<sz(str); i++) {
            int c;
            if ('A'<=str[i] && str[i]<='Z') c=str[i]-'A';
            else if ('a'<=str[i] && str[i]<='z') c=str[i]-'a'+26;
            else if (str[i]=='.') c=52;
            else c=str[i]-'0'+53;
            
            if (tr[cur].cld[c]==-1) return 0;
            cur=tr[cur].cld[c];
        }
        return tr[cur].vld;
    }
    
    void go(int cur) {
        for (int i=0; i<63; i++) {
            if (tr[cur].cld[i]==-1) continue;

            int nxt=tr[cur].cld[i];

            go(nxt);
            tr[cur].val&=tr[nxt].val;
        }
    }

    void f(int cur) {
        if (tr[cur].val) {
            ans++;
            return;
        }
        if (tr[cur].vld&&tr[cur].del) ans++;

        for (int i=0; i<63; i++) {
            if (tr[cur].cld[i]==-1) continue;
            int nxt=tr[cur].cld[i];
            f(nxt);
        }
    }

    trie() {add_nd();}
    void add(string &str, bool d) {_add(str,0,0,d);}  
};

void solve() {
    trie a;

    int n1;
    cin>>n1;
    for (int i=0; i<n1; i++) {
        string s; cin>>s;
        a.add(s,1);
    }

    int n2;
    cin>>n2;
    for (int i=0; i<n2; i++) {
        string s; cin>>s;
        a.add(s,0);
    }

    a.go(0);
    a.f(0);

    cout<<a.ans<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}