using namespace std;

bool game_running=true;

#include "src/Game.h"

int main()
{
    LL_AL5::init_allegro();
    atexit(exit_game);
    if(LL_AL5::native_dialog_addon() and LL_AL5::image_addon() and LL_AL5::text_addon()
       and LL_AL5::audio_addon()and LL_AL5::primitives_addon() and LL_AL5::video_addon())
        init_game();
    return 0;
}
