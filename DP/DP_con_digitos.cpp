const int MAXN = 1e5 +5;

string s; // cadena
int num;
stack<int> st;

bool memo[MAXN][MAXN];
bool dp(int i, int r){
    if (memo[i][r]) return false;
    if (i == s.length()) return r == 0;
 
    if (s[i] == '?'){ 
        for (int k = (i == 0); k <= 9; k++){
            if (dp(i+1, (r*10 + k) % num)) {
                st.push(k);
                return true;
            }
        } 
    }
    else{
        if (dp(i+1, (r*10 + (s[i]-'0')) % num)) {
            st.push(s[i]-'0');
            return true;
        }
    }   
    memo[i][r] = true;
    return false; 
}
 
int main() { 
    cin >> s >> num;
 
    if(dp(0, 0)){
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
        cout << ENDL;
    }
    else cout << "*\n";
 
    return 0;
}
