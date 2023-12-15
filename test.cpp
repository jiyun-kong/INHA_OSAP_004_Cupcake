/*
 * Copyright 2023 CUPCAKE Team, Inha Univ
 * released under GPL 3.0 License
 * Contributor of this file : SungraeKim (23/11/11), JiyunKong (23/11/13), JiyunKong (23/11/19)
 */
#include "avl_tree.hpp"
#include <gtest/gtest.h>
#include <iostream>

class AvlTreeTest : public ::testing::Test
{
protected:
  AvlTree test_tree;       // AVL tree instance to use for testing
  void SetUp() override {} // Initialize the tree for each test
};

// Test size after element insertion
TEST_F(AvlTreeTest, InsertIncreaseSize)
{
  EXPECT_EQ(test_tree.get_size(), 0); // Test the size before insertion
  test_tree.insert(10);
  EXPECT_EQ(test_tree.get_size(), 1); // Test the size after insertion
  test_tree.insert(20);
  EXPECT_EQ(test_tree.get_size(), 2); // Test the size after another insert
}

// Test if the tree is empty
TEST(TestEmpty, EmptyWhenInitialized)
{
  AvlTree test_tree;
  EXPECT_TRUE(test_tree.empty()); // Tree must be empty immediately after initialization
}

// Test if the tree is empty after insertion
TEST(TestInsertEmpty, NotEmptyAfterInsertion)
{
  AvlTree test_tree;
  test_tree.insert(10);
  EXPECT_FALSE(test_tree.empty()); // Tree must not be empty after the element has been inserted
}

// Test the size of the empty tree
TEST(TestSize, EmptyAvlTreeTest)
{
  AvlTree test_tree;
  int size = test_tree.get_size();
  EXPECT_EQ(size, 0);
}

// Test the tree structure
TEST_F(AvlTreeTest, InsertMaintainStructure)
{
  AvlTree test_tree;
  test_tree.insert(10);
  test_tree.insert(20);
  test_tree.insert(5);
  test_tree.insert(15);
  EXPECT_EQ(test_tree.find(10), 0); // Test a specific key in the Avl Tree
}

TEST_F(AvlTreeTest,EraseTest)
{
  test_tree.insert(1);
  test_tree.insert(100000);
  test_tree.insert(2);
  test_tree.insert(9);
  test_tree.insert(3);
  test_tree.insert(8);
  test_tree.insert(4);
  test_tree.insert(7);
  test_tree.insert(5);
  test_tree.insert(6);

  test_tree.erase(100000);

  EXPECT_EQ(test_tree.get_size(),9);

  test_tree.erase(1);
  EXPECT_EQ(test_tree.get_size(),8);

  test_tree.erase(5);
  EXPECT_EQ(test_tree.get_size(),7);
}

TEST_F(AvlTreeTest,PrintRankTest)
{
  test_tree.insert(1);
  test_tree.insert(100000);
  test_tree.insert(5);
  test_tree.insert(10);

  testing::internal::CaptureStdout();
  test_tree.print_rank(1);
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1,"1 1\n");

  testing::internal::CaptureStdout();
  test_tree.print_rank(100000);
  std::string output2 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output2,"1 4\n");

  testing::internal::CaptureStdout();
  test_tree.print_rank(10);
  std::string output3 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output3,"2 3\n");

  testing::internal::CaptureStdout();
  test_tree.print_rank(5);
  std::string output4 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output4,"0 2\n");

  testing::internal::CaptureStdout();
  test_tree.print_rank(4);
  std::string output5 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output5,"0\n");
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
