
     
# Introduction to working with FICO® Xpress Mosel
## FICO Xpress Training




(C) 2001-2026 Fair Isaac Corporation. All rights reserved. 
Licensed under the [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0).



---

## Course topics

 * [Introduction, Xpress overview](#partmccintro "L58")
   * [Chapter 1 Overview of Xpress](#mccoverview "L79")
   * [Section 1.1 Xpress innovations](#secxpinnov "L147")
   * [Section 1.2 Components of FICO Xpress](#secxpcomp "L209")
   * [Chapter 2 Xpress Workbench demonstration](#chapworkbenchdemo "L282")
   * [Chapter 3 VS Code Mosel extension](#chapvscodedemo "L428")
 * [Modeling with Mosel](#partmccmod "L496")
   * [Chapter 4 Modeling basics](#mccbasics "L525")
   * [Section 4.1 A first model](#secmccfirstmod "L538")
   * [Section 4.2 Data structures and loops](#mccstruct "L869")
   * [Section 4.3 Model building style](#secmccmodstyle "L1051")
   * [Chapter 5 Accessing data sources](#mccdata "L1162")
   * [Section 5.1 The `initializations` block](#secmccinit "L1184")
   * [Section 5.2 Sparse arrays](#secmccdyn "L1349")
   * [Section 5.3 Run-time parameters](#secmccparam "L1463")
   * [Section 5.4 Using other data sources](#secmccodbc "L1627")
   * [Chapter 6 Advanced modeling topics](#mccadv "L1836")
   * [Section 6.1 Integer Programming entities supported in Xpress](#secmccvars "L1841")
   * [Section 6.2 Modeling with binary variables](#secmccbinary "L2180")
   * [Chapter 7 Programming language features](#mccprog "L2261")
   * [Section 7.1 Selections](#secmccselect "L2278")
   * [Section 7.2 Loops](#secmccloops "L2311")
   * [Section 7.3 Functions and procedures](#secmccsubr "L2395")
   * [Section 7.4 Data structures](#secmccdstruct "L2508")
   * [Section 7.5 Programming solution algorithms](#secmccheur "L2618")
   * [Chapter 8 Mosel modules and packages](#mccmodules "L2899")
   * [Section 8.1 Mosel: A modular environment](#secmodpkg "L2907")
   * [Section 8.2 Module features: solvers](#secmodsolv "L2959")
   * [Section 8.3 Interfacing with other languages](#secmosjvm "L3155")
   * [Section 8.4 Drawing user graphs](#secmodsvg "L3276")
   * [Section 8.5 Other Mosel components](#secmodother "L3347")
 * [Embedding Mosel models](#partmccembed "L3425")
   * [Chapter 9 Deploying Mosel models](#mccembedj "L3428")
   * [Section 9.1 Application design considerations](#secappdsgn "L3436")
   * [Section 9.2 Deployment options for Mosel models](#secmosdeploy "L3477")
   * [Section 9.3 Standalone executable](#secstanalone "L3525")
   * [Section 9.4 The Mosel API](#secmccapi "L3658")
   * [Section 9.5 Application development with Xpress Insight](#secmccgui "L3686")
 * [Summary and further information](#partmccsum "L3808")

## <a id="partmccintro"></a>Introduction, Xpress overview


### Overview
   * [Chapter 1 Overview of Xpress](#mccoverview "L79")
   * [Section 1.1 Xpress innovations](#secxpinnov "L147")
   * [Section 1.2 Components of FICO Xpress](#secxpcomp "L209")
   * [Chapter 2 Xpress Workbench demonstration](#chapworkbenchdemo "L282")
   * [Chapter 3 VS Code Mosel extension](#chapvscodedemo "L428")

##### Topics

 * Introduction to Xpress
 * Modeling with Mosel: 
     * Linear and Mixed Integer Programming \(LP and MIP\)
     * Accessing data sources
     * Programming language features

 * Embedding models in applications


### <a id="mccoverview"></a>Chapter 1 Overview of Xpress

   * [Section 1.1 Xpress innovations](#secxpinnov "L147")
   * [Section 1.2 Components of FICO Xpress](#secxpcomp "L209")

##### FICO Xpress Optimization

###### The most complete optimization software on the market
 * _**Xpress Solutions**_
     * Point-and-click applications designed for business users, includes **Decision Optimizer**  and **Business Outcome Simulation** .

 * _**Xpress Technology**_
     * **Xpress Insight** – Rapidly deploy analytic & optimization models as powerful applications. 
         * **Compute Interface**  for optimization execution.

     * **Python or Xpress Mosel** – develop models and apps in the preferred language.
     * **Xpress Solver** – Optimization algorithms and technologies to solve linear, mixed integer, non-linear, global and constraint programming problems.
     * _**Xpress Workbench**_ – IDE for developing optimization models, services, and solutions. 
         * Drag & Drop view configuration using **View Designer** 



  _(graphic file Intro/xpprodsolovw)_
      

##### Overview of Xpress

 * Optimization algorithms 
     * solve different classes of problems
     * built for speed, robustness and scalability

 * Modeling interfaces 
     * _Mosel_
         * formulate model and develop optimization methods using Mosel language / environment

     * _Python and object-oriented APIs_
         * build up models in your application code using APIs for C, C++, Java, .NET, Python, R, Julia, MATLAB


 * Application development 
     * _Xpress Insight_
         * deploy multi-user optimization applications




##### Optimization algorithms

 * Xpress Optimizer covers the full spectrum of mathematical optimization: 
     * _LP_ - linear programming \(simplex and barrier\)
     * _MIP_ - mixed integer programming
     * _QP/MIQP_ - quadratic programming
     * _QCQP/SOCP_ - quadratically constrained and second-order cone
     * _NLP/MINLP_ - nonlinear programming \(SLP and global\)
     * _CP_ - constraint programming \(Kalis\)



##### Overview of Xpress

 * The Xpress product suite includes: 
     * _Xpress Solver_ - optimization algorithms and programming language APIs
     * _Xpress Mosel_ - modeling language and environment
     * _Xpress Insight_ - deployment platform for optimization applications
     * _Xpress Workbench_ - IDE for developing models and Insight applications



#### <a id="secxpinnov"></a>Section 1.1 Xpress innovations


##### 43 years of business transformation with FICO Xpress Optimization

 * _Solving_
   *   1983: LP solver running on PCs
   *  1992: parallel MIP \(1997 on distributed PC/Linux networks\)
   *  1995/1996: commercial branch and cut algorithm
   *  1998: bound switching in dual simplex
   *  2003: lift-and-project cuts
   *  2009: parallel MIP heuristics
   *  2010: LP/MIP solver crosses 64-bit coefficient indexing threshold
   *  2013: automatic solver selection for NLP
   *  2014: parallel simplex
   *  2016: task-based parallel MIP
   *  2017: Barrier warm start and parallel crossover; parallel black box optimization
   *  2018: LP folding
   *  2019: iterative solution refiner
   *  2020: Machine Learning for scaling; remote execution
   *  2021: ML for cutting in tree search
   *  2023: Global optimization solver
   *  2025: PDHG; LP solving on GPU


##### 43 years of business transformation with FICO Xpress Optimization

 * _Modeling_
   *   1983: general purpose algebraic modeling language \(mp-model\)
   *  2001: algebraic modeling language combining modeling, solvingand programming \(Mosel\)
   *  2005: profiler and debugger for a modeling language
   *  2005: user-controlled parallelism at the model level
   *  2010: algebraic modeling language supporting distributed computing
   *  2012: remote invocation without local installation \(XPRD\)
   *  2014: parallel profiler and debugger; robust optimization; encryption
   *  2015: model annotations and moseldoc
   *  2016: native language support \(XPRNLS\), Unicode;  remote invocation protocol
   *  2017: cloud-based model and solution development
   *  2018: Mosel free and extensible with new solvers
   *  2019: dynamic package loading; namespaces; hashmap array type
   *  2020: cloning of models and data sharing; constants of native tpyes
   *  2022: union types; reflection


##### 43 years of business transformation with FICO Xpress Optimization

 * _Business user enablement_
   *   2012: Xpress Insight first released
   *  2015: VDL for GUI definition
   *  2016: Xpress Workbench for end-to-end optimization app development
   *  2017-18: Pre-configured applications for Machine Learning \(Pattern Discovery\), ML-driven Forecasting
   *  2019: View Designer for drag & drop UI configuration
   *  2020: Compute Interface; Python-Insight app development
   *  2022: Custom Progress Reporting


##### Our experience


Supply chain optimization; Portfolio generation + maintenance; Personnel scheduling; Production scheduling; Process industries \(blending\); Vehicle routing; Marketing optimization; Generalized assignment \( _e.g._ facility location\); Auctions; Airline operations; Electricity generation, supply and pricing; 


#### <a id="secxpcomp"></a>Section 1.2 Components of FICO Xpress


##### Mosel

 * A modeling and solving environment 
     * integration of modeling and solving
     * programming facilities
     * open, modular architecture

 * Interfaces to external data sources \( _e.g._  ODBC, host application\) provided
 * Language is concise, user friendly, high level
 * Best choice for rapid development and deployment


##### Mosel:Components and interfaces

 * _Mosel language:_ to implement problems and solution algorithms
   *  ⇒ _**model** _  or _**Mosel program** _  \(.mos file\)
   *  ⇒ compiled: _****BI** nary **M** odel** _  \(.bim file\)

 * _Mosel Model Compiler and Run-time Libraries:_ to compile, execute and access models from a programming language
   *  ⇒ _**C/C++, C\#, Java, or VBA program** _ 


##### Mosel:Components and interfaces

 * _Mosel Native Interface_ \(NI\): to provide new or extend existing functionality of the Mosel language
   *  ⇒ _**module (DSO)** _ 
   *  Modules of the Mosel distribution: 
     * _solvers:_  mmxprs, mmquad, mmxnlp, kalis, nlsolv
     * _data handling:_ mmodbc, mmoci, mmsheet, mmxml
     * _model handling, utilities:_  mmjobs, mmsystem, mmhttp, mmssl
     * _graphics, GUI:_  mmsvg, mminsight


 * _Xpress Workbench_: graphical user interface 
     * model editor, debugging, deployment to Xpress Insight


 * _Visual Studio Code_: alternative editor with Mosel language support 
     * syntax highlighting, run and debug Mosel models via the Xpress VS Code extension


 * _Tools:_ debugger, profiler, _moseldoc_ 


##### FICO Xpress Mosel extension for Visual Studio Code

 * Install from the [VS Code Marketplace](https://marketplace.visualstudio.com/items?itemName=fico-xpress.fico-xpress-mosel): search _FICO Xpress Mosel (BETA)_
 * Activates automatically when a `.mos` file is open
 * Language features: syntax highlighting, code folding, jump to definition, code completion, inline help, real-time diagnostics

  _(graphic file Intro/vscodeextension.png)_
      

##### Xpress Optimizer

 * Model is set of arrays within application source code \(C, Java, or C\#\)
 * May also input problems from a matrix file
 * Develop with standard C/C\# /Java tools
 * Provide your own data interfacing
 * Very low level, no problem structure
 * Most efficient but lose easy model development and maintenance


##### Mosel and Optimizer Consoles

 * Stand-alone command line executables with text interfaces
 * Useful for simple deployment using batch/script files
 * Available for all platforms supported by Xpress


### <a id="chapworkbenchdemo"></a>Chapter 2 Xpress Workbench demonstration


##### Xpress Workbench demonstration

 * A tool for creating, editing, and debugging Xpress Insight apps \(implemented with Mosel or Python\) and Xpress Mosel models
 * Insight Workbench enables you to do the following tasks:

 * create and edit source files \(Mosel models, Python programs and VDL views\)
 * publish Xpress Insight apps to an Insight server
 * debug an Insight scenario while it is executing within an Xpress Insight server
 * build an Xpress Insight app archive
 * debug a Mosel model in a standalone instance of Mosel
 * compile a Mosel model into a BIM file


##### Creating an Xpress Mosel project

  _(graphic file Intro/wbentry.png)_
      

##### Exploring the Workbench workspace

  _(graphic file Intro/wbworkspace.png)_
      

##### Xpress Workbench demonstration

 * Workbench panes 
     * model editor \(central window\)
     * project directory navigation and command history \(left\)
     * model output and execution log information \(bottom\)
     * debugging, deployment and collaboration information \(right\) 

| &nbsp; | &nbsp; | 
---------- | ---------- | 
| _(graphic file ButtonsWB/butpref.png)_ | Workspace preferences \(settings\). | 
| _(graphic file ButtonsWB/butwinsize.png)_ | Toggle full-screen view for logging pane. | 




##### Xpress Workbench demonstration

 * Editor 
     * code folding and breakpoint markers appear in the grey area immediately left to the text 

| &nbsp; | &nbsp; | 
---------- | ---------- | 
| _(graphic file ButtonsWB/butopen.png)_ | Open a new file/tab | 
| _(graphic file ButtonsWB/buteditor.png)_ | Subdivide and re-arrange panes in the editor window | 
| _(graphic file ButtonsWB/codefold.png)_ | Code folding for blocks of Mosel statements | 
| _(graphic file ButtonsWB/codeunfold.png)_ _(graphic file ButtonsWB/codefolded.png)_ | Unfold folded code | 
| _(graphic file ButtonsWB/debugpos.png)_ _(graphic file ButtonsWB/debugposbreak.png)_ | Line position markers during debugging | 




##### Xpress Workbench demonstration

 * Model execution 
     * the name of the model is selected in the box next to these buttons, it may be different from the model\(s\) opened in the editor 

| &nbsp; | &nbsp; | 
---------- | ---------- | 
| _(graphic file ButtonsWB/butcomp.png)_ | Compile a model. | 
| _(graphic file ButtonsWB/butrun.png)_ | Execute \(compile/load/run\) a model. | 
| _(graphic file ButtonsWB/butdebug.png)_ | Execute a model in debug mode. | 
| _(graphic file ButtonsWB/buttools.png)_ | Open Compiler Options or Run Dialog. | 

     * alternatively, use menu _Run_  to compile or run a model



##### Debugging an Xpress Mosel project

  _(graphic file Intro/wbdebug.png)_
      

##### Xpress Workbench demonstration

 * Debugger 
     * breakpoints are set by clicking onto the gray area \(left to the line number if it is displayed\) preceding each row in the editor window
     * breakpoint conditions can be added via the right mouse button menu on the breakpoint icon 

| &nbsp; | &nbsp; | 
---------- | ---------- | 
| _(graphic file ButtonsWB/breakpoint.png)_ _(graphic file ButtonsWB/breakpointdes.png)_ | Delete breakpoint/desactivated breakpoint. | 
| _(graphic file ButtonsWB/condbreak.png)_ _(graphic file ButtonsWB/condbreakdes.png)_ | Delete a conditional/desactivated conditional breakpoint. | 




##### Xpress Workbench demonstration

 * Navigating in the debugger 
     * buttons are activated during debug runs 

| &nbsp; | &nbsp; | 
---------- | ---------- | 
| _(graphic file ButtonsWB/butallbreak.png)_ _(graphic file ButtonsWB/butallbreakdes.png)_ | Activate/desactivate all breakpoints. | 
| _(graphic file ButtonsWB/butdebug.png)_ _(graphic file ButtonsWB/butstopdbg.png)_ | Start/stop the debugger. | 
| _(graphic file ButtonsWB/butresumedbg.png)_ _(graphic file ButtonsWB/butsuspenddbg.png)_ | Resume/suspend model execution. | 
| _(graphic file ButtonsWB/butstepover.png)_ | Step over an expression. | 
| _(graphic file ButtonsWB/butstepinto.png)_ | Step into an expression. | 
| _(graphic file ButtonsWB/butstepout.png)_ | Step out of an expression. | 
| _(graphic file ButtonsWB/butexcepbrk.png)_ | Don't pause on exceptions. | 




##### Xpress Workbench demonstration

 * Deployment to Xpress Insight 
     * only if Xpress Insight has been installed 

| &nbsp; | &nbsp; | 
---------- | ---------- | 
| _(graphic file ButtonsWB/butdeploy.png)_ | Publish selected model to Insight. | 
| _(graphic file ButtonsWB/butarchive.png)_ | Build an Insight app archive. | 
| _(graphic file ButtonsWB/butscendbg.png)_ | Debug a scenario. | 
| _(graphic file ButtonsWB/buttableau.png)_ | Edit Tableau workbooks. | 
| _(graphic file ButtonsWB/butscenrefr.png)_ | Refresh Insight scenario tree. | 




##### Project work \[P-1\]: Working with Workbench

 * Start up Xpress Workbench 
     * double click on a Mosel model, or
     * double click on the Workbench icon 
  _(graphic file ButtonsWB/workbenchicon.png)_
       on your desktop

 * Execute a model and observe the changes to the displays in Workbench.
 * Search for information on 'exportprob' and 'verbose' in the online help.


##### Reference material

 * The manual _Getting Started with Xpress_ introduces first time or occasional users to modeling with Mosel and BCL, or the direct Optimizer interface
 * The _Evaluators Guide_ and _Advanced Evaluators Guide_ provide a quick walk-through of the Getting Started examples and some more advanced features
 * The _Xpress Workbench Guide_ explains how to edit models with this GUI


### <a id="chapvscodedemo"></a>Chapter 3 VS Code Mosel extension


##### VS Code Mosel extension

 * An extension for Visual Studio Code that brings full Mosel language support inside the editor
 * Install from the VS Code Marketplace \(`Ctrl+Shift+X`\): search for _FICO Xpress Mosel (BETA)_
     * activates automatically when a `.mos` file is open
     * language features work without Xpress; runtime features require a valid Xpress installation

 * Installing the Mosel extension

  _(graphic file Intro/vscodemarketplace.png)_
      

##### Syntax highlighting, code folding, and navigation

 * _Syntax highlighting_: keywords, string literals, numeric constants, comments, and identifiers each receive distinct visual treatment

  _(graphic file Intro/vscodesyntax.png)_
      
 * _Code folding_: collapse and expand blocks such as `parameters`, `declarations`, `initializations`, `procedure`, and `function`
 * click the arrow in the editor gutter

 * _Jump to definition_: press `F12` on any symbol to jump to its declaration 
 * works across files linked via `uses`, `import`, or `include`



##### Code intelligence

 * _Code completion_: suggestions from the _Mosel Language Reference_ and local declarations, with full signatures and documentation in the _detail panel_

  _(graphic file Intro/vscodecompletion.png)_
      
 * _Inline help_: hover over any symbol to see its declaration and documentation without leaving the current file
 * _Real-time diagnostics_: errors and warnings appear inline from the Mosel parser, without triggering a full compile


##### Runtime features

 * A _play button_ in the editor title bar opens a quick menu to compile, run, or debug the current `.mos` file 
     * all commands are also available in the command palette \(`Ctrl+Shift+P`\)

 * _Compile_: compile Mosel source files into portable binary \(`.bim`\) format
 * _Run_: execute Mosel models with live output in a VS Code terminal
 * _Debug_: full debugging support with breakpoints, variable inspection, and expression evaluation
 * Runtime parameters can be passed via `.vscode/tasks.json` to automate compile and debug workflows

  _(graphic file Intro/vscodebuttons.png)_
      

##### Debugging a Mosel model

 * _Breakpoints_: set anywhere in Mosel code, including conditional breakpoints that trigger only when specific conditions are met
 * _Variable inspection_: inspect variables in the Variables pane and the _Variable Inspector_ panel, which expands sets and arrays into individual elements with their indices
 * _Debug Console_: evaluate Mosel expressions and built-in functions against live model state, without modifying source code

  _(graphic file Intro/vscodedebug.png)_
      

##### Reference material

 * The _Getting Started with Xpress_ manual and the _Evaluators Guide_ provide a quick introduction to modeling with Mosel
 * The _Xpress Mosel Reference Manual_ documents all language constructs and built-in functions supported by the extension
 * The [FICO Xpress Mosel extension](https://marketplace.visualstudio.com/items?itemName=fico-xpress.fico-xpress-mosel) is available on the VS Code Marketplace


## <a id="partmccmod"></a>Modeling with Mosel


### Overview
   * [Chapter 4 Modeling basics](#mccbasics "L525")
   * [Section 4.1 A first model](#secmccfirstmod "L538")
   * [Section 4.2 Data structures and loops](#mccstruct "L869")
   * [Section 4.3 Model building style](#secmccmodstyle "L1051")
   * [Chapter 5 Accessing data sources](#mccdata "L1162")
   * [Section 5.1 The `initializations` block](#secmccinit "L1184")
   * [Section 5.2 Sparse arrays](#secmccdyn "L1349")
   * [Section 5.3 Run-time parameters](#secmccparam "L1463")
   * [Section 5.4 Using other data sources](#secmccodbc "L1627")
   * [Chapter 6 Advanced modeling topics](#mccadv "L1836")
   * [Section 6.1 Integer Programming entities supported in Xpress](#secmccvars "L1841")
   * [Section 6.2 Modeling with binary variables](#secmccbinary "L2180")
   * [Chapter 7 Programming language features](#mccprog "L2261")
   * [Section 7.1 Selections](#secmccselect "L2278")
   * [Section 7.2 Loops](#secmccloops "L2311")
   * [Section 7.3 Functions and procedures](#secmccsubr "L2395")
   * [Section 7.4 Data structures](#secmccdstruct "L2508")
   * [Section 7.5 Programming solution algorithms](#secmccheur "L2618")
   * [Chapter 8 Mosel modules and packages](#mccmodules "L2899")
   * [Section 8.1 Mosel: A modular environment](#secmodpkg "L2907")
   * [Section 8.2 Module features: solvers](#secmodsolv "L2959")
   * [Section 8.3 Interfacing with other languages](#secmosjvm "L3155")
   * [Section 8.4 Drawing user graphs](#secmodsvg "L3276")
   * [Section 8.5 Other Mosel components](#secmodother "L3347")

### <a id="mccbasics"></a>Chapter 4 Modeling basics \(LP\)

   * [Section 4.1 A first model](#secmccfirstmod "L538")
   * [Section 4.2 Data structures and loops](#mccstruct "L869")
   * [Section 4.3 Model building style](#secmccmodstyle "L1051")

##### Topics

 * Definition of decision variables, constraints and objective
 * Solving with Xpress Optimizer
 * Solution output


#### <a id="secmccfirstmod"></a>Section 4.1 A first model


##### Example: Chess problem

 * A joinery makes two different sizes of boxwood chess sets.
 * The small set requires 3 hours of machining on a lathe, and the large set requires 2 hours. There are 4 lathes with skilled operators who each work a 40 hour week.
 * The small chess set requires 1 kg of boxwood, and the large set requires 3 kg. Only 200 kg of boxwood can be obtained per week.


##### Example: Chess problem

 * Each of the large chess sets yields a profit of $20, and one of the small chess sets has a profit of $5.
 * How many sets of each kind should be made each week so as to maximize profit?


##### Chess problem: Mathematical formulation

 * To model a problem mathematically we need _three key components_: 
     * _Decision variables:_ what we want to determine \(quantities to produce\)
     * _Constraints:_ limitations and requirements \(resource availability, capacity\)
     * _Objective function:_ what we want to optimize, a criterion to evaluate solution quality \(maximize profit\)
   *  

 * Formulating the chess problem:
   *   _xl_ – quantity of large chess sets made
   *   _xs_ – quantity of small chess sets made 

| &nbsp; | &nbsp; | 
---------- | ---------- | 
max | _z = 5·xs + 20·xl_ | 
s.t. | _3·xs + 2·xl ≤ 160 \(= 4·40\)_ | \(lathe time\) | 
|  | _xs + 3· xl ≤ 200_ | \(wood\) | 
|  | _xs, xl ≥ 0_ | 



##### Chess problem: Graphical solution

  _(graphic file Moselcrash/chess)_
      

##### Chess problem: Model Chess 1

```

model "Chess 1"
 uses "mmxprs"                 ! Use Xpress Optimizer for solving 
 
 declarations
  xs: mpvar                    ! Number of small chess sets
  xl: mpvar                    ! Number of large chess sets
 end-declarations

 3*xs + 2*xl <= 160            ! Constraint: limit on working hours
 xs + 3*xl <= 200              ! Constraint: raw mat. availability

 maximize(5*xs + 20*xl)        ! Objective: maximize total profit
 
end-model

```



##### Starting and ending a Mosel model

```
model "Chess 1"
   ...
end-model
```



##### Preamble

 * `uses` statement: Say we will use the Xpress Optimizer library, so that we can solve our problem
 * Options: 
     * `noimplicit`: force all objects to be declared
     * `explterm`: Use ';' to mark line ends


```
uses 'mmxprs'
options noimplicit
options explterm
```



##### Decision variables

```
declarations
  x: mpvar
  a, b, c: mpvar
  make: array(1..10, 1..20) of mpvar
  buy, sell: array(1..10) of mpvar
end-declarations
```



##### Decision variables

 * `mpvar` means _mathematical programming variable_ or _decision variable_
 * Decision variables are unknowns: they have no value until the model is run, and the optimizer finds values for the decision variables


##### Decision variables

 * In optimization problems, decision variables are often just called _variables_
 * In computer programs, a variable can be used to refer to many different types of objects
 * For instance, in Mosel models, a _program variable_ can be used to refer to a _decision variable_, as well as integers, reals,  _etc._ 


##### Bounds on decision variables

 * Variables can take values between 0 and infinity by default
 * Other bounds may be specified

```
x <= 10
y(1) = 25.5
y(2) is_free
z(2,3) >= -50
z(2,3) <= 50
```



##### Constraints
 * Have type `linctr`– linear constraint

```
declarations
  Wood: linctr
  Inven: array(1..10) of linctr
end-declarations
```



##### Constraints

 * The \`value' of a constraint entity is a linear expression of decision variables, a constraint type, and a constant term
 * Set using an assignment statement
 * Constraints can be named \(or anonymous\)

```
Wood := xs + 3*xl <= 200
```



##### Constraints

Constraints

```
Ctr(1) := 2*x(1) + 5*x(2) <= 60
Ctr(2) :=   x(1) -   x(2)  =  0
Ctr(3) := 4*x(1) - 3*x(2) >= 10

Inven(2) := stock(2) = stock(1) +
  buy(2) - sell(2)
```



##### Objective function

 * An objective function is just a constraint with no constraint type

```
declarations
  MinCost: linctr
end-declarations

MinCost := 10*x(1) + 20*x(2) + 30*x(3) + 40*x(4)
```



##### Optimization & matrix generation

 * Generate the matrix and solve the problem: 
```
minimize(MinCost)
maximize(5*xs + 20*xl)
```



 * Explicit matrix loading: 
     * performed automatically by `minimize` / `maximize`

```
loadprob(MinCost)
```



 * Matrix export: 
     * problem definition in Mosel:

```
exportprob(0, "explout", MinCost)    ! 0: Output in LP format (human readable)
```


 * problem loaded into the Optimizer: 
 * preferrable for solver tuning or debugging


```
loadprob(MinCost)
writeprob("explout.mps", "")         ! Output as MPS file
```




##### Viewing the solution

 * Can access and manipulate the solution values within the model 
```
writeln('Solution: ', getobjval)

writeln('xs = ', getsol(xs))
writeln('xl = ', getsol(xl))

write('Wood: ', getact(Wood), ' ')
writeln(getslack(Wood))
```



 * Solution values of constraints
   *  activity value + slack value = RHS


##### Viewing the solution

 * Use `case` to handle all problem states

```
case getprobstat of
  XPRS_OPT: writeln('optimal')
  XPRS_INF: writeln('infeasible')
  XPRS_UNB: writeln('unbounded')
  XPRS_UNF: writeln('unfinished')
else
  writeln('unexpected problem status!')
end-case
```



##### Project work \[C-1\]: Chess problem

 * Execute the model `chess1.mos`.
 * Add printing of the solution values.
 * Is the solution realistic/desirable?
 * Constrain the variables to take integer values only.
 * Add output of constraint activity and slack values.


##### Project work \[C-1\]: Chess problem

 * Executing model `chess1.mos` with Xpress Workbench: 
     * double click on the model file to start Workbench or open the file from within the GUI
     * click on the run button: 
  _(graphic file ButtonsWB/butrun.png)_
      

 * Model execution from the command line: 
```
   mosel exec chess1.mos
```


 * or shorter:

```
   mosel chess1
```




##### Solution: Completed model Chess 1

```

model "Chess 1 (completed)"
 uses "mmxprs"                  ! Use Xpress Optimizer for solving 
 
 declarations
  xs,xl: mpvar                  ! Decision variables
 end-declarations

 Profit:= 5*xs + 20*xl          ! Name the objective function
 Time:=   3*xs + 2*xl <= 160    ! and the constraints
 Wood:=     xs + 3*xl <= 200
 xs is_integer; xl is_integer   ! Integrality constraints

 maximize(Profit)               ! Objective: maximize total profit
 if getprobstat=XPRS_OPT then
  writeln("Solution: ", getobjval)                   ! Print objective function value
  writeln("xs: ", getsol(xs), " xl: ", getsol(xl))   ! Print solution values
  write("Time: ", getact(Time), " ", getslack(Time)) ! Constraint activity and slack
 end-if 
end-model

```



##### Solution analysis

 * What happens if machines operate 35 instead of 40 hours? 
  _(graphic file Moselcrash/chess35)_
      

 * Calculate spare capacity: `getslack`, `getactivity`
     * constraint activity + slack = RHS



#### <a id="mccstruct"></a>Section 4.2 Data structures and loops


##### Extending the example: Model Chess 2

```

 uses "mmxprs" 
 options explterm                    ! Use ';' to mark line ends

 declarations
  Allvars: set of mpvar;             ! Set of variables
  DescrV: array(Allvars) of string;  ! Descriptions of variables
  xs,xl: mpvar;
 end-declarations

 DescrV(xs):= "Small"; DescrV(xl):= "Large"; 

 Profit:= 5*xs + 20*xl;              ! Objective function
 Time:=   3*xs + 2*xl <= 160;        ! Constraints
 Wood:=     xs + 3*xl <= 200;
 xs is_integer; xl is_integer;

 maximize(Profit);
 writeln("Solution: ", getobjval);
 forall(x in Allvars) writeln(DescrV(x), ": ", getsol(x)); 

```



##### Data structures

 * _Set:_ unordered collection of objects of the same type 
     * used as _index sets_
     * special type _range sets_ \(= interval of integers\)

 * _Array:_ multidimensional table of objects of the same type 
     * used for data, decision variables, constraints
     * may be _sparse_ or _dense_



##### Arrays and loops: Model Chess 3

```
 uses "mmxprs" 

 declarations
  R = 1..2                             ! Index range
  DUR, WOOD, PROFIT: array(R) of real  ! Coefficients
  x: array(R) of mpvar                 ! Array of variables
 end-declarations

 DUR    :: [3, 2]                      ! Initialize data arrays
 WOOD   :: [1, 3]
 PROFIT :: [5, 20]
 
 sum(i in R) DUR(i)*x(i) <= 160        ! Constraint definition
 sum(i in R) WOOD(i)*x(i) <= 200      
 forall(i in R) x(i) is_integer
 maximize(sum(i in R) PROFIT(i)*x(i))
 writeln("Solution: ", getobjval) 
```



##### Data declaration

```
 declarations
  NWEEKS = 20                      ! Integer constant
  DATA_DIR = 'c:/data'             ! String constant
  NPROD: integer                   ! Integer variable
  SCOST: real                      ! Real variable
  DIR: string                      ! String variable
  IF_DEBUG: boolean                ! Boolean variable
  
  PRODUCTS = {"P1", "P2", "P4"}    ! Constant set of string
  S: set of integer                ! Variable set of integer
  R: range                         ! Range of integers
  COST: array(1..3,1..4) of real   ! Array of real
 end-declarations
```



##### Data initialization

```
NPROD:= 50
SCOST:= 5.4
DIR:= 'c:/data'
IF_DEBUG:= true

S:= {10, 0, -5, 13}
R:= 1..NPROD
COST:: [11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34]
```



##### Summations

 * Sum up an array of variables in a constraint

```
Ctr1:= sum(p in 1..10) (RES(p)*buy(p) + sell(p)) <= 100

Ctr2:= sum(p in PRODUCTS) (buy(p) + sum(r in 1..5) make(p,r)) <= 100

Ctr3:= sum(p in 1..NP) (2*CAP(p)*buy(p)/10 +
  SCAP(p)*sell(p)) <= MAXCAP
```



##### Loops

 * Use a loop to assign an array of constraints

```
forall(t in 2..NT)
  Inven(t):= bal(t) = bal(t-1) + buy(t) - sell(t)
```



##### Loops

 * Use `do`/`end-do` to group several statements into one loop

```
forall(t in 1..NT) do
  MaxRef(t):= sum(i in PRODUCTS)
    use(i,t) <= MAXREF(t)

  Inven(t):= store(t) = store(t-1) + buy(t) - use(t)
end-do
```



##### Loops

 * Can nest `forall` statements

```
forall(t in 1..NT) do
  MaxRef(t):= sum(i in 1..NI) use(i,t) <= MAXREF(t)

  forall(i in 1..NI)
    Inven(i,t):= store(i,t) = store(i,t-1) + buy(i,t) - use(i,t)
end-do
```



##### Conditions

 * May include conditions in sums or loops

```
forall(c in 1..10 | CAP(c)>=100.0)
  MaxCap(c):=
    sum(i in 1..10, j in 1..10 | i<>j)
      TECH(i,j,c)*x(i,j,c) <= MAXTECH(c)
```



##### Mosel statements

 * Can extend over several lines and use spaces
 * However, a line break acts as an expression terminator
 * To continue an expression, it must be cut after a symbol that implies continuation \( _e.g._  + - , \) 
     * alternatively, when defining the `explterm` option line ends are marked with ';'



#### <a id="secmccmodstyle"></a>Section 4.3 Model building style


##### Model building style

 * You should aim to build a model with sections in this order 
     * _constant data_: declare, initialize
     * _all non-constant objects_: declare
     * _variable data_: initialize / input / calculate
     * _decision variables_: create, specify bounds
     * _constraints_: declare, specify
     * _objective_: declare, specify, optimize



##### Model building style

 * In the formulation of \(LP, MIP,...\) optimization models it is very important to distinguish between 
     * _known_ values 
         * data, parameters,  _etc._ 

     * and _unknown_ values 
         * decision variables


 * All constraints must be linear expressions of the variables


##### Model building style

 * Suggestion: name objects as follows 
     * known values \(data\) using upper case
     * unknown values \(variables\) using lower case
     * constraints using mixed case
 so that it is easy to distinguish between them, and see that constraints are indeed linear


##### Model building style

 * Variables are _actions_ that your model will prescribe
 * Use verbs for the names of variables 
     * this emphasizes that variables represent \`_what to do_' decisions

 * Indices are the _objects_ that the actions are performed on
 * Use nouns for the names of indices


##### Model building style

 * Using named index sets/ranges 
     * improves the readability of a model
     * makes it easier to apply the model to different sized data sets
     * makes the model easier to maintain
     * may speed up your model



##### Model building style

 * Name constraints 
     * helps document them \(also describe them with a comment when you declare them\)
     * allows Mosel and the Optimizer to produce better error and log messages
     * you cannot obtain solution information or refer to anonymous constraints
     * you cannot change, hide or delete anonymous constraints



##### Model building style

 * Declare objects 
     * You don't have to\!
     * Allows the compiler to detect syntax errors more easily
     * Mosel's guessed declaration doesn't always work
     * A form of rigour and documentation
     * An opportunity for a descriptive comment



##### Model building style

 * Try to include \`Min' or \`Max' in the name of your objective function
 * An objective function called \`Obj' is not very helpful when taken out of context\!


##### Model building style

 * Comments are essential for a well written model
 * Always use a comment to explain what each parameter, data table, variable, and constraint is for when you declare it
 * Add extra comments to explain any complex calculation  _etc._ 


##### Model building style

 * Comments in Mosel:

```
declarations
  PRODUCTS = 1..NP           ! Set of products
  TIMES = 1..NT              ! Set of time periods
  make: array(PRODUCTS, TIMES) of mpvar
                             ! Amount of p produced in time t
  sell: array(PRODUCTS, TIMES) of mpvar
                             ! Amount of p sold in time t
end-declarations

(! And here is a multi-line
  comment !)    forall(t in TIMES)
```



### <a id="mccdata"></a>Chapter 5 Accessing data sources

   * [Section 5.1 The `initializations` block](#secmccinit "L1184")
   * [Section 5.2 Sparse arrays](#secmccdyn "L1349")
   * [Section 5.3 Run-time parameters](#secmccparam "L1463")
   * [Section 5.4 Using other data sources](#secmccodbc "L1627")

##### Topics

 * Text files
 * Excel spreadsheets
 * ODBC
 * Sparse data


##### Separation of problem logic and data

 * Typically, the model logic stays constant once developed, with the data changing each run
 * Editing the model can create errors, expose intellectual property, and is impractical for industrial size data
 * It makes good sense to fix the model and obtain data from their source


#### <a id="secmccinit"></a>Section 5.1 The `initializations` block


##### Data input from file: Chess 4

```
  uses "mmxprs" 
 
  declarations
   PRODS = 1..2                             ! Index range
   DUR, WOOD, PROFIT: array(PRODS) of real  ! Coefficients
   x: array(PRODS) of mpvar                 ! Array of variables    
  end-declarations

  initializations from "chess.dat"          ! Read data from file
   DUR WOOD PROFIT                    !!! chess.dat: PROFIT: [5 20]  
  end-initializations                 !!!            DUR: [3 2]
                                      !!!            WOOD: [1 3]
  sum(i in PRODS) DUR(i)*x(i) <= 160        ! Constraint definition
  sum(i in PRODS) WOOD(i)*x(i) <= 200      
  forall(i in PRODS) x(i) is_integer
  maximize(sum(i in PRODS) PROFIT(i)*x(i))  ! Solve the problem
  writeln("Solution: ", getobjval)
```



##### Data file `chess.dat`

 * Every data item/table has a _label_, its identifier
 * Single line comments \(marked with '\!'\)

```
! Data file for 'chess4.mos'

DUR:    [3 2]
WOOD:   [1 3]
PROFIT: [5 20] 
```



##### Sparse data format

 * Every data entry specified with its index tuple
 * Can read data from one labeled data source into several Mosel data tables at once 
     * data tables must have identical indices


```
initializations from 'chess.dat'
 [DUR, WOOD, PROFIT]  as 'ChessData'
end-initializations
```



##### Sparse data format

 * Format of data file with several data values in one labeled data range \(use a `*` for a missing data value\)

```
! chess.dat

ChessData: [
  (1) [3 1 5]
  (2) [2 3 20]
]
```



##### Writing data out to text files

 * You can write out values in an analogous way to reading them in using `initializations to`
 * To write out the solution values of variables, or other solution values \(slack, activity, dual, reduced cost\) you must first put the values into a data table, or alternatively, use `evaluation of`


##### Writing data out to text files

```
declarations
  x_sol: array(PRODS) of real
end-declarations

forall(i in PRODS)
  x_sol(i) := getsol(x(i))

initializations to 'result.dat'
  x_sol
end-initializations

! Alternatively:
initializations to 'result.dat'
  evaluation of array(i in PRODS) x(i).sol as 'x_sol'
  evaluation of getobjval as 'obj_sol'
end-initializations
```



##### Free format text files

```
! Redirect output to 'result.dat' (no screen display), appending to existing contents
fopen("result.dat", F_OUTPUT+F_APPEND)          

forall(i in PRODS)
  writeln(i, ": ", getsol(x(i))

fclose(F_OUTPUT)          ! Terminate output redirection
```



##### Free format text files

```
! 'tee:' redirects output to 'result.dat' and also displays on screen/standard output
fopen("tee:result.dat&", F_OUTPUT+F_APPEND)          

forall(i in PRODS)
  writeln(i, ": ", getsol(x(i))

fclose(F_OUTPUT)          ! Terminate output redirection
```



##### Project work \[C-2\]: Arrays and index sets

 * Modify the model `chess4.mos` to use indices of type `string`.
 * Execute this new model `chess4s.mos` with data set `chess2.dat`.
 * Output the solution values to file `sol.dat` using `initializations to`.
 * Modify the models further to read the contents of the index set from file \(`chess3.dat`, `chess4.dat`\).


##### String indices and data output:Chess 4s

```
  uses "mmxprs" 
 
  declarations
   PRODS = {"small", "large"}              ! Index set
   DUR, WOOD, PROFIT: array(PRODS) of real ! Coefficients
   x: array(PRODS) of mpvar                ! Array of variables
  end-declarations

  initializations from "chess2.dat"        ! Read data from file
   DUR WOOD PROFIT    
  end-initializations  
  
  sum(i in PRODS) DUR(i)*x(i) <= 160       ! Constraint definition
  sum(i in PRODS) WOOD(i)*x(i) <= 200      
  forall(i in PRODS) x(i) is_integer
  maximize(sum(i in PRODS) PROFIT(i)*x(i)) 

  initializations to "sol.dat"             ! Write solution to file
   evaluation of array(i in PRODS) x(i).sol as 'x'
  end-initializations

```



#### <a id="secmccdyn"></a>Section 5.2 Sparse arrays


##### Sparse arrays

 * Mosel provides a user friendly and efficient means of modeling mathematical programming problems
 * Objects such as _sparse arrays_ and _variable index sets_, together with efficient loops and sums, allow large scale models to be written easily, and execute quickly


##### Sparse arrays

 * Mosel allows you to use _variable_ index sets 
     * elements may be assigned to variable index sets throughout the model,  _e.g._ , by inputting data from file or using ODBC
     * so the elements may be _defined at run-time_, not compile-time



##### Sparse arrays

 * Declare variable index sets 
     * entries are defined later


```
declarations
  PRODS: set of string
  TYPE: set of integer
  PERIODS: range          ! = set of contiguous integers
end-declarations
```

 * Declare sparse arrays \(`dynamic` or `hashmap`\)

```
declarations
  COST: dynamic array(PRODS,PERIODS) of real
  HARD: dynamic array(PRODS) of real
  use: dynamic array(PRODS,PERIODS) of mpvar
  MinHard: dynamic array(PERIODS) of linctr
end-declarations
```



##### Sparse arrays

 * Use sparse arrays 
     * to size data tables automatically when the data is read in
     * to initialize the index values automatically when the data is read in
     * to conserve memory when storing sparse data
     * to eliminate index combinations without using conditions each time



##### Sparse arrays

 * Don't use sparse arrays 
     * when you can use an ordinary \(dense\) array instead
     * when storing dense data, and you can size the data table and initialize the indices in some other way
   *  \(sparse arrays are slower and use more memory than a static array when storing dense data\)



##### Sparse arrays

 * Array declaration using variable index sets 
     * not the same as explicitly `dynamic` arrays
     * for more efficient handling, Mosel will try to transform these arrays into static arrays after their initialization with data


```
declarations
  COST: array(PRODS,PERIODS) of real
  HARD: array(PRODS) of real
  use: array(PRODS,PERIODS) of mpvar
  MinHard: array(PERIODS) of linctr
end-declarations
```



##### Sparse arrays

 * Initialize sparse arrays from external sources \(text files, databases, ...\) 
     * must use _sparse format_ \(= data values + indices\)
     * this is so Mosel can work out the values of the indices
     * reading in the data array initializes _both_ the _index values_ and the _data values_ at the same time



##### Sparse arrays of decision variables

 * An entry of a sparse array is only created when a value is assigned to it
 * Decision variables don't get created, because you don't assign values to them
 * To create decision variables in a sparse array, use the `create` procedure

```
declarations
  PERIODS: range          ! = set of contiguous integers
  COST: dynamic array(PERIODS) of real
  use: dynamic array(PERIODS) of mpvar
end-declarations

(...)          ! Read in COST data etc

forall(t in PERIODS | exists(COST(t))) create(use(t))
```



##### Sparse arrays of decision variables
 * Use the explicit `dynamic` \(or `hashmap`\) marker in the array declaration if you want to use `create` to control exactly which elements get created


#### <a id="secmccparam"></a>Section 5.3 Run-time parameters


##### Run-time parameters

 * Parameters 
     * a special type of constant
     * default value may be overriden at run-time


```
 parameters
  DATA_DIR = 'c:/data'
  DEBUG = true
  NUM_RECORDS = 1000
 end-parameters
```



##### Run-time parameters

 * The value in the model is used by default
 * A different value may be given at run-time 
     * in Workbench, an alternative value may be entered after the filename in the _Command_  input box of the output pane
     * when running a Mosel model from an application, an alternative value can be set in the parameters string



##### Run-time parameters

 * A `parameters` section must come at the top of the model 
     * after any `uses` or `options` statements
     * before any other statements



##### Run-time parameters

 * Parameters are especially useful for passing directories/paths into the model 
     * all files referenced in the model should use a directory parameter
     * otherwise, Mosel may not be able to find the file when the model is deployed \(the default path differs when run from an application\)
     * use '`+`' to join strings



##### Run-time parameters

 * Specifying directory paths 
     * preferably use '/' as directory separator


```
parameters
 DIR = '.'
end-parameters

fopen(DIR+'/cap.dat', F_INPUT)
...
fclose(F_INPUT)
...
initializations from DIR+'/cost.dat'
 ...
```



##### Project work \[C-3\]: Run-time parameters

 * In models `chess5.mos` and `chess5s.mos` turn the data file name into a run-time parameter.
 * Re-run your model `chess5s.mos` with the larger data set `chess3.dat` without changing the filename in the model.


##### Project work \[C-3\]: Run-time parameters

 * Setting runtime parameters within Workbench:      * specify the parameter value after the filename in the _Command_  input box of the output pane:

```
   chess5s.mos DATAFILE='chess3.dat'
```



 * Setting runtime parameters in Visual Studio Code: 
     * add the parameter to the `args` list in your `.vscode/launch.json` run configuration:

```
   "args": ["DATAFILE='chess3.dat'"]
```



 * Runtime parameters from the command line: 
```
   mosel exe chess5s.mos DATAFILE='chess3.dat'
```


 * or:

```
   mosel chess5s DATAFILE='chess3.dat'
```




##### Run-time parameters:Chess 5

```
  uses "mmxprs" 
  parameters
   FILENAME="chess.dat"                 ! Name of the data file
  end-parameters
 
  declarations
   PRODS: range                         ! Index range
   DUR, WOOD, PROFIT: array(PRODS) of real ! Coefficients
  end-declarations

  initializations from FILENAME         ! Read data from file
   DUR WOOD PROFIT    
  end-initializations  

  declarations
   x: array(PRODS) of mpvar             ! Array of variables
  end-declarations
  
  sum(i in PRODS) DUR(i)*x(i) <= 160    ! Constraint definition
  sum(i in PRODS) WOOD(i)*x(i) <= 200      
  forall(i in PRODS) x(i) is_integer 
```



##### Run-time parameters: Chess 5

```
  uses "mmxprs" 
  parameters
   FILENAME="chess.dat"                 ! Name of the data file
  end-parameters
 
  declarations
   PRODS: range                         ! Index range
   DUR, WOOD, PROFIT: array(PRODS) of real ! Coefficients
  end-declarations

  initializations from FILENAME         ! Read data from file
   DUR WOOD PROFIT    
  end-initializations  

  declarations
   x: array(PRODS) of mpvar             ! Array of variables
  end-declarations
  
  sum(i in PRODS) DUR(i)*x(i) <= 160    ! Constraint definition
  sum(i in PRODS) WOOD(i)*x(i) <= 200      
  forall(i in PRODS) x(i) is_integer
  maximize(sum(i in PRODS) PROFIT(i)*x(i)) 
```



#### <a id="secmccodbc"></a>Section 5.4 Using other data sources


##### Using other data sources

 * The `initializations` block can work with many different data sources and formats thanks to the notion of _**I/O drivers** _ 
 * I/O drivers for physical data files: mmodbc.odbc, mmsheet.excel, mmoci.oci, mmetc.diskdata
 * Other drivers available,  _e.g._  for data exchange in memory
 * Change of the data source = change of the I/O driver, no other modifications to your model


##### Data exchange with spreadsheets

 * Software-specific driver _excel_  for MS Excel 
     * use the _mmsheet.excel_  driver in `initializations` blocks
     * no driver setup required \(works with standard Excel installation\)
     * add the prefix `"mmsheet.excel:"` to the file name

 * Module _mmsheet_  also defines alternative, platform-independent spreadsheet drivers \(_xls_ , _xlsx_ , _csv_ \) that do not rely on Excel
     * usage:
   *   `"mmsheet.xlsx:mydatafile.xlsx"` `"mmsheet.csv:mydatafile.csv"`



##### Data exchange with MS Excel

```
initializations from 'mmsheet.xls:chess.xls'
 [DUR, WOOD, PROFIT]  as 'ChessData'   ! 'ChessData': range area is B4:E8
end-initializations 

initializations to 'mmsheet.xls:chess.xls'
  x_sol as 'grow;ChessSol'             ! 'ChessSol': first row of output area: H5:I5
end-initializations
```


  _(graphic file Moselcrash/chessxls.png)_
      

##### Referencing Excel ranges

 * Named ranges 
     * select the desired area with your mouse
     * MS Excel 2010 and newer: use the menu _Formulas » Define Name_  to enter the range name

 * Direct reference to worksheet cells 
     * standard notation: ` [DUR, WOOD, PROFIT] as '[Sheet1$B5:E8]'`
     * row-column notation: ` [DUR, WOOD, PROFIT] as '[Sheet1$R5C2:R8C5]'`

 * Select columns within a range 
     * using numbers: ` [PROFIT,DUR] as 'ChessData(# 1,# 4,# 2)'`
     * using header text: ` [PROFIT,DUR] as 'skiph;[Sheet1$B4:E8](ITEM,PROFIT,DUR)'`



##### Spreadsheet drivers

 * Module _mmsheet_  defines alternative spreadsheet drivers: _xls_ , _xlsx_  and _csv_ 

|  | ___excel___ | ___xls/xlsx___ | ___csv___ | 
---------- | ---------- | ---------- | ---------- | 
__File type__ | physical file | physical file | extended file | 
__Supported platforms__ | Windows | Windows, Linux, Mac | all Xpress platforms | 
__Requirements__ | Excel + open interactive session | none, can be used remotely | none, can be used remotely | 
__File creation for output__ | no | yes | yes | 
__Output writing mechanism__ | on-screen display without saving if application running, otherwise data saved into file | data saved into file | data saved into file | 
__Named ranges__ | yes | yes | no | 
__Multiple worksheets__ | yes | yes | no | 
__VBA Macros__ | yes | no | no | 



##### Data transfer using ODBC

 * Use the _mmodbc_  module 
     * use the _odbc_  driver in `initializations` blocks, or
     * write out the corresponding SQL commands:
         * set up an ODBC data connection to the specific data source
         * input data using SQL statements
         * disconnect


 * The _mmodbc_  module includes SQLite \(lightweight filebased database\) on all platforms supported by Mosel 
     * no additional software installation or configuration required



##### Reading data via ODBC
 * SQLite database \('ChessData' = data table\): 
```
initializations from 'mmodbc.odbc:debug;chess.sqlite'
 [DUR, WOOD, PROFIT]  as 'ChessData'
end-initializations
```



 * Access database: 
```
initializations from 'mmodbc.odbc:debug;chess.accdb'
...
```


 * Note that if you use ODBC to access components of MS Office \(such as Access\), the bitness of your Xpress installation must match the bitness of MS Office



##### Data export to a database

```
initializations to 'mmodbc.odbc:debug;chess.sqlite'
  x_sol as 'ChessSol'
end-initializations
```


 * Before every new run, delete the data from the previous run in the destination range/table
 * Otherwise the new results will either be appended to the existing ones or, if 'PRODS' has been defined as key field in a database, the insertion will fail


##### Data exchange with Oracle

 * Software-specific driver _oci_  for Oracle databases 
     * use _mmoci_  module
     * setup: Oracle's Instant Client package must be installed on the machine running the Mosel model
     * in `initializations` blocks replace `"mmodbc.odbc:"` by `"mmoci.oci:"` in the preceding examples
     * supports SQL statements \(replace the prefix `SQL` by `OCI`\)



##### SQL

 * The I/O driver _odbc_  generates automatically the SQL commands required to connect to the database/spreadsheet
 * For advanced uses, module _mmodbc_  also defines most standard SQL commands directly for the Mosel language


##### SQL

 * Data input using SQL statements 
```
uses 'mmodbc'

setparam('SQLverbose', true)
setparam('SQLdebug', true)
SQLconnect('chess.mdb')
SQLexecute('select * from ChessData', [DUR, WOOD, PROFIT])
SQLexecute('delete from ChessSol')
SQLdisconnect
```



 * Data output using SQL: 
     * create a new data table and write out data 
```
SQLexecute('create table ChessSol (PName VARCHAR(20), Sol DOUBLE)')
SQLexecute('insert into ChessSol (PName,Sol) values (?,?)', x_sol)
```



     * or may use SQL `update` \(if supported by database\) 
```
SQLupdate('select PName,Sol from ChessSol', x_sol)
```





##### SQL

 * Using SQL, much more is possible... 
```
SQLexecute('select * from Cost where Legs >= 4', COST)

SQLexecute('select count(*) from PRODS', SIZE)

SQLexecute('select CostS,CostM,CostL from CostData 
where (CostS<2 and CostL>10) order by Products,ProdCode', PRICE)
```




##### Project work \[C-4\]: Spreadsheets and databases
 * Re-run your model `chess5.mos` with the Excel file `chess.xls`
 * Re-run your model `chess5.mos` with the SQLite file `chess.sqlite`


##### Summary

 * We have seen that it is possible to completely separate the data and the model
 * The model specifies the logic of the problem, without any reference to its size
 * The model can be applied to any data instance, simply by providing data files


##### Reference material

 * Refer to the _Mosel User Guide_ for a detailed introduction to working with Mosel.
 * The book _Applications of optimization with Xpress-MP_ provides a large collection of examples models from different application areas. 
     * see files under examples/mosel/ApplBook

 * See the whitepaper _Using ODBC and other database interfaces with Mosel_ for further detail on data handling.
 * The whitepaper _General file handling in Mosel_ gives an overview of available I/O drivers and their uses.


### <a id="mccadv"></a>Chapter 6 Advanced modeling topics

   * [Section 6.1 Integer Programming entities supported in Xpress](#secmccvars "L1841")
   * [Section 6.2 Modeling with binary variables](#secmccbinary "L2180")

#### <a id="secmccvars"></a>Section 6.1 Integer Programming entities supported in Xpress


##### Integer Programming entities supported in Xpress

 * _Binary variables_
     * can take either the value 0 or the value 1 \(do/ don't do variables\)
     * model logical conditions

```
x(4) is_binary
```




##### Integer Programming entities supported in Xpress

 * _Integer variables_
     * can take only integer values
     * used where the underlying decision variable really has to take on a whole number value for the optimal solution to make sense

```
x(7) is_integer
```




##### Integer Programming entities supported in Xpress

 * _Semi-continuous variables_
     * can take either the value 0, or a value between some lower limit and upper limit
     * help model situations where if a variable is to be used at all, it has to be used at some minimum level

```
x(2) is_semcont 6   ! A 'hole' between 0 and 6, then continuous
```




##### Integer Programming entities supported in Xpress

 * _Semi-continuous integer variables_
     * can take either the value 0, or an integer value between some lower limit and upper limit
     * help model situations where if a variable is to be used at all, it has to be used at some minimum level, and has to be integer

```
x(3) is_semint 7    ! A 'hole' between 0 and 7, then integer
```




##### Integer Programming entities supported in Xpress

 * _Special Ordered Sets of type one (SOS1)_
     * an ordered set of variables at most one of which can take a non-zero value
     * single choice among several possibilities

 * _Special Ordered Sets of type two (SOS2)_
     * an ordered set of variables, of which at most two can be non-zero, and if two are non-zero these must be consecutive in their ordering
     *  _e.g._  approximation of non-linear functions with a piecewise linear function



##### SOS definition

 * `WEIGHT` array determines the ordering of the variables: 
```
MYSOS:= sum(i in IRng) WEIGHT(i)*x(i) is_sosX
```

 where `is_sosX` is either `is_sos1` or `is_sos2`


##### SOS definition

 * Formulation alternative: set `S` of set members, linear constraint `L` with ordering coefficients \(= _reference row entries_\): 
```
makesos1(S,L); makesos2(S,L)
```


 * must be used if the coefficient `WEIGHT(i)` of an intended set member is zero


 * **Note:**  the ordering coefficients must all be distinct \(or else they are not doing their job of supplying an order\!\)


##### Integer Programming entities supported in Xpress

 * _Piecewise linear expressions_ can be used in place of SOS2 formulations
 * Definition of piecewise linear expressions in Mosel: 

|  _(graphic file IntroMIPForm/pricebrincug1)_ * _For all forms of `pwlin` the curve continues beyond the first and last breakpoint, prolongating the first and last segments to infinity_ 

 * specification as _list of slopes_ with associated intervals:  implementation with Mosel: only points of slope changes are specified, start value is 0: 
```
y = pwlin(x, union(i in 1..2) [B(i)], union(i in 1..3) [SLOPE(i)])
```



 * specification as _list of piecewise linear segments_ with associated intervals: 
```
y = pwlin(union(i in 1..3) [pws(B(i-1), CB(i-1)+SLOPE(i)*(x-B(i-1)))])
```



 * specification as _list of points_: 
```
y = pwlin(x, union(i in 0..3) [B(i), CB(i)])
```





##### Integer Programming entities supported in Xpress

 * _Indicator constraints_ are logic constraints that associate a binary variable _b_  with a linear \(or nonlinear\) constraint _C_ . They take one of these two forms 
   *  'if _b=1_  then _C_ ', in symbols: _b → C_ , 
   *  or
   *  'if _b=0_  then _C_ ', in symbols: _not\(b\) → C_ 

 * Xpress Optimizer accepts indicator constraints in MI\(NL\)P models.


##### Indicator constraints

 * Definition of indicator constraints in Mosel: 
```
 declarations
  R=1..2
  x,b: array(R) of mpvar
 end-declarations  

 forall(i in R) b(i) is_binary  ! Variables for indicator constraints
 C:= x(2)<=5                    ! Auxiliary constraint defintion
 indicator(1, b(1), x(1)+x(2)>=12)   ! b(1)=1 ->  x(1)+x(2)>=12
 indicator(-1, b(2), C)              ! b(2)=0 ->  x(2)<=5
 C:=0                           ! Delete auxiliary constraint def.
```




##### Integer Programming entities supported in Xpress

 * _General constraints_
     * specific constraint relations that are recognized by MIP solvers 
         * **piecewise linear** : can be used in place of SOS2 formulations
         * **absolute**  value, **minimum**  value, **maximum**  value of discrete or continuous decision variables
         * logical constraints: '**and** ' and '**or** ' over binary variables

     * direct statement of \(nonlinear\) relations without any need for reformulation via auxiliary binary variables on the modeling level
     * solver chooses the most appropriate representation and applies presolving to these constructs

 * _Mosel implementation_: 
     * modeling constructs `pwlin`, `fmin`, `fmax`, `abs` \(of type `nlctr`\) for the formulation of MIP require _mmxnlp_  but will result in MIP models if they only involve linear expressions
     * a second form of logical constraints \(type `logctr`\) based on Boolean variables \(type `boolvar`\) is implemented via _mmxprs_ 

```
 uses "mmxnlp" 
 abs(x(1)-2*x(2)) <= 10                     ! Absolute value constraint
 MinCtr:= fmin(union(i in R) [x(i)]) >= 5   ! Minimum value constraint
 y = fmax(x(3), 20, 2*x(1)-z)               ! Maximum value constraint
```




##### Absolute value: MIP formulations

###### Example:  _v = &#124;x<sub>1</sub>-x<sub>2</sub>&#124;_ 
 * Formulation via binary variables: 
```
  uses "mmxprs"
  declarations
    C: real                  ! Must know bounds on x(i): assume 0 <= x(i) <= C
    x: array(1..2) of mpvar
    v, d: mpvar
    C1a, C1b, C2a, C2b, C3a, C3b: linctr
  end-declarations

  d is_binary                ! d = 0 if x(1)-x(2) is positive
                             ! d = 1 if x(2)-x(1) is positive 
  C1a:= x(1) <= C            ! x(1) >= 0 automatically
  C1b:= x(2) <= C            ! x(2) >= 0 automatically
  C2a:= v >= x(1) - x(2)
  C2b:= v <= x(1) - x(2) + 2*C*d
  C3a:= v >= x(2) - x(1)
  C3b:= v <= x(2) - x(1) + 2*C*(1-d)
```




##### Absolute value: MIP formulations

###### Example:  _v = &#124;x<sub>1</sub>-x<sub>2</sub>&#124;_ 
 * Formulation via indicator constraints 
```
  uses "mmxprs"
  declarations
    x: array(1..2) of mpvar
    v, d: mpvar
    C2a, C3a: linctr
    C2b, C3b: logctr
  end-declarations

  d is_binary 
  C2a:= v >= x(1) - x(2)
  C3a:= v >= x(2) - x(1)
  C2b:= indicator(-1, d, v <= x(1) - x(2))     ! d = 0 ->  x(1)-x(2) is positive 
  C3b:= indicator(1, d, v <= x(2) - x(1))      ! d = 1 ->  x(2)-x(1) is positive 
```




##### Absolute value: MIP formulations

###### Example:  _v = &#124;x<sub>1</sub>-x<sub>2</sub>&#124;_ 
 * Formulation as general constraint 
```
  uses "mmxnlp"
  declarations
    x: array(1..2) of mpvar
    v: mpvar
    C2: nlctr
  end-declarations

  C2:= v = abs(x(1) - x(2))
```




##### Maximum value: MIP formulations

###### Example:  _u = max\(x<sub>1</sub>,x<sub>2</sub>,x<sub>3</sub>\)_ 
 * Formulation via binary variables: 
```
  uses "mmxprs"
  declarations
    R = 1..3
    L,U: array(R) of real        ! Must know bounds on x(i): assume L(i) <= x(i) <= U(i)
    x,d: array(R) of mpvar
    u: mpvar
   end-declarations

  forall(i in R) d(i) is_binary  ! d(i) = 1 iff x(i) is maximum
  Umax:= max(i in R) U(i)        ! Largest upper bound

  forall(i in R) do
    L(i) <= x(i); x(i) <= U(i)
    u >= x(i)
    u <= x(i) + (Umax-L(i))*(1-d(i))
  end-do

  sum(i in R) d(i) >= 1
```




##### Maximum value: MIP formulations

###### Example:  _u = max\(x<sub>1</sub>,x<sub>2</sub>,x<sub>3</sub>\)_ 
 * Formulation via indicator constraints 
```
  uses "mmxprs"
  declarations
    R = 1..3
    x,d: array(R) of mpvar
    u: mpvar
  end-declarations

  forall(i in R) d(i) is_binary       ! d(i) = 1 iff x(i) is maximum

  forall(i in R) do
    u >= x(i)
    indicator(1, d(i), u <= x(i))     ! d(i) = 1 -> u <= x(i)
  end-do

  sum(i in R) d(i) >= 1
```




##### Maximum value: MIP formulations

###### Example:  _u = max\(x<sub>1</sub>,x<sub>2</sub>,x<sub>3</sub>\)_ 
 * Formulation as general constraint 
```
  uses "mmxnlp"
  declarations
    R = 1..3
    x: array(R) of mpvar
    u: mpvar
  end-declarations

  u = fmax(union(i in R) [x(i)] )
```




##### Logical constraints over Boolean variables

 * Mosel defines the type _boolvar_ for the formulation of logical constraints 'and' ,'or', 'not' 
     * the resulting constraints are directly sent to the solver as general constraints on binary variables ⇒ MIP model

```
 public declarations
   R=1..5
   bv: array(R) of boolvar
   LC1, LC2: logctr
 end-declarations  

 bv(1) and not bv(5)      ! Simple clause, same as:  bv(1) and (not bv(5)) = true
 bv(3) = (not bv(4))      ! Association of clauses

! Defining a logic expression (not recorded in the constraint store)
 LC1:= and(i in 1..3) bv(i) or and(i in 4..5) not bv(i)
 LC1:= LC1=true          ! Turn expression into a constraint

! A named logic expression (this defines a constraint)
 LC2:= (or(i in 1..3) not bv(i)) = false
```




#### <a id="secmccbinary"></a>Section 6.2 Modeling with binary variables


##### Logical conditions

 * Projects A, B, C, D
 * Binary variables _a_ , _b_ , _c_ , _d_ 
     * do at most 3 projects: _a+b+c+d ≤ 3_ 
     * must do D if A done: _d ≥ a_ 
     * can only do C if both A and B done:
   *   _c ≤ \(a + b\)/2_ 
   *   _c ≤ a, c ≤ b_ 



##### Disjunctions

 * Either _5 ≤ x ≤ 10_ 
   *  or _80 ≤ x ≤ 100_ 

 * Introduce a new variable:
   *   _ifupper_ : 0 if _5 ≤ x ≤ 10_ ; 1 if _80 ≤ x ≤ 100_ 

| &nbsp; | &nbsp; | 
---------- | ---------- | 
_x ≤ 10 + \(100 - 10\) · ifupper_ | \[1\] | 
_x ≥ 5 + \( 80 - 5\) · ifupper_ | \[2\] | 


 * Generalizes to
   *  either _5 ≤ ∑<sub>i</sub> A<sub>i</sub> x<sub>i</sub>≤ 10_ 
   *  or _80 ≤ ∑<sub>i</sub> A<sub>i</sub> x<sub>i</sub>≤ 100_ 

| &nbsp; | &nbsp; | 
---------- | ---------- | 
_∑<sub>i</sub> A<sub>i</sub> x<sub>i</sub>≤ 10 + 90 · ifupper_ | \[1\] | 
_∑<sub>i</sub> A<sub>i</sub> x<sub>i</sub>≥ 5 + 75 · ifupper_ | \[2\] | 



##### Project work \[K-3\]: Logical constraints

 * Take a look at the capital budgeting model in `capbgt.mos`: the objective is to determine the most profitable choice among 8 possible projects, subject to limited resources \(personnel and capital\)
 * Formulate the following additional constraints: 
     1. P1 can only be done if P2 is done
     2. P1 can only be done if P3 and P6 are done
     3. It is not possible to do both P5 and P6
     4. Either P1 and P2 must be done or P3 and P4 \(but not both pairs\).

 * Try to find alternative formulation options for constraint 4. 
     * Compare the matrices resulting from different implementations \(using `writeprob` with option "l"\).



##### Solution

```
! p1 can only be done if p2 is done
 select(2) >= select(1)

! p1 can only be done if p3 and p6 are done
 (select(3) + select(6))/2 >= select(1)
! Or:
 select(3) >= select(1)
 select(6) >= select(1)

! It is not possible to do both p5 and p6
 select(5) + select(6) <= 1

! Either p1 and p2 must be done or p3 and p4 (but not both pairs).
 select(1) = select(2); select(3) = select(4)
 select(1) + select(2) = 2 - (select(3) + select(4))
```



##### Reference material

 * See the _MIP formulations and linearizations_ quick reference guide for an overview of MIP variable types \(including indicator constraints\) and their use.


### <a id="mccprog"></a>Chapter 7 Programming language features

   * [Section 7.1 Selections](#secmccselect "L2278")
   * [Section 7.2 Loops](#secmccloops "L2311")
   * [Section 7.3 Functions and procedures](#secmccsubr "L2395")
   * [Section 7.4 Data structures](#secmccdstruct "L2508")
   * [Section 7.5 Programming solution algorithms](#secmccheur "L2618")

##### Mosel: A programming environment

 * Selections
 * Loops
 * Set operations
 * Subroutines
 * Data structures


#### <a id="secmccselect"></a>Section 7.1 Selections


##### Selections

 * `if`
```
if A >= 20 then
  x <= 7
elif A <= 10 then
  x >= 35
else
  x = 0
end-if
```



 * `case`
```
case A of
  -1000..10 : x >= 35
  20..1000 :  x <= 7
  12, 15 :    x = 1
  else        x = 0
end-case
```



 * **Try it yourself:**  open `examples/select.mos`


#### <a id="secmccloops"></a>Section 7.2 Loops


##### Loops

 * `forall [do]`
 * `while [do]`
 * `repeat until`


##### Example: Prime numbers

 * Implements the \`Sieve of Eratosthenes'. 

_SNumbers = \{2,...,L\}_ 
   *   _n:= 2_ 
   *  repeat
   *    while _\(n ∉ SNumbers\)   n:= n+1_ 
   *    _SPrime:= SPrime∪\{n\}_ 
   *    _i:= n_ 
   *    while _\(i≤L\)_ 
   *    _SNumbers:= SNumbers\\\{i\}_ 
   *    _i:= i+n_ 
   *  until _SNumbers = \{\}_ 



##### Example: Prime numbers

```
model Prime
 parameters
  LIMIT=100                   ! Search for prime numbers in 2..LIMIT
 end-parameters

 declarations
  SNumbers: set of integer    ! Set of numbers to be checked
  SPrime: set of integer      ! Set of prime numbers
 end-declarations

 SNumbers:={2..LIMIT}
 writeln("Prime numbers between 2 and ", LIMIT, ":")
```



##### Example: Prime numbers

```
 n:=2
 repeat
   while (not(n in SNumbers)) n+=1
   SPrime += {n}                ! n is a prime number
   i:=n
   while (i<=LIMIT) do          ! Remove n and all its multiples
     SNumbers-= {i}
     i+=n
   end-do
 until SNumbers={}

 writeln(SPrime)
 writeln(" (", getsize(SPrime), " prime numbers.)")
end-model
```



##### Operations on sets

 * Set operators include 
     * union: `+`
     * intersection: `*`
     * difference: `-`

 * Logical expressions using sets include 
     * subset: `Set1 <= Set2`
     * superset: `Set1 >= Set2`
     * equals: `Set1 = Set2`
     * not equals: `Set1 <>  Set2`
     * element of: `'Oil5' in  Set1`
     * not element of: `'Oil5' not in  Set1`



#### <a id="secmccsubr"></a>Section 7.3 Functions and procedures


##### Functions and procedures

 * Similar structure as `model`, including the  `declarations` blocks
 * Terminated by `end-function` or `end-procedure`
 * Function defines `returned` with its return value
 * `forward` declaration
 * Overloading possible \(each version with a different number or types of arguments\)


##### Example: Quick Sort algorithm

 1. Choose a middle value _v_  for partitioning \(here: _v = (min+max)/2_ \)
 2. Divide the list into two parts \`left' \(all elements _x<v_ \) and \`right' \(all elements _x>v_ \)
 3. Repeat from 1. for lists \`left' and \`right'


##### Example: Quick Sort algorithm

```
model "Quick Sort"
 parameters
  LIM=50
 end-parameters
                        ! Declare procedures that are defined later
 forward procedure swap(L:array(range) of integer, i,j:integer)
 forward procedure qsort(L:array(range) of integer)
 forward procedure qsort(L:array(range) of integer, s,e:integer)

 declarations
  T:array(1..LIM) of integer
 end-declarations
                        ! Generate randomly an array of numbers
 forall(i in 1..LIM) T(i):=round(.5+random*LIM)
 writeln(T)             ! Print the unsorted array

 qsort(T)               ! Sort the array
 writeln(T)             ! Print the sorted array
```


 * **Try it yourself:**  open `examples/mosel/Programming/qsort.mos` in your Xpress installation


##### Example: Quick Sort algorithm

```
model "Quick Sort"
 parameters
  LIM=50
 end-parameters

 declarations           ! Declare procedures that are defined later
  procedure swap(L:array(range) of integer, i,j:integer)
  procedure qsort(L:array(range) of integer)
  procedure qsort(L:array(range) of integer, s,e:integer)
 
  T:array(1..LIM) of integer
 end-declarations
                        ! Generate randomly an array of numbers
 forall(i in 1..LIM) T(i):=round(.5+random*LIM)
 writeln(T)             ! Print the unsorted array

 qsort(T)               ! Sort the array
 writeln(T)             ! Print the sorted array
```



##### Example: Quick Sort algorithm

```
! Start of the sorting process 
 procedure qsort(L:array(r:range) of integer)
  qsort(L,getfirst(r),getlast(r))
 end-procedure
 
! Sorting routine
 procedure qsort(L:array(range) of integer, s,e:integer)
  v:=L((s+e) div 2)
  i:=s; j:=e
  repeat
   while(L(i)<v) i+=1
   while(L(j)>v) j-=1
   if i<j  then
    swap(L,i,j)
    i+=1; j-=1
   end-if
  until i>=j
  if j<e and s<j: qsort(L,s,j)
  if i>s and i<e: qsort(L,i,e)
 end-procedure
```



##### Example: Quick Sort algorithm

```
! Swap the positions of two numbers in an array
 procedure swap(L:array(range) of integer, i,j:integer)
  k:=L(i)
  L(i):=L(j)
  L(j):=k
 end-procedure

end-model
```



#### <a id="secmccdstruct"></a>Section 7.4 Data structures


##### Data structures

 * `array`
 * `set`
 * `list`
 * `record`
 * ... and any combinations thereof,  _e.g._ , 
```
S: set of list of integer
A: array(range) of set of real
```




##### List

 * Collection of objects of the same type
 * May contain the same element several times
 * Order of list elements is specified by construction
 * Handling: `cuthead`, `splittail`, `reverse`... 
```
declarations
  L: list of integer
  M: array(range) of list of string
end-declarations

L:= [1,2,3,4,5]
M:: (2..4)[['A','B','C'], ['D','E'], ['F','G','H','I']]
```




##### Record

 * Finite collection of objects of any type
 * Each component of a record is called a 'field' and is characterized by its name and its type 
```
declarations
  ARC: array(ARCSET:range) of record
    Source,Sink: string      ! Source and sink of arc
    Cost: real               ! Cost coefficient
  end-record
end-declarations

ARC(1).Source:= "B"
ARC(3).Cost:= 1.5
```




##### User types

 * Treated in the same way as the predefined types of the Mosel language
 * New types are defined in `declarations` blocks by specifying a type name, followed by `=`, and the definition of the type 
```
declarations
  myreal = real
  myarray = array(1..10) of myreal
  COST: myarray
end-declarations
```




##### User types

 * Typical uses
     * shorthand for repetitions in declarations
     * naming records 
```
declarations
  arc = record
    Source,Sink: string      ! Source and sink of arc
    Cost: real               ! Cost coefficient
  end-record
  A: arc
  ARC: array(ARCSET:range) of arc
end-declarations
```





##### Summary: Language features

 * _Data structures:_ array, set, list, record
 * _Selections:_ if-then-\[elif-then\]-\[else\], case
 * _Loops:_ forall-\[do\], while-\[do\], repeat-until
 * _Operators:_
     * standard arithmetic operators
     * aggregate operators \(sum, prod, and, or, min, max, union, intersection\)
     * set operators

 * _Subroutines:_ functions, procedures
   *  \(forward declaration, overloading\)


##### Reference material

 * See Part \`II. Advanced language features' of the _Mosel User Guide_ for a comprehensive collection of Mosel model examples demonstrating programming tasks.


#### <a id="secmccheur"></a>Section 7.5 Programming solution algorithms


##### Mosel: A solving environment

 * No separation between \`modeling statements' and \`solving statements'
 * Programming facilities for pre/postprocessing, algorithms
 * Principle of incrementality
 * Not solver-specific
 * Possibility of interaction with solver\(s\)


##### Example: Variable fixing heuristic

 * Consider the following heuristic for solving problems with binary or integer variables 
     * solve the linear relaxation
     * for each binary \(or integer\) variable, check the solution value: if it is integer valued, fix the variable
     * solve the resulting MIP problem \(with the remaining unfixed MIP variables\)

 * Can you see why this heuristic may fail to find the true optimal solution?


##### Example: Variable fixing heuristic

 * Any MIP solution of the modified problem is a feasible MIP solution of the original problem
 * However, it is possible that the modified problem has no feasible MIP solutions, even if the original problem is feasible
 * ⇒Extended heuristic: 
     * solve the problem using the fixing heuristic
     * if a solution was found, store it and record the objective value
     * restore the original problem
     * if an objective value was recorded, use it as a cut-off
     * solve the original MIP problem

 * Use the solution found by the heuristic to reduce the size of the second MIP search 
     * if the heuristic finds a good solution quickly, the overall search time can be reduced considerably



##### Example: Variable fixing heuristic \(implementation features\)

 * Performing partial optimizations 
     * solve the LP relaxation of a MIP 
```
setparam("XPRS_MIPSTOPSTAGE", XPRS_MIPSTOPSTAGE_INITIALRELAXATION)
minimize(MinCost)
```



     * solve the remaining MIP problem 
```
setparam("XPRS_MIPSTOPSTAGE", XPRS_MIPSTOPSTAGE_NONE)
minimize(XPRS_CONT, MinCost)
```



 * Fixing variables and changing bounds      * variables can be fixed by changing the bounds 
```
setub(x(i,j), 0)
setlb(x(i,j), 1)
```



 * Program split into several source files \(via `include`\)


##### Example: Variable fixing heuristic \(main file\)

---
Note: See `examples/mosel/Solving/fixbv.mos` in your Xpress installation
---

```

model Coco
 uses "mmxprs"

 include "fixbv_pb.mos"                ! Model definition
 include "fixbv_solve.mos"             ! Algorithm

 solution:=solve
 writeln("The objective value is: ", solution)

end-model

```



##### Example: Variable fixing heuristic \(model\)

```

declarations
 RF=1..2                ! Range of factories (f)
 RT=1..4                ! Range of time periods (t)
 (...)
 openm: array(RF,RT) of mpvar
end-declarations

(...)
forall(f in RF,t in 1..NT-1) Closed(f,t):= openm(f,t+1) <= openm(f,t)
forall(f in RF,t in RT) openm(f,t) is_binary

```



##### Example: Variable fixing heuristic \(algorithm\)

```

function solve:real
 declarations
  osol: array(RF,1..2) of real
  bas: basis
 end-declarations

 setparam("XPRS_PRESOLVE",0)
 setparam("zerotol", 5.0E-4)     ! Set Mosel comparison tolerance
 setparam("XPRS_MIPSTOPSTAGE", XPRS_MIPSTOPSTAGE_INITIALRELAXATION)
 maximize(MaxProfit)             ! Solve the root LP
 savebasis(bas)                  ! Save the basis

 forall(f in RF, t in 1..2) do   ! Fix some binary variables
  osol(f,t):= getsol(openm(f,t))
  if osol(f,t) = 0 then 
   setub(openm(f,t), 0.0)
  elif osol(f,t) = 1 then
   setlb(openm(f,t), 1.0)
  end-if
 end-do
```



##### Example: Variable fixing heuristic \(algorithm\)

```
 setparam("XPRS_MIPSTOPSTAGE", XPRS_MIPSTOPSTAGE_NONE)
 maximize(XPRS_CONT,MaxProfit) ! Solve modified problem
 ifgsol:=false
 if getprobstat=XPRS_OPT then  ! If a solution was found 
  ifgsol:=true
  solval:=getobjval            ! Save solution value
 end-if

 forall(f in RF, t in 1..2)    ! Reset variable bounds
  if((osol(f,t) = 0) or (osol(f,t) = 1)) then
   setlb(openm(f,t), 0.0);  setub(openm(f,t), 1.0)
  end-if

 loadbasis(bas)                ! Load previously saved basis
 if ifgsol:                    ! Set cutoff to best known solution
  setparam("XPRS_MIPABSCUTOFF", solval)  
 maximize(MaxProfit)           ! Solve original problem
 returned:= if(getprobstat=XPRS_OPT, getobjval, solval)
end-function

```



##### Implementing heuristics

 * It is also possible to save / load complete MIP solutions 
```
declarations
  mipsols: mpsol
end-declarations
...         ! Define &  solve a MIP
savemipsol(mipsols)
...         ! Modify &  reload the MIP
if loadmipsol(mipsols) <> 0 then
  writeln("Problem with loading MIP solution")
end-if
...         ! Solve the MIP problem
```




##### Implementing heuristics

 * Can provide incomplete or infeasible solutions ⇒ use `addmipsol`
```
declarations
  mipsols: array(set of mpvar) of real
end-declarations
...         ! Generate a heuristic solution
mipsols(x(i)):= Heur_sol_val                  ! Set solution values
...         ! (Re)load the MIP
addmipsol("SolutionID", mipsols)
setcallback(XPRS_CB_SOLNOTIFY, ->myheurlog)   ! Optional callback
...         ! Solve the MIP problem

procedure myheurlog(id:string, status:integer)
  writeln("Optimiser loaded solution ", id, " status=", status)
end-procedure
```




##### Implementing heuristics

 * MIP local search heuristics exploit feasible solutions loaded into the Optimizer
 * Parameter setting to reinforce use of these heuristics \(not impacted by _HEUREMPHASIS_ set to 0\): 
```
         ! Exploit user solution in local search 
         ! (-1:automatic, 0:disable, 1-3:increasingly higher effort)
setparam("XPRS_USERSOLHEURISTIC", 3)
```




##### Example: Variable fixing heuristic \(alternative alg.\)

```

function solve:real
 declarations
  osol: array(RF,1..2) of real
  bas: basis
  heurSol: array(mpvar) of real  ! Heuristic solution for MIP
 end-declarations

 setparam("XPRS_PRESOLVE",0)
 setparam("zerotol", 5.0E-4)     ! Set Mosel comparison tolerance
 setparam("XPRS_MIPSTOPSTAGE", XPRS_MIPSTOPSTAGE_INITIALRELAXATION)
 maximize(MaxProfit)             ! Solve the root LP
 savebasis(bas)                  ! Save the basis

 forall(f in RF, t in 1..2) do   ! Fix some binary variables
  osol(f,t):= getsol(openm(f,t))
  if osol(f,t) = 0 then 
   setub(openm(f,t), 0.0)
  elif osol(f,t) = 1 then
   setlb(openm(f,t), 1.0)
  end-if
 end-do
```



##### Example: Variable fixing heuristic \(alternative alg.\)

```
 setparam("XPRS_MIPSTOPSTAGE", XPRS_MIPSTOPSTAGE_NONE)
 maximize(XPRS_CONT,MaxProfit) ! Solve modified problem
 ifgsol:=false
 if getprobstat=XPRS_OPT then  ! If a solution was found 
  ifgsol:=true
  solval:=getobjval            ! Save solution value
  savemipsol(heurSol)          ! Save the solution
 end-if

 forall(f in RF, t in 1..2)    ! Reset variable bounds
  if((osol(f,t) = 0) or (osol(f,t) = 1)) then
   setlb(openm(f,t), 0.0);  setub(openm(f,t), 1.0)
  end-if

 loadbasis(bas)                ! Load previously saved basis
 if ifgsol:                    ! Load the heuristic solution
  addmipsol("startsol", heurSol)  
 maximize(MaxProfit)           ! Solve original problem
 returned:= if(getprobstat=XPRS_OPT, getobjval, solval)
end-function

```



##### Reference material

 * A Mosel implementation of the variable fixing heuristic is discussed in Chapter _8. Heuristics_  of the _Getting Started_ manual.


### <a id="mccmodules"></a>Chapter 8 Mosel modules and packages

   * [Section 8.1 Mosel: A modular environment](#secmodpkg "L2907")
   * [Section 8.2 Module features: solvers](#secmodsolv "L2959")
   * [Section 8.3 Interfacing with other languages](#secmosjvm "L3155")
   * [Section 8.4 Drawing user graphs](#secmodsvg "L3276")
   * [Section 8.5 Other Mosel components](#secmodother "L3347")

#### <a id="secmodpkg"></a>Section 8.1 Mosel: A modular environment


##### Mosel: A modular environment

 * Open architecture: 
     * possibility to define language extensions via _packages_ or _modules_ without any need to modify the core of the Mosel language



##### Mosel modules

  _(graphic file Intro/products)_
      

##### Mosel: A modular environment

 * _Package_ = library written in the Mosel language 
     * making parts of Mosel models re-usable
     * deployment of Mosel code whilst protecting your intellectual property
     * similar structure as models \(keyword `model` is replaced by `package`\), compiled in the same way
     * included with the `uses` or `import` statement
     * definition of new types, subroutines, symbols, control parameters
     * see examples in the _Mosel User Guide_



##### Mosel: A modular environment

 * _Module_ = dynamic library written in C
     * modules of the Mosel distribution: 
         * solver interfaces: Xpress Optimizer \(LP, MIP, QP\), Xpress NonLinear, Xpress Kalis \(CP\)
         * accessing data sources: ODBC, OCI, spreadsheets, XML/JSON, S3
         * system commands; model handling; graphics; HTTP
         * interfaces to external software: R, Matlab, Java, Python

     * write your own modules for 
         * connecting to external software
         * time-critical tasks
         * defining new types, subroutines, operators, I/O drivers, control parameters, symbols




##### Some highlights of module features

 * Interaction with external programs during their execution \(callback functions\)
 * Access to other solvers and solving paradigms \(NLP, CP\)
 * Executing code written with other languages \(Java, R, Python\)
 * Implementation of graphical applications \(_mmsvg_ , Xpress Insight\)


#### <a id="secmodsolv"></a>Section 8.2 Module features: solvers


##### Module mmxprs:Using callback functions

```
uses "mmxprs"

declarations
 x: array(1..10) of mpvar
end-declarations
 
procedure printsol
 writeln("Solution: ", getsol(Objective))
 forall(i in 1..10) writeln("x(", i, ")=", getsol(x(i)))
end-procedure

setcallback(XPRS_CB_INTSOL, ->printsol)
```


  _(graphic file Talks/callback)_
      

##### Module mmxprs:Using callback functions

```
uses "mmxprs"

declarations
 x: array(1..10) of mpvar
end-declarations
 
public procedure printsol
 writeln("Solution: ", getsol(Objective))
 forall(i in 1..10) writeln("x(", i, ")=", getsol(x(i)))
end-procedure

setcallback(XPRS_CB_INTSOL, "printsol")
```


  _(graphic file Talks/callback)_
      
 * **Try it yourself:**  open `examples/printsol.mos`


##### Module mmxnlp: Solving an NLP

 * What is the greatest area of a polygon of N sides and a diameter of 1?


| _(graphic file WB/polygon5.png)_ _(graphic file WB/polygon12.png)_ 

 * **Try it yourself:**  open `examples/mosel/Nonlinear/polygon1_graph.mos` in your Xpress installation


##### Module mmxnlp: Solving an NLP

```
model "Polygon"
 uses "mmxnlp"

 declarations
  N=5
  RN=1..N
  Area: nlctr
  rho, theta: array(RN) of mpvar
  D: array(RN,RN) of nlctr
 end-declarations

 forall(i in 1..N-1) do       ! Initialization of NLP variables
  rho(i) >= 0.1; rho(i) <= 1  
  setinitval(rho(i), 4*i*(N + 1 - i)/((N+1)^2))
  setinitval(theta(i), M_PI*i/N)
 end-do
```



##### Module mmxnlp: Solving an NLP

```
 forall(i in 1..N-2, j in i+1..N-1) ! Third side of all triangles 
  D(i,j):= rho(i)^2 + rho(j)^2 -
           rho(i)*rho(j)*2*cos(theta(j)-theta(i)) <= 1

                                    ! Vertices in increasing order 
 forall(i in 2..N-1) theta(i) >= theta(i-1) +.01
 
 theta(N-1) <= M_PI                 ! Boundary conditions

 Area:=                             ! Objective: sum of areas 
  (sum(i in 2..N-1) (rho(i)*rho(i-1)*sin(theta(i)-theta(i-1))))*0.5
 setparam("xnlp_solver", 0)         ! Select the SLP solver 
 maximize(Area)                     ! Solve the problem

 writeln("Area = ", getobjval)
end-model
```



##### Module kalis: Constraint Programming

 * Example: jobshop scheduling 
     * schedule the production of a set of jobs on a set of machines. Every job is produced by a sequence of tasks, each of these tasks is processed on a different machine. A machine processes at most one job at a time.

 * Implementation with high-level modeling objects \(tasks and resources\)


##### Module kalis: Constraint Programming

```
model "Job Shop"
 uses "kalis"
 
 declarations
  JOBS = 1..NJ                           ! Set of jobs
  MACH = 1..NM                           ! Set of resources
  RES: array(JOBS,MACH) of integer       ! Resource use of tasks
  DUR: array(JOBS,MACH) of integer       ! Durations of tasks

  res: array(MACH) of cpresource         ! Resources
  task: array(JOBS,MACH) of cptask       ! Tasks
 end-declarations

 ...             ! Initialize the data

 HORIZON:= sum(j in JOBS, m in MACH) DUR(j,m)
```



##### Module kalis: Constraint Programming

```
 forall(j in JOBS) getend(task(j,NM)) <= HORIZON

! Setting up the resources (capacity 1)
 forall(m in MACH)
  set_resource_attributes(res(m), KALIS_UNARY_RESOURCE, 1)

! Setting up the tasks (durations, resource used) 
 forall(j in JOBS, m in MACH)
  set_task_attributes(task(j,m), DUR(j,m), res(RES(j,m)))

! Precedence constraints between the tasks of every job
 forall (j in JOBS, m in 1..NM-1)
  setsuccessors(task(j,m), {task(j,m+1)})

! Solve the problem &  print solution
 if cp_schedule(getmakespan)<>0 then
  writeln("Total completion time: ", getsol(getmakespan))
 end-if
end-model 
```



##### Module nlsolv: Using alternative LP/MIP/NLP solvers

 * _Functionality of _nlsolv_ _
     * export a problem in the `.nl` file format
     * solve it using an external solver supporting this format 
         * no interaction during solving

     * retrieve solution values back into the Mosel model

 * _nlsolv_  does _not_ include any solver 
     * separate download/installation for every solver 
         * for example: 

     * solver choice is configured via parameters 
         * `NL_SOLVER` always needs to be set
         * use `NL_SOLVERPATH` if executable is not on the path, or executable name is different from solver prefix in `NL_SOLVER`, or executable requires additional options \(define a batch script
         * optional: specific solver settings in `NL_OPTIONS`

```
setparam("NL_SOLVER", "xpress")
setparam("NL_SOLVERPATH", "amplxpress.exe")
```





##### Project work \[K-1\]: Alternative solvers

 * Inspect the examples of alternative solver types that are provided with the Xpress release: 
     * NLP: open and run model `examples/mosel/Nonlinear/moonshot_graph.mos`
     * RO: open and run model `examples/mosel/Robust/roadworks_graph.mos`
     * CP: open and run model `examples/solver/kalis/UG/freqasgn_graph.mos`



#### <a id="secmosjvm"></a>Section 8.3 Interfacing with analytics tools and other languages


##### Interfacing with analytics tools and other languages

 * Traditional embedding: 
     * a host program launches the execution of a Mosel model
     * data exchange in memory
     * Mosel library APIs: C/C++, Java, C\#, Python, VBA; Matlab


```
import com.dashoptimization.*;

public class folioobj
{
 public static void main(String[] args) throws Exception
 {
  XPRM mosel;
  XPRMModel model;

  mosel = new XPRM();                                  // Initialize Mosel
  mosel.compile("foliodata.mos");                      // Compile the model
  model = mosel.loadModel("foliodata.bim");            // Load compiled model
  model.run();                                         // Run the model
  if(model.getProblemStatus()==XPRMModel.PB_OPTIMAL)   // Access solution info
    System.out.println("Objective value: " + model.getObjectiveValue());
 }
}
```



##### Interfacing with analytics tools and other languages

 * New trend: 
     * use other languages from within a Mosel model
     * data exchange in memory
     * Mosel modules: R, Java, Python3; Mosel NI: C/C++



##### Interfacing with analytics tools and other languages

 * _R:_ pass data to R, execute R functions, retrieve data from R

```
 uses "r"

 declarations
  SHARES = 1..10                     ! Set of shares
  DATES: set of string               ! Historical dates
  VAR: array(SHARES,SHARES) of real  ! Variance/covariance matrix of estimated returns
  OPEN: array(SHARES,DATES) of real  ! Historical share value at market opening
  CLOSE: array(SHARES,DATES) of real ! Historical share value at market closing
 end-declarations
! ... Initialize data ...

! **** Perform some statistics using R **** 
 Rset('open',OPEN)                   ! Copy array to R environment
 Rset('close',CLOSE)
 writeln("Covariances at market openings:")
 Rprint('cov(t(open))')              ! Print covariance of share value at market openings
! Calculate and retrieve covariance of mean value in Mosel array VAR
 Rgetarr('cov(t((open+close)/2))', VAR)
```



##### Interfacing with analytics tools and other languages

 * _Python:_ pass data to Python, execute Python scripts, retrieve data from Python

```
 uses "python3"

! **** Perform some statistics using Python ****
! Copy data to Python environment
 initialisations to PY_IO_GLOBAL_VAR
  SHARES as 'shares'
  DATES as 'dates'
  OPEN as 'open'
  CLOSE as 'close'
 end-initialisations
 
! Import functions from Python scripts
 pyrun('mosel_numpy.py')
 pyrun('folioqp_py.py')
! Calculate and retrieve covariance of mean value
 pyexec('var = covariance_of_mean(open, close, shares, dates)')
 initialisations from PY_IO_GLOBAL_VAR
  VAR as 'var'
 end-initialisations
```



##### Interfacing with analytics tools and other languages

 * _Java:_ pass data to Java, execute Java code, retrieve result

```
 uses "mosjvm"

 ! **** Perform some statistics in Java **** 

 ! Abort model if we encounter a Java exception
  setparam('jvmabortonexception', true)

 ! Tell Java to look for classes in working directory
  setparam('jvmclasspath', getparam('workdir'))

 ! Call Java code to calculate the variance
  forall(s1,s2 in SHARES)
    VAR(s1,s2):= jvmcallreal('CalcCov.calcValue', 
                             array(t in DR) OPEN(s1,DTIDX(t)), 
                             array(t in DR) OPEN(s2,DTIDX(t)))
```



#### <a id="secmodsvg"></a>Section 8.4 Package mmsvg: Drawing user graphs


##### Package mmsvg: Drawing user graphs

```

model "Schedule"
 uses "mmsvg", "mmsystem"

 declarations
  MACHINES=6; JOBS=6
  job: array(1..JOBS) of integer
  curmachine, curjobs, n1, n2, n3: integer
 end-declarations

! Define graph colours
 forall(j in JOBS) do
   job(j):="J"+j
   svgaddgroup(job(j), "Job "+j)
   svgsetstyle(SVG_STROKE, SVG_GRAY)
   svgsetstyle(SVG_FILL, SVG_CURRENT)
 end-do

 svgsetgraphscale(10)                        ! Scale graph size
 svgsetgraphlabels("Time", "Machines")       ! Set axes labels  
```



##### Package mmsvg: Drawing user graphs

```
 fopen("schedule.dat", F_INPUT)
 forall (i in 1..MACHINES) do
  readln(n1, n2)                     ! Read machine no. &  no. of jobs
  writeln("Machine ", n1, " Jobs:", n2) 
  curmachine:= n; curjobs:= n2
  forall(j in 1..curjobs) do
   readln(n1, n2, n3)                ! Read job no., start &  finish times
   writeln("On machine ", curmachine, " job ", n1, 
           " starts at ", n2, " and finishes at ", n3) 
   svgaddrectangle(job(n1),n2,curmachine*10,n3-n2,0.5*10) 
   svgaddtext(job(n1),(3*n2+n3)/4,curmachine*10+1,"Job "+n1) 
   svgsetstyle(svggetlastobj,SVG_COLOR,SVG_BLACK) 
  end-do
 end-do
 fclose(F_INPUT)

 svgsave("gantt.svg")                    ! Optional: save graphic to file
 svgrefresh                              ! Display the graph...
 svgwaitclose                            ! ...until window is closed 
end-model 
```



##### Package mmsvg: Drawing user graphs

  _(graphic file WB/schedwb.png)_
      

##### Project work \[K-2\]: SVG graphic

 * Add a pie chart into the model `chess5i.mos`
     * Hint: take a look at the example implementation provided in the file `pie.mos` under the subdirectory examples/mosel/Graphing of your Xpress installation
     * Can you include the graphic into the documentation generated with _moseldoc_ ?

 * Inspect the examples of SVG graph drawing under examples/mosel/Graphing, in particular the example in file `elscb_graph.mos` that displays progress graphs of the solving process.


#### <a id="secmodother"></a>Section 8.5 Other functionality of Mosel components


##### And also

 * Working with several models in parallel, possibly in a heterogeneous distributed architecture \(module _mmjobs_ \) 
     * see whitepaper _Multiple models and parallel solving with Mosel_

 * Combining different solvers 
     * see whitepaper _Hybrid MIP/CP solving with Xpress Optimizer and Xpress Kalis_



##### Functionality for decomposition and concurrent solving


| &nbsp; | 
---------- | 
The "multis": | 
– multi-solver; | _(graphic file ParDistr/multis0)_ | 

 * Choose among the Xpress solvers the one that is best suited for your problem type, or use _several solvers in combination_ within a single model


##### Functionality for decomposition and concurrent solving


| &nbsp; | 
---------- | 
The "multis": | 
– multi-solver; – multi-problem; | _(graphic file ParDistr/multis1)_ | 

 * _Multiple optimization problems_ \(type `mpproblem`\) can be defined within a single optimization model, such problems can share data, and make use of common decision variables


##### Functionality for decomposition and concurrent solving


| &nbsp; | 
---------- | 
The "multis": | 
– multi-solver; – multi-problem; – multi-model; | _(graphic file ParDistr/multis2)_ | 

 * Multiple optimization problems implemented as _separate model (files)_ make parallel and multithreaded optimization easily accessible


##### Functionality for decomposition and concurrent solving


| &nbsp; | 
---------- | 
The "multis": | 
– multi-solver; – multi-problem; – multi-model; – multi-node; | _(graphic file ParDistr/multis3)_ | 

 * Extension of multiple model handling to distributed computing using _several Mosel instances_ opens new perspectives for the implementation of decomposition approaches


##### Functionality for decomposition and concurrent solving


– multi-node; _(graphic file ParDistr/multis4)_ 

 * Remote execution of a Mosel model _without local installation_


##### Reference material

 * The modules of the Mosel distribution are documented in the _Mosel Language Reference Manual_ \(with separate manuals for modules _mminsight_ , _kalis_ , _matlab_ , and _nlsolv_ \).
 * The _Mosel Native Interface User Guide_ explains how to write your own modules. 
     * see public Mosel open source repository on Github:
   *   `https://github.com/fico-xpress/mosel`
         * MIP+NLP solver interface templates; _random, math, moseltesting, jobqueue, minisat_ 


 * On the topic of alternative solvers see the whitepaper _Xpress Mosel solver interfaces_
 * The whitepaper _Multiple models and parallel solving with Mosel_ discusses examples of parallel and distributed computing.


## <a id="partmccembed"></a>Embedding Mosel models


### <a id="mccembedj"></a>Chapter 9 Deploying Mosel models

   * [Section 9.1 Application design considerations](#secappdsgn "L3436")
   * [Section 9.2 Deployment options for Mosel models](#secmosdeploy "L3477")
   * [Section 9.3 Standalone executable](#secstanalone "L3525")
   * [Section 9.4 The Mosel API](#secmccapi "L3658")
   * [Section 9.5 Application development with Xpress Insight](#secmccgui "L3686")

#### <a id="secappdsgn"></a>Section 9.1 Application design considerations


##### Application design considerations

 * _Model development:_ once deployed, models often remain in use for periods > 10 years ⇒ code needs to be suitable for easy maintenance by changing owners 
     * conventions in _Mosel model development guidelines for optimization projects_ document: 
         * model code structure and formating
         * versioning
         * naming standards
         * model debugging
         * error handling
         * documentation


 * Comments are essential\!


##### Application design considerations

 * _Model formulation:_
     * Solving time varies considerably among problem instances 
         * consider trade-offs between decision type and performance required

     * Do not overmodel\! 
         * overmodeling can be expensive and useless, depending on use-case

     * Consider end-user involvement from the beginning 
         * what is the level/type of interaction required for the end-user?

     * Prefer lightweight / modular integration of model 
         * be prepared for future changes and upgrades




##### Application design considerations

  _(graphic file Moselcrash/appdesignall)_
      

#### <a id="secmosdeploy"></a>Section 9.2 Deployment options for Mosel models


##### Deployment options for Mosel models

 * Distribution as BIM file
 * Standalone executable
 * Embedding in an application via the Mosel API 
     * available for C/C++, Java, .NET and VBA

 * Xpress Insight application


##### Reminder: Compiling Mosel models

 * Mosel command line: 
```
mosel comp mymodel.mos
mosel comp -g mymodel.mos -o mybim.bim
```



 * Mosel language \(_mmjobs_ \): 
```
compile("mymodel.mos")
compile("g", "mymodel.mos", "mybim.bim")
```



 * Mosel libraries \( _e.g._  Java\): 
```
 XPRM mosel; XPRMmodel model;
 model = mosel.compile("mymodel.mos");
 model = mosel.compile("g", "mymodel.mos", "mybim.bim");
```




##### Reminder: Compiling Mosel models

 * Workbench: 
     * select menu _Run » Build_ 



#### <a id="secstanalone"></a>Section 9.3 Standalone executable


##### Standalone executable

 * _deploy_  module: generates an executable containing the BIM file 
     * on all supported platforms \(generating executables requires C compiler\)
     * retrieves arguments from the command line
     * can include additional files \(default application data, public keys, certificates\)

 * Usage \(requires C compiler\): 
```
mosel comp mymodel.mos -o deploy.exe:runmymodel
```



 * Output source file `runmymodel.c`: 
```
mosel comp mymodel.mos -o deploy.csrc:runmymodel
```




##### Standalone executable

 * _mosdeploy.mos_  tool \(see XPRESSDIR/examples/mosel/Programming\): 
     * exploiting _deploy_  functionality to generate executables without need for a C compiler by embedding the BIM file into a shell script
     * usage examples:

```

mosel mosdeploy -- myfile.mos             creates .bat or .sh file (system-dependent)
mosel mosdeploy -- -cmd myfile.mos        creates .cmd file
mosel mosdeploy -- -o runfile myfile.mos  use output name 'runfile'

mosel mosdeploy -- -exe mosdeploy.mos     creates executable (requires C compiler)
Same as:   mosel comp mosdeploy.mos -o deploy.exe:mosdeploy 
mosdeploy myfile.mos                      creates .bat or .sh file

```




##### Standalone executable

 * Retrieving parameter values from the command line 
     * replace the parameters block: 
```
parameters
  LIMIT=2000
end-parameters
```

 by the retrieval of argument value\(s\): 
```
declarations
  LIMIT: integer
end-declarations

if argc>1 then   ! 1: name of program, all following are arguments
  LIMIT:=integer(argv(2))
else
  LIMIT:=200     ! Default value
end-if
```





##### Standalone executable

 * Usage: 
     * Compilation \(requires C compiler\): 
```
mosel comp primedeploy.mos -o deploy.exe:runprime
```



     * Execution: 
         * Windows: 
```
runprime.exe 500
```



         * Unix: 
```
runprime 500
```




     * Compilation using _mosdeploy_  tool: 
```
mosel mosdeploy.mos -- -o runprime primedeploy.mos
```



     * Execution: 
```
runprime 500
```



     * The model can also be run directly as a BIM file: 
```
mosel primedeploy -- 500
```





##### Project work \[P-10\]: Standalone executable

 * Generate an executable for a Mosel model of your choice: 
     * transform any runtime parameters as to read their values from the command line
     * if you do not have any C compiler installed: 
         * generate the C source instead of the executable, or
         * work with the _mosdeploy_  tool \(copy the file XPRESSDIR/examples/mosel/Programming/mosdeploy.mos into your working directory\)




#### <a id="secmccapi"></a>Section 9.4 The Mosel API


##### What is the Mosel API?

 * The Mosel language allows you to formulate optimization problems, and develop optimization methods \( _i.e._ , use the Optimizer to solve them\), as a Mosel model
 * The Mosel API \(also _Mosel libraries_\) allows you to embed Mosel models in an application


##### Summary

 * Mosel libraries allow you to embed model programs directly in your application
 * Access the solution directly in your application, as alternative to using ODBC
 * Enjoy benefits of structured modeling language and rapid deployment when building applications


##### Summary

 * May choose to work with compiled models rather than model source files – provides protection against the user viewing / changing the model
 * Compiled models are platform independent


##### Reference material

 * You will find it helpful to refer to the _Mosel Libraries Reference Manual_
 * The part 'Working with the Mosel libraries' of the _Mosel User Guide_ documents examples for different programming language interfaces


#### <a id="secmccgui"></a>Section 9.5 Application development with Xpress Insight


##### Xpress Insight

 * What is Xpress Insight? 
     * Xpress Insight is an extensible application for deploying optimization models
     * client-server architecture supporting different types of clients
     * features include 
         * data management \(files, attachments, scenarios\)
         * model execution
         * scenario analysis
         * drag & drop UI creation
         * visualization with complex business workflows
         * security & access management \(SAML2\)
         * user and role management \(authorities\)
         * collaborative platform




##### Xpress Insight

 * Desktop installation

  _(graphic file InsightGen/insightovw.png)_
      

##### Xpress Insight

 * Multi-user

  _(graphic file InsightGen/insightovwm.png)_
      

##### Xpress Insight: typical workflow

 * _Load scenario:_ read input data provided in app archive
 * _Modify data:_ User can change the inputs through the GUI
 * _Run scenario:_ Execute the Mosel model with current data
 * _Analyze the solution_


##### Preparing the model file

```
  uses "mmxprs", "mminsight"
  parameters
    DATAFILE='chess5ins.dat'   
  end-parameters             

 !@insight.manage=input
  public declarations
    PRODS: range                             ! Index set for products
    RESOURCES: set of string                 ! Index set for resources
    PRODNAME,PROFIT: array(PRODS) of string  ! Product data
    RESUSE: array(RESOURCES, PRODS) of real  ! Resource usage coefficients
    RESLIM: array(RESOURCES) of real         ! Resource availability
  end-declarations

 !@insight.manage=result
  public declarations
    produce: array(PRODS) of mpvar           ! Array of decision variables
    LimCtr: array(RESOURCES) of linctr       ! Limit on resource usage constr.
    TotalProfit: linctr                      ! Objective function
  end-declarations
```



##### Preparing the model file

```
 ! Handling model execution modes
  case insightgetmode of
    INSIGHT_MODE_LOAD, INSIGHT_MODE_NONE: do
        initializations from DATAFILE        ! Read data from file
          RESUSE [PRODNAME,PROFIT] as "PRODDATA" RESLIM
        end-initializations
        if insightgetmode=INSIGHT_MODE_LOAD then exit(0); end-if
      end-do
    INSIGHT_MODE_RUN:
      insightpopulate
    else
      writeln("Unknown run mode")
      exit(1)
  end-case  

 ! ... state the problem ...

 ! Problem solving via Insight
  insightmaximize(TotalProfit)
```



##### Deployment from Workbench

 * Click the 'publish to Insight' button 
  _(graphic file ButtonsWB/butdeploy.png)_
       once your model is ready 
 * after entering your Insight credentials \(default for desktop installation: `admin / admin123`\) follow the link to the app loaded in the Insight Web Client


 * Workbench also supports the editing of Insight app configuration files 
     * VDL view definition \(custom web views for editing data or reporting results\)
     * XML companion file \(project configuration settings\)


 * To create an _Insight app template_ with the expected subdirectory structure select _Create Xpress Insight Project_  at startup \(or use menu _Project » New Project_ \)


##### Xpress Insight Web Client

  _(graphic file WB/chessinsweb.png)_
      

##### Reference material
 * See section _Deployment to Xpress Insight_  of the _Getting Started with Xpress_ manual.
 * Xpress Insight documentation: see the _Xpress Insight Web Client User Guide_ and also the _Xpress Insight Developer Guide_


## <a id="partmccsum"></a>Summary and further information


##### Summary

 * Have seen:
     * _FICO Xpress product suite_
         * solvers
         * modeling interfaces
         * development environment
         * deployment options




##### Summary

 * Have seen:
     * Linear and Mixed Integer Programming \(LP and MIP\) 
         * basic notions of theory
         * examples of standard problem types

     * Working with Mosel 
         * formulating optimization problems
         * running and debugging Mosel models
         * accessing data sources
         * programming language features
         * embedding models in Insight applications for deployment


 * Going further:
     * advanced optimization techniques 
         * infeasibility handling, accessing multiple solutions, user-provided solutions, user cuts, Nonlinear Programming, ...

     * advanced modelling topics 
         * decomposition schemes, parallel and distributed computing
         * tools: Profiler, _moseldoc_ , _moseltest_ 
         * programming language APIs for embedding models or invoking other programs/languages
         * Mosel Native Interface \(NI\), language extensions \(modules and packages\)




##### Further information

 * FICO Xpress online resources 
     * Online documentation and examples: [http://www.fico.com/fico-xpress-optimization/docs/latest](http://www.fico.com/fico-xpress-optimization/docs/latest)
     * Online searchable examples database: [http://examples.xpress.fico.com/example.pl](http://examples.xpress.fico.com/example.pl)
     * Optimization community \(online discussion group, video library, blogs\): [http://community.fico.com/optimization](http://community.fico.com/optimization)
     * FICO Xpress Academic Partner Program \(free\) [http://www.fico.com/app](http://www.fico.com/app)

 * Public Xpress open source repository 
     * Github: [https://github.com/fico-xpress](https://github.com/fico-xpress)
         * Run Xpress notebooks online: [https://github.com/fico-xpress/python-notebooks](https://github.com/fico-xpress/python-notebooks)



