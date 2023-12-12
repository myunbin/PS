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

struct ed {
    int u,v; ll w;
    bool operator < (const ed &o) const {
        return w<o.w;
    }
};

int N;
ll W[MAX];
vector<int> P[2*MAX];
vector<ed> E;

int pa[4*MAX];
map<pii,int> C;

int fd(int a) {
    if (a==pa[a]) return a;
    return pa[a]=fd(pa[a]);   
}

bool mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    pa[b]=a; return 1;
}

int main() {
    fio();
    for (int i=0; i<4*MAX; i++) pa[i]=i;

    cin>>N;
    int cnt=1;
    for (int i=1; i<=N; i++) {
        cin>>W[i];
        vector<int> p(4);
        for (int &x:p) {
            cin>>x;
            P[x].pb(i);
            C[{i,x}]=cnt++;
        }

        for (int j=0; j<4; j+=2) {
            E.pb({C[{i,p[j]}],C[{i,p[j+1]}],0});
        }

        for (int j=0; j<2; j++) {
            for (int k=2; k<4; k++) {
                E.pb({C[{i,p[j]}],C[{i,p[k]}],W[i]});
            }
        }
    }

    for (int p=1; p<=2*N; p++) {
        int i1=P[p][0], i2=P[p][1];
        E.pb({C[{i1,p}],C[{i2,p}],0});
    }

    sort(all(E));

    int ce=0;
    ll ans=0;
    for (auto [u,v,w]:E) {
        if (mg(u,v)) {
            ce++;
            ans+=w;
        }
        
        if (ce==4*N-1) break;
    }

    cout<<ans;
    return 0;
}