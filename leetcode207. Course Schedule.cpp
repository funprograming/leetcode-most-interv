/* leetcode207. Course Schedule
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to 
first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible 
for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take 
             course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
 */
typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses,prerequisites);
        vector<VStatus> status(numCourses,UNDISCOVERED);
        for(int v=0;v<numCourses;v++){
            if (UNDISCOVERED == status[v]){
                if(!top_sort_dfs(status,v,graph)) return false;
            }
        }
        return true;
    }

    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for(auto p : prerequisites){
            graph[p.second].insert(p.first);
        }
        return graph;
    }

    bool top_sort_dfs(vector<VStatus>& status,int v,vector<unordered_set<int>>& graph){
        status[v] = DISCOVERED;
        for(auto u : graph[v]){
            switch(status[u]){
                case UNDISCOVERED:
                    if(!top_sort_dfs(status,u,graph)) return false;
                    break;
                case DISCOVERED:
                    return false;
                    break;          
                default: 
                    break;
            }
        }
        status[v] = VISITED;
        return true;
    }
};