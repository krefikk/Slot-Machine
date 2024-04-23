#include "Player.h"

Player::Player()
{
	coin = 1000;
	bet = 0;
	totalWin = 0;
	win = 0;

    if (font.loadFromFile("src/assets/fonts/AstroSpace-eZ2Bg.ttf")) {
        betText.setFont(font);
        betText.setCharacterSize(15);
        betText.setFillColor(sf::Color::White);
        betText.setOrigin(coinText.getLocalBounds().width / 2, coinText.getLocalBounds().height / 2);
        betText.setPosition(260, 545);
        betText.setString(std::to_string(bet));
        totalWinText.setFont(font);
        totalWinText.setCharacterSize(15);
        totalWinText.setFillColor(sf::Color::White);
        totalWinText.setOrigin(coinText.getLocalBounds().width / 2, coinText.getLocalBounds().height / 2);
        totalWinText.setPosition(725, 545);
        totalWinText.setString(std::to_string(totalWin));
        coinText.setFont(font);
        coinText.setCharacterSize(15);
        coinText.setFillColor(sf::Color::White);
        coinText.setOrigin(coinText.getLocalBounds().width / 2, coinText.getLocalBounds().height / 2);
        coinText.setPosition(520, 40);
        coinText.setString(std::to_string(coin)); 
    }
    else {
        std::cout << "Error at loading font." << std::endl;
    }

}

Player::~Player()
{
}

void Player::updateCoinText()
{
    coinText.setString(std::to_string(getCoin()));
}

void Player::setCoin(int coin)
{
	this->coin = coin;
    updateCoinText();
}

int Player::getCoin()
{
	return coin;
}

void Player::updateBetText()
{
    betText.setString(std::to_string(getBet()));
}

void Player::setBet(int bet)
{
	this->bet = bet;
    updateBetText();
}

int Player::getBet()
{
	return bet;
}

void Player::updateTotalWinText()
{
    totalWinText.setString(std::to_string(getTotalWin()));
}

void Player::setTotalWin(int totalWin)
{
	this->totalWin = totalWin;
    updateTotalWinText();
}

int Player::getTotalWin()
{
	return totalWin;
}

void Player::setWin(int win)
{
	this->win = win;
}

int Player::getWin()
{
	return win;
}

void Player::resetBet()
{
	bet = 2;
}

void Player::resetWin()
{
	win = 0;
}

sf::Text& Player::getBetText()
{
    return betText;
}

sf::Text& Player::getTotalWinText()
{
    return totalWinText;
}

sf::Text& Player::getCoinText()
{
    return coinText;
}