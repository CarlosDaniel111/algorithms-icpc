const int MAXN = 1e5 +5;

string s; // cadena
int num;
stack<int> st;

bool dp[MAXN][MAXN];
bool solve(int i, int r){
    if (dp[i][r]) return false;
    if (i == s.length()) return r == 0;
 
    if (s[i] == '?'){ 
        for (int k = (i == 0); k <= 9; k++){
            if (solve(i+1, (r*10 + k) % num)) {
                st.push(k);
                return true;
            }
        } 
    }
    else{
        if (solve(i+1, (r*10 + (s[i]-'0')) % num)) {
            st.push(s[i]-'0');
            return true;
        }
    }   
    dp[i][r] = true;
    return false; 
}
 
int main() { 
    cin >> s >> num;
 
    if(solve(0, 0)){
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
        cout << ENDL;
    }
    else cout << "*\n";
 
    return 0;
}
