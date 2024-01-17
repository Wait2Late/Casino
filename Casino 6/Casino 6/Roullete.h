#pragma once
#include "Utilities.h"


namespace Games {
	class Roullete {
        //Street Triple
        int line01[3]{ 1,  2,  3 };
        int line02[3]{ 4,  5,  6 };
        int line03[3]{ 7,  8,  9 };
        int line04[3]{ 10, 11, 12 };
        int line05[3]{ 13, 14, 15 };
        int line06[3]{ 16, 17, 18 };
        int line07[3]{ 19, 20, 21 };
        int line08[3]{ 22, 23, 24 };
        int line09[3]{ 25, 26, 27 };
        int line10[3]{ 28, 29, 30 };
        int line11[3]{ 31, 32, 33 };
        int line12[3]{ 34, 35, 36 };

        //Corner Four
        int comb01[4]{ 3,  6,  2,  5 };
        int comb02[4]{ 6,  9,  5,  8 };
        int comb03[4]{ 9, 12,  8, 11 };
        int comb04[4]{ 12, 15, 11, 14 };
        int comb05[4]{ 15, 18, 14, 17 };
        int comb06[4]{ 18, 21, 17, 20 };
        int comb07[4]{ 21, 24, 20, 23 };
        int comb08[4]{ 24, 27, 23, 26 };
        int comb09[4]{ 27, 30, 26, 29 };
        int comb10[4]{ 30, 33, 29, 32 };
        int comb11[4]{ 33, 36, 32, 35 };
        int comb12[4]{ 2,  5,  1,  4 };
        int comb13[4]{ 5,  8,  4,  7 };
        int comb14[4]{ 8, 11,  7, 10 };
        int comb15[4]{ 11, 14, 10, 13 };
        int comb16[4]{ 14, 17, 13, 16 };
        int comb17[4]{ 17, 20, 16, 19 };
        int comb18[4]{ 20, 23, 19, 22 };
        int comb19[4]{ 23, 26, 22, 25 };
        int comb20[4]{ 26, 29, 25, 28 };
        int comb21[4]{ 29, 32, 28, 31 };
        int comb22[4]{ 32, 35, 31, 34 };

        //Line
        int sixNum01[6]{ 1,  2,  3,  4,  5,  6 };
        int sixNum02[6]{ 4,  5,  6,  7,  8,  9 };
        int sixNum03[6]{ 7,  8,  9, 10, 11, 12 };
        int sixNum04[6]{ 10, 11, 12, 13, 14, 15 };
        int sixNum05[6]{ 13, 14, 15, 16, 17, 18 };
        int sixNum06[6]{ 16, 17, 18, 19, 20, 21 };
        int sixNum07[6]{ 19, 20, 21, 22, 23, 24 };
        int sixNum08[6]{ 22, 23, 24, 25, 26, 27 };
        int sixNum09[6]{ 25, 26, 27, 28, 29, 30 };
        int sixNum10[6]{ 28, 29, 30, 31, 32, 33 };
        int sixNum11[6]{ 31, 32, 33, 34, 35, 36 };

        //Column
        int Column03[12]{ 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36 };
        int Column02[12]{ 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35 };
        int Column01[12]{ 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34 };

        //Dozen
        int Dozen01[12]{ 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12 };
        int Dozen02[12]{ 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
        int Dozen03[12]{ 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 };

        //Low
        int Low[18]{ 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
        //High
        int High[18]{ 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 };
        //Even
        int Even[18]{ 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36 };
        //Odd
        int Odd[18]{ 1, 3, 5, 7,  9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35 };
        //Red & Black
        int Red[18]{ 1, 3, 5, 7,  9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };
        int Black[18]{ 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35 };

        int userIn, userIn2;
        int insideBet = 1, outsideBet = 2;
        int Money = 0, bet;
        int loserZero = 0;

        bool valid = false;
        bool sann = true;

	public:
		void RouletteGame(int& cMoney, std::array<Utilities::eGameResult, 5>& myLastResults, const Casino& aCasino);
	};
}