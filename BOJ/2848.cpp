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
const int MAX = 30; // PLZ CHK!

int main() {
    fio();
    int n;
    cin>>n;
    
    int in[MAX]={0}, is[MAX]={0};
    vector<string> a(n);
    for (auto &x:a) {
        cin>>x;
        for (char c:x) is[c-'a']=1;
    }

    vector<int> g[MAX];
    set<pii> ed;

    

    for (int i=0; i<n-1; i++) {
        string x=a[i], y=a[i+1];

        int p=0,sz=min(sz(x),sz(y));
        while (p<sz && x[p]==y[p]) p++;

        if (p<sz) ed.insert({x[p]-'a', y[p]-'a'});
        else if (sz(x)>sz(y)) {
            cout<<"!";
            return 0;
        }
    }

    for (auto [u,v]:ed) {
        g[u].pb(v);
        in[v]++;
    }

    queue<int> q;
    int v[MAX]={0}, cnt=0;
    for (int i=0; i<='z'-'a'; i++) {
        if (is[i]) {
            cnt++;
            if (in[i]==0) q.push(i);
        }
    }

    string ans;
    bool qq=0;
    for (int i=0; i<cnt; i++) {
        if (q.empty()) {
            cout<<"!";
            return 0;
        }

        if (sz(q)>1) qq=1;
        int cur=q.front(); q.pop();
        ans+=(char)(cur+'a');    
        for (int nxt:g[cur]) {
            if (--in[nxt]==0) {
                v[nxt]=1;
                q.push(nxt);
            }
        }
    }

    if (qq) cout<<"?";
    else cout<<ans;
    return 0;
}