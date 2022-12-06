//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {
public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);


    //copy ctor
    Mtmchkin(const Mtmchkin& game);             //Need to allocate new cardsArray
    //assignment operator 
    Mtmchkin& operator=(const Mtmchkin& game); //Need to allocate new cardsArray
     /*
     * D'tor of the game:
     */
    ~Mtmchkin();

    Mtmchkin() = delete; //We won't be using argument-less constructor

    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;

    //TODO: complete the Mtmchkin class.
private:
    //TODO: complete the Mtmchkin class.
    Player m_player;
    Card* m_cardsArray;
    int m_numOfCards;
    int m_indexCounter;
    GameStatus m_gameStatus;
    
};


#endif //EX2_GAME_H
