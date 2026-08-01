// Last updated: 01/08/2026, 22:44:46
class Solution {
public:
    double gain(int pass, int total) {
        return ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;

        double sumPassRatio = 0.0;
        for (int i = 0; i < classes.size(); i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            sumPassRatio += (double)pass / total;
            pq.push({gain(pass, total), i});
        }

        while (extraStudents-- > 0) {
            auto [g, idx] = pq.top(); pq.pop();
            int pass = classes[idx][0];
            int total = classes[idx][1];
            // Update sum: remove old ratio, add new ratio
            sumPassRatio -= (double)pass / total;
            pass++, total++;
            classes[idx][0] = pass;
            classes[idx][1] = total;
            sumPassRatio += (double)pass / total;
            pq.push({gain(pass, total), idx});
        }

        return sumPassRatio / classes.size();




        
    }
};