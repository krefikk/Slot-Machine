#include "SlotMachine.h"

void SlotMachine::initSlotTextures()
{
	
	// Game Textures
	// #0
	sf::Texture purplepeachTexture;
	if (purplepeachTexture.loadFromFile("src/assets/images/purplepeach.png")) {
		slotTextures.push_back(purplepeachTexture);
	}
	else {
		std::cout << "Error at loading purple peach texture." << std::endl;
	}

	// #1
	sf::Texture cherryTexture;
	if (cherryTexture.loadFromFile("src/assets/images/cherry.png")) {
		slotTextures.push_back(cherryTexture);
	}
	else {
		std::cout << "Error at loading cherry texture." << std::endl;
	}

	// #2
	sf::Texture watermelonTexture;
	if (watermelonTexture.loadFromFile("src/assets/images/watermelon.png")) {
		slotTextures.push_back(watermelonTexture);
	}
	else {
		std::cout << "Error at loading watermelon texture." << std::endl;
	}
	
	// #3
	sf::Texture heartTexture;
	if (heartTexture.loadFromFile("src/assets/images/heart.png")) {
		slotTextures.push_back(heartTexture);
	}
	else {
		std::cout << "Error at loading heart texture." << std::endl;
	}

	// #4
	sf::Texture dollarTexture;
	if (dollarTexture.loadFromFile("src/assets/images/dollar.png")) {
		slotTextures.push_back(dollarTexture);
	}
	else {
		std::cout << "Error at loading dollar texture." << std::endl;
	}

	// #5
	sf::Texture diamondTexture;
	if (diamondTexture.loadFromFile("src/assets/images/diamond.png")) {
		slotTextures.push_back(diamondTexture);
	}
	else {
		std::cout << "Error at loading diamond texture." << std::endl;
	}

	// Interface Textures
	sf::Texture spinningTexture;
	if (spinningTexture.loadFromFile("src/assets/images/spinning.png")) {
		interfaceTextures.push_back(spinningTexture);
	}
	else {
		std::cout << "Error at loading spinning texture." << std::endl;
	}

	sf::Texture spinButtonTexture;
	if (spinButtonTexture.loadFromFile("src/assets/images/spinButton.png")) {
		interfaceTextures.push_back(spinButtonTexture);
	}
	else {
		std::cout << "Error at loading spin button texture." << std::endl;
	}

	sf::Texture autoSpinTexture;
	if (autoSpinTexture.loadFromFile("src/assets/images/autospinbutton.png")) {
		interfaceTextures.push_back(autoSpinTexture);
	}
	else {
		std::cout << "Error at loading auto spin texture." << std::endl;
	}

	sf::Texture maxBetTexture;
	if (maxBetTexture.loadFromFile("src/assets/images/maxbetbutton.png")) {
		interfaceTextures.push_back(maxBetTexture);
	}
	else {
		std::cout << "Error at loading max bet texture." << std::endl;
	}

	sf::Texture infoTexture;
	if (infoTexture.loadFromFile("src/assets/images/infobutton.png")) {
		interfaceTextures.push_back(infoTexture);
	}
	else {
		std::cout << "Error at loading info texture." << std::endl;
	}

	sf::Texture plusTexture;
	if (plusTexture.loadFromFile("src/assets/images/plus.png")) {
		interfaceTextures.push_back(plusTexture);
	}
	else {
		std::cout << "Error at loading plus texture." << std::endl;
	}

	sf::Texture settingsTexture;
	if (settingsTexture.loadFromFile("src/assets/images/settingsbutton.png")) {
		interfaceTextures.push_back(settingsTexture);
	}
	else {
		std::cout << "Error at loading settings texture." << std::endl;
	}

	// Slot Combinations
	firstSlotSprites = { 0, 2, 5, 1, 2, 4, 1, 1, 0, 3 };
	secondSlotSprites = { 0, 2, 4, 2, 0, 1, 5, 0, 1, 3 };
	thirdSlotSprites = { 2, 0, 1, 0, 1, 2, 3, 4, 5, 3 };
	fourthSlotSprites = { 1, 2, 0, 1, 5, 0, 2, 4, 0, 3 };
	fifthSlotSprites = { 1, 4, 1, 2, 4, 1, 0, 1, 5, 3 };

}

