class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> m; // Stores check-in information for each customer ID
    unordered_map<string, pair<int, int>> n; // Stores aggregated travel information for each route

    string w = "*"; // Delimiter to differentiate between start and end string

    UndergroundSystem() {
        // Constructor
    }

    void checkIn(int id, string a, int t) {
        // Records the check-in time and station for a customer ID
        m[id] = make_pair(a, t);
    }

    void checkOut(int id, string b, int t) {
        // Records the check-out time and station for a customer ID and calculates the travel time

        string x = m[id].first; // Get the station name from the check-in information

        x += w; // Append the delimiter to the station name
        x += b; // Append the check-out station name

        int y = 0, diff = t - m[id].second, old = 0;

        if (n.find(x) != n.end()) {
            // If the route (start station + delimiter + end station) already exists in the map
            y = n[x].second; // Get the total travel time
            old = n[x].first; // Get the number of completed trips
        }

        n[x] = make_pair(old + diff, y + 1); // Update the aggregated travel information for the route
    }

    double getAverageTime(string a, string b) {
        // Calculates and returns the average travel time between two stations

        string s = a;
        s += w; // Append the delimiter to the start station name
        s += b; // Append the end station name

        double x = n[s].first; // Get the total travel time
        double y = n[s].second; // Get the number of completed trips

        return x / y; // Calculate and return the average travel time
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */