#ifndef INCLUDED_GAME_FONT_H
#define INCLUDED_GAME_FONT_H

//FONTS
LL_AL5::Font* comic_small=nullptr;
LL_AL5::Font* comic_normal=nullptr;
LL_AL5::Font* comic_long=nullptr;

void init_comic_font()
{
    comic_small=new LL_AL5::Font();
    comic_small->set_path(COMIC_FONT_PATH);
    comic_small->set_size(FONT_SIZE_SMALL);
    errors.initializing_fonts.loading_comic_font=!comic_small->load_ttf_font();
    comic_normal=new LL_AL5::Font();
    comic_normal->set_path(COMIC_FONT_PATH);
    comic_normal->set_size(FONT_SIZE_NORMAL);
    errors.initializing_fonts.loading_comic_font=!comic_normal->load_ttf_font();
    comic_long=new LL_AL5::Font();
    comic_long->set_path(COMIC_FONT_PATH);
    comic_long->set_size(FONT_SIZE_LONG);
    errors.initializing_fonts.loading_comic_font=!comic_long->load_ttf_font();
}

void init_fonts()
{
    init_comic_font();
    if(errors.initializing_fonts.check())
        game_running=false;
}

void destroy_fonts()
{
    if(comic_small)
        delete(comic_small);
    comic_small=nullptr;
    if(comic_normal)
        delete(comic_normal);
    comic_normal=nullptr;
    if(comic_long)
        delete(comic_long);
    comic_long=nullptr;
}

#endif // INCLUDED_GAME_FONT_H
