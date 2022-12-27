#pragma once
#include <array>

class Ancestor {
public:
    Ancestor(int xx, int yy);
    Ancestor(int xx, int yy, int hp, int hpp)
        : x(xx), y(yy), health(hp), potions(hpp) {}

    void SetX(int xx) { x = xx; }
    void SetY(int yy) { y = yy; }
    void SetHealth(int hp) { health = hp; }
    void SetPotions(int hpp) { potions = hpp; }

    int GetX() const { return x; }
    int GetY() const { return y; }
    int GetHealth() const { return health; }
    int GetPotions() const { return potions; }

    virtual int GetID() const = 0; //to ID allazei analoga to paidi
    virtual void BattleRound() = 0;// to BattleRound allazei analoga me to paidi

protected:
    int x;
    int y;
private:
    int health = 3;
    int potions = 0;
};

class NPC : public Ancestor {
public:
    NPC(int xx, int yy);
    void Move();

    virtual void BattleRound() override;
    bool isDead() const { return GetHealth() <= 0; }
    void Heal() { int health = GetHealth();  if ( health < 3) SetHealth(health + 1); }// diadikasia heal twn NPC metaksi toys
protected:
    virtual std::array<int, 2> TryMove() = 0; //sinartisi elenxoy kinisis
private:
    int power_attack;
    int power_defence;
};

class Vampire : public NPC {
public:
    Vampire(int xx, int yy)
        : NPC(xx, yy) {}
    virtual int GetID() const override { return 3; }//an einai vampire exei ID=3
protected:
    virtual std::array<int, 2> TryMove() override;//sinartisi elenxoy kinisis
};

class Werewolf : public NPC {
public:
    Werewolf(int xx, int yy)
        : NPC(xx, yy) {}
    virtual int GetID() const override { return 4; }//an einai werewolf exei ID=4
protected:
    virtual std::array<int, 2> TryMove() override;//sinartisi elenxou kinisis
};

class Avatar : public Ancestor {
public:
    Avatar(int xx, int yy, int _id);
    virtual int GetID() const override { return id; }
    void Move(int xx, int yy);
    virtual void BattleRound(void) override;
    void SetShouldHeal(bool heal) { shouldHeal = heal; }//an plirei tis proipotheseis gia heal = true , ksekinaei false
private:
    int id;
    bool shouldHeal = false;
};