#include <algorithm>
#include <iostream>
using namespace std;
class Node
{
public:
    Node(const int &key)
        : key_(key), height_(0), left_child_(nullptr),
          right_child_(nullptr) {}

    int get_key() const { return key_; }
    int get_height() const
    {
        return height_;
    } // may not use in AvlTree. Instead, use get_node_height declared in AvlTree
    void set_height(const int &height) { height_ = height; }
    Node *get_left_child() const { return left_child_; }
    void set_left_child(Node *left_child) { left_child_ = left_child; }
    Node *get_right_child() const { return right_child_; }
    void set_right_child(Node *right_child) { right_child_ = right_child; }
    void set_key(const int &key) { key_ = key; }

private:
    int key_;
    int height_;
    Node *left_child_;
    Node *right_child_;
};

class AvlTree
{
public:
    AvlTree() : root_(nullptr), size_(0) {}
    int get_size() const { return size_; }
    void minimum(
        const int &x); // print key and depth values of the node which has minimum
    // key in the subtree of given node via standard output
    void maximum(
        const int &x); // print key and depth values of the node which has maximum
    // key in the subtree of given node via standard output
    bool empty();

    int find(const int &x); // return depth of node with given key. If not exist,
    // return 0
    void insert(const int &x);
    void print_rank(const int &key);
    void erase(int key);

private:
    Node *root_;
    int size_;

    int get_node_height(Node *node_ptr) const;

    int get_balance_factor(
        Node *node_ptr) const; // caculate balance factor of given node
    Node *recursive_insert(
        Node *node_ptr,
        const int &key); // recursively move to a proper child position & make new
    // node & update height & rebalance tree
    void
    rebalance_subtree(Node *&node_ptr); // rebalance subtree in LL,LR,RL,RR cases
    Node *rotate_left(Node *center_node);
    Node *rotate_right(Node *center_node);
    Node *erase_node(Node *root, int key, int &depth);
    Node *find_min_node(Node *node) const;
};

bool AvlTree::empty()
{
    return this->size_ == 0;
} // return true if size_ is equal to 0

int AvlTree::find(const int &x)
{
    Node *node_ptr = root_;
    int depth = 0;
    while (node_ptr != nullptr)
    {
        // Check if the key of the current node matches the target value
        if (node_ptr->get_key() == x)
        {
            return depth;
        }
        // If the target value is greater than the key of the current node, move to the right child
        else if (node_ptr->get_key() < x)
        {
            node_ptr = node_ptr->get_right_child();
        }
        // If the target value is smaller than the key of the current node, move to the left child
        else
        {
            node_ptr = node_ptr->get_left_child();
        }
        depth++;
    }
    return 0;
}

int AvlTree::get_node_height(Node *node_ptr) const
{
    if (node_ptr == nullptr)
        return -1;
    else
        return node_ptr->get_height();
} // Consider nullptr case

int AvlTree::get_balance_factor(Node *node_ptr) const
{
    return get_node_height(node_ptr->get_left_child()) -
           get_node_height(node_ptr->get_right_child());
} // caculate balance factor of given node

void AvlTree::insert(const int &x)
{
    root_ = recursive_insert(root_, x);
    size_++;
}

Node *AvlTree::recursive_insert(Node *node_ptr, const int &key)
{
    if (node_ptr == nullptr)
    {
        node_ptr = new Node(key);
        return node_ptr;
    }
    else if (node_ptr->get_key() < key)
    {
        node_ptr->set_right_child(
            recursive_insert(node_ptr->get_right_child(), key));
    }
    else
    {
        node_ptr->set_left_child(recursive_insert(node_ptr->get_left_child(), key));
    }
    node_ptr->set_height(std::max(get_node_height(node_ptr->get_left_child()),
                                  get_node_height(node_ptr->get_right_child())) +
                         1);

    rebalance_subtree(node_ptr);
    return node_ptr;
} // recursively move to a proper child position & make new node & update height & rebalance tree