void SlotMachine::initSoundEffects()
{

	// #0
	if (spinBuffer.loadFromFile("src/assets/sounds/slot_machine_spin.wav")) {
		sf::Sound spinSound;
		spinSound.setVolume(35);
		spinSound.setBuffer(spinBuffer);
		soundEffects.push_back(spinSound);
	}
	else {
		std::cout << "Error at loading spin sound." << std::endl;
	}

	// #1
	if (winBuffer.loadFromFile("src/assets/sounds/gold_coin_win_prize.wav")) {
		sf::Sound winSound;
		winSound.setVolume(35);
		winSound.setBuffer(winBuffer);
		soundEffects.push_back(winSound);
	}
	else {
		std::cout << "Error at loading win sound." << std::endl;
	}

	// #2
	if (jackpotBuffer.loadFromFile("src/assets/sounds/payout-award.wav")) {
		sf::Sound jackpotSound;
		jackpotSound.setVolume(35);
		jackpotSound.setBuffer(jackpotBuffer);
		soundEffects.push_back(jackpotSound);
	}
	else {
		std::cout << "Error at loading jackpot sound." << std::endl;
	}

	// #3
	if (clickBuffer.loadFromFile("src/assets/sounds/tetris-click-sound.wav")) {
		sf::Sound clickSound;
		clickSound.setVolume(35);
		clickSound.setBuffer(clickBuffer);
		soundEffects.push_back(clickSound);
	}
	else {
		std::cout << "Error at loading click sound." << std::endl;
	}

	// #4
	if (coinBuffer.loadFromFile("src/assets/sounds/coins-handling.wav")) {
		sf::Sound coinSound;
		coinSound.setVolume(35);
		coinSound.setBuffer(coinBuffer);
		soundEffects.push_back(coinSound);
	}
	else {
		std::cout << "Error at loading coin sound." << std::endl;
	}

	// #5
	if (errorBuffer.loadFromFile("src/assets/sounds/windows-error-sound-effect.wav")) {
		sf::Sound errorSound;
		errorSound.setVolume(35);
		errorSound.setBuffer(errorBuffer);
		soundEffects.push_back(errorSound);
	}
	else {
		std::cout << "Error at loading error sound." << std::endl;
	}

}

void SlotMachine::increaseSoundEffectsVolume()
{
	for (int i = 0; i < soundEffects.size(); i++) {
		if (soundEffects[i].getVolume() <= 99) {
			soundEffects[i].setVolume(soundEffects[i].getVolume() + 1);
		}
	}
}

void SlotMachine::decreaseSoundEffectsVolume()
{
	for (int i = 0; i < soundEffects.size(); i++) {
		if (soundEffects[i].getVolume() >= 1) {
			soundEffects[i].setVolume(soundEffects[i].getVolume() - 1);
		}
	}
}

int SlotMachine::getSoundEffectsVolume()
{
	return soundEffects[0].getVolume();
}

void SlotMachine::setSoundEffectsVolume(int x)
{
	for (int i = 0; i < soundEffects.size(); i++) {
		soundEffects[i].setVolume(x);
	}
}

sf::Sprite& SlotMachine::getSettingsSprite()
{
	return settingsSprite;
}

bool SlotMachine::getSettingsCondition()
{
	return inSettings;
}

void SlotMachine::setSettingsCondition(bool x)
{
	inSettings = x;
}

bool SlotMachine::getInfoPageCondition()
{
	return inInfoPage;
}

void SlotMachine::setInfoPageCondition(bool x)
{
	inInfoPage = x;
}

SlotMachine::SlotMachine()
{
	if (backgroundTexture.loadFromFile("src/assets/images/slot_machine_ui.png")) {
		backgroundSprite.setTexture(backgroundTexture);	
	}
	else {
		std::cout << "Error at loading slot machine texture." << std::endl;
	}
	initSlotTextures();
	initSoundEffects();
}

SlotMachine::~SlotMachine()
{
}

void SlotMachine::spinFirstSlot()
{
	std::rotate(firstSlotSprites.rbegin(), firstSlotSprites.rbegin() + 1, firstSlotSprites.rend());
}

void SlotMachine::spinSecondSlot()
{
	std::rotate(secondSlotSprites.rbegin(), secondSlotSprites.rbegin() + 1, secondSlotSprites.rend());
}

void SlotMachine::spinThirdSlot()
{
	std::rotate(thirdSlotSprites.rbegin(), thirdSlotSprites.rbegin() + 1, thirdSlotSprites.rend());
}

