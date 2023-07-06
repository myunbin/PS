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

int main() {
    fio();
    int n,d;
    cin>>n>>d;
    vector<pii> a(n);
    for (auto &[x,y]:a) cin>>x>>y;
    sort(all(a));

    deque<pii> dq;
    vector<int> a1(n),a2(n);
    for (int i=0; i<n; i++) {
        auto [x,h]=a[i];
        while (!dq.empty() && dq.front().F<x-d) dq.pop_front();

        if (!dq.empty() && dq.front().S>=2*h) a1[i]=1;
        
        while (!dq.empty() && dq.back().S<h) dq.pop_back();
        dq.push_back(a[i]);
    }

    dq.clear();
    for (int i=n-1; i>=0; i--) {
        auto [x,h]=a[i];
        while (!dq.empty() && dq.front().F>x+d) dq.pop_front();

        if (!dq.empty() && dq.front().S>=2*h) a2[i]=1;

        while (!dq.empty() && dq.back().S<h) dq.pop_back();
        dq.push_back(a[i]);
    }

    int ans=0;
    for (int i=0; i<n; i++) ans+=(a1[i]&&a2[i]);

    cout<<ans;
    return 0;
}