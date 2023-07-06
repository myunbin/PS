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
const int MAX = 111; // PLZ CHK!

string s;
ll dp[MAX][MAX];

ll go(int i, int j) {
    int l=j-i+1;
    if (l==1 || (l+1)%2!=0) return 1;

    ll &ret=dp[i][j];
    if (ret!=-1) return ret;

    ret=1;
    int nl=(l+1)/2;
    string t=s.substr(i,l);

    string a=t.substr(0,nl), b=t.substr(nl,nl-1);
    string c=t.substr(0,nl-1), d=t.substr(nl-1, nl);

    if (a.substr(0,nl-1)==b) ret+=go(i,i+nl-1);
    if (a.substr(1,nl-1)==b) ret+=go(i,i+nl-1);
    if (d.substr(0,nl-1)==c) ret+=go(j-nl+1,j);
    if (d.substr(1,nl-1)==c) ret+=go(j-nl+1,j);
    return ret;
}

int main() {
    fio();
    memset(dp,-1,sizeof dp);

    cin>>s;
    cout<<go(0,sz(s)-1)-1;
    return 0;
}