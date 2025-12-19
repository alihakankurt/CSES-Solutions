#include <bits/stdc++.h>
using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using uptr = uintptr_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = make_signed_t<size_t>;
using iptr = intptr_t;

using f32 = float_t;
using f64 = double_t;

constexpr i32 Modulus = 1e9 + 7;

enum class SearchState : u16
{
    None,
    Searching,
    Completed,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u32 cityCount, roadCount;
    cin >> cityCount >> roadCount;

    auto roadmap = vector<vector<u32>>(cityCount + 1);
    while (roadCount > 0)
    {
        u32 city1, city2;
        cin >> city1 >> city2;

        roadmap[city1].push_back(city2);
        roadmap[city2].push_back(city1);

        roadCount -= 1;
    }

    vector<SearchState> searchStates(cityCount + 1);
    vector<u32> visitedFrom(cityCount + 1);
    pair<u32, u32> cycleEdge;

    function<bool(u32, u32)> searchRoute = [&](u32 previousCity, u32 currentCity)
    {
        searchStates[currentCity] = SearchState::Searching;
        visitedFrom[currentCity] = previousCity;

        for (u32 targetCity : roadmap[currentCity])
        {
            if (targetCity == previousCity)
                continue;

            switch (searchStates[targetCity])
            {
                case SearchState::None:
                    if (searchRoute(currentCity, targetCity))
                        return true;
                    break;
                case SearchState::Searching:
                    cycleEdge = {currentCity, targetCity};
                    return true;
                default:
                    break;
            }
        }

        searchStates[currentCity] = SearchState::Completed;
        return false;
    };

    for (u32 city = 1; city <= cityCount; city += 1)
    {
        if (searchStates[city] == SearchState::None && searchRoute(0, city))
        {
            auto [lastCity, startCity] = cycleEdge;

            vector<u32> route;
            route.push_back(startCity);

            u32 visitedCity = lastCity;
            while (visitedCity != startCity)
            {
                route.push_back(visitedCity);
                visitedCity = visitedFrom[visitedCity];
            }

            route.push_back(startCity);

            cout << route.size() << '\n';
            for (u32 city : route)
            {
                cout << city << ' ';
            }

            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
