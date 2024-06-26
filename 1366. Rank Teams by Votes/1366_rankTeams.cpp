#define SOLUTION_1366
#ifdef SOLUTION_1366
#include "1366_rankTeams.h"

int main()
{
    Solution_1366 myobj;
    vector<string> votes = { "ABC", "ACB", "ABC", "ACB", "ACB" };
    cout << "The final ranking is: " << myobj.rankTeams(votes) << endl;
    return 0;
}
#endif