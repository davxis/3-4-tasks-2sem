#include "pch.h"
#include "CppUnitTest.h"

#include "Rectangle.h"
#include "Point.h"
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlaneFigureLibTests {
    TEST_CLASS(PointTests) {
public:

        TEST_METHOD(Constructor_Default_CreatesOriginPoint) {
            Point p;
            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
        }

        TEST_METHOD(Constructor_WithCoordinates_SetsCorrectValues) {
            Point p(3.5, -2.1);
            Assert::AreEqual(3.5, p.getX());
            Assert::AreEqual(-2.1, p.getY());
        }

        TEST_METHOD(OperatorEquals_ComparesPointsCorrectly) {
            Point p1(1.0, 2.0);
            Point p2(1.0, 2.0);
            Point p3(1.1, 2.0);
            Point p4(1.0, 2.1);

            Assert::IsTrue(p1 == p2);
            Assert::IsFalse(p1 == p3);
            Assert::IsFalse(p1 == p4);
        }

        TEST_METHOD(OperatorNotEquals_ComparesPointsCorrectly) {
            Point p1(1.0, 2.0);
            Point p2(1.0, 2.0);
            Point p3(1.1, 2.0);

            Assert::IsFalse(p1 != p2);
            Assert::IsTrue(p1 != p3);
        }

        TEST_METHOD(ExceedsLimits_ChecksBoundsCorrectly) {
            Point limit(10.0, 10.0);

            Point p1(9.0, 9.0);
            Point p2(10.0, 9.0);
            Point p3(9.0, 10.0);
            Point p4(11.0, 9.0);
            Point p5(9.0, 11.0);

            Assert::IsFalse(p1.exceedsLimits(limit));
            Assert::IsTrue(p2.exceedsLimits(limit));
            Assert::IsTrue(p3.exceedsLimits(limit));
            Assert::IsTrue(p4.exceedsLimits(limit));
            Assert::IsTrue(p5.exceedsLimits(limit));
        }

        TEST_METHOD(OperatorAddition_AddsPointsCorrectly) {
            Point p1(1.5, 2.5);
            Point p2(0.5, -1.5);

            Point result(p1.getX() + p2.getX(), p1.getY() + p2.getY());

            Assert::AreEqual(2.0, result.getX());
            Assert::AreEqual(1.0, result.getY());
        }

        TEST_METHOD(ToString_ReturnsCorrectFormat) {
            Point p1(3.14, -2.71);
            Point p2(0.0, 0.0);
            Point p3(1.0, 2.0);

            Assert::AreEqual(std::string("(3.14; -2.71)"), p1.ToString());
            Assert::AreEqual(std::string("(0; 0)"), p2.ToString());
            Assert::AreEqual(std::string("(1; 2)"), p3.ToString());
        }

        TEST_METHOD(OperatorInput_ReadsCoordinatesCorrectly) {
            std::istringstream input("3.5 -2.1");
            Point p;
            input >> p;

            Assert::AreEqual(3.5, p.getX());
            Assert::AreEqual(-2.1, p.getY());
        }

        TEST_METHOD(OperatorOutput_WritesCoordinatesCorrectly) {
            std::ostringstream output;
            Point p(1.5, -2.5);
            output << p;

            Assert::AreEqual(std::string("(1.5; -2.5)"), output.str());
        }

        TEST_METHOD(GetXGetY_ReturnCorrectValues) {
            Point p(3.14, 2.71);

            Assert::AreEqual(3.14, p.getX());
            Assert::AreEqual(2.71, p.getY());
        }
    };
}
