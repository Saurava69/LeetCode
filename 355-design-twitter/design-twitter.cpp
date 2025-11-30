#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    int timeCounter = 0; // global increasing timestamp
    // userId -> vector of (timestamp, tweetId). Newer tweets appended at back.
    unordered_map<int, vector<pair<int,int>>> tweets;
    // followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> follows;

public:
    Twitter() {
        timeCounter = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timeCounter, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // Use max-heap: (timestamp, tweetId, userId, indexInUserList)
        struct Item {
            int ts;
            int tweetId;
            int uid;
            int idx; // index in that user's vector
        };
        struct Cmp {
            bool operator()(Item const &a, Item const &b) const {
                return a.ts < b.ts; // max-heap by ts
            }
        };

        priority_queue<Item, vector<Item>, Cmp> pq;

        // helper to push the latest tweet of a user if exists
        auto pushLatest = [&](int uid) {
            auto it = tweets.find(uid);
            if (it != tweets.end() && !it->second.empty()) {
                int idx = (int)it->second.size() - 1;
                pq.push({it->second[idx].first, it->second[idx].second, uid, idx});
            }
        };

        // include user's own tweets
        pushLatest(userId);

        // include followees' latest tweets
        if (follows.count(userId)) {
            for (int followee : follows[userId]) {
                if (followee == userId) continue; // optional safety
                pushLatest(followee);
            }
        }

        vector<int> feed;
        while (!pq.empty() && (int)feed.size() < 10) {
            Item it = pq.top(); pq.pop();
            feed.push_back(it.tweetId);

            // move to the previous tweet of that user (idx - 1)
            if (it.idx - 1 >= 0) {
                auto &vec = tweets[it.uid];
                int newIdx = it.idx - 1;
                pq.push({vec[newIdx].first, vec[newIdx].second, it.uid, newIdx});
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // ignore self-follow
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (follows.count(followerId)) follows[followerId].erase(followeeId);
    }
};
