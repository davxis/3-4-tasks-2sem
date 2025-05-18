#include "CppUnitTest.h"

#include <vector>
#include <string>

#include "Queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace PlaneFigureLibTests {
    TEST_CLASS(QueueTests) {
public:

        TEST_METHOD(TestEnqueueDequeue) {
            Queue q;
            q.enqueue(10);
            q.enqueue(20);
            q.enqueue(30);

            Assert::AreEqual(10, q.dequeue());
            Assert::AreEqual(20, q.dequeue());
            Assert::AreEqual(30, q.dequeue());

            Assert::IsTrue(q.isEmpty());
        }

        TEST_METHOD(TestPeek) {
            Queue q;
            q.enqueue(79);

            Assert::AreEqual(79, q.peek());
            Assert::IsFalse(q.isEmpty());
            Assert::AreEqual(79, q.dequeue());
        }

        TEST_METHOD(TestCopyConstructor) {
            Queue q;
            q.enqueue(10);
            q.enqueue(20);

            Queue q2 = q;
            Assert::AreEqual(10, q2.dequeue());
            Assert::AreEqual(20, q2.dequeue());
            Assert::IsTrue(q2.isEmpty());

            // Исходная очередь не должна измениться
            Assert::AreEqual(10, q.dequeue());
            Assert::AreEqual(20, q.dequeue());
        }

        TEST_METHOD(TestAssignmentOperator) {
            Queue q;
            q.enqueue(12);
            q.enqueue(43);

            Queue q2;
            q2.enqueue(300);

            q2 = q;

            Assert::AreEqual(12, q2.dequeue());
            Assert::AreEqual(43, q2.dequeue());

            // Исходная очередь не должна измениться
            Assert::AreEqual(12, q.dequeue());
            Assert::AreEqual(43, q.dequeue());
        }

        TEST_METHOD(TestToString) {
            Queue q;
            q.enqueue(3);
            q.enqueue(6);
            q.enqueue(12);

            Assert::AreEqual(string("3 6 12"), q.toString());
        }
    };
}
