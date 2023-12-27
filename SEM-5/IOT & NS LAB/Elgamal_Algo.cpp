#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    else if (a % b == 0) return b;
    else return gcd(b, a % b);
}

ll gen_key(ll q) {
    ll power = static_cast<ll>(pow(10LL, 20));
    ll mod = (power - q);
    ll key = (rand() % mod) + q;
    while (gcd(q, key) != 1) {
        key = (rand() % mod) + static_cast<ll>(pow(10LL, 20));
    }
    cout << key;
    return key;
}

ll power(ll a, ll b, ll c) {
    ll x = 1;
    ll y = a;
    while (b > 0) {
        if (b % 2 != 0) x = (x * y) % c;
        y = (y * y) % c;
        b = b / 2;
    }
    return x % c;
}

pair<vector<ll>, ll> encrypt(const string& msg, ll q, ll h, ll g) {
    vector<ll> en_msg;
    ll k = gen_key(q);  // Private key for sender
    ll s = power(h, k, q);
    ll p = power(g, k, q);

    for (char c : msg) {
        en_msg.push_back(static_cast<ll>(c));
    }

    cout << "g^k used : " << p << endl;
    cout << "g^ak used : " << s << endl;

    for (ll i = 0; i < en_msg.size(); i++) {
        en_msg[i] = s * en_msg[i];
    }

    return {en_msg, p};
}

string decrypt(const vector<ll>& en_msg, ll p, ll key, ll q) {
    string dr_msg;
    ll h = power(p, key, q);
    for (ll en_char : en_msg) {
        dr_msg += static_cast<char>(en_char / h);
    }
    return dr_msg;
}

int main() {

    string msg = "Sagar Gupta";
    cout << "Original Message: " << msg << endl;
    ll mod = static_cast<ll>(pow(10LL, 50) - pow(10LL, 20));
    ll p = static_cast<ll>(pow(10LL, 20));
    ll q = (rand() % mod);
    ll g = rand() % (q - 2) + 2;
    if (q < 0) q = mod - q + p;
    ll key = gen_key(q);  // Private key for receiver
    ll h = power(g, key, q);

    cout << "g used : " << g << endl;
    cout << "g^a used : " << h << endl;

    auto [en_msg, pt] = encrypt(msg, q, h, g);
    string dr_msg = decrypt(en_msg, pt, key, q);
    cout << "Decrypted Message: " << dr_msg << endl;

    return 0;
}
