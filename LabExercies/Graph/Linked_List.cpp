#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct Adj *adj;
};
struct Adj
{
    struct node *node;
    struct Adj *adj;
};

node *start = NULL, *node_ptr = NULL;
Adj *adj_ptr = NULL;
node *create_node(int);
Adj *create_adj(node *);
void construct_graph();
void print_adjacency_list();
void link_adjacent(node *);

int main(void)
{
    construct_graph();
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

void construct_graph()
{
    int n, e, src, dest;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;
    cout << "Enter edges: \n";
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest;
        if (start == NULL)
        {
            start = create_node(src);
            start->next = create_node(dest);
            start->adj = create_adj(start->next);
        }
        else
        {
            node *node_ptr1 = start, *node_ptr2 = start, *p_node_ptr = start;
            Adj *adj_ptr1 = NULL;
            while (node_ptr1 != NULL)
            {
                node_ptr = node_ptr1;
                if (node_ptr1->data == src)
                {
                    while (node_ptr2 != NULL)
                    {
                        p_node_ptr = node_ptr2;
                        if (node_ptr2->data == dest)
                        {
                            link_adjacent(node_ptr2);
                            break;
                        }
                    }
                    if (node_ptr2 == NULL)
                    {
                        p_node_ptr->next = create_node(dest);
                        link_adjacent(p_node_ptr->next);
                    }
                    break;
                }
            }
            if(node_ptr1 == NULL) {
                node_ptr->next = create_node(src);
            }
        }
    }
}

void link_adjacent(node *node_ptr2)
{
    Adj *adj_ptr1 = NULL;
    adj_ptr = create_adj(node_ptr2);
    if (node_ptr->adj == NULL)
    {
        node_ptr->adj = adj_ptr;
    }
    else
    {
        adj_ptr1 = node_ptr->adj;
        node_ptr->adj = adj_ptr;
        adj_ptr->adj = adj_ptr1;
    }
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