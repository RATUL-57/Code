#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int number;
    int total_child_in_subtree;
    string line;
    double fraction;
    char character;
    Node *parent;
    Node *leftchild;
    Node *rightchild;
    int height;

    Node() : parent(nullptr), leftchild(nullptr), rightchild(nullptr), total_child_in_subtree(0), height(0) {}
};

class BinaryTree
{
public:
    Node *root;
    Node *lastInsertedNode;

    BinaryTree() : root(nullptr) {}

    void insert_in_binary_tree(int value, int parent, int child);

    void level_order_traversal(Node *current);
    Node *find_by_level_order_traversal(int data);
    void pre_order_traversal(Node *current);
    Node *find_by_pre_order_traversal(int data, Node *current);
    void in_order_traversal(Node *current);
    Node *find_by_in_order_traversal(int data, Node *current);
    void post_order_traversal(Node *current);
    Node *find_by_post_order_traversal(int data, Node *current);

    int find_height(Node *current);

    int find_maximum_value_in_path(int x, int y, Node *temp);

    void insert_in_binary_search_tree(Node *temp, int value);
    void delete_from_binary_search_tree(int value);

    Node *search_by_binary_search_tree(Node *temp, int value);
    Node *minimum_value_in_binary_search_tree(Node *current);
    Node *maximum_value_in_binary_search_tree(Node *current);
    void sorting_using_binary_search_tree(Node *temp, vector<int> &sorted);
    Node *find_successor_from_binary_search_tree(Node *current);
    Node *find_predecessor_from_binary_search_tree(Node *current);

    void left_rotation_in_AVL_tree(Node *temp);
    void right_rotation_in_AVL_tree(Node *temp);
    void balance_node_in_AVL_tree(Node *temp, int balance_factor, int data);
    void insert_in_AVL_tree(Node *temp, int data);
    int balance_factor(Node *current);
    void update_height_for_whole_tree(Node *root);
    Node * find_heavychild(Node * temp);
};

int main()
{
    BinaryTree bst;
    int total_node;
    cin >> total_node;

    // while (total_node--)
    // {
    //     int val, par, cld;
    //     cin >> val >> par >> cld;
    //     bst.insert_in_binary_tree(val, par, cld);
    // }

    for (int i = 0; i < total_node; i++)
    {
        int num;
        cin >> num;
        bst.insert_in_AVL_tree(bst.root, num);
        cout << "after inserting " << num << endl;
        bst.level_order_traversal(bst.root);
        cout << endl
             << endl;
        // bst.insert_in_binary_search_tree(bst.root,num);
    }
    bst.level_order_traversal(bst.root);
}

void BinaryTree::insert_in_binary_tree(int value, int parent, int child)
{
    Node *newNode = new Node();
    newNode->number = value;

    if (parent == 0)
    {
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        else
        {
            cout << "Error: Root node already exists." << endl;
            delete newNode;
            return;
        }
    }

    queue<Node *> tree;
    tree.push(root);

    while (!tree.empty())
    {
        Node *current = tree.front();
        tree.pop();

        if (current->number == parent)
        {
            if (child == 1)
            {
                if (current->leftchild == nullptr)
                {
                    current->leftchild = newNode;
                    newNode->parent = current;
                    return;
                }
                else
                {
                    cout << "Error: Left child already exists for parent " << parent << endl;
                    delete newNode;
                    return;
                }
            }
            else if (child == 2)
            {
                if (current->rightchild == nullptr)
                {
                    current->rightchild = newNode;
                    newNode->parent = current;
                    return;
                }
                else
                {
                    cout << "Error: Right child already exists for parent " << parent << endl;
                    delete newNode;
                    return;
                }
            }
        }

        if (current->leftchild != nullptr)
            tree.push(current->leftchild);

        if (current->rightchild != nullptr)
            tree.push(current->rightchild);
    }

    cout << "Error: Parent " << parent << " not found in the tree." << endl;
    delete newNode;
}

void BinaryTree::pre_order_traversal(Node *current)
{
    if (current == nullptr)
        return;

    cout << current->number << endl;

    pre_order_traversal(current->leftchild);
    pre_order_traversal(current->rightchild);
}

Node *BinaryTree::find_by_pre_order_traversal(int data, Node *current)
{
    if (current == nullptr)
        return nullptr;

    if (current->number == data)
        return current;

    Node *foundNode = find_by_pre_order_traversal(data, current->leftchild);
    if (foundNode != nullptr)
        return foundNode;

    return find_by_pre_order_traversal(data, current->rightchild);
}

