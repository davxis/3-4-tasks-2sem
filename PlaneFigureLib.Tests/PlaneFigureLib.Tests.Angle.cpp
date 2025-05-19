#include "pch.h"
#include "CppUnitTest.h"

#include "Angle.h"
#include "Point.h"
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlaneFigureLibTests {
    TEST_CLASS(AngleTests) {
public:

        TEST_METHOD(IsRight_RightAngle_ReturnsTrue) {
            // Прямой угол в точке B (90 градусов)
            Angle angle1(Point(0, 0), Point(0, 1), Point(1, 1));
            Assert::IsTrue(angle1.isRight());

            // Другой прямой угол
            Angle angle2(Point(1, 1), Point(1, 0), Point(0, 0));
            Assert::IsTrue(angle2.isRight());

            // Еще один вариант прямого угла
            Angle angle3(Point(2, 3), Point(2, 1), Point(4, 1));
            Assert::IsTrue(angle3.isRight());
        }
    };
}
