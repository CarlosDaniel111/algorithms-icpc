// Retorna si el punto P se encuentra en el segmento de puntos S a E
bool onSegment(Point s, Point e, Point p) {
  return orient(p, s, e) == 0 && dot(s - p, e - p) <= 0;
}

// Retorna la distancia mas corta entre el punto P y el segmento S a E
double dist2(Point x) { return x * x + y * y; }
double dist(Point x) { sqrt((double)dist2(x)); }
double segDist(Point& s, Point& e, Point& p) {
  if (s == e) return dist(p - s);
  auto d = dist2(e - s), t = min(d, max(.0, dot(p - s, e - s)));
  return (dist((p - s) * d - (e - s) * t) / d);
}

// Retorna la distancia mas corta entre el punto P y el segmento A a B
// y guarda el punto mas cercano en C
double distToLineSegment(Point p, Point a, Point b, Point& c) {
  vec ap = toVector(a, p), ab = toVector(a, b);
  double u = dot(ap, ab) / sq(ab);
  if (u < 0.0) {
    c = Point{a.x, a.y};
    return dist(p, a);
  }
  if (u > 1.0) {
    c = Point{b.x, b.y};
    return dist(p, b);
  }
  return distToLine(p, a, b, c);
}

// Si existe un punto de interseccion unico entre los segmentos de linea que van de A a B y de C a D, se devuelve.
// Si no existe ningun punto de interseccion, se devuelve un vector vacio.
// Si existen infinitos, se devuelve un vector con 2 elementos, que contiene los puntos finales del segmento de linea comun.
vector<Point> segInter(Point a, Point b, Point c, Point d) {
  auto oa = orient(c, d, a), ob = orient(c, d, b),
       oc = orient(a, b, c), od = orient(a, b, d);
  if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
    return {(a * ob - b * oa) / (ob - oa)};
  set<Point> s;
  if (onSegment(c, d, a)) s.insert(a);
  if (onSegment(c, d, b)) s.insert(b);
  if (onSegment(a, b, c)) s.insert(c);
  if (onSegment(a, b, d)) s.insert(d);
  return {ALL(s)};
}