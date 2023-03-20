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
const int MAX = 101010; // PLZ CHK!

int main() {
    fio();
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    map<pii,bool> v;
    queue<pair<pii,int>> q;
    v[{0,0}]=1, q.push({{0,0},0});

    while (!q.empty()) {
        auto [p,cnt]=q.front(); q.pop();
        auto [cx,cy]=p;
        if (cx==c && cy==d) {
            cout<<cnt;
            return 0;
        }
        
        if (cx!=a && !v[{a,cy}]) {
            v[{a,cy}]=1;
            q.push({{a,cy},cnt+1});          
        }
        if (cy!=b && !v[{cx,b}]) {
            v[{cx,b}]=1;
            q.push({{cx,b},cnt+1});
        }
        if (cx!=0 && !v[{0,cy}]) {
            v[{0,cy}]=1;
            q.push({{0,cy},cnt+1});
        }
        if (cy!=0 && !v[{cx,0}]) {
            v[{cx,0}]=1;
            q.push({{cx,0},cnt+1});
        }
        int nx=cx-min(cx,b-cy), ny=cy+min(cx,b-cy);
        if (!v[{nx,ny}]) {
            v[{nx,ny}]=1;
            q.push({{nx,ny},cnt+1});
        }
        nx=cx+min(cy,a-cx), ny=cy-min(cy,a-cx);
        if (!v[{nx,ny}]) {
            v[{nx,ny}]=1;
            q.push({{nx,ny},cnt+1});
        }
    }
    cout<<-1;
    return 0;
}