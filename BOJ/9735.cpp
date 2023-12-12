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

ll A,B,C,D;
ll f(ll x) {return A*x*x+B*x+C+D/x;}

const double eps=1e-9;

void solve() {
    cin>>A>>B>>C>>D;

    double x0=0.0;
    for (ll i=1; i*i<=abs(D); i++) {
        if (abs(D)%i==0) {
            vector<ll> X={i,D/i,-i,-D/i};
            bool ok=0;
            for (ll x:X) {
                if (f(x)==0) {
                    x0=1.0*x;
                    ok=1;
                    break;
                }   
            }
            if (ok) break;
        }
    }
    
    double a=1.0*A, b=1.0*B+a*x0, c=1.0*C+b*x0;

    vector<double> ans; ans.pb(x0);

    if (abs(b*b-4.0*a*c)<eps) {
        double x1=-b/(2.0*a);
        ans.pb(x1);
    }
    else if (b*b-4.0*a*c>eps) {
        double x1=(-b+sqrt(b*b-4.0*a*c))/(2.0*a);
        double x2=(-b-sqrt(b*b-4.0*a*c))/(2.0*a);
        ans.pb(x1), ans.pb(x2);
    }
    sort(all(ans));

    vector<double> XX; XX.pb(ans[0]);
    for (int i=1; i<sz(ans); i++) {
        if (abs(ans[i]-ans[i-1])<eps) continue;
        XX.pb(ans[i]); 
    }

    cout<<fixed; cout.precision(10);
    for (double x:XX) cout<<x<<sp; cout<<endl;
}

int main() {
    fio();
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}