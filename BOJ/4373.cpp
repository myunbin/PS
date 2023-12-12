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

vector<int> A;
map<int,vector<pii>> P,M;

bool solve() {
    int N;
    cin>>N;
    if (N==0) return 0;

    A.clear(),P.clear(),M.clear();
    A.resize(N);
    for (int &x:A) cin>>x;

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            P[A[i]+A[j]].pb({i,j});
            P[A[i]+A[j]].pb({j,i});

            M[A[i]-A[j]].pb({i,j});
            M[A[j]-A[i]].pb({j,i});
        }
    }

    for (auto &[x,v]:P) sort(all(v));
    for (auto &[x,v]:M) sort(all(v));

    int ans=-1;
    for (auto &[x,v]:M) {
        if (P.find(x)==P.end()) continue;
        auto &u=P[x];

        bool ok=0;
        for (auto [i,j]:v) {
            int k=lb(all(u),pii({i,-1}))-u.begin();
            int l=lb(all(u),pii({j,-1}))-u.begin();
            
            bool isk=0,isl=0;
            if (k<sz(u) && u[k].F==i) isk=1;
            if (l<sz(u) && u[l].F==j) isl=1;

            if (isk&&isl) {
                
            }
            else if (isk) {

            }
            else if (isl) {

            }
            else {

            }

            if (ok) break;
        }
    }

    if (ans<0) cout<<"no solution\n";
    else cout<<ans<<endl;

    return 1;
}
int main() {
    fio();
    while (solve());
    return 0;
}