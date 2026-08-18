/*******************************************************
   Mosel Example Problems
   ====================== 

   file chessd.c
   `````````````
   Executing a compiled Mosel model.
   Printing detailed solution statistics.
   
   (c) 2008 Fair Isaac Corporation
       author: S. Heipcke, Feb. 2008
********************************************************/

#include <stdio.h>
#include "xprm_rt.h"

int main(int argc, char *argv[])
{
  XPRMmodel model;
  XPRMalltypes rval, pname;
  XPRMarray profit, ax;
  XPRMmpvar x;
  XPRMset prods;
  int indices[1], result, type;
  double val;
 
  if(XPRMinit())                       /* Initialize Mosel */
    return 1;
  
  if((model=XPRMloadmod("chess5s.bim",NULL))==NULL)  /* Load a BIM file */
    return 2;
  
  if(XPRMrunmod(model,&result,"DATAFILE=chess3.dat"))  /* Run the model */
    return 3;
  
  if((XPRMgetprobstat(model)&XPRM_PBRES)!=XPRM_PBOPT)
    return 4;                         /* Test whether a solution is found */
  
  printf("Objective value: %g\n", XPRMgetobjval(model));

  type = XPRMfindident(model,"PRODS",&rval); /* Get the model object 'PRODS' */
  if((XPRM_TYP(type)!=XPRM_TYP_STRING)||     /* Check the type: */
     (XPRM_STR(type)!=XPRM_STR_SET))         /* it must be a set of strings */
       return 5;
  prods = rval.set;

  type=XPRMfindident(model,"PROFIT",&rval);  /* Get the model object 'PROFIT' */
  if((XPRM_TYP(type)!=XPRM_TYP_REAL)||       /* Check the type: */
     (XPRM_STR(type)!=XPRM_STR_ARR))         /* it must be an array of reals */
       return 6;
  profit = rval.array;

  type=XPRMfindident(model,"x",&rval);    /* Get the model object 'x' */
  if((XPRM_TYP(type)!=XPRM_TYP_MPVAR)||      /* Check the type: */
     (XPRM_STR(type)!=XPRM_STR_ARR))         /* it must be an `mpvar' array */
       return 7;
  ax = rval.array;

  XPRMgetfirstarrentry(ax, indices);      /* Get the first entry of array 'ax'
                                             (we know that the array is dense 
                                             and has a single dimension) */
  do
  {
    XPRMgetarrval(ax, indices, &x);          /* Get a variable from 'ax' */
    XPRMgetarrval(profit, indices, &val);    /* Get the corresponding value */
    printf("x(%s): %g\t (profit: %g)\n", XPRMgetelsetval(prods, indices[0], 
         &pname)->string, XPRMgetvsol(model,x), val); 
                                             /* Print the solution value */
  } while(!XPRMgetnextarrentry(ax, indices));   /* Get the next index */

  XPRMresetmod(model);  
  XPRMfree();
  return 0;
}
