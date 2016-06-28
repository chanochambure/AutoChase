#ifndef INCLUDED_GAME_LANGUAGE_H
#define INCLUDED_GAME_LANGUAGE_H

#include "GameText.h"

GameText game;

#include "ES_text.h"
#include "EN_text.h"
#include "PR_text.h"

void load_game_text()
{
    switch(language_map)
    {
        case LANGUAGE_ES:
        {
            load_ES_game_text();
            break;
        }
        case LANGUAGE_EN:
        {
            load_EN_game_text();
            break;
        }
        case LANGUAGE_PR:
        {
            load_PR_game_text();
            break;
        }
    }
}

#endif // INCLUDED_GAME_LANGUAGE_H
