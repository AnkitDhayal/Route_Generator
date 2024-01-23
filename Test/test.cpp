#include "pch.h"

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}


#include "gtest/gtest.h"
#include "Point3D.h"

TEST(Point3DTest, DefaultConstructor) {
    Point3D point;
    EXPECT_DOUBLE_EQ(point.X(), 0.0);
    EXPECT_DOUBLE_EQ(point.Y(), 0.0);
    EXPECT_DOUBLE_EQ(point.Z(), 0.0);
}

TEST(Point3DTest, ParameterizedConstructor) {
    Point3D point(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(point.X(), 1.0);
    EXPECT_DOUBLE_EQ(point.Y(), 2.0);
    EXPECT_DOUBLE_EQ(point.Z(), 3.0);
}

TEST(Point3DTest, SettersAndGetters) {
    Point3D point;
    point.setX(3.0);
    point.setY(4.0);
    point.setZ(5.0);

    EXPECT_DOUBLE_EQ(point.X(), 3.0);
    EXPECT_DOUBLE_EQ(point.Y(), 4.0);
    EXPECT_DOUBLE_EQ(point.Z(), 5.0);
}

// Add more tests as needed for other functionality of the Point3D class.

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}