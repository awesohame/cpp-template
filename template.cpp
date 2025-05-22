#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);std::cin.tie(NULL);cout.tie(NULL)

// macros
#define ll long long
#define lld long long double
#define lli long long int
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vll vector<long long>
#define vvl vector<vector<long long>>
#define vvvl vector<vector<vector<long long>>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<long,long>>
#define mii map<int, int>
#define um unordered_map
#define umii unordered_map<int, int>
#define umll map<long long,long long>
#define si set<int>
#define sc set<char>
#define MOD 1000000007
#define MOD1 998244353
#define endl '\n'
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.1415926535897932384626433832795
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

// Ordered Set
template <typename T, typename Compare = less<T>>
using ordered_set = __gnu_pbds::tree<
    T,
    __gnu_pbds::null_type,
    Compare,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

// custom map
struct chash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };
struct pair_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }size_t operator()(pii x)const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1); } };

template<typename T1, typename T2>
using safe_map = unordered_map<T1, T2, chash>;

// input and output
template <typename T>
istream& operator>>(istream& in, vector<T>& a) { for(auto& x : a) in >> x; return in; }

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& a) { for(const auto& x : a) out << x << " "; return out; }

template <typename T>
istream& operator>>(istream& in, vector<vector<T>>& a) { for(auto& row : a) in >> row; return in; }

template <typename T>
ostream& operator<<(ostream& out, const vector<vector<T>>& a) { for(const auto& row : a) out << row << endl; return out; }

template <typename T1, typename T2>
istream& operator>>(istream& in, vector<pair<T1, T2>>& a) { for(auto& x : a) in >> x.first >> x.second; return in; }

template <typename T1, typename T2>
ostream& operator<<(ostream& out, const vector<pair<T1, T2>>& a) { for(const auto& x : a) out << x.first << " " << x.second << endl; return out; }

template <typename T>
void pl(const T& x) {
    cout << x << endl;
}

// arrays
template <typename T> // get indices all occurrences of an element
vector<int> allOccur(const vector<T>& a, T e) { vector<int> indices; for(int i = 0; i < a.size(); ++i) { if(a[i] == e) indices.push_back(i); }return indices; }

template <typename T> // gcd of array
T gcdArr(vector<T>& a) { return accumulate(a.begin() + 1, a.end(), a[0], [](T x, T y) {return gcd(x, y); }); }

// functions
ll min(ll a, int b) { if(a < b) return a; return b; }
ll min(int a, ll b) { if(a < b) return a; return b; }
ll max(ll a, int b) { if(a > b) return a; return b; }
ll max(int a, ll b) { if(a > b) return a; return b; }
ll gcd(ll a, ll b) { if(b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// utils
#define yes printYes()
#define no printNo()
string to_upper(string a) { for(int i = 0; i < (int)a.size(); ++i) if(a[i] >= 'a' and a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for(int i = 0; i < (int)a.size(); ++i) if(a[i] >= 'A' and a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }
bool prime(ll a) { if(a == 1) return 0; for(int i = 2; i <= round(sqrt(a)); ++i) if(a % i == 0) return 0; return 1; }

void printYes() { cout << "yes\n"; }
void printNo() { cout << "no\n"; }

template<typename T> // get greatest factor of number
T greatestFactor(T n) { if(n <= 1) return n; for(T i = n / 2; i >= 1; --i) { if(n % i == 0) { return i; } }return -1; }

// sieve
vector<bool> sieve(int n) { vector<bool> p(n + 1, 1); p[0] = p[1] = 0; for(int i = 2; i * i <= n; i++) if(p[i]) for(int j = i * i; j <= n; j += i) p[j] = 0; return p; }

// DSU
class DSU {
public:vector<int>par, rank; DSU(int n) { par.resize(n); rank.resize(n); for(int i = 0; i < n; i++)par[i] = i; }int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }void unite(int x, int y) { int xp = find(x), yp = find(y); if(xp != yp) { if(rank[xp] > rank[yp])par[yp] = xp; else if(rank[xp] < rank[yp])par[xp] = yp; else par[yp] = xp, rank[xp]++; } }
};

// main
void solve(ll tc) {

}

// driver
int main() {
    fastio();

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
// #endif

    ll tc = 1;
    cin >> tc;

    for(ll i = 1; i <= tc; i++) {
        solve(i);
    }

    return 0;
}