void SlotMachine::spinFourthSlot()
{
	std::rotate(fourthSlotSprites.rbegin(), fourthSlotSprites.rbegin() + 1, fourthSlotSprites.rend());
}

void SlotMachine::spinFifthSlot()
{
	std::rotate(fifthSlotSprites.rbegin(), fifthSlotSprites.rbegin() + 1, fifthSlotSprites.rend());
}

std::vector<int>& SlotMachine::getFirstSlot()
{
	return firstSlotSprites;
}

std::vector<int>& SlotMachine::getSecondSlot()
{
	return secondSlotSprites;
}

std::vector<int>& SlotMachine::getThirdSlot()
{
	return thirdSlotSprites;
}

std::vector<int>& SlotMachine::getFourthSlot()
{
	return fourthSlotSprites;
}

std::vector<int>& SlotMachine::getFifthSlot()
{
	return fifthSlotSprites;
}

bool SlotMachine::isSpinning()
{
	return spinning;
}

void SlotMachine::checkWin(int bet)
{
	float multiplication = 1.0f;

	for (int i = 0; i < 3; i++) {
		/*
		- - - - -    - - - - -    * * * * * 
		- - - - - or * * * * * or - - - - -
		* * * * *    - - - - -    - - - - -
		*/           
		if (firstSlotSprites[i] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i]) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 40;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 50;
			}
			else if (firstSlotSprites[i] == 4) {
				multiplication *= 75;
			} 
			else if (firstSlotSprites[i] == 5) { // BONUS
				multiplication *= 500;
			}
		}

		/*
		* * - - -    - - - * *
		- - * - - or - - * - -
		- - - * *    * * - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i+1] && thirdSlotSprites[i+1] == fourthSlotSprites[i+2] && fourthSlotSprites[i+2] == fifthSlotSprites[i+2] && (i+2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 10;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 15;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 30;
			}
		}
		if (firstSlotSprites[i+2] == secondSlotSprites[i+2] && secondSlotSprites[i+2] == thirdSlotSprites[i+1] && thirdSlotSprites[i+1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 10;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 15;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 30;
			}
		}

		/*
		* - - - *    - - * - -
		- * - * - or - * - * -
		- - * - -    * - - - *
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i+1] && secondSlotSprites[i+1] == thirdSlotSprites[i+2] && thirdSlotSprites[i + 2] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 15;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 25;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 40;
			}
		}
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 15;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 25;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 40;
			}
		}

		/*
		* * * * -    - - - - -
		- - - - * or * * * * -
		- - - - -    - - - - *
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 7.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 15;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 20;
			}
		}

		/*
		* * * - *    - - - - -
		- - - * - or * * * - *
		- - - - -    - - - * -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i+1] && fourthSlotSprites[i+1] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 10;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 12.5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 20;
			}
		}

		/*
		* * - * *    - - - - -
		- - * - - or * * - * *
		- - - - -    - - * - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 10;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 12.5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 20;
			}
		}

		/*
		* - * * *    - - - - -
		- * - - - or * - * * *
		- - - - -    - * - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 10;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 12.5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 20;
			}
		}

		/*
		- * * * *    - - - - -
		* - - - - or - * * * *
		- - - - -    * - - - -
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 10;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 12.5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 20;
			}
		}

		/*
		* - - - -    - - - - -
		- * * * * or * - - - -
		- - - - -    - * * * *
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 10;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 12.5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 20;
			}
		}

		/*
		- * - - -    - - - - -
		* - * * * or - * - - -
		- - - - -    * - * * *
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 7.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 15;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 20;
			}
		}

		/*
		- - * - -    - - - - -
		* * - * * or - - * - -
		- - - - -    * * - * *
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 7.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 15;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 20;
			}
		}

		/*
		- - - * -    - - - - -
		* * * - * or - - - * -
		- - - - -    * * * - *
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 10;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 12.5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 20;
			}
		}

		/*
		- - - - *    - - - - -
		* * * * - or - - - - *
		- - - - -    * * * * -
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 10;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 12.5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 20;
			}
		}

		/*
		* - - - *    - - - - -    - - - - -    - * * * -
		- * * * - or * - - - * or - * * * - or * - - - *
		- - - - -    - * * * -    * - - - *    - - - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}

		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* - - - -    - - - - *
		- * * * - or - * * * -
		- - - - *    * - - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* - * - *    - - - - -    - - - - -    - * - * -
		- * - * - or * - * - * or - * - * - or * - * - *
		- - - - -    - * - * -    * - * - *    - - - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* - - * -    - - - - -
		- * * - * or * - - * -
		- - - - -    - * * - *    
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- * * - *    - - - - -
		* - - * - or - * * - *
		- - - - -    * - - * -
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- * - - *    - - - - -
		* - * * - or - * - - *
		- - - - -    * - * * -
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* - * * -    - - - - -
		- * - - * or * - * * -
		- - - - -    - * - - *
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* - * - -    - - - - -
		- * - * * or * - * - -
		- - - - -    - * - * *
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- * - * *    - - - - -
		* - * - - or - * - * *
		- - - - -    * - * - -
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- - * - *    - - - - -
		* * - * - or - - * - *
		- - - - -    * * - * -
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* * - * -    - - - - -
		- - * - * or * * - * -
		- - - - -    - - * - *
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* * * - -    - - - - -
		- - - * * or * * * - -
		- - - - -    - - - * *
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- - * * *    - - - - -
		* * - - - or - - * * *
		- - - - -    * * - - -
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* * - - -    - - - - -
		- - * * * or * * - - -
		- - - - -    - - * * *
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 1] && (i + 1 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- - - * *    - - - - -
		* * * - - or - - - * *
		- - - - -    * * * - -
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i] && (i + 1 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* * - - -    - - - * *
		- - * * - or - * * - -
		- - - - *    * - - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* - - - -    - - - - *
		- * * - - or - - * * -
		- - - * *    * * - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 2] && fourthSlotSprites[i + 2] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 2] && secondSlotSprites[i + 2] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* * - - -    - - - * *
		- - * - * or * - * - -
		- - - * -    - * - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 2] && fourthSlotSprites[i + 2] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 2] && secondSlotSprites[i + 2] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- * - - -    - - - * -
		* - * - - or - - * - *
		- - - * *    * * - - -
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 2] && fourthSlotSprites[i + 2] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 2] && secondSlotSprites[i + 2] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* - - - -    - - - - *
		- * * - * or * - * * -
		- - - * -    - * - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 2] && fourthSlotSprites[i + 2] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 2] && secondSlotSprites[i + 2] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- * - - -    - - - * -
		* - * * - or - * * - *
		- - - - *    * - - - -
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* * * - -    - - * * *
		- - - * - or - * - - -
		- - - - *    * - - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- - - - *    * - - - -
		- - - * - or - * - - -
		* * * - -    - - * * *
		*/
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 2] && secondSlotSprites[i + 2] == thirdSlotSprites[i + 2] && thirdSlotSprites[i + 2] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 2] && thirdSlotSprites[i + 2] == fourthSlotSprites[i + 2] && fourthSlotSprites[i + 2] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* - * - -    - - * - *
		- * - * - or - * - * -
		- - - - *    * - - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- - - - *    * - - - -
		- * - * - or - * - * -
		* - * - -    - - * - *
		*/
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 2] && thirdSlotSprites[i + 2] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 2] && thirdSlotSprites[i + 2] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- - * * -    - * * - -
		- * - - * or * - - * -
		* - - - -    - - - - *
		*/
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* - - - -    - - - - *
		- * - - * or * - - * -
		- - * * -    - * * - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 2] && thirdSlotSprites[i + 2] == fourthSlotSprites[i + 2] && fourthSlotSprites[i + 2] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 2] && secondSlotSprites[i + 2] == thirdSlotSprites[i + 2] && thirdSlotSprites[i + 2] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* - - - -    - - - - *
		- * * - * or * - * * -
		- - - * -    - * - - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 2] && fourthSlotSprites[i + 2] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 2] && secondSlotSprites[i + 2] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- - - * -    - * - - -
		- * * - * or * - * * -
		* - - - -    - - - - *
		*/
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- - * - -    - - * - -
		- * - * * or * * - * -
		* - - - -    - - - - *
		*/
		if (firstSlotSprites[i + 2] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 2] == 0 || firstSlotSprites[i + 2] == 1 || firstSlotSprites[i + 2] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 2] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 2] == 4 || firstSlotSprites[i + 2] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i] && thirdSlotSprites[i] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 2] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		* - - - -    - - - - *
		- * - * * or * * - * -
		- - * - -    - - * - -
		*/
		if (firstSlotSprites[i] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 2] && thirdSlotSprites[i + 2] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i] == 0 || firstSlotSprites[i] == 1 || firstSlotSprites[i] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i] == 4 || firstSlotSprites[i] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 1] && secondSlotSprites[i + 1] == thirdSlotSprites[i + 2] && thirdSlotSprites[i + 2] == fourthSlotSprites[i + 1] && fourthSlotSprites[i + 1] == fifthSlotSprites[i] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

		/*
		- - - * -    - * - - -
		* - * - * or * - * - *
		- * - - -    - - - * -
		*/
		if (firstSlotSprites[i + 1] == secondSlotSprites[i + 2] && secondSlotSprites[i + 2] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i] && fourthSlotSprites[i] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}
		if (firstSlotSprites[i + 1] == secondSlotSprites[i] && secondSlotSprites[i] == thirdSlotSprites[i + 1] && thirdSlotSprites[i + 1] == fourthSlotSprites[i + 2] && fourthSlotSprites[i + 2] == fifthSlotSprites[i + 1] && (i + 2 < 3)) {
			if (firstSlotSprites[i + 1] == 0 || firstSlotSprites[i + 1] == 1 || firstSlotSprites[i + 1] == 2) {
				multiplication *= 2.5;
			}
			else if (firstSlotSprites[i + 1] == 3) {
				multiplication *= 5;
			}
			else if (firstSlotSprites[i + 1] == 4 || firstSlotSprites[i + 1] == 5) {
				multiplication *= 7.5;
			}
		}

	}

	if (multiplication >= 500) { // Jackpot
		getPlayer().setWin(multiplication* bet);
		getPlayer().setTotalWin(getPlayer().getTotalWin() + getPlayer().getWin());
		getPlayer().setCoin(getPlayer().getCoin() + getPlayer().getWin());
		soundEffects[2].play();
	}
	else if (multiplication != 1) { // Regular Win
		getPlayer().setWin(multiplication* bet);
		getPlayer().setTotalWin(getPlayer().getTotalWin() + getPlayer().getWin());
		getPlayer().setCoin(getPlayer().getCoin() + getPlayer().getWin());
		soundEffects[1].play();
	} 

}

