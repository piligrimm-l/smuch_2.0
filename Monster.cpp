#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

class Monster {
  public:
    enum MonsterType {
      DRAGON,
      GOBLIN,
      OGRE,
      ORC,
      SKELETON,
      TROLL,
      VAMPIRE,
      ZOMBIE,
      MAX_MONSTERS_TYPES
    };

  private:
    MonsterType m_mt;
    std::string m_name;
    int m_hp; 

  public:
    Monster(MonsterType mt, std::string name, int hp)
      : m_mt(mt), m_name(name), m_hp(hp) 
      {
      }

    std::string getTypeString(MonsterType mt) {
      std::string monster_name;
      switch(mt) {
        case DRAGON:
          monster_name = "Dragon";
          break;
        case GOBLIN:
          monster_name = "Goblin";
          break;
        case OGRE:
          monster_name = "Ogre";
          break;
        case ORC:
          monster_name = "Orc";
          break;
        case SKELETON:
          monster_name = "Skeleton";
          break;
        case TROLL:
          monster_name = "Troll";
          break;
        case VAMPIRE:
          monster_name = "Vampire";
          break;
        case ZOMBIE:
          monster_name = "Zombie";
          break;
        default:
          break;
      }
      return monster_name;
    }
    
    void print() {
      std::cout << "Monster(" << getTypeString(m_mt) << ", " << m_name << ", " << m_hp << ")\n";
      std::cout << m_name << " is the " << getTypeString(m_mt) << " that has " << m_hp << " health points.\n";
    }
};

class MonsterGenerator {
  private:
  public:
    static int getRandomNumber(int min, int max) {
      static const double fraction =
                          1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
      return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

    static Monster generateMonster() {
      //Monster newMonster;
      Monster::MonsterType g_mt = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTERS_TYPES - 1 ));
      int g_hp = getRandomNumber(1, 100);
      static std::string s_names[6] {
        "Suglod", "Jignok", "Windrakt", "Algsiz", "Breyndum", "Ulmo"
      };
      return Monster(g_mt, s_names[getRandomNumber(0, 5)], g_hp); 
    }
};

int main(void) {
  std::srand(static_cast<unsigned int>(time(0)));
  //Monster jack(Monster::ORC, "Jack", 90);
  Monster m = MonsterGenerator::generateMonster();
  m.print();
  return 0;
}
