#ifndef GAME_ENCRYPTOR_H_INCLUDED
#define GAME_ENCRYPTOR_H_INCLUDED

//Encryptors Object
LL::Encryptor* encryptor_files=nullptr;

void init_encryptor_files()
{
    encryptor_files=new LL::Encryptor();
    encryptor_files->set_dictionary(DICTIONARY_GAME_FILES);
    encryptor_files->add_new_key(_ENCRYPTER_DOC_KEY);
    encryptor_files->add_new_key(_ENCRYPTER_ERIK_KEY);
    encryptor_files->add_new_key(_ENCRYPTER_CHANO_KEY);
    encryptor_files->add_new_key(_ENCRYPTER_CHECHO_KEY);
    encryptor_files->add_new_key(_ENCRYPTER_CHUJU_KEY);
}

void destroy_encryptor_files()
{
    if(encryptor_files)
        delete(encryptor_files);
    encryptor_files=nullptr;
}

#endif // GAME_ENCRYPTOR_H_INCLUDED
