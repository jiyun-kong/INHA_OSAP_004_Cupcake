/*
 * Copyright 2023 CUPCAKE Team, Inha Univ
 * released under GPL 3.0 License
 * Contributor of this file : SungraeKim (23/11/11)
 */
#include "avl_tree.hpp"
#include <gtest/gtest.h>
#include <iostream>

class AvlTreeTest : public ::testing::Test
{
protected:
  AvlTree test_tree;            // AVL tree instance to use for testing
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

TEST(TestEmpty, EmptyWhenInitialized)
{
  AvlTree test_tree;
  EXPECT_TRUE(test_tree.empty()); // Tree must be empty immediately after initialization
}

TEST(TestInsertEmpty, NotEmptyAfterInsertion)
{
  AvlTree test_tree;
  test_tree.insert(10);
  EXPECT_FALSE(test_tree.empty()); // Tree must not be empty after the element has been inserted
}

// Test the size of the empty AvlTree
TEST(TestSize, EmptyAvlTreeTest)
{
  AvlTree test_tree;
  int size = test_tree.get_size();
  EXPECT_EQ(size, 0);
}

/*
// Test tree structure : Test later due to the non-implementation of find()
TEST_F(AvlTreeTest, InsertMaintainStructure) {
    test_tree.insert(10);
    test_tree.insert(20);
    test_tree.insert(5);
    test_tree.insert(15);
    EXPECT_EQ(test_tree.find(10)->get_key(), 10); // Test a specific key in the Avl Tree
}
*/

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
