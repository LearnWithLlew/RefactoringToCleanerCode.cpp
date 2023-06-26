//
// Created by LLEWELLYN FALCO on 12/14/17.
//

#ifndef CATCHPLAYGROUND_YOURCODEGOESHERE_H
#define CATCHPLAYGROUND_YOURCODEGOESHERE_H


#include <vector>
#include <array>

enum ScoringType {
    Pair,
    TwoPair,
    FullHouse,
    FiveOfAKind
};

namespace BigDiceGame {
    const int bigScore = 50;

    int CalculateScore(ScoringType st, int die1, int die2, int d3, int dieFour, int fifthDie) {
        switch (st) {
        case Pair: {
            const int value = 2;
            std::array<int, 6> tallies1 = {0};
            tallies1[die1 - 1]++;
            tallies1[die2 - 1]++;
            tallies1[d3 - 1]++;
            tallies1[dieFour - 1]++;
            tallies1[fifthDie - 1]++;
            for (int i = 5; i >= 0; i--) {
                if (tallies1[i] >= value) {
                    return (i + 1) * value;
                }
            }
            return 0;
        }

        case TwoPair: {
            std::array<int, 6> counts1 = {0};
            counts1[die1 - 1]++;
            counts1[die2 - 1]++;
            counts1[d3 - 1]++;
            counts1[dieFour - 1]++;
            counts1[fifthDie - 1]++;
            int n = 0;
            int score = 0;
            for (int i = 0; i < 6; i++) {
                if (counts1[5 - i] >= 2) {
                    n++;
                    score += 5 - i;
                }
            }
            if (n == 2) {
                return score * 2;
            }
            return 0;
        }

        case FullHouse: {
            std::array<int, 6> tallies = {0};
            bool _2 = false;
            int _2_at = 0;
            bool _3 = false;
            int _3_at = 0;

            tallies[die1 - 1]++;
            tallies[die2 - 1]++;
            tallies[d3 - 1]++;
            tallies[dieFour - 1]++;
            tallies[fifthDie - 1]++;

            for (int i = 0; i < 6; i++) {
                if (tallies[i] == 2) {
                    _2 = true;
                    _2_at = i + 1;
                }
            }

            for (int i = 0; i < 6; i++) {
                if (tallies[i] == 3) {
                    _3 = true;
                    _3_at = i + 1;
                }
            }

            if (_2 && _3) {
                return _2_at * 2 + _3_at * 3;
            }
            return 0;
        }

        case FiveOfAKind: {
            std::vector<int> dice1 = {die1, die2, d3, dieFour, fifthDie};
            std::array<int, 6> counts2 = {0};
            for (const auto &die : dice1) {
                counts2[die - 1]++;
            }

            for (int i = 0; i < 6; i++) {
                if (counts2[i] == 5) {
                    return bigScore;
                }
            }
            return 0;
        }
        }
        return 0;
    }
}

#endif //CATCHPLAYGROUND_YOURCODEGOESHERE_H
