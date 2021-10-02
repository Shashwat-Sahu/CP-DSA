#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

class minHeapNode
{
public:
    int v, key;
    minHeapNode();
    minHeapNode(int, int);
};

minHeapNode::minHeapNode(int v, int dist)
{
    this->v = v;
    this->key = key;
}

class minHeap
{
public:
    int size, capacity;
    int *pos;
    minHeapNode **arr;
    minHeap();
    minHeap(int);
    void swapp(int, int);
    void minHeapify(int);
    bool isEmpty();
    minHeapNode *extractMin();
    void decreaseKey(int, int);
    bool isInMinHeap(int);
};

minHeap::minHeap(int capacity)
{
    this->capacity = capacity;
    size = 0;
    pos = new int[capacity];
    arr = new minHeapNode *[capacity];
}

void minHeap::swapp(int i, int j)
{
    minHeapNode *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void minHeap::minHeapify(int index)
{
    int temp, left, right;
    temp = index;
    left = 2 * index + 1;
    right = 2 * index + 2;

    if (left < size && arr[left]->key < arr[temp]->key)
        temp = left;

    if (right < size && arr[right]->key < arr[temp]->key)
        temp = right;

    if (temp != index)
    {
        minHeapNode *tempNode = arr[temp];
        minHeapNode *indexNode = arr[index];

        pos[tempNode->v] = index;
        pos[indexNode->v] = temp;

        swapp(temp, index);

        minHeapify(temp);
    }
}

bool minHeap::isEmpty()
{
    return size == 0;
}

minHeapNode *minHeap::extractMin()
{
    if (isEmpty())
        return NULL;

    minHeapNode *root = arr[0];

    minHeapNode *lastNode = arr[size - 1];
    arr[0] = lastNode;

    pos[root->v] = size - 1;
    pos[lastNode->v] = 0;

    --size;
    minHeapify(0);

    return root;
}

void minHeap::decreaseKey(int v, int key)
{
    int i = pos[v];

    arr[i]->key = key;

    while (i && arr[i]->key < arr[(i - 1) / 2]->key)
    {
        pos[arr[i]->v] = (i - 1) / 2;
        pos[arr[(i - 1) / 2]->v] = i;
        swapp(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

bool minHeap::isInMinHeap(int v)
{
    if (pos[v] < size)
        return true;
    return false;
}
class node
{
public:
    int vertex;
    int weight;
    node *next;
    node();
    node(int v, int w)
    {
        vertex = v;
        weight = w;
        next = NULL;
    }
};

class graph
{
public:
    int numVertices;
    node **adjList;
    graph();
    graph(int);
    bool Search(int, int);
    void addEdge(int, int, int);
    void Prim(int);
    void Display();
};

graph::graph(int n)
{
    numVertices = n;
    adjList = new node *[n];
    for (int i = 0; i < n; i++)
        adjList[i] = NULL;
}

bool graph::Search(int src, int dst)
{

    node *temp = adjList[src];
    while (temp)
    {
        if (temp->vertex == dst)
            return true;
        temp = temp->next;
    }
    return false;
}

void graph::addEdge(int src, int dst, int wt)
{
    if (Search(src, dst))
        return;

    node *newNode = new node(dst, wt);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = new node(src, wt);
    newNode->next = adjList[dst];
    adjList[dst] = newNode;
}

void printArr(int arr[], int n, int key[])
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += key[i];
    cout << "Total weight of MST : " << total << endl;
    cout << "Edges in the MST : " << endl;
    for (int i = 1; i < n; ++i)
        cout << arr[i] << " - " << i << endl;
}

void graph::Prim(int src)
{
    int V = numVertices;
    int parent[V];
    int key[V];

    minHeap *pq = new minHeap(V);

    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        pq->arr[v] = new minHeapNode(v, key[v]);
        pq->pos[v] = v;
    }

    key[0] = 0;
    pq->arr[0] = new minHeapNode(0, key[0]);
    pq->pos[0] = 0;

    pq->size = V;

    while (!pq->isEmpty())
    {
        minHeapNode *tempNode = pq->extractMin();
        int u = tempNode->v;

        node *temp = adjList[u];
        while (temp != NULL)
        {
            int v = temp->vertex;

            if (pq->isInMinHeap(v) && temp->weight < key[v])
            {
                key[v] = temp->weight;
                parent[v] = u;
                pq->decreaseKey(v, key[v]);
            }
            temp = temp->next;
        }
    }

    printArr(parent, V, key);
}

void graph::Display()
{

    for (int i = 0; i < numVertices; i++)
    {
        cout << i << " : ";
        node *temp = adjList[i];
        while (temp)
        {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{

    int n, src, dest, weight;
    cin >> n;

    graph g(n);
    for (int i = 0; i < n; i++)
    {
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }
    g.Prim(0);
    return 0;
}