/*******************************************************
   Mosel Example Problems
   ====================== 

   file chessd.java
   ````````````````
   Executing a compiled Mosel model.
   Printing detailed solution statistics.
   
   (c) 2008 Fair Isaac Corporation
       author: S. Heipcke, Feb. 2008
********************************************************/

import com.dashoptimization.*;

public class chessd
{
  public static void main(String[] args) throws Exception
  {
    int result;
    XPRMModel model;
    XPRM xprm;
    XPRMSet prods;
    XPRMArray profit, ax;
    XPRMMPVar x;
    int[] idx = new int[1];
    double val;

    // Initialize Mosel
    xprm = new XPRM();

    // Load compiled model (.BIM file)
    model = xprm.loadModel("chess5s.bim");

    // Run model
    model.execParams = "DATAFILE=chess3.dat";
    model.run();
    System.out.println("Model execution returned: " + model.getResult());

    // Check problem status and retrieve the solution
    if (model.getProblemStatus()==XPRMModel.PB_OPTIMAL)
    {
      System.out.println("Objective value: " + model.getObjectiveValue());
    
      prods = (XPRMSet)model.findIdentifier("PRODS");
      profit = (XPRMArray)model.findIdentifier("PROFIT");
      ax = (XPRMArray)model.findIdentifier("x");

      idx = ax.getFirstIndex();        // Get the first entry of array 'ax'
                                       // (we know that the array is dense) 
      do
      {
        x = ax.get(idx).asMPVar();     // Get a variable from 'ax'
        val = profit.getAsReal(idx);   // Get the corresponding value
        System.out.println(prods.get(idx[0]) + ": " + 
                           x.getSolution() + "\t (profit: " + val + ")"); 
                                      // Print the solution value
      } while(ax.nextIndex(idx));     // Get the next index
    }

    model.reset();
  }
}
