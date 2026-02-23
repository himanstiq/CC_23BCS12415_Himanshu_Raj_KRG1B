#include <bits/stdc++.h>
using namespace std;

vector<int> JobScheduling(Job arr[], int n) { 
    int max_deadline = arr[0].dead;
    for(int i=1; i<n; i++)
        max_deadline = max(max_deadline, arr[i].dead);
        
    vector<int> sequence(max_deadline+1, -1);
    sort(arr, arr+n, comp);
    
    int countJobs=0;
    int maxProfit=0;
    
    for(int i=0; i<n; i++) {
        for(int j=arr[i].dead; j>0; j--) {
            if(sequence[j]==-1) {
                sequence[j]=i;
                countJobs++;
                maxProfit+=arr[i].profit;
                break;
            }
        }
    }
    return {countJobs, maxProfit};
} 