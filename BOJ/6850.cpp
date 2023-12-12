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
const int MAX = 10101; // PLZ CHK!

int N;
pll A[MAX];

int ccw(pll a, pll b, pll c) {
    ll t1=a.F*b.S+b.F*c.S+c.F*a.S;
    ll t2=a.S*b.F+b.S*c.F+c.S*a.F;
    if (t1==t2) return 0;
    return t1>t2?1:-1;
}

ll ccw2(pll a, pll b, pll c) {
    ll t1=a.F*b.S+b.F*c.S+c.F*a.S;
    ll t2=a.S*b.F+b.S*c.F+c.S*a.F;
    return t1-t2;
}

vector<pll> ch() {
    sort(A,A+N);
    vector<pll> U,D;
    for (int i=0; i<N; i++) {
        while (sz(U)>1 && ccw(*(++U.rbegin()), *U.rbegin(), A[i])>=0) U.pop_back();
        while (sz(D)>1 && ccw(*(++D.rbegin()), *D.rbegin(), A[i])<=0) D.pop_back();
        U.pb(A[i]), D.pb(A[i]);
    }
    reverse(all(U));
    for (int i=1; i<sz(U)-1; i++) D.pb(U[i]);
    return D;
}

int main() {
    fio();
    cin>>N;
    for (int i=0; i<N; i++) cin>>A[i].F>>A[i].S;

    vector<pll> C=ch();
    double sum=0;
    for (int i=1; i<sz(C)-1; i++) {
        sum+=ccw2(C[0],C[i],C[i+1]);
    }
    sum=1.0*abs(sum)/2.0;

    cout<<floor(sum/50.0);
    return 0;
}