#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"

class SlotMachine
{
private:
	
	// Button Sprites
	sf::Sprite spinningSprite;
	sf::Sprite autospinSprite;
	sf::Sprite maxBetSprite;
	sf::Sprite infoSprite;
	sf::Sprite plusSprite;
	sf::Sprite settingsSprite;

	// Player
	Player player;

	// Flags
	bool spinning = false;
	bool autospinning = false;
	bool inSettings = false;
	bool inInfoPage = false;

	// Textures
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	std::vector<sf::Texture> slotTextures;
	std::vector<sf::Texture> interfaceTextures;
	std::vector<float> textureValues;

	// Randomizer
	std::random_device randomizer;

	// Slot Variables
	int slotNumber = 5;
	int minBet = 25;

	// Slot Arrays
	std::vector<int> slots;
	std::vector<int> firstSlotSprites;
	std::vector<int> secondSlotSprites;
	std::vector<int> thirdSlotSprites;
	std::vector<int> fourthSlotSprites;
	std::vector<int> fifthSlotSprites;

	// Slot Sprites
	sf::Sprite oneToOne;
	sf::Sprite oneToTwo;
	sf::Sprite oneToThree;
	sf::Sprite twoToOne;
	sf::Sprite twoToTwo;
	sf::Sprite twoToThree;
	sf::Sprite threeToOne;
	sf::Sprite threeToTwo;
	sf::Sprite threeToThree;
	sf::Sprite fourToOne;
	sf::Sprite fourToTwo;
	sf::Sprite fourToThree;
	sf::Sprite fiveToOne;
	sf::Sprite fiveToTwo;
	sf::Sprite fiveToThree;
	std::vector<sf::Sprite> slotSprites = {oneToOne, oneToTwo, oneToThree, twoToOne, twoToTwo, twoToThree, threeToOne, threeToTwo, threeToThree, fourToOne, fourToTwo, fourToThree, fiveToOne, fiveToTwo, fiveToThree};

	// Sound Buffers
	sf::SoundBuffer spinBuffer;
	sf::SoundBuffer winBuffer;
	sf::SoundBuffer jackpotBuffer;
	sf::SoundBuffer clickBuffer;
	sf::SoundBuffer coinBuffer;
	sf::SoundBuffer errorBuffer;
	std::vector<sf::Sound> soundEffects;


public:
	SlotMachine();
	~SlotMachine();
	void spin(sf::RenderWindow& window);
	void spinFirstSlot();
	void spinSecondSlot();
	void spinThirdSlot();
	void spinFourthSlot();
	void spinFifthSlot();
	void display(sf::RenderWindow& window);
	int getSlot(int index);	
	int getSlotNumber();
	sf::Sprite& getSprite();
	void initSlotTextures();
	void initSoundEffects();
	std::vector<sf::Texture>& getSlotTextures();
	sf::Texture& getSlotTexture(int index);
	std::vector<int>& getFirstSlot();
	std::vector<int>& getSecondSlot();
	std::vector<int>& getThirdSlot();
	std::vector<int>& getFourthSlot();
	std::vector<int>& getFifthSlot();
	bool isSpinning();
	void checkWin(int bet);
	void maxBet();
	void autoSpin(sf::RenderWindow& window);
	void increaseBet();
	void decreaseBet();
	Player& getPlayer();
	sf::Sprite& getSpinningSprite();
	sf::Sprite& getAutoSpinSprite();
	sf::Sprite& getMaxBetSprite();
	sf::Sprite& getInfoSprite();
	sf::Sprite& getPlusSprite();
	sf::Sprite& getSettingsSprite();
	bool getAutoSpinCondition();
	void setAutoSpinCondition(bool x);
	void increaseSoundEffectsVolume();
	void decreaseSoundEffectsVolume();
	void setSoundEffectsVolume(int x);
	int getSoundEffectsVolume();
	bool getSettingsCondition();
	void setSettingsCondition(bool x);
	bool getInfoPageCondition();
	void setInfoPageCondition(bool x);
};

