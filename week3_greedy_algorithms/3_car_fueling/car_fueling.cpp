#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{

    int numStops = 0;
    int currStop = 0;
    int idx = 0;

    if (dist <= tank)
        return 0;

    // Go over all stops
    while (idx < stops.size())
    {
        // If destination is reachable from current stop , return number of stops
        if (currStop + tank >= dist)
            return numStops;
        // If next stop is not reachable return -1
        else if (currStop + tank < stops[idx])
            return -1;
        //find the farthest station reachable
        while (idx < stops.size() && currStop + tank >= stops[idx])
            idx++;

        currStop = stops[idx - 1];
        numStops++;
    }
    //From furthest stop, check if dest is reachable
    if (currStop + tank >= dist)
        return numStops;
    return -1;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
