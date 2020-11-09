#include "results_container.h"

#include <set>

ResultsContainer::ResultsContainer() {}

ResultsContainer::~ResultsContainer() {}

void ResultsContainer::add_result(std::string name, bool loop, bool unused) {
  std::unique_lock<std::mutex> lock(m);
  results[name].push_back(loop);
  results[name].push_back(unused);
}

void ResultsContainer::show_results() {
  std::set<std::string> keys;
  for (auto &res : results) keys.insert(res.first);

  for (std::string key : keys) {
    bool loop = results[key][0];
    bool unused = results[key][1];
    if (!loop && !unused)
      std::cout << key << " GOOD\n";
    else if (loop)
      std::cout << key << " FAIL: cycle detected\n";
    else
      std::cout << key << " FAIL: unused instructions detected\n";
  }
}
