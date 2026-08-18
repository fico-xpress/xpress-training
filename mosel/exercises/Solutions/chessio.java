/*******************************************************
   Mosel Example Problems
   ====================== 

   file chessio.java
   `````````````````
   Exchanging data between model and host application
   in memory using IO drivers (dense data format).
   
   (c) 2008 Fair Isaac Corporation
       author: S. Heipcke, Feb. 2008
********************************************************/

import com.dashoptimization.*;

public class chessio
{
  static int NP = 4;                   // Input data
  static final double[] dur    = {3, 2, 2, 3};
  static final double[] wood   = {1, 2, 3, 6};
  static final double[] profit = {5,12,20,40}; 

                                       // Array to receive solution values
  static double[] solution = new double[NP];  
  
  public static void main(String[] args) throws Exception
  {
    int result;
    XPRMModel model;
    XPRM xprm;

    xprm = new XPRM();                 // Initialize Mosel

    xprm.compile("chess5ioj.mos");     // Compile + load model
    model = xprm.loadModel("chess5ioj.bim");

                        // Associate the Java objects with names in Mosel
    xprm.bind("DUR", dur);
    xprm.bind("WOOD", wood);
    xprm.bind("PROFIT", profit);
    xprm.bind("xsol", solution);

    model.execParams = "NP="+NP;       // Set runtime parameters
    model.run();                       // Run the model
    System.out.println("Model execution returned: " + model.getResult());

                        // Check problem status and display the solution
    if (model.getProblemStatus()==model.PB_OPTIMAL)
    {
      System.out.println("Objective value: " + model.getObjectiveValue());
      for(int i=0;i<NP;i++)
        System.out.println("x(" + (i+1) + "): " + 
                           solution[i] + "\t (profit: " + profit[i] + ")"); 
    }

    model.reset();
  }
}
