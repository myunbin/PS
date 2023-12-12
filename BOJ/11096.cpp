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
const int MAX = 303; // PLZ CHK!

int N,p[MAX];

int fd(int a) {
    if (a==p[a]) return a;
    return p[a]=fd(p[a]);
}

bool mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    p[a]=b; return 1;
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) p[i]=i;

    cin>>N;
    vector<array<int,3>> V;
    
    const int S=0,E=N+1;
    int ans=N+1;
    for (int i=1; i<=N; i++) {
        int x,y,r; cin>>x>>y>>r;
        if (x-r<0) mg(S,i);
        if (x+r>200) mg(E,i);

        for (int j=1; j<i; j++) {
            auto [xx,yy,rr]=V[j-1];
            int d=(x-xx)*(x-xx)+(y-yy)*(y-yy);
            if (d<(r+rr)*(r+rr)) {
                mg(i,j);
            }
        }

        if (fd(S)==fd(E)) {
            ans=min(ans,i-1);
        }

        V.pb({x,y,r});
    }
    
    cout<<ans;
    return 0;
}