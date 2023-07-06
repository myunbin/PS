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

int n;
ll m;
vector<ll> w;

bool ok(int x) {
    vector<ll> d(n+1,0), p(n+1,0);
    for (int i=1; i<=n; i++) {
        d[i]=p[max(0,i-x-1)]+w[i];
        p[i]=max(p[i-1], d[i]);
    }
    return p[n]>=m;
}

int main() {
    fio();
    cin>>n>>m;
    w.resize(n+1);
    
    ll sum=0, mx=0;
    for (int i=1; i<=n; i++) {
        cin>>w[i];
        sum+=w[i];
        mx=max(mx, w[i]);
    }

    if (sum<m) {
        cout<<-1;
        return 0;
    }
    if (mx>=m) {
        cout<<"Free!";
        return 0;
    }

    int le=0, ri=n, ans=0;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) ans=md, le=md+1;
        else ri=md-1;
    }
    
    cout<<ans;
    return 0;
}