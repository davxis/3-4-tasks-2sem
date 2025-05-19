#include "pch.h"
#include "CppUnitTest.h"

#include "Rectangle.h"
#include "Point.h"
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlaneFigureLibTests
{
	TEST_CLASS(RectangleTests)
	{
	public:
		
		// Максимальное разрешение экрана для тестов
        const Point maxResolution = Point(1000, 1000);
        
        TEST_METHOD(Constructor_Default_CreatesValidRectangle)
        {
            Rectangle rect(maxResolution);
            
            Assert::AreEqual(std::string("Rectangle(a = (0; 2), b = (0; 5), c = (2; 5), d = (2; 2))"), 
                            rect.ToString());
        }
        
        TEST_METHOD(Constructor_WithPoints_CreatesValidRectangle)
        {
            Rectangle rect(maxResolution, Point(1, 1), Point(1, 3), Point(3, 3));
            
            Assert::AreEqual(std::string("Rectangle(a = (1; 1), b = (1; 3), c = (3; 3), d = (3; 1))"), 
                            rect.ToString());
        }
        
        TEST_METHOD(Constructor_WithCoordinates_CreatesValidRectangle)
        {
            Rectangle rect(maxResolution, 1.0, 1.0, 1.0, 3.0, 3.0, 3.0);
            
            Assert::AreEqual(std::string("Rectangle(a = (1; 1), b = (1; 3), c = (3; 3), d = (3; 1))"), 
                            rect.ToString());
        }
        
        TEST_METHOD(ValidateForEqualPoints_ThrowsWhenPointsEqual)
        {
            auto func = [this]() {
                Rectangle rect(maxResolution, Point(1, 1), Point(1, 1), Point(2, 2));
            };
            
            Assert::ExpectException<const char*>(func);
        }
        
        TEST_METHOD(ValidateForMaxScreenResolution_ThrowsWhenPointExceedsLimit)
        {
            auto func = [this]() {
                Rectangle rect(maxResolution, Point(1001, 0), Point(0, 0), Point(0, 1));
            };
            
            Assert::ExpectException<const char*>(func);
        }
        
        TEST_METHOD(SetABCChooseBAsRightAngle_SelectsCorrectRightAngle)
        {
            // Функция для проверки строки на соответствие одному из вариантов
            auto assertOneOf = [](const std::string& actual, const std::initializer_list<std::string>& expectedOptions) {
                for (const auto& expected : expectedOptions) {
                    if (actual == expected) {
                        return; // Нашли совпадение - тест пройден
                    }
                }
                // Если не нашли совпадение
                std::string message = "Actual value: " + actual + "\nExpected one of:";
                for (const auto& expected : expectedOptions) {
                    message += "\n  " + expected;
                }
                Assert::Fail(std::wstring(message.begin(), message.end()).c_str());
            };

            // Тест 1: Прямой угол в точке B
            {
                Rectangle rect(maxResolution, Point(0, 0), Point(0, 2), Point(2, 2));
                assertOneOf(rect.ToString(), {
                    "Rectangle(a = (0; 0), b = (0; 2), c = (2; 2), d = (2; 0))",
                    "Rectangle(a = (2; 2), b = (0; 2), c = (0; 0), d = (2; 0))"
                    });
            }

            // Прямой угол в точке A (должен переставить точки)
            {
                Rectangle rect2(maxResolution, Point(0, 2), Point(0, 0), Point(2, 2));
                assertOneOf(rect2.ToString(), {
                    "Rectangle(a = (0; 0), b = (0; 2), c = (2; 2), d = (2; 0))",
                    "Rectangle(a = (2; 2), b = (0; 2), c = (0; 0), d = (2; 0))"
                    });
            }

            // Прямой угол в точке C (должен переставить точки)
            {
                Rectangle rect3(maxResolution, Point(0, 0), Point(2, 2), Point(0, 2));
                assertOneOf(rect3.ToString(), {
                    "Rectangle(a = (0; 0), b = (0; 2), c = (2; 2), d = (2; 0))",
                    "Rectangle(a = (2; 2), b = (0; 2), c = (0; 0), d = (2; 0))"
                    });
            }
        }
        
        TEST_METHOD(SetD_CalculatesCorrectFourthPoint)
        {
            Rectangle rect(maxResolution, Point(1, 1), Point(1, 3), Point(3, 3));
            Assert::AreEqual(std::string("Rectangle(a = (1; 1), b = (1; 3), c = (3; 3), d = (3; 1))"), 
                            rect.ToString());
        }
        
        TEST_METHOD(Validate_ThrowsWhenNotRightAngle)
        {
            auto func = [this]() {
                Rectangle rect(maxResolution, Point(1, 1), Point(2, 2), Point(3, 3));
            };
            
            Assert::ExpectException<const char*>(func);
        }
        
        TEST_METHOD(OperatorInput_ReadsValidRectangle)
        {
            std::istringstream input("1 1 1 3 3 3");
            Rectangle rect(maxResolution);
            input >> rect;
            
            Assert::AreEqual(std::string("Rectangle(a = (1; 1), b = (1; 3), c = (3; 3), d = (3; 1))"), 
                            rect.ToString());
        }
	};
}
