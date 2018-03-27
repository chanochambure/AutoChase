#ifndef INCLUDED_GAME_ENCRYPTOR_H
#define INCLUDED_GAME_ENCRYPTOR_H

//Encryptors Object
LL::Encryptor* encryptor_files=nullptr;

void init_encryptor_files()
{
    encryptor_files=new LL::Encryptor();
    encryptor_files->set_dictionary(DICTIONARY_GAME_FILES);
    encryptor_files->add_new_key(KEY_ENCRYPTER_DOC);
    encryptor_files->add_new_key(KEY_ENCRYPTER_ERIK);
    encryptor_files->add_new_key(KEY_ENCRYPTER_CHANO);
    encryptor_files->add_new_key(KEY_ENCRYPTER_CHECHO);
    encryptor_files->add_new_key(KEY_ENCRYPTER_CHUJU);
    encryptor_files->add_new_key(KEY_ENCRYPTER_RAJI);
}

void destroy_encryptor_files()
{
    if(encryptor_files)
        delete(encryptor_files);
    encryptor_files=nullptr;
}

#endif // INCLUDED_GAME_ENCRYPTOR_H
