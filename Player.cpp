#include "assert.h"
#include "Player.h"
#include <string>


Player::Player(std::string name, int max_HP = INITIAL_MAX_HP , int force = INITIAL_FORCE , int level,
    int coins, int HP):   
                    m_name(std::string(name)),
                    m_maxHP(max_HP),
                    m_force(force),
                    m_level(1),
                    m_coins(0),
                    m_HP(max_HP){}
    

Player::Player(const Player& player) = default;

                  

Player::~Player() = default;


Player& Player::operator=(const Player&) = default;



void Player::printInfo() const{
    printPlayerInfo(m_name.std::string::c_str(),m_level,m_force,m_HP,m_coins);
}

bool Player::levelUp(){
    assert(m_level>= 0 && m_level < 10);

    if(m_level >= 10)
        return false;

    m_level++;

    return true;
}

int Player::getLevel() const{
    assert(m_level <= 10);
    return m_level;
};

void Player::buff(int amount){
    if (amount < 0)
    {
        amount = 0;
    }
    m_force+=amount;
}

bool Player::heal(int amount){
    if (amount < 0)
    {
        amount = 0;
    }
    if (m_HP + amount > m_maxHP)
    {
        m_HP = m_maxHP;
        return false;
    }
    else {
        m_HP = m_HP + amount;
        return true;
    }
}

bool Player::damage(int amount){
    if(amount < 0)
    {
        return true;
    }
    else if ( amount > m_HP){
        m_HP = 0;
        return false;
    }
    else{
        m_HP -= amount;
        return true;
    }
}

bool Player::isKnockedOut() const{
    if(!m_HP)
    {
        return true;
    }
    else{
        return false;
    }
}

void Player::addCoins(int amount){
     if (amount < 0)
    {
        amount = 0;
    }
    m_coins += amount;
}

bool Player::pay(int amount){
    if (amount < 0)
    {
        amount = 0;
    }
    if(m_coins >= amount)
    {
        m_coins -= amount;
        return true;
    }
    else{
        return false;
    }
}

int Player::getAttackStrength() const{
    return(m_force+m_level);
}