#ifndef INCLUDED_GAME_MIXER_H
#define INCLUDED_GAME_MIXER_H

//Audio Options
float global_volume_option=1;

void configure_audio_options(int new_audio)
{
    if(MAX_VOLUME<new_audio)
        errors.loading_interface_options.invalid_audio_number=true;
    else
        global_volume_option=new_audio/NORMAL_VOLUME;
}

//Mixer Object
LL_AL5::Mixer* mixer=nullptr;

void init_mixer()
{
    mixer=new LL_AL5::Mixer;
    mixer->create();
    mixer->set_default_mixer();
}

void destroy_mixer()
{
    if(mixer)
        delete(mixer);
    mixer=nullptr;
}

#endif // INCLUDED_GAME_MIXER_H
