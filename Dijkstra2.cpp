#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
int n, m, k, from, to, cost, Start; //vertex's count, edge's count, startpoint, endpoint, weight, StartCity.
//priority queue to get shortest distance node.
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
priority_queue<int> Distance[1001]; //city's shortest distance queue.
//vertex array.
vector<pair<int, int> > v[1001];    //pair. => node. (start, end)
void dijkstra();
int main()
{
    //vertex's count, edge's count, find key index.
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(to, cost));
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        //if size small than K => can't find Route
        if (Distance[i].size() < k)
        {
            cout << "-1" << "\n";
        }
        else
        {
            cout << Distance[i].top() << "\n";
        }
    }
    return 0;
}
//not need visited array. because find Index is not =1.
void dijkstra()
{
    pq.push(make_pair(0, 1));
    Distance[1].push(0); // 1->1로가는 첫번째 최단경로는 무조건!! 0이다.

    while (!pq.empty())
    {
        //get weight.
        int x = pq.top().second;
        int num = pq.top().first;
        pq.pop();

        for (int i = 0; i < v[x].size(); i++)
        {
            int next = v[x][i].first;
            int cost = num + v[x][i].second;
            // distance queue. small than find index. => push distance.
            if (Distance[next].size() < k)
            {
                Distance[next].push(cost);
                pq.push(make_pair(cost, next));
            }
            else
            {
                //compare next distance, queue's shortest distance
                if (Distance[next].top() > cost)
                {
                    Distance[next].pop();
                    //add new shortest distance.
                    Distance[next].push(cost);
                    pq.push(make_pair(cost, next));
                }
            }
        }
    }
}