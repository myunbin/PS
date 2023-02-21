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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010101; // PLZ CHK!

int mp[MAX];
void sv() {
    for (int i=2; i<MAX; i++) mp[i]=i;
    for (int i=4; i<MAX; i+=2) mp[i]=2;
    for (int i=3; i*i<MAX; i++) {
        if (mp[i]!=i) continue;
        for (int j=i*i; j<MAX; j+=i) mp[j]=i;
    }
}

int f(int x) {
    int ret=0;
    while (x!=1) {
        ret++;
        x/=mp[x];
    }
    return ret;
}

int main() {
    fio();
    sv();

    int n;
    cin>>n;

    int a[MAX];
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }

    int d[MAX];
    for (int i=1; i<MAX; i++) d[i]=f(i);

    vector<pii> v[MAX];
    for (int i=1; i<=n; i++) {
        for (int j=1; j*j<=a[i]; j++) {
            if (a[i]%j) continue;
            v[j].pb({d[a[i]], i});
            if (j*j!=a[i]) v[a[i]/j].pb({d[a[i]], i});
        }
    }

    pii ans[MAX];
    fill(ans, ans+MAX, pii(INF, INF));
    for (int i=1; i<MAX; i++) {
        sort(all(v[i]));
        for (pii p:v[i]) {
            auto [da, ia]=p;
            if (sz(v[i])>0 && p!=v[i][0]) {
                ans[ia]=min(ans[ia], {da+v[i][0].F-2*d[i], v[i][0].S});
            }
            if (sz(v[i])>1 && p!=v[i][1]) {
                ans[ia]=min(ans[ia], {da+v[i][1].F-2*d[i], v[i][1].S});
            }
        }
    }

    for (int i=1; i<=n; i++) cout<<ans[i].S<<endl;
    return 0;
}