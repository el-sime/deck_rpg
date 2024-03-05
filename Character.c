#include "Character.h"

#include <string.h>

Character CharacterFactory(int level, CharacterType type)
{
    Character newChar;
    strcpy(newChar.Name, "Citizen");
    newChar.Level = type == PLAYER ? 1 : level;
    newChar.XP = 0;
    newChar.CharacterPoints = 0;
    newChar.SkillPoints = 0;
    newChar.Type = type;
    int hp = 90 + level * 10;
    newChar.HitPoints.baseValue = newChar.HitPoints.currentValue = newChar.HitPoints.maxValue = hp;
    int ap = 5 + level;
    newChar.ActionPoints.baseValue = newChar.ActionPoints.currentValue = newChar.ActionPoints.maxValue = ap;
    newChar.Position.x = newChar.Position.y = 0.0f;
    return newChar;
}
