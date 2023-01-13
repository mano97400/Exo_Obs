#ifndef MAX_H
#define MAX_H


typedef struct Info_Msg_CU{
    float position[3];
    float dynamique[2];
} Info_Msg_CU;

typedef struct OutputControler{
    bool systeme_freinage;
    Info_Msg_CU info;
} OutputControler;


extern OutputControler controleur(bool bouton, float radar);
#endif
