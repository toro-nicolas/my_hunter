/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The game_infos.c
*/

#include "game.h"

char *get_level_str(game_t *game)
{
    char *level_number = my_str_nbr(game->settings->level);
    char *level = malloc(sizeof(char) * (10 + my_strlen(level_number)));

    level[0] = '\0';
    my_strcat(level, "Level ");
    my_strcat(level, level_number);
    return level;
}

char *get_record_str(game_t *game)
{
    char *record_number = my_str_nbr(game->settings->record);
    char *record = malloc(sizeof(char) * (12 + my_strlen(record_number)));

    record[0] = '\0';
    my_strcat(record, "Record: ");
    my_strcat(record, record_number);
    return record;
}

char *get_score_str(game_t *game)
{
    char *score_number = my_str_nbr(game->settings->score);
    char *score = malloc(sizeof(char) * (10 + my_strlen(score_number)));

    score[0] = '\0';
    my_strcat(score, "Score: ");
    my_strcat(score, score_number);
    return score;
}

char *get_monster_life_str(monster_list_t *monster)
{
    char *monster_life_number = my_str_nbr(monster->life);
    char *monster_life = malloc(sizeof(char) * 13 +
        my_strlen(monster_life_number));

    monster_life[0] = '\0';
    my_strcat(monster_life, "Life: ");
    my_strcat(monster_life, monster_life_number);
    my_strcat(monster_life, " / 3");
    return monster_life;
}
