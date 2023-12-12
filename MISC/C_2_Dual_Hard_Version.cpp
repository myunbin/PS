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

void solve() {
    int N;
    cin>>N;
    vector<int> A(N+1);

    pii M={0,0}, m={30,0};
    int pl=0, mi=0;
    for (int i=1; i<=N; i++) {
        cin>>A[i];
        if (A[i]>0) M=max(M, {A[i],i}), pl++;
        if (A[i]<0) m=min(m, {A[i],i}), mi++;
    }

    if (pl==0) {
        cout<<N-1<<endl;
        for (int i=N-1; i>=1; i--) {
            cout<<i<<sp<<i+1<<endl;
        }
        return;
    }
    if (mi==0) {
        cout<<N-1<<endl;
        for (int i=2; i<=N; i++) {
            cout<<i<<sp<<i-1<<endl;
        }
        return;
    }
    vector<pii> ans;

    if (abs(M.F)>abs(m.F)) {
        if (mi<=12) {
            for (int i=1; i<=N; i++) {
                if (A[i]<0) ans.pb({i,M.S});
            }
            for (int i=2; i<=N; i++) {
                ans.pb({i,i-1});
            }
        }
        else {
            for (int i=0; i<5; i++) ans.pb({m.S,m.S});
            for (int i=1; i<=N; i++) {
                if (A[i]>0) ans.pb({i,m.S});
            }
            for (int i=N-1; i>=1; i--) {
                ans.pb({i,i+1});
            }
        }
    }
    else {
        if (pl<=12) {
            for (int i=1; i<=N; i++) {
                if (A[i]>0) ans.pb({i,m.S});
            }
            for (int i=N-1; i>=1; i--) {
                ans.pb({i,i+1});
            }
        }
        else {
            for (int i=0; i<5; i++) ans.pb({M.S,M.S});
            for (int i=1; i<=N; i++) {
                if (A[i]<0) ans.pb({i,M.S});
            }
            for (int i=2; i<=N; i++) {
                ans.pb({i,i-1});
            }
        }
    }

    cout<<sz(ans)<<endl;
    for (auto [x,y]:ans) cout<<x<<sp<<y<<endl;
}

int main() {
    fio();

    int t=1;
    cin>>t;
    while (t--) solve();

    return 0;
}