void AvlTree::maximum(const int &x)
{
    Node *node_ptr = root_;
    while (node_ptr != nullptr && node_ptr->get_key() != x)
    { // Loop until the node pointer is not null
        if (node_ptr->get_key() < x)
        {                                           // Check if the key of the current node is less than the input value
            node_ptr = node_ptr->get_right_child(); // Move to the right child of the current node
        }
        else
        {
            node_ptr = node_ptr->get_left_child(); // Move to the left child of the current node
        }
    }

    if (node_ptr == nullptr)
    {
        return;
    }

    // Find the right node in the subtree which has the maximum key
    while (node_ptr->get_right_child() != nullptr)
    {
        node_ptr = node_ptr->get_right_child();
    }

    cout << node_ptr->get_key() << " " << find(node_ptr->get_key()) << "\n";
}

void AvlTree::minimum(const int &x)
{ // Define the minimum function that takes an integer reference as input
    Node *node_ptr = root_;
    while (node_ptr != nullptr && node_ptr->get_key() != x)
    { // Loop until the node pointer is not null
        if (node_ptr->get_key() > x)
        {                                          // Check if the key of the current node is less than the input value
            node_ptr = node_ptr->get_left_child(); // Move to the right child of the current node
        }
        else
        {
            node_ptr = node_ptr->get_right_child(); // Move to the left child of the current node
        }
    }

    if (node_ptr == nullptr)
    {
        return;
    }

    // Find the left node in the subtree which has the minimum key
    while (node_ptr->get_left_child() != nullptr)
    {
        node_ptr = node_ptr->get_left_child();
    }

    cout << node_ptr->get_key() << " " << find(node_ptr->get_key()) << "\n";
}

void AvlTree::rebalance_subtree(Node *&node_ptr)
{
    int balance_factor = get_balance_factor(node_ptr);

    // LL case
    if (balance_factor > 1 && get_node_height(node_ptr->get_left_child()->get_left_child()) >= get_node_height(node_ptr->get_left_child()->get_right_child()))
    {
        node_ptr = rotate_right(node_ptr);
    }

    // LR case
    else if (balance_factor > 1 && get_node_height(node_ptr->get_left_child()->get_left_child()) < get_node_height(node_ptr->get_left_child()->get_right_child()))
    {
        node_ptr->set_left_child(rotate_left(node_ptr->get_left_child()));
        node_ptr = rotate_right(node_ptr);
    }

    // RL case
    else if (balance_factor < -1 &&
             get_node_height(node_ptr->get_right_child()->get_right_child()) < get_node_height(node_ptr->get_right_child()->get_left_child()))
    {
        node_ptr->set_right_child(rotate_right(node_ptr->get_right_child()));
        node_ptr = rotate_left(node_ptr);
    }

    // RR case
    else if (balance_factor < -1 && get_node_height(node_ptr->get_right_child()->get_right_child()) >= get_node_height(node_ptr->get_right_child()->get_left_child()))
    {
        node_ptr = rotate_left(node_ptr);
    }
} // rebalance subtree in LL,LR,RL,RR cases

Node *AvlTree::rotate_left(Node *center_node)
{
    Node *rotating_node = center_node->get_right_child();
    center_node->set_right_child(rotating_node->get_left_child());
    rotating_node->set_left_child(center_node);

    center_node->set_height(
        std::max(get_node_height(center_node->get_left_child()),
                 get_node_height(center_node->get_right_child())) +
        1);
    rotating_node->set_height(
        std::max(get_node_height(rotating_node->get_left_child()),
                 get_node_height(rotating_node->get_right_child())) +
        1);

    return rotating_node;
}

Node *AvlTree::rotate_right(Node *center_node)
{
    Node *rotating_node = center_node->get_left_child();
    center_node->set_left_child(rotating_node->get_right_child());
    rotating_node->set_right_child(center_node);

    center_node->set_height(
        std::max(get_node_height(center_node->get_left_child()),
                 get_node_height(center_node->get_right_child())) +
        1);
    rotating_node->set_height(
        std::max(get_node_height(rotating_node->get_left_child()),
                 get_node_height(rotating_node->get_right_child())) +
        1);

    return rotating_node;
}

