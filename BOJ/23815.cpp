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

int d[MAX][2];

int main() {
    fio();
    int n; cin>>n;
    vector<pair<string,string>> a(n+1);
    for (int i=1; i<=n; i++) {
        cin>>a[i].F>>a[i].S;
    }

    for (int i=0;i<MAX;i++)for(int j=0;j<2;j++) d[i][j]=-INF;

    d[0][0]=d[0][1]=1;
    for (int i=1; i<=n; i++) {
        auto [s1,s2]=a[i];
        int x=s1[1]-'0', y=s2[1]-'0';
        if (s1[0]=='+') {
            d[i][0]=max(d[i][0], d[i-1][0]+x);
            d[i][1]=max(d[i][1], d[i-1][0]);
            d[i][1]=max(d[i][1], d[i-1][1]+x);
        }
        if (s1[0]=='-') {
            d[i][0]=max(d[i][0], d[i-1][0]-x);
            d[i][1]=max(d[i][1], d[i-1][0]);
            d[i][1]=max(d[i][1], d[i-1][1]-x);
        }
        if (s1[0]=='*') {
            d[i][0]=max(d[i][0], d[i-1][0]*x);
            d[i][1]=max(d[i][1], d[i-1][0]);
            d[i][1]=max(d[i][1], d[i-1][1]*x);
        }
        if (s1[0]=='/') {
            d[i][0]=max(d[i][0], d[i-1][0]/x);
            d[i][1]=max(d[i][1], d[i-1][0]);
            d[i][1]=max(d[i][1], d[i-1][1]/x);
        }

        if (s2[0]=='+') {
            d[i][0]=max(d[i][0], d[i-1][0]+y);
            d[i][1]=max(d[i][1], d[i-1][0]);
            d[i][1]=max(d[i][1], d[i-1][1]+y);
        }
        if (s2[0]=='-') {
            d[i][0]=max(d[i][0], d[i-1][0]-y);
            d[i][1]=max(d[i][1], d[i-1][0]);
            d[i][1]=max(d[i][1], d[i-1][1]-y);
        }
        if (s2[0]=='*') {
            d[i][0]=max(d[i][0], d[i-1][0]*y);
            d[i][1]=max(d[i][1], d[i-1][0]);
            d[i][1]=max(d[i][1], d[i-1][1]*y);
        }
        if (s2[0]=='/') {
            d[i][0]=max(d[i][0], d[i-1][0]/y);
            d[i][1]=max(d[i][1], d[i-1][0]);
            d[i][1]=max(d[i][1], d[i-1][1]/y);
        }

        if (d[i][0]<=0) d[i][0]=-INF;
        if (d[i][1]<=0) d[i][1]=-INF;
    }   

    if (d[n][0]<=0 && d[n][1]<=0) cout<<"ddong game";
    else cout<<max(d[n][0], d[n][1]);

    return 0;
}