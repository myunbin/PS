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

struct trie {
    trie *ch[10];
    bool f;
    trie() {
        fill(ch,ch+10,nullptr);
        f=0;
    }
    ~trie() {
        for (int i=0; i<10; i++) if (ch[i]) delete ch[i];
    }
};

void insert(trie *rt, string s) {
    trie *hr=rt;
    int i=0; 
    while (i<sz(s)) {
        int x=s[i]-'0';
        if (hr->ch[x]==NULL) hr->ch[x]=new trie();
        hr=hr->ch[x];
        i++;
    }
    hr->f=1;
}

bool qry(trie *rt, string s) {
    trie *hr=rt;
    int i=0;
    while (i<sz(s)) {
        int x=s[i]-'0';
        hr=hr->ch[x];
        if (i<sz(s)-1 && hr->f) return 0;
        i++;
    }
    return 1;
}

void solve() {
    int n;
    cin>>n;
    trie *rt=new trie();
    vector<string> v(n);
    for (string &s:v) {
        cin>>s;
        insert(rt,s);
    }

    for (string s:v) {
        if (!qry(rt,s)) {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    delete rt;
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}