#ifndef GAME_FONT_H_INCLUDED
#define GAME_FONT_H_INCLUDED

//FONTS
LL_AL5::Font* comic_16C=nullptr;
LL_AL5::Font* comic_24C=nullptr;
LL_AL5::Font* comic_32C=nullptr;

void init_comic_font()
{
    comic_16C=new LL_AL5::Font();
    comic_16C->set_path(COMIC_FONT_PATH);
    comic_16C->set_size(16);
    errors.initializing_fonts.loading_comic_font=!comic_16C->load_ttf_font();
    comic_24C=new LL_AL5::Font();
    comic_24C->set_path(COMIC_FONT_PATH);
    comic_24C->set_size(24);
    errors.initializing_fonts.loading_comic_font=!comic_24C->load_ttf_font();
    comic_32C=new LL_AL5::Font();
    comic_32C->set_path(COMIC_FONT_PATH);
    comic_32C->set_size(32);
    errors.initializing_fonts.loading_comic_font=!comic_32C->load_ttf_font();
}

void init_fonts()
{
    init_comic_font();
    if(errors.initializing_fonts.check())
        exit_program=1;
}

void destroy_fonts()
{
    if(comic_16C)delete(comic_16C);comic_16C=nullptr;
    if(comic_24C)delete(comic_24C);comic_24C=nullptr;
    if(comic_32C)delete(comic_32C);comic_32C=nullptr;
}

#endif // GAME_FONT_H_INCLUDED
