#include<set>
#include<cmath>

class cmp {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1]; // Sort by size descending
    }
};

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        vector<int> answer(queries.size());

    // Step 1: Sort rooms by size descending
    sort(rooms.begin(), rooms.end(), cmp());

    // Step 2: Pair each query with its original index
    vector<pair<vector<int>, int>> indexedQueries;
    for (int i = 0; i < queries.size(); ++i) {
        indexedQueries.push_back({queries[i], i});
    }

    // Step 3: Sort queries by minSize descending (i.e., query[1])
    sort(indexedQueries.begin(), indexedQueries.end(), [](const pair<vector<int>, int>& a,  const pair<vector<int>, int>& b) {
        return a.first[1] > b.first[1];
    });

    // Step 4: Use a set to store valid room IDs
    set<int> validRoomIds; //creating set only once as it is descending order rooms satisfied previous query will satisfy further query also
    int roomIdx = 0;

    for (const auto& queryPair : indexedQueries) {
        const vector<int>& query = queryPair.first;
        int preferredId = query[0];
        int minSize = query[1];
        int originalIndex = queryPair.second;

        // Insert all rooms with size >= minSize into the set
        while (roomIdx < rooms.size() && rooms[roomIdx][1] >= minSize) {
            validRoomIds.insert(rooms[roomIdx][0]);
            ++roomIdx;
        }

        // If no valid room
        if (validRoomIds.empty()) {
            answer[originalIndex] = -1;
            continue;
        }

        int closestId = -1;
        int minDist = INT_MAX;

        auto it = validRoomIds.lower_bound(preferredId);

        // Check current (>= preferredId)
        if (it != validRoomIds.end()) {
            int dist = abs(*it - preferredId);
            if (dist < minDist || (dist == minDist && *it < closestId)) {
                closestId = *it;
                minDist = dist;
            }
        }

        // Check previous (< preferredId)
        if (it != validRoomIds.begin()) {
            --it;
            int dist = abs(*it - preferredId);
            if (dist < minDist || (dist == minDist && *it < closestId)) {
                closestId = *it;
            }
        }

        answer[originalIndex] = closestId;
    }

    return answer;    
    }
};