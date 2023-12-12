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
const int MAX = 12; // PLZ CHK!

int N;
array<double,3> A[12];

int main() {
    fio();
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>A[i][0]>>A[i][1]>>A[i][2];
    }

    const double eps=1e-9;
    double ans=0.0;
    for (double x=-10.0; x+eps<=20.0; x+=0.01) {
        for (double y=-10.0; y+eps<=20.0; y+=0.01) {
            bool ok=0;
            for (int i=0; i<N; i++) {
                auto [x0,y0,r]=A[i];
                if ((x-x0)*(x-x0)+(y-y0)*(y-y0)+eps<=r*r) {
                    ok=1;
                    break;
                }
            }
            if (ok) ans+=0.0001;
        }
    }
    cout<<fixed; cout.precision(10);
    cout<<ans;
    return 0;
}