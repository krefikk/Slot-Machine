#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player
{
private:
	int coin;
	int bet;
	int totalWin;
	int win;
	sf::Font font;
	sf::Text betText;
	sf::Text totalWinText;
	sf::Text coinText;
public:
	Player();
	~Player();
	void setCoin(int coin);
	int getCoin();
	void setBet(int bet);
	int getBet();
	void setTotalWin(int totalWin);
	int getTotalWin();
	void setWin(int win);
	int getWin();
	void resetBet();
	void resetWin();
	sf::Text& getBetText();
	void updateBetText();
	sf::Text& getTotalWinText();
	void updateTotalWinText();
	sf::Text& getCoinText();
	void updateCoinText();
};

