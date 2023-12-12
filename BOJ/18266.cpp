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
const int MAX = 50505; // PLZ CHK!

struct cow {
    int w,x,d;
    bool operator < (const cow &ot) const {
        return x<ot.x;
    }
};

int N,L;
cow A[MAX];

int main() {
    fio();

    int tw=0;
    cin>>N>>L;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for (int i=1; i<=N; i++) {
        cin>>A[i].w>>A[i].x>>A[i].d;
        if (A[i].d==1) pq.push({L-A[i].x,1});
        else pq.push({A[i].x,-1});
        tw+=A[i].w;
    }

    sort(A+1,A+N+1);
    int le=1,ri=N;

    int T=0,cw=0;
    while (!pq.empty() && 2*cw<tw) {
        auto [x,d]=pq.top(); pq.pop();
        T=x;
        if (d==1) {
            cw+=A[ri].w;
            ri--;
        }
        else {
            cw+=A[le].w;
            le++;
        }
    }

    vector<int> R;
    for (int i=1; i<=N; i++) {
        if (A[i].d==1) R.pb(A[i].x);
    }

    ll ans=0;
    for (int i=1; i<=N; i++) {
        if (A[i].d==-1) {
            int r=lb(all(R),A[i].x)-R.begin();
            int l=lb(all(R),A[i].x-2*T)-R.begin();
            ans+=r-l;
        }
    }

    cout<<ans;

    return 0;
}