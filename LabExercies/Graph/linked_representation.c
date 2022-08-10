#include <bits/stdc++.h>
using namespace std;
struct node //Nodes of graph
{
    int data;
    struct node *next;
    struct Adj *adj;
};
struct Adj //Connectors
{
    struct node *node;
    struct Adj *adj;
};
node *start = NULL, *node_ptr = NULL;
node *create_node(int);
Adj *create_adj(node *);
void print_adjacency_list();
int main(void)
{
    int n, name;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter your nodes: ";
    for (int i = 0; i < n; i++) //Creating the node list
    {
        cin >> name;
        if (i == 0)
        {
            start = create_node(name);
            node_ptr = start;
        }
        else
        {
            node *new_node = create_node(name);
            node_ptr->next = new_node;
            node_ptr = new_node;
        }
    }
    node_ptr = start;
    while (node_ptr != NULL) //Creating the adjacency list
    {
        int adj_number = 0, adj_node;
        cout << "Enter number of adjacent nodes of " << node_ptr->data << ": ";
        cin >> adj_number;
        if (adj_number)
            cout << "Enter adjacent node(s) of " << node_ptr->data << ": ";
        Adj *adj_ptr = NULL, *new_adj = NULL;
        for (int i = 0; i < adj_number; i++)
        {
            cin >> adj_node;
            node *search = start;
            while (search != NULL)
            {
                if (search->data == adj_node)
                {
                    if (i == 0)
                    {
                        new_adj = create_adj(search);
                        adj_ptr = new_adj;
                        node_ptr->adj = new_adj;
                    }
                    else
                    {
                        new_adj = create_adj(search);
                        adj_ptr->adj = new_adj;
                        adj_ptr = new_adj;
                    }
                    break;
                }
                search = search->next;
            }
        }
        node_ptr = node_ptr->next;
    }
    print_adjacency_list();
    return 0;
}
node *create_node(int data)
{
    node *new_node = (node *)(malloc(sizeof(node)));
    new_node->data = data;
    new_node->next = NULL;
    new_node->adj = NULL;
    return new_node;
}
Adj *create_adj(node *adj_node)
{
    Adj *new_adj_node = (Adj *)(malloc(sizeof(Adj)));
    new_adj_node->node = adj_node;
    new_adj_node->adj = NULL;
    return new_adj_node;
}
void print_adjacency_list()
{
    node_ptr = start;
    while (node_ptr != NULL)
    {
        Adj *adj_ptr = NULL;
        adj_ptr = node_ptr->adj;
        cout << "Adjacent node(s) of " << node_ptr->data << "--> ";
        while (adj_ptr != NULL)
        {
            cout << adj_ptr->node->data << " ";
            adj_ptr = adj_ptr->adj;
        }
        cout << "\n";
        node_ptr = node_ptr->next;
    }
}
