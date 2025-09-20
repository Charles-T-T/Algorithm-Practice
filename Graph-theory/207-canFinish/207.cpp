#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<vector<int>> prerequistes_;
  unordered_map<int, vector<int>> prerequisite_map_;

 public:
  void build_prerequire_map() {
    for (const auto& pair : prerequistes_) {
      prerequisite_map_[pair[0]].push_back(pair[1]);
    }
  }

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    prerequistes_ = prerequisites;
    build_prerequire_map();

    unordered_set<int> to_be_studied;
    unordered_set<int> have_studied;
    for (int i = 0; i < numCourses; ++i) {
      if (prerequisite_map_[i].empty()) {
        have_studied.insert(i);
      } else {
        to_be_studied.insert(i);
      }
    }
    if (have_studied.empty()) {
      return false;
    }

    size_t last_studied_cnt = have_studied.size();
    while (true) {
      for (auto it = to_be_studied.begin(); it != to_be_studied.end();) {
        // 检查目前 course[i] 能不能学
        bool can_study = true;
        for (int required : prerequisite_map_[*it]) {
          if (!have_studied.count(required)) {
            can_study = false;
            break;
          }
        }
        if (can_study) {
          have_studied.insert(*it);
          it = to_be_studied.erase(it);
        } else {
          ++it;
        }
      }
      // 检查这轮过后，能学的课程是否有增加
      if (have_studied.size() == last_studied_cnt) {
        break;
      }
      last_studied_cnt = have_studied.size();
    }

    return int(have_studied.size()) == numCourses;
  }
};

int main() {
  vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
  Solution obj;
  cout << obj.canFinish(2, prerequisites) << endl;

  return 0;
}