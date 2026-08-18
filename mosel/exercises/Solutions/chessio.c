/*******************************************************
   Mosel Example Problems
   ====================== 

   file chessio.c
   ``````````````
   Exchanging data between model and host application
   in memory using IO drivers (dense data format).
   
   (c) 2008 Fair Isaac Corporation
       author: S. Heipcke, Feb. 2008, rev. Feb. 2017
********************************************************/

#include <stdio.h>
#include "xprm_mc.h"

#define NP 4                 
double dur[]    = {3, 2, 2, 3};    /* Input data */
double wood[]   = {1, 2, 3, 6};
double profit[] = {5,12,20,40}; 
                    
double solution[NP];               /* Array to receive solution values */

int main(int argc, char *argv[])
{
  XPRMmodel model;
  int result,i;
  char ddata[40],wdata[40],pdata[40],sol[40];    /* File names of data */
  char params[200];                /* Parameter string for model execution */
 
  if(XPRMinit())                   /* Initialize Mosel */
    return 1;
  
/* Prepare file names for 'initializations' using the 'raw' driver:         */
/*   "rawoption[,...],filename"                                             */
/*   (Here, 'filename' uses the 'mem' driver, data is stored in memory)     */
  sprintf(ddata, "mem:%p/%d", dur, (int)sizeof(dur));
  sprintf(wdata, "mem:%p/%d", wood, (int)sizeof(wood));
  sprintf(pdata, "mem:%p/%d", profit, (int)sizeof(profit));
  sprintf(sol, "mem:%p/%d", solution, (int)sizeof(solution));

                                  /* Pass file names as execution param. */
  sprintf(params, "NP=%d,DDATA='%s',WDATA='%s',PDATA='%s',SOL='%s'", NP,
          ddata, wdata, pdata, sol);

  if(XPRMexecmod(NULL, "chess5ioc.mos", params, &result, &model))
    return 2;                     /* Execute (compile/load/run) a model file */
  
  if((XPRMgetprobstat(model)&XPRM_PBRES)!=XPRM_PBOPT)
    return 3;                     /* Test whether a solution is found */
  
  printf("Objective value: %g\n", XPRMgetobjval(model));
                    
  for(i=0;i<NP;i++)               /* Display the solution */
    printf("x(%d): %g \t(profit: %g)\n", i, solution[i], profit[i]); 

  XPRMresetmod(model);  
  XPRMfree();
  return 0;
}
