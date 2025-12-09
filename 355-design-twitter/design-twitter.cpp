#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    int timeStamp;
    
    // user -> list of followees
    unordered_map<int, unordered_set<int>> followMap;
    
    // user -> list of tweets (pair of timestamp, tweetId)
    unordered_map<int, vector<pair<int, int>>> tweets;
    
public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // max heap of (timestamp, tweetId, owner, index in owner's tweet list)
        priority_queue<vector<int>> pq;  
        
        // include user's own tweets
        if (tweets.count(userId)) {
            auto &tw = tweets[userId];
            int idx = tw.size() - 1;
            pq.push({tw[idx].first, tw[idx].second, userId, idx});
        }
        
        // include followees' tweets
        for (int followee : followMap[userId]) {
            if (tweets.count(followee)) {
                auto &tw = tweets[followee];
                int idx = tw.size() - 1;
                pq.push({tw[idx].first, tw[idx].second, followee, idx});
            }
        }
        
        vector<int> feed;
        
        while (!pq.empty() && feed.size() < 10) {
            auto top = pq.top(); 
            pq.pop();
            
            int time = top[0];
            int tweetId = top[1];
            int user = top[2];
            int idx = top[3];
            
            feed.push_back(tweetId);
            
            // push the next older tweet from same user
            if (idx - 1 >= 0) {
                pq.push({tweets[user][idx - 1].first,
                         tweets[user][idx - 1].second,
                         user,
                         idx - 1});
            }
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followMap.count(followerId))
            followMap[followerId].erase(followeeId);
    }
};
