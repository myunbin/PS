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
const int MAX = 33333; // PLZ CHK!

bool solve(int x) {
    string s; cin>>s;
    if (s=="()") return 0;

    int n=sz(s);
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        if (s[i]=='T') a[i]=1;
        else if (s[i]=='F') a[i]=0;
        else if (s[i]=='(') a[i]=2;
        else a[i]=3;
    }

    int op=0, mxo=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='(') mxo=max(mxo, ++op);
        else if (s[i]==')') --op;
    }
    mxo%=2;

    vector<int> st;
    for (int i=0; i<n; i++) {
        if (s[i]==')') {
            int t=st.back(); st.pop_back();
            while (!st.empty() && st.back()!=2) {
                if (op%2==mxo) t&=st.back();
                else t|=st.back();
                st.pop_back();
            }   
            if (!st.empty()) st.pop_back(), op--;
            st.pb(t);
        }
        else {
            if (s[i]=='(') op++;
            st.pb(a[i]);
        }
    }

    cout<<x<<". "<<(st.back()?"true":"false")<<endl;

    return 1;
}

int main() {
    fio();
    for (int i=1;; i++) {
        if (!solve(i)) break;
    }

    return 0;
}