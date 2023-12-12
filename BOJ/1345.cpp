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
const int MAX = 55; // PLZ CHK!

int N;
double A0, S[MAX];

int main() {
    fio();
    cin>>N>>A0;
    
    typedef pair<double,double> pdd;

    pdd d={0.0, 1e9};
    const double eps=1e-12;
    for (int i=1; i<=N; i++) {
        cin>>S[i];

        double s=(S[i]-A0)/(1.0*i), e=(S[i]+1.0-A0)/(1.0*i);
        if (eps<s-d.F) d.F=s;
        if (d.S-e>eps) d.S=e;
    }

    cout<<fixed; cout.precision(10);

    if (d.S-d.F>eps) cout<<d.F;
    else cout<<-1;
    
    return 0;
}