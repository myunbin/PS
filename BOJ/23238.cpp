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

int N,Q;
vector<int> a,b;    
vector<array<int,3>> q;

int cnt[MAX], h[MAX];
int cur;

void add(int x) {
    h[cnt[x]]--;
    cnt[x]++;
    h[cnt[x]]++;
    cur=max(cur, cnt[x]);
}

void del(int x) {
    h[cnt[x]]--;
    if (h[cur]==0) cur--;
    cnt[x]--;
    h[cnt[x]]++;
}

int main() {
    fio();
    cin>>N>>Q;
    a.resize(N), q.resize(Q);
    for (int &x:a) cin>>x, b.pb(x);

    cmprs(b);
    for (int &x:a) x=lb(all(b),x)-b.begin()+1;

    for (int i=0; i<Q; i++) {
        q[i][0]=i;
        cin>>q[i][1]>>q[i][2];
    }
    
    int sq=(int)sqrt(N);
    sort(all(q), [](auto a, auto b){
        auto [ai,as,ae]=a; auto [bi,bs,be]=b;
        if (as/sq==bs/sq) return ae<be;
        return as/sq<bs/sq;
    });

    vector<int> ans(Q);
    int l=1, r=0;

    for (auto [i,ql,qr]:q) {
        while (l>ql) add(--l);
        while (r<qr) add(++r);
        while (l<ql) del(l++);
        while (r>qr) del(r--);
        ans[i]=cur;
    }
    
    for (int &x:ans) cout<<x<<endl;
    
    return 0;
}