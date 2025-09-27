#include <string>
#include <iostream>
using namespace std;

class TimeMap {
public:
    TimeMap(unordered_map<string, vector<pair<string, int>>> map) : map(map) { }

    TimeMap() : map({}) { }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({ value, timestamp });
    }

    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) return "";

        const auto& u_v = map[key];
        int left = 0;
        int right = u_v.size() - 1;
        string tmp_str = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (u_v[mid].second <= timestamp) {
                tmp_str = u_v[mid].first;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return tmp_str;
    }
    
    /*string get(string key, int timestamp) {
        if (map.find(key) == map.end()) return "";

        string temp_str = "";
        vector<pair<string, int>> u_v = map[key];
        int low = 0;
        int high = u_v.size() - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            for (int i = low; i <= middle; ++i) {
                pair<string, int> middle_pair = u_v[middle];
                if (middle_pair.second <= timestamp) {
                    temp_str = middle_pair.first;
                    if (middle_pair.second == timestamp) {
                        return middle_pair.first;
                    }
                }
            }
            low = middle + 1;
        }

        return temp_str;
    }*/

private:
    unordered_map<string, vector<pair<string, int>>> map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    vector<pair<pair<string, int>, string>> map = {};
    TimeMap* timeMap = new TimeMap();
    timeMap->set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    cout << timeMap->get("foo", 1) << endl;         // return "bar"
    cout << timeMap->get("foo", 3) << endl;         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap->set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    cout << timeMap->get("foo", 4) << endl;         // return "bar2"
    cout << timeMap->get("foo", 5) << endl;         // return "bar2"
    delete timeMap;

    cout << endl << endl;

    // [null,null,null,"","high","high","low","low"]
    timeMap = new TimeMap();
    timeMap->set("love","high",10);
    timeMap->set("love","low",20);
    cout << timeMap->get("love",5) << endl;
    cout << timeMap->get("love",10) << endl;
    cout << timeMap->get("love",15) << endl;
    cout << timeMap->get("love",20) << endl;
    cout << timeMap->get("love",25) << endl;
    delete timeMap;

    return 0;
}