void SlotMachine::maxBet()
{
	player.setBet(player.getCoin());
}

void SlotMachine::autoSpin(sf::RenderWindow& window)
{ // When player presses auto spin button, it will keep spinning until player runs out of coin or presses auto spin button again.
	if (!autospinning) {
		autospinning = true;
	}
	else {
		autospinning = false;
	}
	while (player.getCoin() > 0 && autospinning && getPlayer().getBet() > 0) {
		spin(window);
	}
}

void SlotMachine::increaseBet()
{
	if (getPlayer().getBet() + 25 <= player.getCoin()) {
		player.setBet(player.getBet() + 25);
	}	
}

void SlotMachine::decreaseBet()
{
	if (getPlayer().getBet() >= minBet + 25) {
		player.setBet(player.getBet() - 25);
	}
}

Player& SlotMachine::getPlayer()
{
	return player;
}

sf::Sprite& SlotMachine::getSpinningSprite()
{
	return spinningSprite;
}

sf::Sprite& SlotMachine::getAutoSpinSprite()
{
	return autospinSprite;
}

sf::Sprite& SlotMachine::getMaxBetSprite()
{
	return maxBetSprite;
}

sf::Sprite& SlotMachine::getInfoSprite()
{
	return infoSprite;
}

bool SlotMachine::getAutoSpinCondition()
{
	return autospinning;
}

