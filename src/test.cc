#include <gtest/gtest.h>

TEST(TestFind, FindExistingElement) {
    // Setup
    AvlTree<int> tree;
    tree.insert(5);
    
    // Exercise
    bool found = tree.find(5);
    
    // Verify
    EXPECT_TRUE(found);
}