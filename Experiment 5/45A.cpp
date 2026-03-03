#include <iostream>
#include <string>
using namespace std;
 
struct Node {
    Node* child[3];
    bool eow;
 
    Node() {
        for (int i = 0; i < 3; i++) child[i] = nullptr;
        eow = false;
    }
};
 
Node* top = new Node();
 
void built(const string& s) {
    Node* root = top;
 
    for (int i = 0; i < (int)s.size(); i++) {
        int idx = s[i] - 'a';
 
        if (root->child[idx] == nullptr) {
            root->child[idx] = new Node();
        }
        root = root->child[idx];
    }
    root->eow = true;
}
 
bool searchWord(const string& s, bool fl, int idx, Node* root) {
    if (root == nullptr) return false;
 
    if (idx == (int)s.size()) {
        return fl && root->eow;
    }
 
    int pos = s[idx] - 'a';
 
    if (searchWord(s, fl, idx + 1, root->child[pos])) {
        return true;
    }
 
    if (!fl) {
        for (int i = 0; i < 3; i++) {
            if (i == pos) continue;
            if (root->child[i] != nullptr) {
                if (searchWord(s, true, idx + 1, root->child[i])) {
                    return true;
                }
            }
        }
    }
    return false;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        built(s);
    }
 
    string s;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (searchWord(s, false, 0, top)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}