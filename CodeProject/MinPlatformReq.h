#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>
#include <time.h>
#include <fstream>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class Schedule
{
public:
    int arrival;
    int departure;
    Schedule(int arrival, int departure) : arrival(arrival), departure(departure) {}
    string str() {
        return "{" + to_string(arrival) + ", " + to_string(departure) + "}";
    }
};

class StationTimeChart
{
public:
    vector<Schedule> schedules;

public:
    StationTimeChart(vector<pair<int, int>>& schedules) {
        for (auto s : schedules) {
            this->schedules.push_back(Schedule(s.first, s.second));
        }
    }
    string str() {
        stringstream ss;
        ss << "{";
        for (auto s : schedules) ss << s.str() << ", ";
        ss << "}";

        return ss.str();
    }
};
class MinPlatformRequired
{
public:
    void test()
    {
        vector<vector<pair<int, int>>> v = {
            {{900,910}, {940,1200},{950,1120},{1100,1130},{1500,1900},{1800,2000}}
        };

        vector<StationTimeChart> charts;
        for (auto i : v) {
            charts.push_back(StationTimeChart(i));
        }

        for (auto chart : charts) {
            cout << "Processing: {" << chart.str() << "} :";
            auto res = minPlatforms(chart);
            cout << "Result = " << res << endl;
        }
    }

    int minPlatforms(StationTimeChart chart)
    {
        int result = 0;
        multimap<int, char> map;
        for (auto v : chart.schedules) {
            map.insert({ v.arrival, 'a' });
            map.insert({ v.departure, 'd' });
        }

        int tmp = 0;
        for (auto m : map) {
            if (m.second == 'a') {
                tmp++; if (tmp > result) result = tmp;
            }
            else tmp--;
        }

        return result;
    }
};