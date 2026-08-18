/* C deployment template completed with model parameter setting and
   retrieval of the optimal solution value */

#include <stdio.h>
#include "xprm_rt.h"

int main(int argc, char *argv[])
{
 int err,result;

 result=run_mosel(&err);
 switch(err)
 {
  case 0: printf("Model execution returned: %d\n",result); break;
  case 1: printf("Initialisation of Mosel failed\n"); break;
  case 2: printf("Mosel could not load the model\n"); break;
  case 3: printf("Error during execution\n"); break;
  case 4: printf("Solution is not optimal\n"); break;
 }
 return 0;
}

int run_mosel(int *err)
{
  XPRMmodel model;
  int result;
 
  /* Initialize Mosel */
  *err=XPRMinit();
  if((*err!=0)&&(*err!=32))
  {
   *err=1;
   return 0;
  }
  
  /* Load compiled model (.BIM file) */
  model = XPRMloadmod("chess5.bim",NULL);
  if (model==NULL)
  {
   *err=2;
   return 0;
  }
  
  /* Run model */
  *err = XPRMrunmod(model,&result,"DATAFILE=chess4.dat");
  if(*err!=0)
  {
   XPRMunloadmod(model);
   *err=3;
   return 0;
  }
  
  if((XPRMgetprobstat(model)&XPRM_PBRES)!=XPRM_PBOPT)
   result=4;
  else
   printf("Objective value: %g\n", XPRMgetobjval(model));

  XPRMunloadmod(model);
  
  XPRMfree();
  return result;
}
