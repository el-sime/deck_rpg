#ifndef CHARACTER_H
#define CHARACTER_H

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
    char *Name[100];
    int Level;
    float XP;
    int CharacterPoints;
    int SkillPoints;
    CharacterType Type;
    Attribute HitPoints;
    Attribute ActionPoints;
} Character;

Character CharacterFactory(int level, CharacterType type)
{
    Character newChar;
    newChar.Name = "Citizen";
    newChar.Level = type == PLAYER ? 1 : level;
    newChar.XP = 0;
    newChar.CharacterPoints = 0;
    newChar.SkillPoints = 0;
    newChar.Type = type;
    int hp = 90 + level * 10;
    newChar.HitPoints.baseValue = hp;
    newChar.HitPoints.currentValue = hp;
    newChar.HitPoints.maxValue = hp;
    int ap = 5 + level;
    newChar.ActionPoints.baseValue = ap;
    newChar.ActionPoints.currentValue = ap;
    newChar.ActionPoints.maxValue = ap;

    return newChar;
}
#endif // CHARACTER_H
