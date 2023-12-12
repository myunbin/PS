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
const int MAX = 111; // PLZ CHK!

int N;
pll A[MAX];

int ccw(pll a, pll b, pll c) {
    ll t1=a.F*b.S+b.F*c.S+c.F*a.S;
    ll t2=a.S*b.F+b.S*c.F+c.S*a.F;
    if (t1==t2) return 0;
    return t1>t2?1:-1;
}

vector<pll> ch() {
    sort(A,A+N);
    vector<pll> U,D;
    for (int i=0; i<N; i++) {
        while (sz(U)>=2 && ccw(*(++U.rbegin()), *U.rbegin(), A[i])>=0) U.pop_back();
        while (sz(D)>=2 && ccw(*(++D.rbegin()), *D.rbegin(), A[i])<=0) D.pop_back();
        U.pb(A[i]), D.pb(A[i]);
    }
    reverse(all(U));
    for (int i=1; i<sz(U)-1; i++) D.pb(U[i]);

    // for (auto [x,y]:D) cout<<
    return D;
}

void solve(int t) {
    memset(A,0,sizeof A);
    cin>>N;

    if (N==0) exit(0);
    for (int i=0; i<N; i++) cin>>A[i].F>>A[i].S;

    vector<pll> C=ch();
    double ans=1e12;

    int M=sz(C);
    for (int i=0; i<M; i++) {
        pll v1={C[(i+1)%M].F-C[i].F, C[(i+1)%M].S-C[i].S};

        double mx=0.0;
        for (int j=0; j<M; j++) {
            if (j==i || j==(i+1)%M) continue;
            pll v2={C[j].F-C[i].F, C[j].S-C[i].S};
            double d1=sqrt(1.0*v1.F*v1.F+1.0*v1.S*v1.S);
            double d2=sqrt(1.0*v2.F*v2.F+1.0*v2.S*v2.S);
            double th=acos(1.0*(v1.F*v2.F+v1.S*v2.S)/d1/d2);
            double l=sin(th)*d2;
            mx=max(mx, l);
        }
        ans=min(ans, mx);
    }

    cout<<fixed;
    cout.precision(2);
    cout<<"Case "<<t<<": "<<(ans+0.00499999)<<endl;
}

int main() {
    fio();
    for (int i=1;; i++) {
        solve(i);
    }

    return 0;
}