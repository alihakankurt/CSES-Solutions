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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u32 pupilCount, friendshipCount;
    cin >> pupilCount >> friendshipCount;

    auto friends = vector<vector<u32>>(pupilCount + 1);
    while (friendshipCount > 0)
    {
        u32 pupil1, pupil2;
        cin >> pupil1 >> pupil2;

        friends[pupil1].push_back(pupil2);
        friends[pupil2].push_back(pupil1);

        friendshipCount -= 1;
    }

    queue<u32> qu;
    vector<u16> team(pupilCount + 1, 0);
    for (u32 pupil = 1; pupil <= pupilCount; pupil += 1)
    {
        if (team[pupil] != 0)
        {
            continue;
        }

        qu.push(pupil);
        team[pupil] = 1;
        while (!qu.empty())
        {
            u32 current = qu.front();
            qu.pop();

            for (u32 next : friends[current])
            {
                if (team[next] == 0)
                {
                    team[next] = team[current] ^ 3;
                    qu.push(next);
                    continue;
                }

                if (team[next] == team[current])
                {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
            }
        }
    }

    for (u32 pupil = 1; pupil <= pupilCount; pupil += 1)
    {
        cout << team[pupil] << ' ';
    }

    return 0;
}
