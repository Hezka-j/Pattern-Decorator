#include <iostream>
#include <string>
using namespace std;

class Hero abstract {
protected:
    string name;
    string abilities;
public:
    string GetName() {
        return name;
    }

    string GetAbilities() {
        return abilities;
    }

    void Print() {
        cout << name << "\n";
        cout << abilities << "\n";
    }
};

class Human : public Hero{
public:
    Human(string name) {
        this->name = name;
    }
};

class Elf : public Hero{
public:
    Elf(string name) {
        this->name = name;
    }
};

class Profession : public Hero {
protected:
    Hero* hero;
};

class SwordMaster : public Profession {
public:
    SwordMaster(Hero* hero) {
        this->hero = hero;
        this->abilities = this->hero->GetAbilities() + "SwordMaster\n";
    }

    void SwordSwing() {
        cout << "shhh...\n";
    }
};

class Archer : public Profession {
public:
    Archer(Hero* hero) {
        this->hero = hero;
        abilities = this->hero->GetAbilities() + "Archer\n";
    }

    void Archery() {
        cout << "poww.\n";
    }
};

class Wizard : public Profession {
public:
    Wizard(Hero* hero) {
        this->hero = hero;
        abilities = this->hero->GetAbilities() + "Wizard\n";
    }

    void SpellCast() {
        cout << "magic\n";
    }
};

class Blacksmith : public Profession {
public:
    Blacksmith(Hero* hero) {
        this->hero = hero;
        abilities = this->hero->GetAbilities() + "Blacksmith\n";
    }

    void ForgeWeapon() {
        cout << "weapon\n";
    }
};

int main()
{
    Hero* human = new Human("Alex");
    Archer* archer_human = new Archer(human);
    archer_human->Archery();
    Archer* archer_blacksmith_human = new Archer(new Blacksmith(human));   
    archer_blacksmith_human->Archery();
    archer_blacksmith_human->Print();
}

