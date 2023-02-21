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

pii f(int k, int a) {
    if (k==1) {
        if (a==1) return {1,1};
        if (a==2) return {1,2};
        if (a==3) return {2,2};
        return {2,1};
    }

    int t=1<<(2*k-2), tt=1<<(k-1);
    if (1<=a && a<=t) {
        auto [x,y]=f(k-1, a);
        return {y, x};
    }
    else if (1+t<=a && a<=2*t) {
        auto [x,y]=f(k-1, a-t);
        return {x, y+tt};
    }
    else if (1+2*t<=a && a<=3*t) {
        auto [x,y]=f(k-1, a-2*t);
        return {x+tt, y+tt};
    }
    else {
        auto [x,y]=f(k-1, a-3*t);
        return {1+2*tt-y, 1+tt-x};
    }
}

int main() {
    fio();
    int n,m;
    cin>>n>>m;

    n=32-__builtin_clz(n)-1;
    auto [x,y]=f(n,m);
    cout<<x<<sp<<y;
    return 0;
}