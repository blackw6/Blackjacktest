// ConsoleApplication3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include "BlackJack.h"


using namespace std;



blackjack dealer;
blackjack player1;



class chips {
public:
	int player_chip = 1000;
	int dealer_chip = 1000000;
	int maxbet = 1000;
	int now_bet;

	void betting() {
		cout << "배팅금을 설정해주세요";
		cin >> now_bet;
		if (now_bet > maxbet)
		{
			cout << "최대 배팅금액은 1천칩입니다.";
		}

	}
	void win()
	{

		if (player1.score == 21)
		{
			cout << "블랙잭으로 이겼으므로 2.5배획득합니다";
			player_chip = (int)(player_chip + now_bet * 2.5);
		}
		else
		{
			cout << "배팅금을 획득합니다";
			player_chip = player_chip + now_bet;
		}

	}
};

chips player_c;
chips dealer_c;

int main()
{

	player_c.betting();
	player1.start();
	player1.menu();



	dealer.start();
	if (dealer.score < 17)
	{
		cout << "딜러의 패가 16이하이므로 한장 더 받습니다.";
		dealer.hit();
	}

	if (player1.score<22 && dealer.score<22 && player1.score > dealer.score)
	{
		cout << "플레이어의 승리!";
		player_c.win();
	}
	else if (player1.score<22 && dealer.score<22 && player1.score < dealer.score)
	{
		cout << "딜러의 승리!";
	}
	else
	{
		cout << "무승부입니다!";
	}
	return 0;
}