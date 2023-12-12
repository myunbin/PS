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

map<string,ll> A,B;

int main() {
    fio();
    A["black"]=0, A["brown"]=1, A["red"]=2;
    A["orange"]=3, A["yellow"]=4, A["green"]=5;
    A["blue"]=6, A["violet"]=7, A["grey"]=8;
    A["white"]=9;

    B["black"]=1e0, B["brown"]=1e1, B["red"]=1e2;
    B["orange"]=1e3, B["yellow"]=1e4, B["green"]=1e5;
    B["blue"]=1e6, B["violet"]=1e7, B["grey"]=1e8;
    B["white"]=1e9;

    string a,b,c; cin>>a>>b>>c;

    cout<<A[a]*B[c]*10ll+A[b]*B[c];

    return 0;
}