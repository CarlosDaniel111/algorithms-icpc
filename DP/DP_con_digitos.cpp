/* Enunciado.
   Dada una cadena s de la forma ?????d???d?d?? o ?d????d?d, donde d es un digito cualquiera
   asignar a los caracteres '?' digitos, para formar el numero mas pequeño posible
   que ademas sea divisible por D y no tenga ceros a la izquierda
*/

const int MAXN = 1e5 +5;

string s; // cadena
int D;
stack<int> st;

bool dp[MAXN][MAXN]; //He pasado por aqui? 
bool solve(int pos, int residuo){
    if (dp[pos][residuo]) return false;
    if (pos == s.length()) return residuo == 0;
 
    if (s[pos] == '?'){ 
        for (int k = (pos == 0); k <= 9; k++){
            if (solve(pos+1, (residuo*10 + k) % D)) {
                st.push(k);
                return true;
            }
        } 
    }
    else{
        if (solve(pos+1, (residuo*10 + (s[pos]-'0')) % D)) {
            st.push(s[pos]-'0');
            return true;
        }
    }   
    dp[pos][residuo] = true;
    return false; 
}
 
int main() { 
    cin >> s >> D;
 
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
