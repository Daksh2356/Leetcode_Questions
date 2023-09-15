/*
Question : 332. Reconstruct Itinerary
Date : 14-09-23
Problem Difficulty level : Hard
Related Topics : Depth-First Search, Graph and Eulerian Circuit

Problem Statement:

You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of
one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK".
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

Example 1:
Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]

Example 2:
Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.


Constraints:
1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi and toi consist of uppercase English letters.
fromi != toi
*/
class Solution
{
public:
    unordered_map<string, vector<string>> graph;
    vector<string> path;

    void buildGraph(vector<vector<string>> &tickets)
    {
        for (const auto &ticket : tickets) // step 1 - building the graph
        {
            graph[ticket[0]].push_back(ticket[1]);
        }
    }

    void sortGraph()
    {
        for (auto &pair : graph) // step 2 : sorting for lexical order
        {
            sort(pair.second.begin(), pair.second.end());
        }
    }

    void dfs(string airport) // step 3 : DFS algo
    {
        while (!graph[airport].empty())
        {
            string newAirport = graph[airport].front();
            graph[airport].erase(graph[airport].begin()); // removing the visited airport
            dfs(newAirport);                              // calling dfs on the last visited airport
        }

        path.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        buildGraph(tickets);
        sortGraph();
        dfs("JFK");

        reverse(path.begin(), path.end());

        return path;
    }

    // the time complexity is O(m + n * log(n))
    // the space complexity is O(m + n)

    // IMP NOTE : The complexity for this solution is influenced by various factors, including
    // the number of airports (n) and the number of flights (m).
};