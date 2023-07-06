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
const int MAX = 7070; // PLZ CHK!

int d[MAX];

int main() {
    fio();
    int n; ll s;
    cin>>n>>s;

    vector<array<ll,3>> a(n+1);
    a[0]={0,0,0};
    for (int i=1; i<=n; i++) {
        cin>>a[i][1]>>a[i][2]>>a[i][0];
    }

    sort(all(a));

    memset(d,-1,sizeof d);
    d[0]=0;
    for (int i=1; i<=n; i++) {
        auto [ti,xi,yi]=a[i];
        for (int j=0; j<i; j++) {
            auto [tj,xj,yj]=a[j];
            ll dt=(xi-xj)*(xi-xj)+(yi-yj)*(yi-yj), tt=(ti-tj)*(ti-tj); 
            if (d[j]!=-1 && dt<=tt*s*s) {
                d[i]=max(d[i], 1+d[j]);
            }
        }
    }

    cout<<*max_element(d,d+n+1);
    return 0;
}