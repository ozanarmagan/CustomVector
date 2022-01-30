#include <gtest/gtest.h>

#include "../vector.h"


class VectorTest : public ::testing::Test
{
    protected: 
        void SetUp() override {
            vec0_.add(1);
            vec1_.add(2);
            vec2_.add(3);
        }

        void TearDown() override 
        {
            std::cout << "Current size of vecs " << vec0_.getSize() << " " << vec1_.getSize() << " " << vec2_.getSize() << std::endl;  
        }

        CustomVector<int> vec0_;
        CustomVector<int> vec1_;
        CustomVector<int> vec2_;


};


TEST_F(VectorTest,isEmptyAtStart)
{
    EXPECT_EQ(vec0_.getSize(),1);
}


TEST_F(VectorTest,isRemoveWorks)
{
    auto before = vec0_.getSize();
    vec0_.removeIndex(0);
    ASSERT_NE(before,vec0_.getSize());
}   


int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

