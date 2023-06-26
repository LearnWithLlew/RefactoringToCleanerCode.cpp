#define APPROVAL_TESTS_HIDE_DEPRECATED_CODE 1

#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"
#include "YourCodeGoesHere.h"
#include <ostream>

using namespace ApprovalTests;


struct Demo
{
    int value1;
    int value2;

    // See https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/ToString.md#top
    friend std::ostream& operator<<(std::ostream& os, const Demo& obj)
    {
        return os << "value1: " << obj.value1 << ", value2: " << obj.value2;
    }
};

TEST_CASE("DemoCombinationTestCase")
{
    // See https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/TestingCombinations.md#top
    std::vector<int> dice{1, 2, 3, 4, 5,6};
    std::vector<ScoringType> types{Pair,TwoPair, FullHouse, FiveOfAKind};
    CombinationApprovals::verifyAllCombinations(
        [](ScoringType s, int d1, int d2, int d3, int d4, int d5) {
            return BigDiceGame::CalculateScore(s,d1,d2,d3,d4,d5);
        },
        types,
        dice,
        dice,
        dice,
        dice,
        dice);
}
