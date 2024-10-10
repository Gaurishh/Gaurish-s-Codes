#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// Define the ordered_set type
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);
#define int long long
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
#define endl '\n'
#define MOD 1000000007

// Function to compute the modular inverse using Fermat's Little Theorem
int mod_inverse(int a, int mod)
{
    int result = 1;
    int power = mod - 2;

    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        power /= 2;
    }

    return result;
}

int query(int a, int b)
{ // comment the #define endl '\n' line in case this is being used
    int x;
    cout << "? " << a << " " << b << endl;
    cin >> x;

    return x;
}

void println(auto x)
{
    cout << x << endl;
}

void println(vector<int> &v)
{
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << '\n';
}

int lcm(int a, int b)
{
    return ((a * b) / __gcd(a, b));
}

// const int N = 1e6;
// int spf[N+1];
// void calculateSPF(){
//     for(int i=1; i<=N; i++){
//         spf[i] = i;
//     }

//     for (int i = 2; i <= N; i++) {
//         if (spf[i] == i) {  // `i` is a prime
//             for (int j = i * 2; j <= N; j += i) {
//                 if (spf[j] == j) {
//                     spf[j] = i;
//                 }
//             }
//         }
//     }
// }

// vector<int> primeFactorise(int n){ //O(log n)
//     vector<int> primes;

//     while(n != 1){
//         int x = spf[n];
//         while(n%x == 0){
//             n = n/x;
//         }

//         primes.push_back(x);
//     }

//     return primes;
// }

// bool isPrime[N+1];
// void primeSieve(){
//     isPrime[0] = 0;
//     isPrime[1] = 0;
//     for(int i=2; i<=N; i++){
//         isPrime[i] = 1;
//     }

//     for(int i=2; i<=N/2; i++){
//         if(isPrime[i]){
//             for(int j=2*i; j<=N; j+=i){
//                 isPrime[j] = false;
//             }
//         }
//     }
// }

int modular_exponentiation(int a, int b, int m = MOD)
{
    int result = 1;
    a = a % m; // Update a if it is more than or equal to m

    while (b > 0)
    {
        // If b is odd, multiply a with the result
        if (b % 2 == 1)
        {
            result = (result * a) % m;
        }

        // b must be even now
        b = b >> 1;      // Divide b by 2
        a = (a * a) % m; // Change a to a^2
    }
    return result;
}

int power(int a, int b)
{
    int result = 1;

    while (b > 0)
    {
        // If b is odd, multiply a with the result
        if (b % 2 == 1)
        {
            result = (result * a);
        }

        // b must be even now
        b = b >> 1;  // Divide b by 2
        a = (a * a); // Change a to a^2
    }

    return result;
}

int customSqrt(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int s = 0;
    int e = n;

    while (s < e)
    {
        int mid = s + (e - s + 1) / 2;
        if (mid > n / mid)
        {
            e = mid - 1;
        }
        else
        {
            s = mid;
        }
    }

    return s;
}

struct Hashing
{
    string s;
    int n;
    int primes;
    vector<int> hashPrimes = {(int)1e9 + 7, (int)1e9 + 9};

    const int base = 31;
    vector<vector<int>> hashValues;
    vector<vector<int>> powersOfBase;
    vector<vector<int>> inversePowersOfBase;

    Hashing(string a)
    {
        primes = hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);

        s = a;
        n = s.size();
        for (int i = 0; i < hashPrimes.size(); i++)
        {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);

            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }

            inversePowersOfBase[i][n] = modular_exponentiation(powersOfBase[i][n], hashPrimes[i] - 2, hashPrimes[i]);
            for (int j = n - 1; j >= 0; j--)
            {
                inversePowersOfBase[i][j] = inversePowersOfBase[i][j + 1] % hashPrimes[i] * base % hashPrimes[i];
            }
        }

        for (int i = 0; i < hashPrimes.size(); i++)
        {
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }

    vector<int> substringHash(int l, int r)
    {
        vector<int> hash(primes);
        for (int i = 0; i < primes; i++)
        {
            int val1 = hashValues[i][r];
            int val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            int x = (val1 - val2 + hashPrimes[i]) % hashPrimes[i];
            hash[i] = (x * inversePowersOfBase[i][l] % hashPrimes[i]) % hashPrimes[i];
        }

        return hash;
    }
};

// vector<int> fact, inv_fact;
// // Precompute factorials and inverse factorials
// void precomputeFactorials(int n) {
//     fact.resize(n + 1);
//     inv_fact.resize(n + 1);

//     fact[0] = 1;
//     for (int i = 1; i <= n; i++) {
//         fact[i] = (fact[i - 1] * i) % MOD;
//     }

//     // Compute inverse factorials using Fermat's Little Theorem
//     inv_fact[n] = modular_exponentiation(fact[n], MOD - 2, MOD);
//     for (int i = n - 1; i >= 0; i--) {
//         inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
//     }
// }

// // Function to compute nCk using precomputed factorials
// int nCk(int n, int k) {
//     if (k > n) return 0;
//     return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
// }

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //---INPUT---
}

int32_t main()
{
    fastIO;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
