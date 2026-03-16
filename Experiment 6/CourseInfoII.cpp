#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);

    for (const auto &pre : prerequisites)
    {
        int course = pre[0];
        int prereq = pre[1];

        graph[prereq].push_back(course);
        indegree[course]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for (int neighbor : graph[current])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    if (result.size() == numCourses)
    {
        return result;
    }
    else
    {
        return {};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numCourses, numPrereqs;
    
    if (cin >> numCourses >> numPrereqs) {
        vector<vector<int>> prerequisites(numPrereqs, vector<int>(2));
        
        for (int i = 0; i < numPrereqs; ++i) {
            cin >> prerequisites[i][0] >> prerequisites[i][1];
        }
        
        
        vector<int> result = findOrder(numCourses, prerequisites);
        
        if (result.empty()) {
            cout << "[]\n"; 
        } else {
            for (int i = 0; i < result.size(); ++i) {
                cout << result[i] << (i == result.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    
    return 0;
}