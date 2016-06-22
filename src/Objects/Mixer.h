#ifndef MIXER_H_INCLUDED
#define MIXER_H_INCLUDED

//Audio Options
float _audio_volume=1;
void configure_audio_options(int audio)
{
    if(10<audio)
        errors.loading_interface_options.invalid_audio_number=1;
    else
        _audio_volume=audio/10.0;
}

//Mixer Object
LL_AL5::Mixer* mixer=nullptr;

void init_mixer()
{
    mixer=new LL_AL5::Mixer;
    mixer->create();
    mixer->set_default_mixer();
}

void destroy_mixer(){if(mixer)delete(mixer);mixer=nullptr;}

#endif // MIXER_H_INCLUDED
