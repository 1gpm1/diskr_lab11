#include <iostream>
using namespace std;

#define V 7
#define INF 99999

class FloydWarshall {
public:
    int dist[V][V];

    void floydWarshall(int graph[V][V]) {
        int i, j, k;

        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = graph[i][j];

        for (k = 0; k < V; k++) {
            for (i = 0; i < V; i++) {
                for (j = 0; j < V; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        printSolution();
    }

    void printSolution() {
        cout << "Following matrix shows the shortest distances between every pair of vertices" << endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << "   ";
            }
            cout << endl;
        }
    }
};

int main() {
    int graph[V][V] = { {0, 7, 3, INF, INF, INF, INF},
                        {INF, 0, INF, 8, INF, INF, INF},
                        {INF, INF, 0, INF, 2, INF, INF},
                        {INF, INF, INF, 0, INF, 4, INF},
                        {INF, INF, INF, INF, 0, 3, 2},
                        {INF, INF, INF, INF, INF, 0, 6},
                        {INF, INF, INF, INF, INF, INF, 0}
    };

    FloydWarshall a;
    a.floydWarshall(graph);

    return 0;
}
