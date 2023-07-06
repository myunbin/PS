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
    // freopen("trapped.in", "r", stdin);
    // freopen("trapped.out", "w", stdout);

    fio();
    int n,b;
    cin>>n>>b;
    vector<pii> h(n);
    for (auto &[s,p]:h) cin>>s>>p;
    sort(all(h), [](pii a, pii b){
        return a.S<b.S;
    });

    int le=-1,ri=-1;
    for (int i=0; i<n-1; i++) {
        if (h[i].S<b && b<h[i+1].S) {
            le=i, ri=i+1;
            break;
        }
    }

    if (le==-1) {
        cout<<-1;
        return 0;
    }

    int ans=INF;

    int j=ri;
    for (int i=le; i>=0; i--) {
        while (j<n && h[j].S-h[i].S<=h[i].F) {
            ans=min(ans, h[j].S-h[i].S-h[j].F);
            j++;
        }
    }

    j=le;
    for (int i=ri; i<n; i++) {
        while (j>=0 && h[i].S-h[j].S<=h[i].F) {
            ans=min(ans, h[i].S-h[j].S-h[j].F);
            j--;
        }
    }

    cout<<(ans==INF?-1:max(0,ans));
    return 0;
}