#include "stdafx.h"
#include "BlackJack.h"
void blackjack::givecard() {
	for (int i = 0; i < 2; i++)
	{
		int shape_no = random() % shape;
		int card_no = random() % cardCNT;
		h_card[i] = cshape[shape_no] + clist[card_no];

		cout << h_card[i] << "||";
		nowCNT++;
	}
	cout << endl;
}

void  blackjack::start() {
	givecard();
	checkcard();
}

int  blackjack::checkcard() {
	score = 0;
	for (int i = 0; i < nowCNT; i++)
	{
		if (h_card[i].substr(2, 1) == "J" || h_card[i].substr(2, 1) == "Q" | h_card[i].substr(2, 1) == "K")
		{
			score = score + 10;
		}
		else if (h_card[i].substr(2, 1) == "A") {

			if (score < 11)
			{
				score = score + 11;
			}
			else
			{
				score = score + 1;
			}
		}
		else if (h_card[i].length() == 3)
		{
			score = score + stoi(h_card[i].substr(2, 1));
		}
		else if (h_card[i].length() == 4)
		{
			score = score + stoi(h_card[i].substr(2, 2));
		}
	}
	cout << score << endl;
	if (score > 21)
	{
		cout << "ÆÄ»ê." << endl;
		return false;
	}
	if (score == 21 && nowCNT == 2)
	{
		cout << "!ºí·¢Àè!." << endl;
		return false;

	}
	cout << endl;
}

int  blackjack::menu() {
	for (int i = nowCNT; i<5; i++)
	{
		if (score > 21)
		{
			return 1;
		}
		cout << "hit(1) or stand?(2)";
		int menu;
		cin >> menu;
		switch (menu)
		{
		case 1:hit(); break;
		case 2:i = 5; break;
		default:
			break;
		}
	}
}

void  blackjack::hit() {
	int shape_no = random() % shape;
	int card_no = random() % cardCNT;

	h_card[nowCNT] = cshape[shape_no] + clist[card_no];

	for (int i = 0; i < nowCNT + 1; i++)
	{
		cout << h_card[i] << "||";
	}
	nowCNT++;
	cout << endl;
	checkcard();

}
