struct Vertex {
    unordered_map<char, int> children;
    bool leaf;
    int parent, suffixLink, wordID, endWordLink;
    char parentChar;

    Vertex() {
        children.clear();
        leaf = false;
        parent = suffixLink = wordID = endWordLink = -1;
    }
};

class Aho {
   private:
    vector<Vertex *> Trie;
    vector<int> wordsLength;
    int size, root;

    void calcSuffixLink(int vertex) {
        // Procesar root
        if (vertex == root) {
            Trie[vertex]->suffixLink = root;
            Trie[vertex]->endWordLink = root;
            return;
        }
        // Procesamiento de hijos de la raiz
        if (Trie[vertex]->parent == root) {
            Trie[vertex]->suffixLink = root;
            if (Trie[vertex]->leaf) {
                Trie[vertex]->endWordLink = vertex;
            } else {
                Trie[vertex]->endWordLink =
                    Trie[Trie[vertex]->suffixLink]->endWordLink;
            }
            return;
        }

        // Para calcular el sufijo link para el vértice actual, necesitamos el
        // sufijo
        // enlace para el padre del vértice y el personaje que nos movió a la
        // vértice actual.
        int curBetterVertex = Trie[Trie[vertex]->parent]->suffixLink;
        char chVertex = Trie[vertex]->parentChar;
        while (true) {
            if (Trie[curBetterVertex]->children.count(chVertex)) {
                Trie[vertex]->suffixLink =
                    Trie[curBetterVertex]->children[chVertex];
                break;
            }
            if (curBetterVertex == root) {
                Trie[vertex]->suffixLink = root;
                break;
            }
            curBetterVertex = Trie[curBetterVertex]->suffixLink;
        }

        if (Trie[vertex]->leaf) {
            Trie[vertex]->endWordLink = vertex;
        } else {
            Trie[vertex]->endWordLink =
                Trie[Trie[vertex]->suffixLink]->endWordLink;
        }
    }

   public:
    Aho() {
        size = root = 0;
        Trie.pb(new Vertex());
        size++;
    }

    void addString(string s, int wordID) {
        int curVertex = root;
        F0R(i, s.length()) {  // Iteracion sobre los caracteres de la cadena
            char c = s[i];
            if (!Trie[curVertex]->children.count(c)) {
                Trie.pb(new Vertex());
                Trie[size]->suffixLink = -1;
                Trie[size]->parent = curVertex;
                Trie[size]->parentChar = c;
                Trie[curVertex]->children[c] = size;
                size++;
            }
            curVertex = Trie[curVertex]
                            ->children[c];  // Mover al nuevo vertice en el trie
        }
        // Marcar el final de la palabra y almacene su ID
        Trie[curVertex]->leaf = true;
        Trie[curVertex]->wordID = wordID;
        wordsLength.pb(s.length());
    }

    void prepareAho() {
        queue<int> vertexQueue;
        vertexQueue.push(root);
        while (!vertexQueue.empty()) {
            int curVertex = vertexQueue.front();
            vertexQueue.pop();
            calcSuffixLink(curVertex);
            for (auto key : Trie[curVertex]->children) {
                vertexQueue.push(key.second);
            }
        }
    }

    int processString(string text) {
        int currentState = root;
        int result = 0;
        F0R(j, text.length()) {
            while (true) {
                if (Trie[currentState]->children.count(text[j])) {
                    currentState = Trie[currentState]->children[text[j]];
                    break;
                }
                if (currentState == root) break;
                currentState = Trie[currentState]->suffixLink;
            }
            int checkState = currentState;
            // Tratar de encontrar todas las palabras posibles de este prefijo
            while (true) {
                checkState = Trie[checkState]->endWordLink;

                // Si estamos en el vertice raiz, no hay mas coincidencias
                if (checkState == root) break;

                result++;
                int indexOfMatch =
                    j + 1 - wordsLength[Trie[checkState]->wordID];

                // Tratando de encontrar todos los patrones combinados de menor
                // longitud
                checkState = Trie[checkState]->suffixLink;
            }
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    vector<string> patterns = {"abc", "bcd", "abcd"};
    string text = "abcd";
    Aho ahoAlg;
    F0R(i, patterns.size()) { ahoAlg.addString(patterns[i], i); }
    ahoAlg.prepareAho();
    cout << ahoAlg.processString(text) << ENDL;

    return 0;
}