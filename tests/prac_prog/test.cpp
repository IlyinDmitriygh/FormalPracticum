#include <gtest/gtest.h>
#include "prac_prog.h"
#include <fstream>
#include <string>
#include <sstream>

TEST(Tests, Base) {
  std::streambuf *cinbuf = std::cin.rdbuf();
  std::ifstream in("../tests/prac_prog/base_test.txt");
  std::cin.rdbuf(in.rdbuf());
  std::streambuf *coutbuf = std::cout.rdbuf();
  std::ostringstream oss;
  std::cout.rdbuf(oss.rdbuf());
  fromPolishEntryToAnswer();
  std::string result = oss.str();
  EXPECT_EQ(result, "4");
  in.close();
  in.open("../tests/prac_prog/base_test_epsilon.txt");
  std::cin.rdbuf(in.rdbuf());
  oss.str("");
  fromPolishEntryToAnswer();
  result = oss.str();
  EXPECT_EQ(result, "8");
  in.close();
  std::cout.rdbuf(coutbuf);
  std::cin.rdbuf(cinbuf);
}


TEST(Tests, Exceptions) {
  std::streambuf *cinbuf = std::cin.rdbuf();
  std::ifstream in("../tests/prac_prog/test_unknown_operation.txt");
  std::cin.rdbuf(in.rdbuf());
  std::streambuf *coutbuf = std::cout.rdbuf();
  std::ostringstream oss;
  std::cout.rdbuf(oss.rdbuf());
  bool err_flag = false;
  std::string err_message;
  try {
    fromPolishEntryToAnswer();
  }
  catch(const std::runtime_error& err) {
    err_flag = true;
    err_message = err.what();
  }
  EXPECT_TRUE(err_flag);
  EXPECT_EQ(err_message, "unknown operation");
  in.close();
  std::cout.rdbuf(coutbuf);
  std::cin.rdbuf(cinbuf);
}
