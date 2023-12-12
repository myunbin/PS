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
const int MAX = 303030; // PLZ CHK!

int N,M;
ll A[MAX],B[MAX];

int main() {
    fio();

    cin>>N;
    for (int i=1; i<=N; i++) cin>>A[i];
    for (int i=1; i<=N; i++) cin>>B[i];

    M=(N+1)/2;
    vector<ll> v;
    v.pb(A[M]), v.pb(B[M]);
    for (int i=M-1,j=M+1,k=1; i>=1; i--,j++,k++) {
        v.pb(A[i]-1ll*k), v.pb(B[i]-1ll*k);
        v.pb(A[j]-1ll*k), v.pb(B[j]-1ll*k);
    }

    sort(all(v));

    ll m=max(0ll,v[N]), ans=0;
    for (int i=0; i<2*N; i++) ans+=abs(v[i]-m);

    cout<<ans;
    return 0;
}