void BinaryTree::in_order_traversal(Node *current)
{
    if (current == nullptr)
        return;

    in_order_traversal(current->leftchild);

    cout << current->number << endl;
    // cout << current->height << endl << endl;

    in_order_traversal(current->rightchild);
}

Node *BinaryTree::find_by_in_order_traversal(int data, Node *current)
{
    if (current == nullptr)
        return nullptr;

    Node *foundNode = find_by_in_order_traversal(data, current->leftchild);
    if (foundNode != nullptr)
        return foundNode;

    if (current->number == data)
        return current;

    Node *foundNode2 = find_by_in_order_traversal(data, current->rightchild);
    if (foundNode2 != nullptr)
        return foundNode2;

    return nullptr;
}

void BinaryTree::post_order_traversal(Node *current)
{
    if (current == nullptr)
        return;

    post_order_traversal(current->leftchild);
    post_order_traversal(current->rightchild);

    cout << current->number << endl;
}

Node *BinaryTree::find_by_post_order_traversal(int data, Node *current)
{
    if (current == nullptr)
        return nullptr;

    Node *foundNode = find_by_post_order_traversal(data, current->leftchild);
    if (foundNode != nullptr)
        return foundNode;

    Node *foundNode2 = find_by_post_order_traversal(data, current->rightchild);
    if (foundNode2 != nullptr)
        return foundNode2;

    if (current->number == data)
        return current;

    return nullptr;
}

int BinaryTree::find_height(Node *current)
{
    if (current == nullptr)
        return -1;

    int left_child_height = find_height(current->leftchild) + 1;
    int right_child_height = find_height(current->rightchild) + 1;
    current->height = max(left_child_height, right_child_height);
    return current->height;
}

void BinaryTree::level_order_traversal(Node *current)
{
    if (current == nullptr)
        return;

    queue<Node *> tree;
    tree.push(current);

    while (!tree.empty())
    {
        Node *temp = tree.front();
        tree.pop();

        // cout << temp->number << endl;
        cout << temp->number << ' ';

        if (temp->leftchild != nullptr)
            tree.push(temp->leftchild);

        if (temp->rightchild != nullptr)
            tree.push(temp->rightchild);
    }
}

Node *BinaryTree::find_by_level_order_traversal(int data)
{
    if (root == nullptr)
        return nullptr;

    queue<Node *> tree;
    tree.push(root);

    while (!tree.empty())
    {
        Node *temp = tree.front();
        tree.pop();

        if (temp->number == data)
            return temp;

        if (temp->leftchild != nullptr)
            tree.push(temp->leftchild);

        if (temp->rightchild != nullptr)
            tree.push(temp->rightchild);
    }

    return nullptr;
}

void BinaryTree::insert_in_binary_search_tree(Node *temp, int value)
{
    Node *newNode = new Node();
    newNode->number = value;
    if (temp == nullptr)
    {
        root = newNode;
        newNode->height = 0;
        lastInsertedNode = newNode;
    }
    else
    {
        while (1)
        {
            if (temp->number > value)
            {
                temp->total_child_in_subtree++;
                if (temp->leftchild == nullptr)
                {
                    temp->leftchild = newNode;
                    newNode->parent = temp;
                    temp = newNode;
                    lastInsertedNode = newNode;
                    for (int i = 0;; i++)
                    {
                        temp->height = max(i, temp->height);
                        if (temp->parent == nullptr)
                            break;
                        else
                            temp = temp->parent;
                    }
                    break;
                }
                else
                    temp = temp->leftchild;
            }
            else
            {
                temp->total_child_in_subtree++;
                if (temp->rightchild == nullptr)
                {
                    temp->rightchild = newNode;
                    newNode->parent = temp;
                    temp = newNode;
                    lastInsertedNode = newNode;
                    for (int i = 0;; i++)
                    {
                        temp->height = max(i, temp->height);
                        if (temp->parent == nullptr)
                            break;
                        else
                            temp = temp->parent;
                    }
                    break;
                }
                else
                    temp = temp->rightchild;
            }
        }
    }
}

Node *BinaryTree::search_by_binary_search_tree(Node *temp, int value)
{
    while (temp != nullptr && temp->number != value)
    {
        if (temp->number > value)
        {
            temp = temp->leftchild;
        }
        else
        {
            temp = temp->rightchild;
        }
    }
    return temp;
}

