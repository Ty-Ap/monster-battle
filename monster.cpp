#include <iostream>
#include <string>

class Monster {
  public: 
    std::string name;
    int lvl;
    int maxHp;
    int currentHp;
    int atk;

    Monster(std::string name, int lvl, int maxHp, int atk)
      : name(name), lvl(lvl), maxHp(maxHp), currentHp(maxHp), atk(atk) {}

  void takeDmg(int dmg) {
    currentHp -= dmg;
    if(currentHp < 0) {
      currentHp = 0;
    }
  }
};

void battle(Monster &playerMonster, Monster &enemyMonster)
{
  // turn fn
  while (playerMonster.currentHp > 0 && enemyMonster.currentHp > 0)
  {
    int playerDmg = playerMonster.atk * (1 + rand() % 3);
    enemyMonster.takeDmg(playerDmg);
    std::cout << playerMonster.name << " attacks " << enemyMonster.name << " for " << playerDmg << " damage! \n";
    if (enemyMonster.currentHp <= 0)
    {
      std::cout << enemyMonster.name << " fainted!\n";
      break;
    }
    int enemyDmg = enemyMonster.atk * (1 + rand() % 3);
    playerMonster.takeDmg(enemyDmg);
    std::cout << enemyMonster.name << " attacks " << playerMonster.name << " for " << enemyDmg << " damage! \n";
    if (playerMonster.currentHp <= 0)
    {
      std::cout << playerMonster.name << " fainted!\n";
      break;
    }
  }
}

int main() {
  //create sample monster objs//
  Monster playerMonster("Belle", 10, 100, 40);
  Monster enemyMonster("Sadie", 10, 115, 36);

  //start battle//
  std::cout << "A wild " << enemyMonster.name << " appears! \n";
  battle(playerMonster, enemyMonster);

  return 0;
}

