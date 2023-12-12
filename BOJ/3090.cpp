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

int N,A[MAX],B[MAX];
ll T;

bool ok(int x) {
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int V[MAX]={0};

    for (int i=1; i<=N; i++) {
        pq.push({A[i],i});
        B[i]=A[i];
    }

    ll cnt=0;
    while (!pq.empty()) {
        auto [a,i]=pq.top(); pq.pop();
        if (V[i]) continue;
    
        V[i]=1;
        if (i>1) {
            if (a+x<B[i-1]) {
                cnt+=B[i-1]-a-x;
                B[i-1]=a+x;
                pq.push({B[i-1], i-1});
            }
        }
        if (i<N) {
            if (a+x<B[i+1]) {
                cnt+=B[i+1]-a-x;
                B[i+1]=a+x;
                pq.push({B[i+1], i+1});
            }
        }
    }

    return (cnt<=T);
}

int main() {
    fio();
    cin>>N>>T;

    int le=0, ri=0;
    for (int i=1; i<=N; i++) {
        cin>>A[i];
        if (i>1) ri=max(ri, abs(A[i]-A[i-1]));
    }

    int ans=ri;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) {
            ans=md;
            ri=md-1;
        }
        else le=md+1;
    }

    ok(ans);
    for (int i=1; i<=N; i++) cout<<B[i]<<sp;
    return 0;
}