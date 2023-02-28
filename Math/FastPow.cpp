//iterative way
ll binpow(ll a, ll b, ll m){ //(a^b) mod m
  ll res = 1;
  while(b){
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
//recursive way
ll binpow(ll a, ll b, ll m){
  if (b == 0) return 1;

  ll ans = binpow(a, b / 2, m) % m;
  ans = (ans * ans) % m;
  if (b & 1) ans = (ans * a) % m;

  return ans;
}