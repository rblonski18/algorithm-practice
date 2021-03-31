/* LC 253 - Meeting Rooms II

Given some array of meeting time intervals, 

[[0, 30], [5, 10], [15, 20]]

where intervals[i] = [start, end], return
the minimum number of conference rooms required. 

*/


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        map<int, int> numRooms;
        
        for(auto interval : intervals) {
            numRooms[interval[0]] += 1;
            numRooms[interval[1]] -= 1;
        }
        
        int rooms = 0;
        int maxRooms = 0;
        
        for(auto it : numRooms) {
            rooms += it.second;
            maxRooms = max(maxRooms, rooms);
        }
        
        return maxRooms;
    }
};

