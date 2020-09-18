#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x;
    int y;
    int idx;
    struct Node* left;
    struct Node* right;
};

void preorder(Node* node, vector<int>& order) {
    if (node == nullptr) return;
    order.push_back(node->idx);
    preorder(node->left, order);
    preorder(node->right, order);
}

void postorder(Node* node, vector<int>& order) {
    if (node == nullptr) return;
    postorder(node->left, order);
    postorder(node->right, order);
    order.push_back(node->idx);
}

Node* constructTrees(Node** nodes, int n_nodes) {
    if (n_nodes == 0)
        return nullptr;
    
    Node* top;
    int y_max = -1;
    int top_idx = -1;
    for (int i = 0; i < n_nodes; i++)
    {
        if (nodes[i]->y > y_max) {
            y_max = nodes[i]->y;
            top_idx = i;
        }
    }
    top = nodes[top_idx];

    top->left = constructTrees(nodes, top_idx);
    if (top_idx == n_nodes - 1) {
        top->right = nullptr;
    }
    else {
        top->right = constructTrees(nodes + top_idx + 1, n_nodes - top_idx - 1);
    }

    return top;
}

bool compare(const Node* node1, const Node* node2) {

    return node1->x < node2->x;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);

    std::vector<Node*> nodes(nodeinfo.size());
    for (size_t i = 0; i < nodes.size(); i++)
    {
        nodes[i] = new Node;
        nodes[i]->x = nodeinfo[i][0];
        nodes[i]->y = nodeinfo[i][1];
        nodes[i]->idx = i + 1;
        nodes[i]->left = nullptr;
        nodes[i]->right = nullptr;
    }

    std::sort(nodes.begin(), nodes.end(), compare);

    Node* top = constructTrees(nodes.data(), nodes.size());

    preorder(top, answer[0]);
    postorder(top, answer[1]);

    for (size_t i = 0; i < nodes.size(); i++)
    {
        delete nodes[i];
    }

    return answer;
}

int main() {
    vector<vector<int>> nodes = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};

    vector<vector<int>> answer = solution(nodes);

    return 0;
}