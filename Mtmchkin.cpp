#include "Mtmchkin.h"

//Constructor. allocate memory for the card pack.
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
            m_player(playerName),
            m_cardsArray(new Card[numOfCards]), 
            m_numOfCards(numOfCards),
            m_indexCounter(0),
            m_gameStatus(GameStatus::MidGame)
{   
    for (int i=0; i < numOfCards;  ++i)
    {
        m_cardsArray[i] = cardsArray[i];
    }

}

//D'tor. we allocate memory in the constructor.
Mtmchkin::~Mtmchkin()
{
    delete[] m_cardsArray;
}
//Copy c'tor.  we copy the card pack to another copy of our own.
Mtmchkin::Mtmchkin(const Mtmchkin& game): 
            m_player(game.m_player), 
            m_cardsArray(new Card[game.m_numOfCards]),
            m_numOfCards(game.m_numOfCards),
            m_indexCounter(game.m_indexCounter),
            m_gameStatus(game.m_gameStatus)
    {
    for (int i=0; i < m_numOfCards; ++i)
    {
        m_cardsArray[i] = game.m_cardsArray[i];
    }               
    
}

//assigment operator. we allocate memory to ,ake copy of the card pack , to avoid invalid read memory.
//return refrence to the "new" object.(it may be use if we make a chain of  game1 = game2 = game3 ... ).
Mtmchkin& Mtmchkin::operator=(const Mtmchkin& game)
{
    m_player = game.m_player; 
    m_cardsArray = new Card[game.m_numOfCards];
    m_numOfCards = game.m_numOfCards;
    m_indexCounter = game.m_indexCounter;
    m_gameStatus = game.m_gameStatus;
    for (int i=0; i < game.m_numOfCards; ++i)
    {
        m_cardsArray[i] = game.m_cardsArray[i];
    }  
    return *this;
}


void Mtmchkin::playNextCard()
{
     
    // if(m_gameStatus != GameStatus::MidGame){//Game's over
    //     return; 
    // }

    if(m_indexCounter == m_numOfCards) //Guarantees cyclic nature of deck
    {
        m_indexCounter = 0 ;
    }
    m_cardsArray[m_indexCounter].printInfo();   //prints Card info
    m_cardsArray[m_indexCounter].applyEncounter(m_player);
    m_player.printInfo(); //prints Player info post encounter
    m_indexCounter++; //Equivalent to removing the played card from top of deck
   
}

//check if player lose or win according to the player level and hp.
 bool Mtmchkin::isOver() 
 { 
    if(m_player.getLevel() == Player::MAX_LEVEL)
    {   
        m_gameStatus = GameStatus::Win;
        return true;
    }

    if (m_player.isKnockedOut())
    {  
         m_gameStatus = GameStatus::Loss;
        return true;
    }
  
    return false;
 }


 GameStatus Mtmchkin::getGameStatus() const
 {
    return m_gameStatus;
 }