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

int N,M,D;
vector<int> A,B;
map<tuple<int,vector<int>,vector<int>>, double> d;

double go(int i, vector<int> a, vector<int> b) {
    // cout<<i<<sp<<"(a:";
    // for (int x:a) cout<<x<<sp; cout<<") (b:";
    // for (int x:b) cout<<x<<sp; cout<<")\n";

    if (b.empty()) return 1.0;
    if (i==D) return 0.0;

    if (d.find({i,a,b})!=d.end()) return d[{i,a,b}];

    double ret=0.0;
    double uni=1.0/(1.0*sz(a)+1.0*sz(b));
    for (int &x:a) {
        x--;
        vector<int> c=a;
        sort(all(c),greater<>());
        if (c.back()==0) c.pop_back();
        ret+=uni*go(i+1,c,b);
        x++;
    }
    for (int &x:b) {
        x--;
        vector<int> c=b;
        sort(all(c),greater<>());
        if (c.back()==0) c.pop_back();
        ret+=uni*go(i+1,a,c);
        x++;
    }

    return d[{i,a,b}]=ret;
}

int main() {
    fio();
    cin>>N>>M>>D;

    int sum=0;
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        sum+=x;
        A.pb(x);
    }
    for (int i=0; i<M; i++) {
        int x; cin>>x;
        sum+=x;
        B.pb(x);
    }

    D=min(sum,D);

    cout<<fixed; cout.precision(10);
    cout<<go(0,A,B);

    return 0;
}