#include "Card.h"


Card::Card(CardType type, const CardStats& stats) :
                    m_effects(type),
                    m_stats(stats)
                    {}

void Card::applyEncounter(Player& player) const{
    if(m_effects == CardType::Buff){ //
        player.buff(m_stats.buff);

    }
    else if(m_effects == Battle){ //
    bool res;
        if(player.getAttackStrength()>= m_stats.force){
           player.addCoins(m_stats.loot);
           player.levelUp(); 
           res = true;
        }
        else{
            player.damage(m_stats.hpLoss);
            res = false;
        }
        printBattleResult(res);
    }  
    else if(m_effects == CardType::Heal){ //
        player.heal(m_stats.heal);
    }
    else if(m_effects == CardType::Treasure){ //
        player.addCoins(m_stats.loot);
    }
    else{//Shouldn't get here
        return;
    }      
}

void Card::printInfo() const{
     if(m_effects == CardType::Buff){ //
          printBuffCardInfo(m_stats);
    }
    else if(m_effects == Battle){ //
          printBattleCardInfo(m_stats);
    }  
    else if(m_effects == CardType::Heal){ //
          printHealCardInfo(m_stats);
    }
    else if(m_effects == CardType::Treasure){ //
          printTreausureCardInfo(m_stats);
    }
    else{//Shouldn't get here
        return;
    }      
}                                    
