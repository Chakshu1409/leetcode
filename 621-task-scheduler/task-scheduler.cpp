class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) {
            freq[t - 'A']++;
        }

        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) pq.push(f);
        }

        queue<pair<int, int>> cooldown; // {time when it can be re-added, remaining count}
        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            if (!pq.empty()) {
                int cnt = pq.top(); pq.pop();
                cnt--;
                if (cnt > 0) {
                    cooldown.push({time + n, cnt});
                }
            }

            if (!cooldown.empty() && cooldown.front().first == time) {
                pq.push(cooldown.front().second);
                cooldown.pop();
            }
        }

        return time;
    }
};