void AvlTree::print_rank(const int &key)
{
    // Initialize depth and rank
    int depth = 0;
    int rank = 0;

    // Start from the root
    Node *current = root_;

    while (current != nullptr)
    {
        // If the key is smaller than the current node's key,
        // move to the left subtree
        if (key < current->get_key())
        {
            current = current->get_left_child();
        }
        else if (key > current->get_key())
        {
            // If the key is greater than the current node's key,
            // add the rank of the left subtree plus one, move to the right subtree, and increment depth
            rank += 1 + (current->get_left_child() != nullptr ? current->get_left_child()->get_height() : 0);
            current = current->get_right_child();
            depth++;
        }
        else
        {
            // If the key is equal to the current node's key,
            // add the rank of the left subtree and break
            rank += (current->get_right_child() != nullptr ? current->get_left_child()->get_height() : 0);
            break;
        }
    }

    std::cout << depth << " " << rank + 1 << "\n"; // Add 1 to adhere to the definition of rank (1-based index)
}
Node *AvlTree::find_min_node(Node *node) const
{
    while (node && node->get_left_child())
    {
        node = node->get_left_child();
    }
    return node;
}
void AvlTree::erase(int key)
{
    int depth = find(key); // Use find function to get the depth
    if (depth > 0)
    {
        root_ = erase_node(root_, key, depth);
    }
    std::cout << depth << std::endl; // Output the depth
}

Node *AvlTree::erase_node(Node *root, int key, int &depth)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->get_key())
    {
        root->set_left_child(erase_node(root->get_left_child(), key, depth));
    }
    else if (key > root->get_key())
    {
        root->set_right_child(erase_node(root->get_right_child(), key, depth));
    }
    else
    {
        // Node found, update depth
        depth = find(root->get_key());

        // Node with only one child or no child
        if (root->get_left_child() == nullptr)
        {
            Node *temp = root->get_right_child();
            delete root;
            return temp;
        }
        else if (root->get_right_child() == nullptr)
        {
            Node *temp = root->get_left_child();
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node *temp = find_min_node(root->get_right_child());

        // Copy the inorder successor's data to this node
        root->set_key(temp->get_key());

        // Delete the inorder successor
        root->set_right_child(erase_node(root->get_right_child(), temp->get_key(), depth));
    }

    // Update height and balance factor
    root->set_height(std::max(get_node_height(root->get_left_child()), get_node_height(root->get_right_child())) + 1);
    int balance = get_balance_factor(root);

    // Left Left Case
    if (balance > 1 && get_balance_factor(root->get_left_child()) >= 0)
    {
        return rotate_right(root);
    }

    // Left Right Case
    if (balance > 1 && get_balance_factor(root->get_left_child()) < 0)
    {
        root->set_left_child(rotate_left(root->get_left_child()));
        return rotate_right(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance_factor(root->get_right_child()) <= 0)
    {
        return rotate_left(root);
    }

    // Right Left Case
    if (balance < -1 && get_balance_factor(root->get_right_child()) > 0)
    {
        root->set_right_child(rotate_right(root->get_right_child()));
        return rotate_left(root);
    }

    return root;
}

int main()
{
    // for speeding up input, output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    { // repeat for test case T times
        AvlTree tree;
        int Q;
        cin >> Q;
        for (int j = 0; j < Q; j++)
        { // repeat for command Q times
            string cmd;
            cin >> cmd;

            if (cmd == "minimum")
            {
                int node;
                cin >> node;
                tree.minimum(node);
            }
            else if (cmd == "maximum")
            {
                int node;
                cin >> node;
                tree.maximum(node);
            }
            else if (cmd == "empty")
            {
                if (tree.empty())
                {
                    cout << "1\n";
                }
                else
                {
                    cout << "0\n";
                }
            }
            else if (cmd == "size")
            {
                cout << tree.get_size() << "\n";
            }
            else if (cmd == "find")
            {
                int node;
                cin >> node;

                cout << tree.find(node) << "\n";
            }
            else if (cmd == "insert")
            {
                int value;
                cin >> value;
                tree.insert(value);
                cout << tree.find(value) << "\n";
            }
            else if (cmd == "rank")
            {
                int node;
                cin >> node;

                tree.print_rank(node);
            }
            else if (cmd == "erase")
            {
                int node;
                cin >> node;

                tree.erase(node);
            }
        }
    }

    return 0;
}
