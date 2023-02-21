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

int n, d[10101][11];
string s,t;

int go(int i, int j) {
    if (i==n) return 0;
    int &ret=d[i][j];
    if (ret!=-1) return ret;

    int si=s[i]-'0', ti=t[i]-'0', ci=(si+j)%10;
    ret=INF;
    if (ci<=ti) {
        ret=min(ret, ti-ci+go(i+1, (j+ti-ci)%10));
        ret=min(ret, 10+ci-ti+go(i+1, j));
    }
    else {
        ret=min(ret, ci-ti+go(i+1, j));
        ret=min(ret, 10+ti-ci+go(i+1, (j+10+ti-ci)%10));
    }
    return ret;
}

void tr(int i, int j) {
    if (i==n) return;
    int ret=go(i,j);

    int si=s[i]-'0', ti=t[i]-'0', ci=(si+j)%10;
    if (ci<=ti) {
        if (ret==ti-ci+go(i+1, (j+ti-ci)%10)) {
            cout<<(i+1)<<sp<<(ti-ci)<<endl;
            tr(i+1, (j+ti-ci)%10);
        }
        else {
            cout<<(i+1)<<sp<<-(10+ci-ti)<<endl;
            tr(i+1, j);
        }
    }
    else {
        if (ret==ci-ti+go(i+1, j)) {
            cout<<(i+1)<<sp<<-(ci-ti)<<endl;
            tr(i+1, j);
        }
        else {
            cout<<(i+1)<<sp<<(10+ti-ci)<<endl;
            tr(i+1, (j+10+ti-ci)%10);
        }
    }
}

int main() {
    fio();
    memset(d,-1,sizeof d);
    cin>>n>>s>>t;
    cout<<go(0,0)<<endl;
    tr(0,0);
    return 0;
}