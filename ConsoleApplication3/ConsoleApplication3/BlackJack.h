#pragma once

#include "stdafx.h"
#include <iostream>
#include <random>
#include <string>
using namespace std;

class blackjack
{
public:
	const int cardCNT = 13;
	const int shape = 4;
	int nowCNT = 0;
	int score = 0;
	string h_card[10];
	string cshape[4] = { "¢¼","¢À","¢¾","¡ß" };
	string clist[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	random_device random;

	void givecard();
	void start();
	int checkcard();
	int menu();
	void hit();
};