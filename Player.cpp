#include "assert.h"
#include "Player.h"
#include <string>

//Player constructor. inizialized by inizializetion list.
Player::Player(const std::string name, int maxHP  , int force , int level,
    int coins, int HP):   
                    m_name(name),
                    m_maxHP(maxHP),
                    m_force(force),
                    m_level(STARTING_LEVEL),
                    m_coins(STARTING_COINS),
                    m_HP(maxHP){
                        //Invalid inputs
                        if( m_maxHP <= 0){ 
                            m_maxHP = INITIAL_MAX_HP;
                            m_HP = INITIAL_MAX_HP;
                        }
                        m_force = ( m_force < 0 ? INITIAL_FORCE : m_force);
                    }
    

//copy consstructor. inizialize new Player object and give him the same data as the argument.
Player::Player(const Player& player) = default;

                  
//Destructor.
Player::~Player() = default;

//Assignment Operator. unlike the copy constructor is copy data field by field between two exist objects.
Player& Player::operator=(const Player&) = default;


//printing player data field by field.
void Player::printInfo() const{
    printPlayerInfo(m_name.std::string::c_str(),m_level,m_force,m_HP,m_coins);
}

//if level is below 10 we add plus 1 to player->level. return true if the function add 1, false other.
bool Player::levelUp(){
    assert(m_level>= 0 && m_level < MAX_LEVEL);

    if(m_level >= MAX_LEVEL){
        return false;
    }
    else{

    m_level++;

    return true;
    }
}

//getting Player level. 
int Player::getLevel() const{
    assert(m_level <= MAX_LEVEL);
    return m_level;
}

//getting Player's HP. 
int Player::getHP() const{
    assert(m_HP >= 0);
    return m_HP;
}

//getting Player Coins. 
int Player::getCoins() const{
    assert(m_coins >= 0);
    return m_coins;
}

//getting Player Force. 
int Player::getForce() const{
    return m_force;
}

const char* Player::getName() const{
    //std::string tempStr = m_name;
    //return tempStr.std::string::c_str();
    return m_name.std::string::c_str();
}

// If Player has won the battle this function will add him point to his force. 
void Player::buff(int amount){
    if (amount < 0)
    {
        amount = 0;
    }
    m_force+=amount;
}

//This function adding healing points to the player(class) heal field. note that there is limit HP == maxHP.
//**Return true if  ------ BENJO WTF??  benjo look at the second if , it is not needed to be true??
bool Player::heal(int amount){
    if (amount < 0)
    {
        amount = 0;
        return true;
    }
    else if (m_HP + amount > m_maxHP)
    {
        m_HP = m_maxHP;
        return false;
    }
    else {
        m_HP = m_HP + amount;
        return true;
    }
}

//If Player hes lost his battle this function will take amount heal points from his heal field.
// if amount is bigger then the player HP so we set his hp = 0.
//return true if the function did her job, false other.
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

//If Player->HP = 0 ,player has lost the game.
//return true if player lost, false other.
bool Player::isKnockedOut() const{
    if(!m_HP)
    {
        return true;
    }
    else{
        return false;
    }
}

//Adding coins to Player-.coins.
void Player::addCoins(int amount){
     if (amount < 0)
    {
        amount = 0;
    }
    m_coins += amount;
}

//This function take some Player coins if possible.
//return true if the function took coins or amount =0, false other.
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

//Getting data about the Player strength. note that strength = force + level.
int Player::getAttackStrength() const{
    return(m_force+m_level);
}