Node *BinaryTree::minimum_value_in_binary_search_tree(Node *current)
{
    while (current->leftchild != nullptr)
    {
        current = current->leftchild;
    }
    return current;
}

Node *BinaryTree::maximum_value_in_binary_search_tree(Node *current)
{
    while (current->rightchild != nullptr)
    {
        current = current->rightchild;
    }
    return current;
}

void BinaryTree::sorting_using_binary_search_tree(Node *current, vector<int> &sorted)
{
    if (current == nullptr)
        return;

    sorting_using_binary_search_tree(current->leftchild, sorted);

    sorted.push_back(current->number);

    sorting_using_binary_search_tree(current->rightchild, sorted);
}

Node *BinaryTree::find_successor_from_binary_search_tree(Node *current)
{
    if (current == nullptr)
    {
        cout << "No Successor" << endl;
        return nullptr;
    }

    if (current->rightchild != nullptr)
    {
        return minimum_value_in_binary_search_tree(current->rightchild);
    }

    Node *current_parent = current->parent;
    while (current_parent != nullptr && current->number > current_parent->number)
    {
        current_parent = current_parent->parent;
    }

    if (current_parent == nullptr)
    {
        cout << "No Successor" << endl;
        return nullptr;
    }

    return current_parent;
}

Node *BinaryTree::find_predecessor_from_binary_search_tree(Node *current)
{
    if (current == nullptr)
    {
        cout << "No Predecessor" << endl;
        return nullptr;
    }

    if (current->leftchild != nullptr)
    {
        return maximum_value_in_binary_search_tree(current->leftchild);
    }

    Node *current_parent = current->parent;
    while (current_parent != nullptr && current->number < current_parent->number)
    {
        current_parent = current_parent->parent;
    }

    if (current_parent == nullptr)
    {
        cout << "No Predecessor" << endl;
        return nullptr;
    }

    return current_parent;
}

