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
const int MAX = 1010; // PLZ CHK!

int N,L;
pll A[MAX];

int ccw(pll p1, pll p2, pll p3) {
    ll t1=p1.F*p2.S+p2.F*p3.S+p3.F*p1.S;
    ll t2=p2.F*p1.S+p3.F*p2.S+p1.F*p3.S;
    if (t1==t2) return 0;
    return t1>t2?1:-1;
}

int main() {
    fio();

    cin>>N>>L;
    for (int i=0; i<N; i++) cin>>A[i].F>>A[i].S;
    sort(A,A+N);

    vector<int> U,D;

    U.pb(0);
    for (int i=1; i<N; i++) {
        while (sz(U)>1) {
            int j=U.back(); U.pop_back();
            int k=U.back();
            if (ccw(A[k],A[j],A[i])<0) {
                U.pb(j);
                break;
            }
        }
        U.pb(i);
    }

    D.pb(0);
    for (int i=1; i<N; i++) {
        while (sz(D)>1) {
            int j=D.back(); D.pop_back();
            int k=D.back();
            if (ccw(A[k],A[j],A[i])>0) {
                D.pb(j);
                break;
            }
        }
        D.pb(i);
    }

    double ans=0;
    for (int i=1; i<sz(U); i++) {
        int a=U[i], b=U[i-1];
        ans+=sqrt(1.0*(A[a].F-A[b].F)*(A[a].F-A[b].F)+1.0*(A[a].S-A[b].S)*(A[a].S-A[b].S));
    }
    for (int i=1; i<sz(D); i++) {
        int a=D[i], b=D[i-1];
        ans+=sqrt(1.0*(A[a].F-A[b].F)*(A[a].F-A[b].F)+1.0*(A[a].S-A[b].S)*(A[a].S-A[b].S));
    }
    ans+=2.0*L*acos(-1);

    cout<<(ll)(ans+0.5);
    return 0;
}