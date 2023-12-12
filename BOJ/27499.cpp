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

int N,M,K;
map<pii,int> C;

int main() {
    fio();
    cin>>N>>M>>K;
    for (int i=0; i<N; i++) {
        pii a; cin>>a.F>>a.S;
        
        int g=gcd(a.F,a.S);
        C[{a.F/g, a.S/g}]++;
        for (int j=1; j<K; j++) {
            a={2*j*M-a.F, a.S};
            g=gcd(a.F, a.S);
            C[{a.F/g, a.S/g}]++;
        }
    }

    int ans=0;
    for (auto [x,c]:C) {
        ans=max(ans, c);
        // cout<<x.F<<sp<<x.S<<sp<<c<<endl;
    } 
    // cout<<endl;

    cout<<ans;
    return 0;
}