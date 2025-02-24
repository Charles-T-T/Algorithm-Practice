#include <iostream>
#include <vector>

using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) : ptr_(1) {
        streams_.resize(n + 1);
    }

    vector<string> insert(int idKey, string value) {
        vector<string> result;
        streams_[idKey] = value;
        while (ptr_ < streams_.size() && !streams_[ptr_].empty()) {
            result.push_back(streams_[ptr_]);
            ++ptr_;
        }
        return result;
    }

private:
    int ptr_;
    vector<string> streams_;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main() {
    OrderedStream *obj = new OrderedStream(5);
    vector<string> param_1 = obj->insert(3, "ccccc");
    vector<string> param_2 = obj->insert(1, "aaaaa");
    vector<string> param_3 = obj->insert(2, "bbbbb");
    for (const auto &s : param_3) {
        std::cout << s << std::endl;
    }
    obj->insert(5, "eeeee");
    obj->insert(4, "ddddd");
    return 0;
}