#pragma once
#include "../Header.h"

//https://www.careercup.com/question?id=6282171643854848
class SeeIfAllTasksCanBeRescheduledOnGivenServers
{
public:
    static void test()
    {
        SeeIfAllTasksCanBeRescheduledOnGivenServers obj;

        {
            vector<int> servers = { 8, 16, 8, 32 };
            vector<int> needs = { 18, 4, 8, 4, 6, 6, 8, 8 };
            bool res = obj.canBeArranged(servers, needs);
            cout << "Result? " << res << endl;
        }

        {
            vector<int> servers = { 1,3 };
            vector<int> needs = { 4 };
            bool res = obj.canBeArranged(servers, needs);
            cout << "Result? " << res << endl;
        }
    }

    bool canBeArranged(vector<int> servers, vector<int> needs)
    {
        int s = 0;
        return canBeArranged(servers, needs, s);
    }

    bool canBeArranged(vector<int>& servers, vector<int> needs, int s)
    {
        if (s == needs.size()) return true;

        for (auto& server : servers) {
            if (needs[s] <= server) {
                server -= needs[s];
                if (canBeArranged(servers, needs, s + 1)) return true;
                server += needs[s];
            }
        }

        return false;
    }
};