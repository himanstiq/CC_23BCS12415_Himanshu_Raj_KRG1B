#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    bool adj[26][26] = {false};
    vector<int> indegree(26, 0);

    for (int i = 0; i < n - 1; ++i) {
        string word1 = names[i];
        string word2 = names[i + 1];
        
        int len = min(word1.length(), word2.length());
        bool found_diff = false;

        for (int j = 0; j < len; ++j) {
            if (word1[j] != word2[j]) {
                int u = word1[j] - 'a';
                int v = word2[j] - 'a';
                
                if (!adj[u][v]) {
                    adj[u][v] = true;
                    indegree[v]++;
                }
                found_diff = true;
                break; 
            }
        }

    
        if (!found_diff && word1.length() > word2.length()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    // Kahn's Algorithm (BFS)
    queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    string result = "";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result += (char)(current + 'a'); 

        for (int neighbor = 0; neighbor < 26; ++neighbor) {
            if (adj[current][neighbor]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
    }

    if (result.length() == 26) {
        cout << result << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}