void SlotMachine::setAutoSpinCondition(bool x)
{
	autospinning = x;
}

sf::Sprite& SlotMachine::getPlusSprite()
{
	return plusSprite;
}

void SlotMachine::display(sf::RenderWindow& window)
{	
	
	spinningSprite.setPosition(361, 499);
	if (spinning) {
		spinningSprite.setTexture(interfaceTextures[0]);
	}
	else {
		spinningSprite.setTexture(interfaceTextures[1]);
	}
	
	autospinSprite.setTexture(interfaceTextures[2]);
	autospinSprite.setPosition(257, 600);

	maxBetSprite.setTexture(interfaceTextures[3]);
	maxBetSprite.setPosition(613, 600);

	infoSprite.setTexture(interfaceTextures[4]);
	infoSprite.setPosition(40, 35);

	plusSprite.setTexture(interfaceTextures[5]);
	plusSprite.setPosition(583, 38);

	settingsSprite.setTexture(interfaceTextures[6]);
	settingsSprite.setPosition(920, 30);
	
	window.clear();
	window.draw(backgroundSprite);
	window.draw(spinningSprite);
	window.draw(autospinSprite);
	window.draw(maxBetSprite);
	window.draw(infoSprite);
	window.draw(plusSprite);
	window.draw(settingsSprite);
	window.draw(player.getCoinText());
	window.draw(player.getBetText());
	window.draw(player.getTotalWinText());

	for (int i = 0; i < 3; i++) {
		slotSprites[i].setTexture(slotTextures[firstSlotSprites[i]]);
		slotSprites[i].setPosition(235, 200 + 75 * i);
	}
	for (int i = 0; i < 3; i++) {
		slotSprites[i+3].setTexture(slotTextures[secondSlotSprites[i]]);
		slotSprites[i+3].setPosition(355, 200 + 75 * (i));
	}
	for (int i = 0; i < 3; i++) {
		slotSprites[i+6].setTexture(slotTextures[thirdSlotSprites[i]]);
		slotSprites[i+6].setPosition(470, 200 + 75 * (i));
	}
	for (int i = 0; i < 3; i++) {
		slotSprites[i+9].setTexture(slotTextures[fourthSlotSprites[i]]);
		slotSprites[i+9].setPosition(590, 200 + 75 * (i));
	}
	for (int i = 0; i < 3; i++) {
		slotSprites[i+12].setTexture(slotTextures[fifthSlotSprites[i]]);
		slotSprites[i+12].setPosition(710, 200 + 75 * (i));
	}
	for (int i = 0; i < 15; i++) {
		window.draw(slotSprites[i]);
	}

	window.display();
}

