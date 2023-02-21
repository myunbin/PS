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
const int MAX = 202020; // PLZ CHK!


int main() {
    fio();
    int n;
    string s;

    cin>>s;
    n=sz(s);
    if (n==1) {
        cout<<(s[0]=='+'?10:1);
        return 0;
    }
    else if (n==2) {
        cout<<11;
        return 0;
    }

    reverse(all(s)), s+="x", reverse(all(s));
    vector<ll> d(n+1, -LINF);
    d[0]=0;
    d[1]=(s[1]=='+'?10:1);
    d[2]=(s[1]=='+' && s[2]=='-' ? 11:-LINF);
    
    for (int i=3; i<=n; i++) {
        if (s[i]=='-') {
            if (s[i-1]=='+') {
                d[i]=max(d[i], d[i-2]+1);
                if (i>3) {
                    if (s[i-2]=='+') d[i]=max(d[i], d[i-3]+11);
                    else d[i]=max(d[i], d[i-3]-11);
                }
            }
            else {
                d[i]=max(d[i], d[i-2]-1);
            }
        }
        else {
            if (s[i-1]=='+') d[i]=max(d[i], d[i-2]+10);
            else d[i]=max(d[i], d[i-2]-10);
        }
    }
    
    cout<<d[n];

    return 0;
}