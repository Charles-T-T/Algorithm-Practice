#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode(int id, uint64_t weight);
    ~TreeNode();

    int id;
    uint64_t weight;              // 当前节点自身的权重
    vector<TreeNode *> children;  // 子节点

    uint64_t GetSumWeights();  // 计算当前节点及其子节点的权重和

    // 添加子节点
    void AddChild(int id, uint64_t weight);
};

TreeNode::TreeNode(int id, uint64_t weight) : id(id), weight(weight) {}

TreeNode::~TreeNode() {}

uint64_t TreeNode::GetSumWeights() {
    uint64_t sum_weight = weight;
    for (const auto &node : children) {
        if (node != nullptr) {
            sum_weight += node->weight;
        }
    }
    return sum_weight;
}

void TreeNode::AddChild(int id, uint64_t weight) {
    children.emplace_back(new TreeNode(id, weight));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;  // 全部类别的数量
    int m;  // 需要测试的类别数量

    return 0;
}