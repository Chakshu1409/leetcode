class Twitter {
public:
    unordered_map<int, vector< pair<int,int> > > userToTweets;
    unordered_map<int, set<int> > userToFollowing;
    int time=0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userToTweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        userToFollowing[userId].insert(userId);
        for(auto it: userToFollowing[userId]){
            for(auto ij: userToTweets[it]){
                pq.push(ij);
                if(pq.size() > 10){
                    pq.pop();
                }
            }
        }
        vector<int> ans;
        while(!pq.empty() && ans.size()<=10){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        // sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        userToFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userToFollowing[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */