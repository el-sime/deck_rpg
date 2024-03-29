#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"

typedef enum CharacterTypes {
    PLAYER,
    NPC
} CharacterType;

typedef struct Attributes {
    int baseValue;
    int currentValue;
    int maxValue;
} Attribute;

typedef struct Character {
    char Name[100];
    Vector2 Position;
    int Level;
    float XP;
    int CharacterPoints;
    int SkillPoints;
    CharacterType Type;
    Attribute HitPoints;
    Attribute ActionPoints;
} Character;

Character CharacterFactory(int level, CharacterType type);
#endif // CHARACTER_H
