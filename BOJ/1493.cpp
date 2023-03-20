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

vector<pii> a;
int ans=0;
bool ok=1;
void go(int x, int y, int z) {
    if (!ok) return;
    if (x==0 || y==0 || z==0) return;
    for (auto &[w,c]:a) {
        if (x-w>=0 && y-w>=0 && z-w>=0 && c>0) {
            ans++;
            c--;
            go(x, y, z-w);
            go(x-w, y, w);
            go(w, y-w, w);
            return;
        }
    }
    ok=0;
}

int main() {
    fio();
    int l,w,h;
    cin>>l>>w>>h;
    
    int n; cin>>n;
    a.resize(n);
    for (auto &[x,y]:a) {
        cin>>x>>y;
        x=(1<<x);
    }
    sort(all(a), greater<>());

    go(l,w,h);
    cout<<(ok?ans:-1);
    return 0;
}