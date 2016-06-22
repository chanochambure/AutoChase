#ifndef GAME_LANGUAGE_INCLUDE_H_INCLUDED
#define GAME_LANGUAGE_INCLUDE_H_INCLUDED

#include "GameText.h"

GameText game;

#include "ES_text.h"
#include "EN_text.h"
#include "PR_text.h"

void load_game_text()
{
    switch(language_map)
    {
        case _LANGUAGE_ES:
            load_ES_game_text();
            break;
        case _LANGUAGE_EN:
            load_EN_game_text();
            break;
        case _LANGUAGE_PR:
            load_PR_game_text();
            break;
    }
}

#endif // GAME_LANGUAGE_INCLUDE_H_INCLUDED
