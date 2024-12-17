#include "../include/prac_prog.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <map>


void fromPolishEntryToAnswer() {
  std::string regExpr;
  char symbol;
  int k;
  std::cin >> regExpr >> symbol >> k;
  std::set<char> operations{'*', '.', '+'};
  std::set<char> alphabet{'a', 'b', 'c', '1'};
  std::stack<std::pair<std::string, std::vector<size_t>>> stack;
  for (auto elem: regExpr) {
    if (!operations.contains(elem) && alphabet.contains(elem)) {
      std::vector<size_t> lengths(k + 1, SIZE_MAX);
      if (elem == symbol) {
        lengths[1] = 1;
      } else {
        if (elem == '1') {
          lengths[0] = 0;
        } else {
          lengths[0] = 1;
        }
      }
      std::string symbolAsString;
      symbolAsString.push_back(elem);
      stack.push(std::pair(symbolAsString, lengths));
    } else {
      std::vector<size_t> new_lengths(k + 1, SIZE_MAX);
      std::string s;
      if (elem != '*') {
        if (stack.size() < 2) {
          throw std::runtime_error("So less elems in stack");
        }
        auto secondElem = stack.top();
        stack.pop();
        auto firstElem = stack.top();
        stack.pop();


        if (elem == '.') {
          for (size_t i = 0; i < k + 1; ++i) {
            for (size_t j = 0; j < k + 1; ++j) {
              if (i + j <= k) {
                if (firstElem.second[i] == SIZE_MAX || secondElem.second[j] == SIZE_MAX) {
                  new_lengths[i + j] = std::min(new_lengths[i + j], SIZE_MAX);
                } else {
                  new_lengths[i + j] = std::min(new_lengths[i + j], firstElem.second[i] + secondElem.second[j]);
                }
              }
            }
          }
        } else if (elem == '+') {
          for (size_t i = 0; i < k + 1; ++i) {
            new_lengths[i] = std::min(firstElem.second[i], secondElem.second[i]);
          }
        } else {
          throw std::runtime_error("unknown operation");
        }
        s = firstElem.first + secondElem.first;
      } else {
        if (stack.size() < 1) {
          throw std::runtime_error("So less elems in stack");
        }
        auto firstElem = stack.top();
        stack.pop();
        for (size_t i = 1; i < k + 1; ++i) {
          for (size_t j = 1; j < k + 1; ++j) {
            if (i * j <= k) {
              new_lengths[i * j] = std::min(new_lengths[i * j], firstElem.second[i] * j);
            }
          }
        }
        s = firstElem.first + "*";
      }
      stack.push(std::pair(s, new_lengths));
    }
  }
  auto ans = stack.top();
  std::cout << ans.second[k];
}
