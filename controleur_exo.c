
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "controleur_exo.h"



OutputControler controleur(bool bouton, float radar){
    OutputControler output;
    if(bouton){
        output.systeme_freinage=true;
        Info_Msg_CU info_t;
        info_t.position[0] = 1; //Longitude
        info_t.position[1] = 1; //Latitude
        info_t.position[2] = 1; //Altitude
        info_t.dynamique[0] = 12; //Vitesse
        info_t.dynamique[1] = 20; //Direction
        output.info= info_t;
    }
    else{
        output.systeme_freinage=false;
    }
    return output;
}

// int main(){
//     OutputControler output;
//     bool bouton = true;
//     float radar = 10;
//     output = controleur( bouton,  radar);
//     printf("%d\n",output.systeme_freinage);
//     //printf("%f\n",output.info.position[3]);
// }