//problem: Given a, b and n. Find x and y that satisfies ax + by = n. Print any of the x and y satisfying the equation

int gcd(int a, int b,int &x, int &y){
    if(b == 0){
        x= 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

void solution(int a, int b, int n) {
    int x0, y0;
    int g = gcd(a, b, x0, y0);
    if(n%g != 0){
        cout<<"No Solution Exists"<<endl;
        return;
    }
    x0 = x0*n/g;
    y0 = y0*n/g;
    // single valid answer
    cout<<"x = "<<x0<<", y = "<<y0<<endl;
 
    // other valid answers can be obtained through...
    // x = x0 + k*(b/g)
    // y = y0 - k*(a/g)
    for(int k = -3; k <= 3; k++){
        int x = x0 + k*(b/g);
        int y = y0 - k*(a/g);
        cout<<"x = "<<x<<", y = "<<y<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int a = 2, b = 3, n = 7;
    solution(a, b, n);
    return 0;
}