void SlotMachine::spin(sf::RenderWindow& window)
{
	if (player.getBet() == 0) {
		soundEffects[5].play();
		std::cout << "You should pick a bet." << std::endl;
		if (autospinning) {
			autospinning = false;
		}
	}
	else if (player.getBet() < 0) {
		soundEffects[5].play();
		std::cout << "An error happened, try again." << std::endl;
		player.setBet(0);
		if (autospinning) {
			autospinning = false;
		}
	}
	else if (player.getBet() > player.getCoin()) {
		soundEffects[5].play();
		std::cout << "You don't have enough coin." << std::endl;
		if (autospinning) {
			autospinning = false;
		}
	}
	else {

		int bet = getPlayer().getBet();
		getPlayer().setWin(0);

		spinning = true;
		std::uniform_int_distribution<int> dist(20, 30); // number of spins
		const int spinDuration = 25;

		player.setCoin(player.getCoin() - player.getBet());

		int random = dist(randomizer);
		std::cout << random << std::endl;
		soundEffects[0].play();
		for (int i = 0; i < random; i++)
		{
			spinFirstSlot();
			display(window);
			std::this_thread::sleep_for(std::chrono::milliseconds(spinDuration));
		}

		random = dist(randomizer);
		std::cout << random << std::endl;
		for (int i = 0; i < random; i++)
		{
			spinSecondSlot();
			display(window);
			std::this_thread::sleep_for(std::chrono::milliseconds(spinDuration));
		}

		random = dist(randomizer);
		std::cout << random << std::endl;
		for (int i = 0; i < random; i++)
		{
			spinThirdSlot();
			display(window);
			std::this_thread::sleep_for(std::chrono::milliseconds(spinDuration));
		}

		random = dist(randomizer);
		std::cout << random << std::endl;
		for (int i = 0; i < random; i++)
		{
			spinFourthSlot();
			display(window);
			std::this_thread::sleep_for(std::chrono::milliseconds(spinDuration));
		}

		random = dist(randomizer);
		std::cout << random << std::endl;
		for (int i = 0; i < random; i++)
		{
			spinFifthSlot();
			display(window);
			std::this_thread::sleep_for(std::chrono::milliseconds(spinDuration));
		}
		soundEffects[0].stop();

		checkWin(getPlayer().getBet());
		spinning = false;
	}
}

int SlotMachine::getSlot(int index)
{
	return slots[index];
}

int SlotMachine::getSlotNumber()
{
	return slotNumber;
}

sf::Sprite& SlotMachine::getSprite()
{
	return backgroundSprite;
}

std::vector<sf::Texture>& SlotMachine::getSlotTextures()
{
	return slotTextures;
}

sf::Texture& SlotMachine::getSlotTexture(int index)
{
	return slotTextures[index];
}
