#define F0R(i, a) for (int i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n = 12, heights[n] = {1, 8, 4, 9, 9, 10, 3, 2, 4, 8, 1, 13}, leftSmaller[n];
    stack<int> st;
    F0R (i, n) {
        while (!st.empty() && heights[st.top()] > heights[i])
            st.pop();
        if (st.empty())
            leftSmaller[i] = -1;
        else   
            leftSmaller[i] = st.top();
        st.push(i);
    }
    //Ahora leftSmaller[i] tiene el indice del elemento menor mas cercano a la izquierda de heights[i]
}
