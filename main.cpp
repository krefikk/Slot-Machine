#include <iostream>
#include <random>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "SlotMachine.h"
#include "Player.h"

/*  TO-DO LIST
* - Add sound effects.
* - Add win animations. (Shine sprites, write jackpot, etc.)
* - Auto Spin?
* - Bigger coin space.
* - Auto Spin Button 130x36 veya 100x36 tam hatýrlamýyorum. Koordinat (257, 580)
*/

int main()
{
    // Declaring window, slot machine and player objects
    sf::RenderWindow window(sf::VideoMode(1000, 666), "Slot Machine");
    SlotMachine slotMachine;
    sf::Font font;
    if (!font.loadFromFile("src/assets/fonts/AstroSpace-eZ2Bg.ttf")) {
		std::cout << "Error at loading font." << std::endl;
	}
    sf::Sprite back;
    sf::Texture backTexture;
    if (!backTexture.loadFromFile("src/assets/images/back.png")) {
        std::cout << "Error at loading back button texture." << std::endl;
    }
    back.setTexture(backTexture);
    back.setScale(0.1, 0.1);
    int defaultVolumeValue = 35;

    window.setKeyRepeatEnabled(false);

    // Creating Settings and Info Tab Properties
    // Settings
    sf::Text volumeSetting;
    sf::Text volumeValue;
    sf::Sprite increase;
    sf::Texture increaseTexture;
    sf::Sprite decrease;
    sf::Texture decreaseTexture;
    sf::Sprite apply;
    sf::Texture applyTexture;
    // Info
    sf::Text rtpInfo;
    sf::Text howToPlay;
    sf::Text minBetInfo;
    sf::Text forMoreInfo;
    sf::Text forMoreInfo2;
    sf::Text githubLink;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Declaring Cursor Location
            auto mouse_pos = sf::Mouse::getPosition(window);
            auto translated_pos = window.mapPixelToCoords(mouse_pos);

            // Opening Info Tab
            if (slotMachine.getInfoSprite().getGlobalBounds().contains(translated_pos)) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    slotMachine.setInfoPageCondition(true);
                }
            }

            // Opening Settings Tab
            if (slotMachine.getSettingsSprite().getGlobalBounds().contains(translated_pos)) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    defaultVolumeValue = slotMachine.getSoundEffectsVolume();
                    slotMachine.setSettingsCondition(true);
                }
            }   

            // Handling Game Tabs
            //Settings Tab
            if (slotMachine.getSettingsCondition()) 
            {
                window.clear(sf::Color::Black);

                // Loading and Initializing Textures
                volumeSetting.setFont(font);
                volumeSetting.setCharacterSize(30);
                volumeSetting.setString("Volume");
                volumeSetting.setFillColor(sf::Color::White);
                volumeSetting.setPosition(100, 200);
                volumeValue.setFont(font);
                volumeValue.setCharacterSize(30);
                volumeValue.setString(std::to_string(slotMachine.getSoundEffectsVolume()));
                volumeValue.setFillColor(sf::Color::White); 
                volumeValue.setPosition(750, 200);
                back.setPosition(10, 10);
                if (!increaseTexture.loadFromFile("src/assets/images/increase.png")) { 
                    std::cout << "Error at loading volume increase texture." << std::endl; 
                }
                increase.setTexture(increaseTexture);
                increase.setPosition(850, 200);
                if (!decreaseTexture.loadFromFile("src/assets/images/decrease.png")) { 
                    std::cout << "Error at loading volume decrease texture." << std::endl; 
                }
                decrease.setTexture(decreaseTexture);
                decrease.setPosition(650, 200);
                if (!applyTexture.loadFromFile("src/assets/images/apply.png")) {
					std::cout << "Error at loading apply texture." << std::endl; 
				}
                apply.setTexture(applyTexture);
                apply.setPosition(860, 600);
                apply.setScale(0.25, 0.25);

                window.draw(back);
                window.draw(increase);
                window.draw(decrease);
                window.draw(volumeSetting);
                window.draw(volumeValue);
                window.draw(apply);
                window.display();

                // Functions
                // Back Action
                if (back.getGlobalBounds().contains(translated_pos)) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        slotMachine.setSoundEffectsVolume(defaultVolumeValue);
                        slotMachine.setSettingsCondition(false);
                    }
                }

                // Volume Increase & Decrease Action
                if (increase.getGlobalBounds().contains(translated_pos)) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        slotMachine.increaseSoundEffectsVolume();
                    }
                }
                if (decrease.getGlobalBounds().contains(translated_pos)) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        slotMachine.decreaseSoundEffectsVolume();
                    }
                }

                // Apply Action
                if (apply.getGlobalBounds().contains(translated_pos)) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        slotMachine.setSettingsCondition(false);
                    }
                }

            }

            // Info Tab
            if (slotMachine.getInfoPageCondition())
            {
				window.clear(sf::Color::Black);

                back.setPosition(10, 10);
                if (!increaseTexture.loadFromFile("src/assets/images/increase.png")) {
                    std::cout << "Error at loading volume increase texture." << std::endl;
                }
                rtpInfo.setFont(font);
                rtpInfo.setCharacterSize(30);
                rtpInfo.setString("This Game Has Theoretical RTP of 97.96%");
                rtpInfo.setFillColor(sf::Color::White);
                rtpInfo.setPosition(150, 50);
                howToPlay.setFont(font);
                howToPlay.setCharacterSize(15);
                howToPlay.setString("You win if you get 5 identical shapes connected to each other in any way.");
                howToPlay.setFillColor(sf::Color::White);
                howToPlay.setPosition(150, 200);
                minBetInfo.setFont(font);
                minBetInfo.setCharacterSize(15);
                minBetInfo.setString("Minimum bet is 25. There is no maximum bet limit.");
                minBetInfo.setFillColor(sf::Color::White);
                minBetInfo.setPosition(150, 225);
                forMoreInfo.setFont(font);
                forMoreInfo.setCharacterSize(15);
                forMoreInfo.setString("You can check the PAR Sheet in the repository to learn more about the shapes,");
                forMoreInfo.setFillColor(sf::Color::White);
                forMoreInfo.setPosition(150, 275);
                forMoreInfo2.setFont(font);
                forMoreInfo2.setCharacterSize(15);
                forMoreInfo2.setString("combinastions and the odds of winning:");
                forMoreInfo2.setFillColor(sf::Color::White);
                forMoreInfo2.setPosition(150, 300);
                githubLink.setFont(font);
                githubLink.setCharacterSize(20);
                githubLink.setString("https://github.com/krefikk/slot-machine");
                githubLink.setFillColor(sf::Color::Cyan);
                githubLink.setPosition(250, 330);

                
                window.draw(back);
                window.draw(rtpInfo);
                window.draw(howToPlay);
                window.draw(minBetInfo);
                window.draw(forMoreInfo);
                window.draw(forMoreInfo2);
                window.draw(githubLink);
                
                // Functions
                // Back Action
                if (back.getGlobalBounds().contains(translated_pos)) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        slotMachine.setSoundEffectsVolume(defaultVolumeValue);
                        slotMachine.setInfoPageCondition(false);
                    }
                }

                window.display();
			}

            // Main Game
			if (!slotMachine.getInfoPageCondition() && !slotMachine.getSettingsCondition())
            {
            
                if (event.type == sf::Event::MouseButtonPressed)
                {

                    // Spin Action
                    if (slotMachine.getSpinningSprite().getGlobalBounds().contains(translated_pos)) {
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            slotMachine.spin(window);
                        }
                    }

                    // Max Bet Action
                    if (slotMachine.getMaxBetSprite().getGlobalBounds().contains(translated_pos)) {
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            slotMachine.maxBet();
                        }
                    }

                    // Auto Spin Action
                    bool clicked = false;
                    if (slotMachine.getAutoSpinSprite().getGlobalBounds().contains(translated_pos)) {
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            slotMachine.setAutoSpinCondition(true);
                            while (slotMachine.getAutoSpinCondition()) { 
                                slotMachine.spin(window);
                                // Declaring Cursor Location Agin for Auto Spin
                                auto mouse_pos = sf::Mouse::getPosition(window);
                                auto translated_pos = window.mapPixelToCoords(mouse_pos);
                                if (slotMachine.getSpinningSprite().getGlobalBounds().contains(translated_pos)) {
                                    if (event.mouseButton.button == sf::Mouse::Right) {
                                        std::cout << "Clicked" << std::endl;
                                        slotMachine.setAutoSpinCondition(false);
                                    }
                                }
                                std::this_thread::sleep_for(std::chrono::milliseconds(500));
							}
						}
					}

                }

                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up) {
                        slotMachine.increaseBet();
                    }
                    if (event.key.code == sf::Keyboard::Down) {
                        slotMachine.decreaseBet();
                    }
                }
            }

        }

        if (!slotMachine.getInfoPageCondition() && !slotMachine.getSettingsCondition()) {
            slotMachine.display(window);
		}
        
    }

    return 0;
}