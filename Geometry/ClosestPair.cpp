/*
 * Descripcion: Dado un arreglo de N puntos en el plano, encontrar el par
 * de puntos con la menor distancia entre ellos
 * Utilizar con long long de preferencia
 * Tiempo: O(n log n)
 */

// Agregar en el struct Point
bool operator<(Point p) const { return tie(x, y) < tie(p.x, p.y); }
T dist2() const { return x * x + y * y; }

typedef Point P;
pair<P, P> closest(vector<P> &v) {
  set<P> S;
  sort(ALL(v), [](P a, P b) { return a.y < b.y; });
  pair<ll, pair<P, P>> ret{LLONG_MAX, {P{0, 0}, P{0, 0}}};
  int j = 0;
  for (P p : v) {
    P d{1 + (ll)sqrt(ret.first), 0};
    while (v[j].y <= p.y - d.x) S.erase(v[j++]);
    auto lo = S.lower_bound(p - d), hi = S.upper_bound(p + d);
    for (; lo != hi; ++lo)
      ret = min(ret, {(*lo - p).dist2(), {*lo, p}});
    S.insert(p);
  }
  return ret.second;
}