#include "Mtmchkin.h"

//Constructor
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
            m_player(playerName),
            m_cardsArray(cardsArray),
            m_numOfCards(numOfCards)
{

}

//default destructor

int Mtmchkin::m_indexCounter;

void Mtmchkin::playNextCard(){

    if(getGameStatus() != GameStatus::MidGame){//Game's over
        return; 
    }

    if(m_indexCounter == m_numOfCards)
    {
        m_indexCounter = 0 ;
    }
    m_cardsArray[m_indexCounter].printInfo();
    m_cardsArray[m_indexCounter].applyEncounter(m_player);
    printPlayerInfo(m_player.getName(), m_player.getLevel(), m_player.getForce(),
     m_player.getHP(), m_player.getCoins());
    m_indexCounter++;
   
}

 bool Mtmchkin::isOver() const{ //How to know which player?
    if(m_player.getLevel() == Player::MAX_LEVEL)
    {
        return true;
    }

    if (m_player.isKnockedOut())
    {
        return true;
    }
  
    return false;
 }

 GameStatus Mtmchkin::getGameStatus() const{
    if(isOver()){
        if (!m_player.isKnockedOut())
        {
            return GameStatus::Win;
        }
        else
        {
            return GameStatus::Loss;
        }
    }
    else
    {
        return GameStatus::MidGame;
    }
 }