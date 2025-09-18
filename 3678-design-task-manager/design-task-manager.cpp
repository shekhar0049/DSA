#include <bits/stdc++.h>
using namespace std;

class TaskManager {
private:
   
    unordered_map<int, pair<int, int>> taskMap;

   
    priority_queue<array<long long, 3>> maxHeap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskMap[taskId] = {userId, priority};
            maxHeap.push({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        maxHeap.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        if (taskMap.find(taskId) == taskMap.end()) return;
        int userId = taskMap[taskId].first;
        taskMap[taskId] = {userId, newPriority};
        maxHeap.push({newPriority, taskId, userId});
    }

    void rmv(int taskId) {
        if (taskMap.find(taskId) == taskMap.end()) return;
        taskMap.erase(taskId);
    }

    int execTop() {
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            int priority = top[0], taskId = top[1], userId = top[2];

           
            if (taskMap.find(taskId) != taskMap.end() && taskMap[taskId].second == priority) {
                maxHeap.pop();
                taskMap.erase(taskId); 
                return userId;
            }
            maxHeap.pop(); 
        }
        return -1; 
    }
};
