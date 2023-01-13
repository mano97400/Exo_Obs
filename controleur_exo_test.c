#include <CUnit.h>
#include <Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "Automated.h"
//#include "CUnit/Console.h"

#include "controleur_exo.h"

#include <stdio.h>  // for printf

/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/

void test_case_sample(void)
{
   CU_ASSERT(CU_TRUE);
   CU_ASSERT_NOT_EQUAL(2, -1);
   CU_ASSERT_STRING_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");

   CU_ASSERT(CU_FALSE);
   CU_ASSERT_EQUAL(2, 3);
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_EQUAL("string #1", "string #2");
}

void controleur_test_obstacle(void) {
    bool button=true;
    float radar=100;
    OutputControler output = controleur(button, radar);
    CU_ASSERT(false);
}


// void controleur_test_emergency(void) {
//     bool button_emergency=true;
//     Capteurs capteurs = {
//       .capteur_radar = {200,200,200,200,200}
//     };
//     batterie = 100;
//     retour_point_de_depart = false;
//     OutputControler output = controleur(capteurs, button_emergency);
//     flag = retour_point_de_depart==true && pas_echantillonage>=DEFAULT_PAS_ECHANTILLONAGE;
//     printf("Test %d : %s\n", cnt++, flag?"Success":"Failure");
//     CU_ASSERT(output.retour_point_de_depart);
// }

/************* Test Runner Code goes here **************/

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "rover_test_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "controleur_test_obstacle", controleur_test_obstacle)) )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // Run all tests using the basic interface
//    CU_basic_set_mode(CU_BRM_VERBOSE);
//    CU_basic_run_tests();
//    printf("\n");
//    CU_basic_show_failures(CU_get_failure_list());
//    printf("\n\n");

   // Run all tests using the automated interface
   CU_automated_run_tests();
   //CU_list_tests_to_file();

   // Run all tests using the console interface
   //CU_console_run_tests();

   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
