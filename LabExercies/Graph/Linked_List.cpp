#include <bits/stdc++.h>
using namespace std;

struct #include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    int status;
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
void link_adjacent(node *, node *);
node *find_address(int);
void bfs();
void dfs();

int main(void)
{
    construct_graph();
    print_adjacency_list();
    bfs();
    dfs();
    return 0;
}

node *create_node(int data)
{
    node *new_node = (node *)(malloc(sizeof(node)));
    new_node->data = data;
    new_node->status = 1;
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
    int n, e;
    int src, dest;
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
            node *addres_of_src = find_address(src);
            node *addres_of_dest = find_address(dest);
            link_adjacent(addres_of_src, addres_of_dest);
        }
    }
}

void link_adjacent(node *addres_of_src, node *addres_of_dest)
{
    if (addres_of_src->adj != NULL)
    {
        Adj *tmp = create_adj(addres_of_dest);
        tmp->adj = addres_of_src->adj;
        addres_of_src->adj = tmp;
    }
    else
    {
        addres_of_src->adj = create_adj(addres_of_dest);
    }
}

void print_adjacency_list()
{
    node_ptr = start;
    cout << "\n\nNode List     Adjacency List\n";
    while (node_ptr != NULL)
    {
        Adj *adj_ptr = NULL;
        adj_ptr = node_ptr->adj;
        // cout << "Adjacent node(s) of " << node_ptr->data << "--> ";
        cout << "    " << node_ptr->data << "    ---->   ";
        while (adj_ptr != NULL)
        {
            cout << adj_ptr->node->data << " ";
            adj_ptr = adj_ptr->adj;
        }
        cout << "\n";
        node_ptr = node_ptr->next;
    }
}

node *find_address(int val)
{
    int count = 0;
    node *pre_node_ptr = NULL;
    node_ptr = start;
    while (node_ptr != NULL)
    {
        pre_node_ptr = node_ptr;
        if (node_ptr->data == val)
        {
            return node_ptr;
        }
        node_ptr = node_ptr->next;
        count++;
    }
    pre_node_ptr->next = create_node(val);
    return pre_node_ptr->next;
}

void bfs()
{
    cout << "\n\nResult of bfs: ";
    queue<node *> que;
    que.push(start);
    start->status = 2;
    while (!que.empty())
    {
        node_ptr = que.front();
        cout << node_ptr->data << " ";
        node_ptr->status = 3;
        que.pop();
        adj_ptr = node_ptr->adj;
        while (adj_ptr != NULL)
        {
            if (adj_ptr->node->status == 1)
            {
                que.push(adj_ptr->node);
                adj_ptr->node->status = 2;
            }
            adj_ptr = adj_ptr->adj;
        }
    }
    cout << "\n\n";
}
void dfs() {
    cout << "\n\nResult of dfs: ";
    stack<node *> stk;
    stk.push(start);
    start->status = 2;
    while (!stk.empty())
    {
        node_ptr = stk.top();
        cout << node_ptr->data << " ";
        node_ptr->status = 3;
        stk.pop();
        adj_ptr = node_ptr->adj;
        while (adj_ptr != NULL)
        {
            if (adj_ptr->node->status == 1)
            {
                stk.push(adj_ptr->node);
                adj_ptr->node->status = 2;
            }
            adj_ptr = adj_ptr->adj;
        }
    }
    cout << "\n\n";
}
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
