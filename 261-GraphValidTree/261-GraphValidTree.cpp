class Solution {
public:
    bool dfs(unordered_map<int , vector<int>>& edgeMap , int n , int current , unordered_set<int>& visited, int parent){
        if(visited.count(current)){
            return false;
        }
        
        visited.insert(current);
        
        vector<int>& neighbours = edgeMap[current];

        stack<int> toVisit;
        for(int i = 0 ; i < neighbours.size() ; i++){
            if(neighbours[i] == parent){
                continue; 
            }
            toVisit.push(neighbours[i]);
        }

        while(!toVisit.empty()){
            int top = toVisit.top();
            toVisit.pop();
            

            if(!dfs(edgeMap , n , top , visited , current)){
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1) {
            return false;
        }

        unordered_map<int , vector<int>> edgeMap;
        for(int i = 0 ; i < edges.size() ; i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];

            edgeMap[n1].push_back(n2);
            edgeMap[n2].push_back(n1);
        }
        
        unordered_set<int> visited;
        
        bool hasNoCycles = dfs(edgeMap, n, 0, visited, -1);
        
        if (!hasNoCycles) {
            return false;
        }

        return visited.size() == n; 
    }
};