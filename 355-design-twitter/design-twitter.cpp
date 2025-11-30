#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Twitter {
private:
    struct Tweet {
        int timestamp;
        int tweetId;
    };

    struct HeapNode {
        int timestamp;
        int tweetId;
        int userId;
        int index; // index of tweet inside user's list
    };

    struct Compare {
        bool operator()(const HeapNode &a, const HeapNode &b) const {
            return a.timestamp < b.timestamp; // max-heap
        }
    };

    int currentTime = 0;

    // userId -> list of tweets (each tweet stores timestamp + tweetId)
    unordered_map<int, vector<Tweet>> userTweets;

    // followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> followList;

public:
    Twitter() = default;

    // ---------------------------------------------------------------
    // Post a tweet for a user
    // ---------------------------------------------------------------
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({++currentTime, tweetId});
    }

    // ---------------------------------------------------------------
    // Helper: push the most recent tweet of a user into the heap
    // ---------------------------------------------------------------
    void pushUserLatestTweet(int userId, priority_queue<HeapNode, vector<HeapNode>, Compare> &pq) {
        auto &tweets = userTweets[userId];
        if (!tweets.empty()) {
            int idx = tweets.size() - 1;
            pq.push({tweets[idx].timestamp, tweets[idx].tweetId, userId, idx});
        }
    }

    // ---------------------------------------------------------------
    // Get the 10 most recent tweets from user + followees
    // ---------------------------------------------------------------
    vector<int> getNewsFeed(int userId) {
        priority_queue<HeapNode, vector<HeapNode>, Compare> pq;

        // Include the user's own latest tweet
        pushUserLatestTweet(userId, pq);

        // Include followees
        if (followList.count(userId)) {
            for (int followee : followList[userId]) {
                if (followee != userId) {
                    pushUserLatestTweet(followee, pq);
                }
            }
        }

        vector<int> result;

        // Extract at most 10 most recent tweets
        while (!pq.empty() && result.size() < 10) {
            auto top = pq.top();
            pq.pop();
            result.push_back(top.tweetId);

            // Move to the previous tweet from the same user
            if (top.index > 0) {
                int newIndex = top.index - 1;
                const auto &tweetList = userTweets[top.userId];
                pq.push({
                    tweetList[newIndex].timestamp,
                    tweetList[newIndex].tweetId,
                    top.userId,
                    newIndex
                });
            }
        }

        return result;
    }

    // ---------------------------------------------------------------
    // Follow
    // ---------------------------------------------------------------
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followList[followerId].insert(followeeId);
        }
    }

    // ---------------------------------------------------------------
    // Unfollow
    // ---------------------------------------------------------------
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};