void BinaryTree::delete_from_binary_search_tree(int value)
{
    Node *target = search_by_binary_search_tree(root, value);
    if (target == nullptr)
    {
        cout << "Node doesn't exist" << endl;
        return;
    }

    Node *target_parent = target->parent;

    if (target->leftchild == nullptr && target->rightchild == nullptr)
    {
        if (target_parent == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (target_parent->leftchild == target)
        {
            target_parent->leftchild = nullptr;
            delete target;
        }
        else
        {
            target_parent->rightchild = nullptr;
            delete target;
        }
    }
    else if (target->leftchild == nullptr || target->rightchild == nullptr)
    {
        Node *child = (target->leftchild != nullptr) ? target->leftchild : target->rightchild;

        if (target_parent == nullptr)
        {
            delete root;
            root = child;
            child->parent = nullptr;
        }
        else if (target_parent->leftchild == target)
        {
            target_parent->leftchild = child;
            child->parent = target_parent;
            delete target;
        }
        else
        {
            target_parent->rightchild = child;
            child->parent = target_parent;
            delete target;
        }
    }
    else
    {
        Node *target_successor = find_successor_from_binary_search_tree(target);
        if (target->parent == nullptr)
        {
            target_successor->leftchild = target->leftchild;
            target->leftchild->parent = target_successor;
            target->rightchild->parent = nullptr;
            root = target->rightchild;
            delete target;
        }
        else if (target == target_parent->rightchild)
        {
            target_parent->rightchild = target->rightchild;
        }
        else
        {
            target_parent->leftchild = target->rightchild;
        }
        target->rightchild->parent = target_parent;
        target_successor->leftchild = target->leftchild;
        target->leftchild->parent = target_successor;
    }
}

int BinaryTree::find_maximum_value_in_path(int x, int y, Node *temp)
{
    int large;
    while (1)
    {
        if (x < temp->number && y < temp->number)
        {
            temp = temp->leftchild;
        }
        else if (x > temp->number && y > temp->number)
        {
            temp = temp->rightchild;
        }
        else if (x < temp->number && y == temp->number)
        {
            return y;
        }
        else
        {
            large = y;
            while (temp != nullptr && temp->number != y)
            {
                if (temp->number > y)
                {
                    large = max(large, temp->number);
                    temp = temp->leftchild;
                }
                else
                {
                    large = max(large, temp->number);
                    temp = temp->rightchild;
                }
            }
            return large;
        }
    }
}

Node * BinaryTree::find_heavychild(Node * temp)
{
    if(temp == nullptr || temp->parent == nullptr)
    return lastInsertedNode;

    else
    {
        Node* parent;
        parent = temp->parent;
        int BF_of_parent = balance_factor(parent);

        if(BF_of_parent<-1 || BF_of_parent>1)
        return temp;
        else
        find_heavychild(parent);
    }
    return root;
}

void BinaryTree::update_height_for_whole_tree(Node *current)
{
    if (current == nullptr)
        return;

    update_height_for_whole_tree(current->leftchild);

    if (current->leftchild && current->rightchild)
    {
        current->height = std::max(current->leftchild->height, current->rightchild->height) + 1;
    }
    else if (current->leftchild)
    {
        current->height = current->leftchild->height + 1;
    }
    else if (current->rightchild)
    {
        current->height = current->rightchild->height + 1;
    }
    else
    {
        current->height = -1;
    }

    update_height_for_whole_tree(current->rightchild);
}

int BinaryTree::balance_factor(Node *current)
{
    int left = -1;
    int right = -1;

    if (current->leftchild != nullptr)
    {
        left = current->leftchild->height;
    }

    if (current->rightchild != nullptr)
    {
        right = current->rightchild->height;
    }

    return left - right;
}

void BinaryTree::left_rotation_in_AVL_tree(Node *temp)
{
    Node *imbalanced_node = temp;
    Node *heavy_child = temp->rightchild;
    Node *heavy_left = heavy_child->leftchild;
    heavy_child->parent = imbalanced_node->parent;
    if (imbalanced_node == root)
        root = heavy_child;
    else
    {
        if (imbalanced_node == imbalanced_node->parent->leftchild)
        {
            imbalanced_node->parent->leftchild = heavy_child;
        }
        else
        {
            imbalanced_node->parent->rightchild = heavy_child;
        }
    }
    heavy_child->leftchild = imbalanced_node;
    imbalanced_node->parent = heavy_child;
    imbalanced_node->rightchild = heavy_left;
    if (heavy_left->parent != nullptr)
        heavy_left->parent = imbalanced_node;
    //update_height_for_whole_tree(root);
    find_height(root);
}

void BinaryTree::right_rotation_in_AVL_tree(Node *temp)
{
    Node *imbalanced_node = temp;
    Node *heavy_child = temp->leftchild;
    Node *heavy_right = heavy_child->rightchild;
    heavy_child->parent = imbalanced_node->parent;
    if (imbalanced_node == root)
        root = heavy_child;
    else
    {
        if (imbalanced_node == imbalanced_node->parent->leftchild)
        {
            imbalanced_node->parent->leftchild = heavy_child;
        }
        else
        {
            imbalanced_node->parent->rightchild = heavy_child;
        }
    }
    heavy_child->rightchild = imbalanced_node;
    imbalanced_node->parent = heavy_child;
    imbalanced_node->leftchild = heavy_right;
    if (heavy_right->parent != nullptr)
        heavy_right->parent = imbalanced_node;
    // update_height_for_whole_tree(root);
    find_height(root);
}

void BinaryTree::balance_node_in_AVL_tree(Node *temp, int balance_factor, int data)
{
    if (balance_factor > 1)
    {
        if (temp->number > data)
        {
            right_rotation_in_AVL_tree(temp);
        }
        else if (temp->number < data)
        {
            left_rotation_in_AVL_tree(temp->leftchild);
            right_rotation_in_AVL_tree(temp);
        }
    }
    else if (balance_factor < -1)
    {
        if (temp->number < data)
        {
            left_rotation_in_AVL_tree(temp);
        }
        else if (temp->number > 1)
        {
            right_rotation_in_AVL_tree(temp->rightchild);
            left_rotation_in_AVL_tree(temp);
        }
    }
}

void BinaryTree::insert_in_AVL_tree(Node *root, int data)
{
    insert_in_binary_search_tree(root, data);
    Node *newNode = lastInsertedNode;
    Node *temp = newNode;
    // update_height_for_whole_tree(root);
    find_height(root);
    while (temp != nullptr)
    {
        int bf = balance_factor(temp);
        cout << temp->number << ' ' << bf << ' ' << temp->height << endl;
        if (bf < -1 || bf > 1)
        {
            cout << "balancing:" << endl;
            balance_node_in_AVL_tree(temp, bf, data);
            break;
        }
        temp = temp->parent;
    }
}