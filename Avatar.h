#pragma once
#include <array>

class Ancestor {
public:
    Ancestor(int xx, int yy);
    Ancestor(int xx, int yy, int _id, int hp, int hpp)
        : x(xx), y(yy), health(hp), healing_power(hpp) {}

    void SetX(int xx) { x = x; }
    void SetY(int yy) { y = y; }
    void SetHealth(int hp) { health = hp; }
    void SetHealingPower(int hpp) { healing_power = hpp; }

    int GetX() const { return x; }
    int GetY() const { return y; }
    int GetHealth() const { return health; }
    int GetHealingPower() const { return healing_power; }

    virtual int GetID() const = 0;

protected:
    int x;
    int y;
private:
    int health = 3;
    int healing_power = 0;
};

class NPC : public Ancestor {
public:
    NPC(int xx, int yy);
    void Move();
protected:
    virtual std::array<int, 2> TryMove() = 0;
private:
    int power_attack;
    int power_defence;
};

class Vampire : public NPC {
public:
    Vampire(int xx, int yy)
        : NPC(xx, yy) {}
    virtual int GetID() const override { return 3; }

private:
    virtual std::array<int, 2> TryMove() override;
};

class Werewolf : public NPC {
public:
    Werewolf(int xx, int yy)
        : NPC(xx, yy) {}
    virtual int GetID() const override { return 4; }
protected:
    virtual std::array<int, 2> TryMove() override;
};

class Avatar : public Ancestor {
public:
    Avatar(int xx, int yy, int _id);
    virtual int GetID() const override { return id; }
private:
    int potions = 1;
    int id;
};