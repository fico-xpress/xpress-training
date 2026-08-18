
     
# Advanced topics with FICO® Xpress Solver \(Python\)
## FICO Xpress Training




(C) 2001-2026 Fair Isaac Corporation. All rights reserved. 
Licensed under the [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0).



---

## <a id="chapintropy"></a>Chapter 1 Introduction to the course


##### Format

 * Course split into topics, each topic comprises: 
     * Introduction to concepts and recommendation of best practices
     * Running example in Python Notebook using FICO® Xpress Solver

 * In this course you will learn how to: 
     * Configure and tune the Xpress MIP solver for your problem
     * Diagnose and handle infeasible and numerically challenging models
     * Use advanced solver features: nonlinear solving, multiple MIP solutions, and multi-objective optimization

 * Other materials: 
     * This deck focuses on selected areas that are of practical importance
     * Not a replacement for the reference manuals
     * Does not try to be exhaustive ⇒ you will need to look up the details by yourself

---
Finding help: Check the [Xpress Python Examples](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/chExamples.html) and the [Xpress Solver reference manual](https://www.fico.com/fico-xpress-optimization/docs/latest/solver), including the [Python Interface Reference Manual](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/GUID-616C323F-05D8-3460-B0D7-80F77DA7D046.html)
---



##### Course Overview

 * Xpress overview
 * **MIP solving and tuning** 
 * **Tolerances and scaling** 
 * **Infeasibility handling** 
 * **Nonlinear solving and tuning** 
 * **Multiple MIP solutions** 
 * **Multi-objective optimization** 


##### Running the Python Notebook examples

 * General instructions: 
     * The accompanying Python notebook contains text descriptions, mathematical formulations, and code snippets to be analyzed, run and understood in the order they appear
     * Two versions are provided: `Xpress_solver_training.ipynb` contains exercises with TODO items for you to complete; `Xpress_solver_training_Solutions.ipynb` contains completed reference examples - note that other valid solutions exist
     * _Tip: try the exercises yourself before looking at the reference solutions!_ 

 * _Option 1_ : Run on _GitHub Codespaces_ \(Recommended\): 
     * Run the notebook in the cloud - no installation needed\! You only need a [GitHub](https://github.com/signup) account
     * Upload the notebook to a codespace created from our [python-notebooks](https://github.com/fico-xpress/python-notebooks?tab=readme-ov-file) public repo
     * Alternatively, use [Google Colab](https://colab.research.google.com/) or other equivalent cloud platforms

 * _Option 2_ : _Run locally_ \(for experienced users, when using a non-community license or working with sensitive data\). Requirements: 
     * Python 3.10-3.14
     * Jupyter Notebook or other compatible IDE \(VS Code, PyCharm\)
     * Latest version of the following packages: _xpress, pandas, scipy, matplotlib_ 



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



## <a id="chapMIPpy"></a>Chapter 2 MIP solving in Xpress


##### Basic concepts

 * IP = Integer Programming
 * MIP = Mixed Integer Programming
 * MILP = Mixed Integer Linear Programming 
     * _All used (by us) to mean the same thing!_
     * An LP in which some of the variables take integer values

 * Allows wealth of decisions to be modeled: 
     * Discrete choices: yes/no, on/off, etc
     * Logical conditions: if do A, must do B
     * Discrete quantities: batch sizes
     * Fixed costs
     * Price breaks
     * Piecewise linear functions



##### Example MIP


| &nbsp; | &nbsp; | &nbsp; | 
---------- | ---------- | ---------- | 
max; _x<sub>1</sub>_; _+_; _x<sub>2</sub>_; s.t.; _6 x<sub>1</sub>_; _+_; _x<sub>2</sub>_; _≤_ _15_; \(A\); _5 x<sub>1</sub>_; _+_; _8 x<sub>2</sub>_; _≤_ _20_; \(B\); __ __ _x<sub>2</sub>_; _≤_ _2_; \(C\); _x<sub>1</sub>, x<sub>2</sub>≥ 0_ **and integer**; |  | _(graphic file IntroMIP/mipexpl3)_ | 
|  | 
⇒Optimal MIP solution: _x_1 = 2, x_2 = 1_ | 


##### Solution techniques

 * Cannot simply round the LP solution:

 * None of the grid points surrounding the 'LP solution' point lie within the feasible region
 * So rounding up or down to the closest integer values will not necessarily result in a MIP solution

  _(graphic file IntroMIP/miplpsol)_
      

##### LP relaxation

 * _Relax_ integer conditions and solve as an LP...

  _(graphic file IntroMIP/lprelax)_
       * If the LP solution happens to be integer, then it is the _optimal MIP solution_
 * If the LP is infeasible, then the _MIP is infeasible_
 * In both cases we have "solved" the MIP problem
 * If not...⇒ Branch & Bound


##### Presolve

 * _Presolve_ attempts to simplify the problem by detecting and removing redundant constraints, tightening variable bounds, etc.

 * Applied before Branch & Bound, which then acts on the _presolved_ problem
 * In some cases, infeasibility may be determined at this stage
 * Presolve logging:

  _(graphic file Opt/presolvelog.png)_
      
 * Control [presolve](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/PRESOLVE.html) _is ON by default_, set to 0 to turn it OFF:

```
p.controls.presolve = 0
```

 * Control the amount of _probing during presolve_ with the [preprobing](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/PREPROBING.html) control
 * Perform _several rounds of presolving_ with [presolvepasses](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/PRESOLVEPASSES.html)


##### Branch and Bound

 * Example: Branch and Bound for a _maximization_ problem

  _(graphic file IntroMIP/BB/BB18.png)_
      

##### Branch and Bound

 * How the solver searches for the Branch and Bound tree: 
     * Select a 'best node' \(by default the best bound, but controllable via the [backtrack](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/BACKTRACK.html) control\)
     * Performs a _full dive in_ \(control when to backtrack using the [localchoice](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/LOCALCHOICE.html) control\)


  _(graphic file IntroMIP/BB/BB19.png)_
      

##### Heuristics

 * The Xpress Optimizer contains a wide variety of heuristics to help find feasible solutions during a MIP solve: 
     * _Simple rounding heuristics_: 
         * Fast heuristics that apply some simple rules to the solution of the continuous relaxation in order to produce a feasible MIP solution
         * These are typically run on every node

     * _Diving heuristics_: 
         * Combine rounding and fixing of MIP entities and re-optimize to construct a better quality MIP solution
         * They are run frequently on both the root node and during the branch and bound tree search
         * Specific controls: [heurfreq](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEURFREQ.html), [heurdivestrategy](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEURDIVESTRATEGY.html), [heurdivespeedup](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEURDIVESPEEDUP.html)

     * _Local search heuristics_: 
         * The most expensive heuristics and involve solving one or more smaller MIPs whose feasible regions describe a neighborhood around a candidate MIP solution
         * Run during the root cut-loop and typically on every 500 - 1000 nodes during the tree search
         * Specific controls in the next slides




##### Heuristics

 * Important control to experiment with -> [heuremphasis](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEUREMPHASIS.html) control: 
     * Try different heuristic strategies that impact the [Primal-Dual Integral \(PDI\)](https://www.sciencedirect.com/science/article/abs/pii/S0167637713001181)
     * Setting `heuremphasis=1` means more emphasis on finding good solutions early, i.e. on the primal side of the PDI: 
```
p.controls.heuremphasis = 1
```



| &nbsp; | &nbsp; | 
---------- | ---------- | 
-1: | Automatic selection of heuristic \(default\) | 
0: | No heuristics | 
1: | Focus on reducing the primal-dual gap in the early part of the search | 
2: | Extremely aggressive search heuristics | 



---
Hint: The value of the PDI can be obtained by querying the problem attribute [primaldualintegral](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/PRIMALDUALINTEGRAL.html)
---


##### Large Scale Neighborhood Search \(LSNS\) heuristics

 * Control the overall local search heuristic effort with [heursearcheffort](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEURSEARCHEFFORT.html):

```
p.controls.heursearcheffort = 2
```


 * A multiplier \(type `double`\) on the default amount of work the local search heuristics should do
 * A higher value means the local search heuristics will be run more often and that they are allowed to search larger neighborhoods
 * Other related controls: 
     * [heurfreq](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEURSEARCHROOTCUTFREQ.html): specifies how many cutting rounds should be done between two runs of the local search heuristic
     * [heursearchfreq](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEURSEARCHFREQ.html): for specifying after how many nodes to run the local search again during the tree
     * [heursearchrootselect](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEURSEARCHROOTSELECT.html): control local search heuristics to apply on the root node \(bit vector\)
     * [heursearchtreeselect](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEURSEARCHTREESELECT.html): control local search heuristics to apply during the tree search \(bit vector\)


---
Hint: Heuristic solutions found during the tree search are marked with  _a letter in front of the log line_. A star \(\*\) refers to a MIP-feasible relaxation solution. For more information, check the [reference manual page](https://www.fico.com/fico-xpress-optimization/docs/latest/opttuning/sectuneguideheur.html)
---


##### MIP Heuristic Logging

  _(graphic file Opt/heurlog.png)_
      

##### Branch and cut

 * A cut is a new constraint, which doesn't change the IP solutions, but cuts off parts of the LP relaxation
 * By adding cuts, we strengthen the formulation
 * This gives stronger bounds and removes the need for some branching
 * But generating cuts takes time, and cuts increase the size of the problem
 * So cuts can also slow down optimization


##### Cut example

  _(graphic file IntroMIP/Cuts/Cut07.png)_
      

##### Cuts

 * Try different levels of automatic cuts with the [cutstrategy](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/CUTSTRATEGY.html) control: 
```
p.controls.cutstrategy = 2
```



| &nbsp; | &nbsp; | 
---------- | ---------- | 
0: | cut generation disabled \(always try this once\) | 
1: | conservative cut generation strategy | 
2: | moderate cut generation strategy | 
3: | aggressive cut generation strategy | 
-1: | automatic choice between options 1 - 3 | 



##### Cuts

 * Other controls for determining the amount of in-tree cutting without specifying any specific cut separator: 
     * [gomcuts](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/GOMCUTS.html) and [covercuts](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/COVERCUTS.html): number of rounds of Gomory and lifted cover cuts at the root node:

     * There is usually an increased benefit from _generating these at the root node_, since these inequalities then apply to every subsequent node in the tree search
     * [cutselect](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/CUTSELECT.html) and [treecutselect](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/TREECUTSELECT.html): number of rounds of lifted cover inequalities at the root node and tree search

     * These are _bit vector controls_ providing detailed management of the cuts created



##### Branch and Cut - Concepts

 * _Preprocessing_: set of routines that eliminates redundant elements and strengthens a model formulation with the aim of accelerating the subsequent solution process \(includes presolving\)
 * _Domain propagation_: tighten the local domains of variables by inspecting the constraints and current domains of other variables
 * _Probing_: technique that looks at the logical implications of fixing certain variables \( _e.g._  fixing a binary variable to 0 and to 1\)
 * _Conflict analysis_: generate valid global constraints from infeasible subproblems, derived from cut off subproblems
 * _Strong branching_: precomputes the dual bounds of potential child nodes by solving auxiliary LPs, which leads to smaller search trees


##### Branch and Cut - Overview

  _(graphic file Opt/BBovw.png)_
      

##### Branch and Cut - Node

  _(graphic file Opt/BBnode.png)_
      

##### Near optimal solutions

 * Set stopping criteria if you only require a MIP solution close to optimal: 
     * Setting a _relative_ value stopping criterion \(example for 1 percent\): 
```
p.controls.miprelstop = 0.01
```


  _(graphic file IntroMIP/relstop.png)_
      

 * Setting an _absolute_ value stopping criterion: 
```
p.controls.mipabsstop = 100
```



 * Set a cut-off if you know a value the MIP solution must beat with _mipabscutoff_: 
```
p.controls.mipabscutoff = 110.0
```


 * The closer the cut-off is to the optimal solution, the quicker the solve will be
 * Setting a cutoff can make a solve slower because the solver might have difficulties to find a first feasible solution
 * If a solution is known it is always better to load it as a start solution instead of setting a cutoff



##### Optimizer built-in Tuner

 * The FICO® Xpress Optimizer _Tuner_ is a tool to automate the process of discovering better control parameter settings: 
     * There are over _200_ controls _affecting solver performance_
     * Tuner systematically tests the problem against a range of _different combinations of control settings_
     * A single tuning run will typically involve solving each problem at least 100-200 times: 
         * Can therefore _become computationally very expensive for large problems_


 * Examples of tuner-related controls and functions: 
```
p.controls.tunermaxtime = 100     # set max time spent in tuning
p.controls.tunerthreads = 2       # number of concurrent tuner jobs per thread
p.tunerWriteMethod('default.xtm') # export tuner options onto an XTM
p.tunerReadMethod('default.xtm')  # read tuner options from a file
p.tune('g')                       # tune the problem as a MIP
p.optimize()											   # optimize the problem with best control settings found
```



---
Finding help: Check the [Xpress Optimizer tuning guide](https://www.fico.com/fico-xpress-optimization/docs/latest/opttuning/GUID-A812CF0D-3316-34F0-85D9-ACADCB4497AB.html) to learn more about the built-in Tuner
---


##### Warm-start for Barrier

 * Barrier can be warm-started in memory using the [problem.loadlpsol\(\)](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/problem.loadlpsol.html) method:

 * To accept the given warm-start solution, _set the [barstart](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/BARSTART.html) control to -1_
 * By default, Barrier will use a weighted combination of its own starting point and the provided solution:

 * Use the [barstartweight](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/BARSTARTWEIGHT.html) control to experiment with this weighting
 * Any provided LP warm-start solution will be used by the Barrier solve of the initial LP relaxation of a MIP:

 * Use the 'l' flag to [p.readSlxSol\("sol", 'l'\)](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/problem.readSlxSol.html) for providing a warm-start LP solution using an `.slx` file

---
Hint: Check the [online Python example](https://www.fico.com/fico-xpress-optimization/docs/latest/examples/python/GUID-C6D17901-369B-3EFC-8BD3-ADB959C90342.html) that demonstrates warm-starting of Barrier, both using a file and through memory
---


##### Other possibilities for boosting solves

 * Add a starting basis with [p.loadBasis\(\)](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/problem.loadbasis.html): 
     * Set _p.controls.keepbasis=0_ to prevent automatic warm-starting

 * Use branching priorities with [p.loadDirs\(\)](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/problem.loaddirs.html) to prioritize groups of integer variables: 
     * Directives can be given relating to priorities, forced branching directions, pseudo costs and model cuts

 * Interact with the solver via [callbacks](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/chCallbacks.html) to: 
     * Add your own heuristic solutions
     * Tighten node problems
     * Add your own cutting planes / constraints
     * Provide multiple branching candidate for the Solver to choose between
     * Override the Solver branching choice
     * ...



##### Multi-Threading

 * Single machine, shared memory multi-threading:

 * Automatic detection of logical cores available, including container restrictions, with the attribute [coresdetected](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/CORESDETECTED.html)
 * Thread limit set automatically to match cores detected
 * Main control: [threads](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/THREADS.html), the default number of threads used during optimization

 * Hierarchy of threading controls for fine-grained adjustments with the controls below
 * What can be multi-threaded:

 * Dual simplex: use the [dualthreads](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/DUALTHREADS.html) control
 * Barrier algorithm: [barthreads](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/BARTHREADS.html) and [crossoverthreads](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/CROSSOVERTHREADS.html)
 * Concurrent LP/QP: [concurrentthreads](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/CONCURRENTTHREADS.html)
 * MIP: 
     * Root heuristics: [heurthreads](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEURTHREADS.html) and [backgroundmaxthreads](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/BACKGROUNDMAXTHREADS.html)
     * Branch-and-bound: [mipthreads](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/MIPTHREADS.html)



##### Predictability and reproducibility in Xpress Solvers

 * All solver components are _deterministic_ by default:

 * Running the same problems from the same starting conditions \( _e.g._  control settings\) will _produce identical solves_
 * Platform independence:

 * _win64_, _linux64_ and _mac64_ on _Intel_  will produce identical solves
 * _linux64_ and _mac64_ on _ARM_  will produce identical solves
 * Minimal dependence on threads and architecture:

 * To ensure reproducibility, use the [threads](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/THREADS.html) control to match number of threads

---
Note: Determinism and reproducibility cannot be guaranteed when a user interacts non-deterministically with a solve through callbacks or when setting non-deterministic stopping criteria \( _e.g._  time limit\)
---


##### Python Notebook \[PN-1\]: Solving and tuning a MIP problem

 * Navigate to _Exercise 1 - Solving and tuning a MIP problem_
 * **Exercise 1.1** :

 * Experiment by switching the [heuristic emphasis](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEUREMPLHASIS.html) control between 0, 1, and 2 and evaluate the impact in time to optimality
 * **Exercise 1.2** :

 * Deactivate cuts by using the [cut strategy](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/CUTSTRATEGY.html) control and evaluate the impact in time to optimality


## <a id="chaptolerscalpy"></a>Chapter 3 Tolerances and scaling


##### Numerical challenges

 * Numerical issues arise from models with...

 * ...coefficients spanning _many orders of magnitude_
 * ...structures that amplify _numeric error propagation_
 * Xpress provides tools to check coefficient ranges and condition numbers to identify numerical stability issues
 * Adjust numerical tolerances, reconsider control values, and use alternative strategies like different simplex algorithms or barrier methods

---
Finding help: Check the [reference manual page](https://www.fico.com/fico-xpress-optimization/docs/dms2020-03/solver/optimizer/HTML/chapter5_sec_numerics.html) for more information about analyzing and handling numerical issues
---


##### Scaling and Big-M formulations

 * Example of a scaled constraint \(with _b_  binary variable\)

  _(graphic file Opt/scaledcons.png)_
       * Valid solution: any that satisfies the \(scaled\) constraints within tolerances:

  _(graphic file Opt/tolercons.png)_
      
 * By default: `miptol = 5·10<sup>6</sup>` and `feastol = 10<sup>6</sup>`
 * Example: _M = 10<sup>8</sup>_ ⇒ _x ≤ 10<sup>8</sup>· 6 · 10<sup>-6</sup> = 600_  is feasible \(even if _b = 0_ \)\!


##### Rule of 10<sup>6</sup>

 * Double precision floating point 16-digit "budget":

  _(graphic file Opt/16digiterrors.png)_
       * Too large coefficients can cause round-off errors to exceed feasibility tolerance
 * To stay relatively safe, _use the following limits_: 
     * Largest value: 10<sup>6</sup>
     * Smallest value: 10<sup>-6</sup>
     * Largest row/column ratio: 10<sup>6</sup>



##### Adjust numerical tolerances

 * The feasibility tolerance control [feastol](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/FEASTOL.html) determines when a solution is treated as feasible:

```
p.controls.feastol = 1e-6
```


 * A constraint or bound violated by less than `feastol` is treated as satisfied
 * The [miptol](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/MIPTOL.html) value determines when a decision variable's value is considered to be integral:

```
p.controls.miptol = 5e-6
```


 * Must be slightly larger than _feastol_; larger values may cause slight infeasibilities when fixing integers
 * **Important:**  use `feastol`/`miptol` to express the feasibility your _application_ needs. _Tightening_ them does _not_ make a numerically unstable model more reliable: on ill-conditioned models it can even lead to _incorrect dual bounds_ or _false infeasibility_. To address instability, use the tools on the next slides.


##### Scaling

 * Xpress provides the user with information on the coefficient ranges in both the original problem and the problem after _presolving and scaling has been applied_:

  _(graphic file Opt/coefflog.png)_
       * [Autoscaling](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/AUTOSCALING.html) will select a scaling method that improves the coefficient distribution:

```
p.controls.autoscaling = -1
```


 * Can be disabled \(0\), or set to a cautious \(1\), moderate \(2\), or aggressive \(3\) strategy
 * A more detailed scaling strategy can be defined using the bitwise [scaling](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/SCALING.html) control:

```
p.controls.scaling = 163
```


 * If set to a non-default value by the user, autoscaling will be ignored


##### Diagnosing stability: the attention level

 * For MIP problems, set [mipkappafreq](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/MIPKAPPAFREQ.html) to compute the basis condition number \(_kappa_\) during the branch-and-bound search:

```
p.controls.mipkappafreq = 1
```

 * The log then reports the share of bases that are _stable_, _suspicious_, _unstable_ or _ill-posed_, and an overall _attention level_ between 0 and 1:

 * 0 means all bases are stable, 1 means all are ill-posed: the higher the value, the more likely numerical errors are
 * _Rule of thumb:_ an attention level above 0.1 should be investigated further
 * Available afterwards as the `attentionlevel` attribute \(and `maxkappa` for the largest kappa sampled\)
 * After the root LP, Xpress also _predicts_ the attention level from matrix features \([predictedattlevel](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/PREDICTEDATTLEVEL.html)\): a prediction above 0.1 logs 'High attention level predicted from matrix features'


##### Addressing numerical issues

 * _Improve the model first:_ narrow coefficient ranges \(rule of 10<sup>6</sup>\), prefer indicators over _Big-M_ 
 * Emphasize stability over speed with [numericalemphasis](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/NUMERICALEMPHASIS.html) \(the first control to try\):

```
p.controls.numericalemphasis = 1   # mild (1), medium (2), strong (3)
```

 * If still hard to solve reliably, try alternative _scaling_, switching off dedicated _presolve_ operations, or a different `dualstrategy`
 * _Refine the solution rather than loosen feasibility:_ the solution refiner targets higher precision _after_ solving \(see next slide\)

---
Finding help: See [Analyzing and Handling Numerical Issues](https://www.fico.com/fico-xpress-optimization/docs/dms2020-03/solver/optimizer/HTML/chapter5_sec_numerics.html) in the reference manual for the full workflow
---


##### Solution refinement

 * Xpress includes two methods for _solution refinement_:

 * _LP Refinement_ \(ON by default\) - providing LP solutions of a higher precision:

 * iteratively attempts to increase the accuracy of the solution until tolerance targets are satisfied
 * _MIP Refinement_ - providing MIP solutions which are truly integral:

 * attempts to round any fractional MIP entity and reduce LP infeasiblity
 * Both methods _can lead to a slowdown_ of the solution process, which is more considerable the more numerically challenging the matrix is
 * Use the [refineops](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/REFINEOPS.html) control to specify when the solution refiner should be executed to reduce solution infeasibilities \(bit vector control\):

 * The refiner will attempt to satisfy the target tolerances for all original linear constraints _before presolve or scaling has been applied_
 * Set the precision the refiner aims for with `feastoltarget`, `miptoltarget` and `optimalitytarget`:

 * Unlike `feastol`/`miptol`, these tighten the _achieved_ accuracy without changing what counts as feasible


##### Indicator constraints as alternative to  _Big-M_ formulations

 * Indicator constraints are a very important alternative to _Big-M_  formulations:

 * The solver will convert an indicator to a _Big-M_  constraint if it can deduce a sufficiently small _M_  that is numerically safe
 * An indicator constraint is a _logic constraint_ that expresses the implication _'if indicator condition holds then apply the constraint'_: 
     * Represented by _a tuple_ containing a condition on a _binary variable_, called the indicator, and an expression representing _a constraint_: `(indicator condition, constraint)`

 * Indicator constraints are defined by using the _problem.addIndicator()_ method: 
```
p.addIndicator(c1, c2, ...)
```


 * Each argument `c1,c2,...` can be a single indicator constraint, or a list, tuple, or _NumPy_  array of indicator constraints \(tuples\)
 * The constraint is only enforced when the value of the indicator variable matches a user-defined value \(0 or 1\)



##### Indicator constraints as alternative to  _Big-M_ formulations

 * Example enforcing the constraint `y <= 15` when binary variable `x = 1` for an optimization problem `p`: 
```
x = p.addVariable(vartype=xp.binary)
y = p.addVariable(lb=10, ub=20)
ind1 = (x == 1, y <= 15)
p.addIndicator(ind1)
```



---
Note: The  _addIndicator()_ method also accepts nonlinear expressions for the constraint to enforce
---


##### Python Notebook \[PN-2.1\]: Tolerance settings

 * Navigate to _Exercise 2 - Tolerances and scaling_, section 2.1 \(TODO 2.1\)
 * Run the Python code cell with the following model:

_ maxx<sub>1</sub>_

_ s.t. x<sub>1</sub> - x<sub>2</sub> = 1.0000001 _

_ x<sub>1</sub>≤ 1_

_ x<sub>1</sub>≥ 0, x<sub>2</sub>≥ 0_

 * Do you get the expected result?
 * Which tolerance's value would you need to change to make this work?


##### Python Notebook \[PN-2.2\]: MIP tolerance settings

 * Navigate to _Exercise 2 - Tolerances and scaling_, section 2.2 \(TODO 2.2\)
 * Run the Python code cell with the following model:


| &nbsp; | &nbsp; | 
---------- | ---------- | 
min | _y_ | 
s.t. | _x ≤ 1000000 · y_ | 
|  | _x ≥ 1000001_ | 
|  | _y_ integer | 

 * Is the solution correct? Why ?
 * What happens after we reduce the MIP tolerance and adjust the feasibility tolerance ?


## <a id="chapinfeaspy"></a>Chapter 4 Infeasibility handling


##### Infeasibility

 * One of the most common difficulties is what to do when a model is infeasible... 
     * ... is the model wrong?
     * ... is the data wrong?
     * ... is the problem genuinely infeasible?
     * ... where is the infeasibility so I can correct or investigate it?

 * Two types of infeasibility in MIP problems:

 * _Continuous infeasibility_: LP relaxation of the MIP problem is in itself infeasible
 * _Integer infeasibility_: LP relaxation is feasible but the problem is MIP infeasible

 * These are harder to detect and handle...


##### Detecting infeasibility with FICO® Xpress

 * Infeasibility status can be identified by the _solution status_  attribute after a solve:

 * The value of _solstatus_ is `xp.SolStatus.INFEASIBLE` for an infeasible problem
 * It is returned by the _p.optimize()_ function, together with the _solve status_ : 
```
solvestatus, solstatus = p.optimize()

if solstatus == xp.SolStatus.INFEASIBLE:
  print("Problem is infeasible.")
```



 * Alternatively, use the problem attribute named _solstatus_: 
```
p.optimize()

if p.attributes.solstatus == xp.SolStatus.INFEASIBLE:
  print("Problem is infeasible.")
```




##### Detecting infeasibility with FICO® Xpress

 * Diagnosis in presolve:

 * Possible to "trace" back the implications that determined an inconsistency and identify a cause
 * Solver log information about infeasibility by default:

 * `The problem is infeasible due to row R67`
 * Set _p.controls.trace = 1_ to display a more detailed infeasibility diagnosis during presolve before calling _p.lpOptimize()_
 * Diagnosis using primal "phase 1" simplex solution:

 * Set _p.controls.presolve = -1_ to force presolve to continue to simplex even when an infeasibility is discovered
 * The sum of infeasibilities is minimized in the solution
 * The resulting set of violated constraints and violated variable bounds provides a clear picture of what aspect of the model is causing the infeasibility

---
Finding help: Check the [reference manual page](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/chapter3.html) for more information about infeasibility handling, and see the [diagnose\_infeasible](https://github.com/fico-xpress/python-notebooks/blob/main/modeling_examples/diagnose_infeasible.ipynb) example notebook on GitHub
---


##### Irreducible Infeasible Sets \(IIS\)

 * Subsets of constraints, bounds and integrality conditions that form an infeasibility:

 * A model may have several infeasibilities. Repairing a single IIS may not make the model feasible
 * Works with _any problem type_, but does not support user functions
 * Calculating IIS can be computationally expensive, so they can be _generated iteratively_
 * Generation of IISs available as API functions: _problem.firstIIS(), problem.nextIIS(), problem.IISAll(), problem.getIISData(), problem.writeIIS(), ..._
 * Basic method for LP infeasibility:

 * Filtering after first phase primal simplex
 * Uses duals of rows and reduced costs of columns to identify subproblems containing all infeasibilities
 * Basic method for MIP infeasibility when LP-feasible:

 1. Drop one or more constraints/bounds/integrality conditions of the problem

 * If the resulting problem becomes feasible, keep them
 3. Stop with an irreducible set when nothing can be removed


##### Irreducible Infeasible Sets \(IIS\)

 * Generate a single IIS with _p.firstIIS()_ or _p.nextIIS()_, and export it to a file using _p.writeIIS()_:

```
if p.firstIIS(1) == 0:  # returns 0 if successful
    p.writeIIS(iis=1, filename="iis", filetype=0, flags="l")  # export in LP format
    
```


 * This step might likely be enough to diagnose an infeasible problem
 * Alternatively, use _p.IISAll()_ to generate all IISs \(only for LPs\):

 * The _numiis_ attribute to retrieve the number of IISs found so far

```
solvestatus, solstatus = p.optimize()

if solstatus.name == "INFEASIBLE":
  p.IISAll()  # generate all IIS
  numiis = p.attributes.numiis  # retrieve the number of IISs generated so far
  print(f"The problem has {numiis} IISs")
```



##### Irreducible Infeasible Sets \(IIS\)

 * Use _p.getIISData()_ to retrieve information for a specific IIS, after `p.IISAll()`, such as: 
     * Size, variables \(row and column vectors\) and conflicting sides of the variables, duals, reduced costs, and isolation rows and columns, if available


```
for i in range(1,numiis+1):
  miisrow, miiscol, constrainttype, colbndtype, duals, rdcs, \
    isolationrows, isolationcols = [], [], [], [], [], [], [], []

 # retrieve the i'th IIS data
  p.getIISData(i,miisrow, miiscol, constrainttype, colbndtype, \
    duals, rdcs, isolationrows, isolationcols)

  print("iis data:", miisrow, miiscol, constrainttype, colbndtype, \
    duals, rdcs, isolationrows, isolationcols)
```



##### Irreducible Infeasible Sets \(IIS\)

 * Perform the _isolation_ identification procedure for an Irreducible Infeasible Set \(IIS\) via _problem.IISIsolations(iis)_: 
     * An IIS isolation is a special constraint or bound in an IIS
     * They indicate the likely cause of each independent infeasibility and _which constraints or bounds to drop or modify_
     * Removing/repairing constraints and bounds in an IIS isolation will remove all infeasibilities in the IIS without increasing the infeasibilities in other IISs
     * This procedure is computationally expensive, and is done via _p.IISIsolations_ for an identified IIS:

```
p.IISAll()
numiis = p.attributes.numiis
for i in range(1,numiis+1):
    p.IISIsolations(i)
```




##### Infeasibility repair utility

 * A _two-phase approach_ to solve the problem with a minimum weighted sum of violations of relaxed constraints and bounds:

 * A set of _preferred constraints and bounds_ is indicated, and the Optimizer attempts to identify a 'solution' that violates them minimally while satisfying all other constraints and bounds
 * Available via the _p.repairInfeas()_ method:

 * Phase I:

 * Adds _penalty_  variables to constraints and bounds
 * Minimizes the weighted sum of penalties to obtain a minimally weighted infeasible solution
 * Phase II:

 * Adds a constraint to restrict the sum of violations to the Phase 1 solution \(plus a tolerance\)
 * Solves for the original objective
 * More advanced functions are available to allow weights to be specified for each constraint and bound: _p.repairWeightedInfeas(), p.repairWeightedInfeasBounds()_

---
Finding help: Check the [reference manual page](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/problem.repairinfeas.html) for more information on the  _repairInfeas*_ functions
---


##### Infeasibility repair utility

 * Example:

```
p.optimize()

if p.attributes.solstatus.name == "INFEASIBLE":

  penalty = 'c' # each penalty is the reciprocal of the corresponding preference
  phase2 = 'o'  # use the objective sense of the original problem
  flags = 'g'   # do the tree search
  delta = 0     # the relaxation multiplier in phase II

  # integer arguments represent the preferences "lepref, gepref, lbpref, ubpref"
  p.repairInfeas(penalty,phase2,flags,1,0,0,0,delta)
```


 * A preference value of 0 results in the row or bound not being relaxed, and a negative preference indicates that a quadratic penalty cost should be applied
 * The sum of violations in phase II is restricted to be no greater than `(1 + delta) * p` \(with `p` = sum of violations in phase I\)


##### Infeasibility repair utility

 * _p.repairWeightedInfeas()_ allows _per-row and per-column preferences_, giving precise control over which constraints can be relaxed:

```
n_rows = p.attributes.rows
n_cols = p.attributes.cols
row_types = p.getRowType(0, n_rows - 1)

# protect equality constraints (E) from relaxation, allow relaxation of others
le_prefs = [0.0 if t == 'E' else 1.0 for t in row_types]
ge_prefs = [0.0 if t == 'E' else 1.0 for t in row_types]
lb_prefs = [0.0] * n_cols  # do not relax lower bounds
ub_prefs = [0.0] * n_cols  # a choice: upper bounds could also be relaxed

p.repairWeightedInfeas(lepref=le_prefs, gepref=ge_prefs,
                        lbpref=lb_prefs, ubpref=ub_prefs)
```



##### Infeasibility repair utility

 * Preference values for _repairWeightedInfeas()_:

 * _0_: constraint is _never relaxed_
 * _positive value_: constraint may be relaxed; higher values make relaxation cheaper \(weight = 1/preference\)
 * ⇒ Less programming effort than manual IIS analysis, but less fine-grained and likely to give a different solution than manual constraint tightening


##### Avoiding infeasibility
 * Try to introduce some flexibility into the problem by adding slack variables: 
     * Incorporate explicit _slack/surplus variables_ in constraints, so that if demand cannot be met or more resources are required, this is apparent from a feasible solution
     * Rather than making the model infeasible, the slack variables act as _pressure valves_
     * For example, replace: 
_∑<sub>f</sub> ship<sub>fc</sub>≥ DEM<sub>c</sub> ∀ c_
 by 
_∑<sub>f</sub> ship<sub>fc</sub>≥ DEM<sub>c</sub> - xdem<sub>c</sub> ∀ c_

     * Penalize the extra variables in the objective function with a high enough cost so that they are at _zero unless the model in infeasible:_

     * If no actual penalty costs \( _e.g._  price for buying additional quantities\) are known, _coefficients should be one order of magnitude larger_ than any other coefficient...
     * ... but _within the recommended numerical tolerances_\!



##### Avoiding infeasibility - Example

 * **Objects:** 
     * suppliers, depots, customers

 * **Data:** 
     * availability _AVAIL<sub>s</sub>_ , demand _DEM<sub>c</sub>_ , transportation cost per route: _COSTsd<sub>sd</sub>_  and _COSTdc<sub>dc</sub>_ 

 * **Decisions:** 
     * quantities to be shipped: _flowsd<sub>sd</sub>_  and _flowdc<sub>dc</sub>_ 
     * _slack variables:  _xavail<sub>s</sub>, xdemand<sub>c</sub>_ _

 * **Constraints:** 
     * remain within supply limits: _∀ s:  ∑<sub>d</sub> flowsd<sub>sd</sub>≤ AVAIL<sub>s</sub>+ xavail<sub>s</sub>_ 
     * satisfy customer demand: _∀ c:  ∑<sub>d</sub> flowdc<sub>dc</sub>≥ DEM<sub>c</sub>- xdemand<sub>c</sub>_ 
     * flow balance in depots: _∀ d:  ∑<sub>d</sub> flowsd<sub>sd</sub> =  ∑<sub>d</sub> flowdc<sub>dc</sub>_ 

 * **Objective:** 
     * minimize total cost of selected routes _and penalize slack_: _min  ∑<sub>s</sub> ∑<sub>d</sub> COSTsd<sub>sd</sub>·flowsd<sub>sd</sub> +  ∑<sub>d</sub> ∑<sub>c</sub> COSTdc<sub>dc</sub>·flowdc<sub>dc</sub>+ ∑<sub>s</sub> PENALTY·xavail<sub>s</sub> + ∑<sub>c</sub> PENALTY·xdemand<sub>c</sub>_ 



##### Avoiding infeasibility

 * Important to keep in mind when adding slack/surplus variables: 
     * Always assert the values of the added variables to ensure they are equal to zero \(feasible problem\)
     * If the slack variables are active \(non-zero\), it means that the original problem is infeasible, and you should go back and find out why
     * Be careful not to set penalty costs so large as to cause numerical issues
     * Be aware not to treat an infeasible solution as a feasible solution\!

 * Putting slack variables in all constraints _can slow down the optimization_:

 * An _alternative approach_ is to solve the problem first without slack variables, then, if the problem is infeasible, add the slack variables to the formulation and re-solve
 * Another alternative could be to use multi-objective optimization to first find a minimally violated solution and then solve for the intended objective

---
Note: Slack/surplus variables should  _only be introduced in inequality  contraints_ to ensure that the model remains valid\!
---


##### Python Notebook \[PN-3\]: Infeasibility handling in Portfolio Optimization

 * Navigate to _Exercise 3 - Infeasibility handling_ in the notebook
 * The portfolio model is _intentionally infeasible_: sector allocation limits and regional minimum requirements conflict
 * The notebook walks through the full diagnostic workflow:

 1. Solve and detect infeasibility via _p.attributes.solstatus_
 2. Call _diagnose\_infeasible\(\)_ helper to compute IIS and isolations
 3. Interpret the output: which constraint type is causing the infeasibility?
 4. _Manual fix_: relax the binding sector constraints and re-solve
 5. _Automatic repair_: apply _p.repairWeightedInfeas()_ with equality constraints protected
 * Both approaches yield different portfolio allocations - visualized side by side


## <a id="chapnonlinearpy"></a>Chapter 5 Nonlinear Optimization \(incl. FICO® Xpress Global\)


##### The world is nonlinear

 * Many applications are inherently nonlinear:

 * Chemical processing, electrical engineering, gas transmission,...
 * _A priori_  linearization can work in some cases and is often quite fast...

 * ...but can be arbitrarily bad w.r.t. both feasibility and optimality.
 * In many applications, guaranteed global optima are required

 * Small objective difference can equate to huge financial loss or regulatory non-compliance

  _(graphic file NonLinear/worldnonlinear.png)_
      

##### What kind of nonlinear functions does FICO® Xpress support?

 * All combinations of:

  _(graphic file NonLinear/nonlineartypes.png)_
       * Examples:

  _(graphic file NonLinear/nlnforms.png)_
      

##### Modeling nonlinear problems in Python

 * _Nonlinear problems_, i.e. problems containing _at least one nonlinear constraint or objective_, can be modeled via the Xpress Python interface: 
     * Nonlinear expressions follow the _same relational and arithmetic logic_ as linear expressions
     * Available arithmetic operators: `+`,`-`, `*`, `/`, `**` \(which is the Python equivalent for the power operator, "^"\)
     * _Univariate functions_ can be used from the following list: `sin`, `cos`, `tan`, `asin`, `acos`, `atan`, `exp`, `log`, `log10`,`abs`, `sign`, `sqrt`, `erf`, and `erfc`
     * The _multivariate functions_ `min` and `max` can receive an arbitrary number of arguments
     * Piecewise linear functions \(`pwl`\) are discussed later



##### Modeling nonlinear problems in Python

 * Examples of nonlinear problem elements:

```
p.addConstraint(x**4 + 2 * x**2 - 5  >= 0)  # polynomial constraint
p.addConstraint(xp.sin(math.pi * x) == 0)   # terrible way to constrain x to be integer
p.addConstraint(x**2 * xp.sign(x) <= 4)     # signum function 
p.setObjective((a-x)**2 + b*(y-x**2)**2)    # minimize Rosenbrock function
```


---
Finding help: For more information about modeling nonlinear problems, browse the [FICO® Xpress NonLinear reference manual](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/GUID-4B40E940-6A38-342F-9531-A13E84FB1467.html)
---


##### Local vs Global Optimization

  _(graphic file NonLinear/localglobalopt.png)_
      

##### Solvers

 * FICO® Xpress Optimizer:

 * Used to solve _convex quadratic problems_ \(QP, MIQP, QCQP, SOCP\)
 * FICO® Xpress Global:

 * Finds a global optimum, including valid bounds and gaps during the solve
 * Uses spatial branching, convexification cuts, and local solver heuristics
 * Detailed techniques covered in upcoming slides
 * FICO® Xpress NonLinear = Local solvers \(find _local optima_\):

 * SLP: _Successive Linear Programming_ 

 * Iterative linear approximations
 * Nonlinear Branch&Bound \(MISLP\)
 * Artelys Knitro: used as a plugin to solve highly nonlinear models. Some algorithms include:

 * Interior Point/direct \(default\)
 * Augmented Lagrangian
 * Nonlinear Branch&Bound
 * ...


##### Convex quadratic problems \(QP, MIQP, MIQCQP\)

 * _Quadratic Programming (QP)_: quadratic objective, linear constraints

 * Solved by Xpress Optimizer using KKT-Simplex \(default\) or Newton-Barrier algorithm
 * _Mixed Integer Quadratic Programming (MIQP)_: QP with integer variables

 * Solved by Xpress Optimizer using KKT-Simplex-based Branch-and-Bound \(default\)
 * KKT-Simplex solves QP relaxations at each node
 * _Quadratically Constrained QP (QCQP)_: quadratic terms in constraints

 * Handled by Xpress Optimizer using Barrier-based Branch-and-Bound \(default\)
 * _Mixed Integer Quadratically Constrained QP (MIQCQP)_: QCQP with integer variables

 * Solved by Xpress Optimizer using Outer Approximation \(default\)
 * **Solving these problems does not require an Xpress Nonlinear/Global solver license** 


##### Second-order cone programming \(SOCP, MISOCP\)

 * _Second-Order Cone Programming (SOCP)_: Convex optimization with conic constraints

 * Special form of convex nonlinear constraints: &#124;&#124;Ax + b&#124;&#124;≤c<sup>T</sup>x + d, linear objective function
 * Applications: Portfolio optimization, robust optimization, signal processing

  _(graphic file NonLinear/secondordercone.png)_
      
 * _Mixed Integer SOCP (MISOCP)_: SOCP with integer variables

 * Common in portfolio optimization with cardinality constraints


##### MIQCQP and MISOCP solution approaches

 * _KKT-Simplex Branch-and-Bound_: Primary method for convex MIQP \(quadratics only in objective\)

 * Solves KKT optimality conditions using Simplex-like approach
 * Handles complementarity condition \(zero/non-zero variables\) similar to variable bounds in Simplex
 * _Outer Approximation_: Primary method for convex MIQCQP/MISOCP

 * Approximates quadratic/conic constraints with supporting hyperplanes
 * Iteratively refines linear approximation
 * _Barrier-based Branch-and-Bound_: Alternative for MIQCQP/MISOCP

 * Uses Newton-Barrier algorithm to solve continuous relaxations
 * All methods: Branch on integer variables to explore solution space


##### \(MI\)SOCP/QCQP/QP tuning

 * For quadratically constrained problems \(QCQP\) and second-order cone programs \(SOCP\):

 * [miqcpalg](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/MIQCPALG.html): Chooses between nonlinear Branch&Bound with barrier solves and an LP-based outer approximation 
     * On most instances outer approximation performs better
     * In some cases barrier can significantly outperform it

 * Preprocessing controls for quadratic problems:

 * [preconvertobjtocons](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/PRECONVERTOBJTOCONS.html): Whether to keep quadratic objective and solve with KKT-simplex or move it to a constraint to solve with barrier or OA
 * [preconvertseparable](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/PRECONVERTSEPARABLE.html): Whether to keep SCOP as is or convert to many smaller or even diagonal cones


##### Python Notebook \[PN-4.1\]: Circle packing - local vs global solver

 * Navigate to _Exercise 4.1 - Local vs Global NLP solver_ in the notebook
 * The problem: pack _N_  circles inside a unit square to _maximize the sum of radii_
 * Run the local solver \(SLP\) code cell and note the solution quality
 * Run the global solver code cell and compare:

 * Are the solutions the same?
 * What are the differences in objective value and solving time?
 * Run the visualization cell to compare both solutions side by side


##### Xpress NonLinear vs Xpress Global


| &nbsp; | &nbsp; | 
---------- | ---------- | 
__Xpress NonLinear_ _ | __Xpress Global_ _ | 
|  | 
Local optimum | **Global optimum** | 
|  | 
No bounds on distance to optimum | **Duality/Optimality Gap** | 
|  | 
No proof of infeasibility | **Can detect infeasibility, required for nonlinear IIS** | 
|  | 
**Fast in general** | Possibly long branch-and-bound search | 
|  | 
**Supports user functions** | No user functions | 


##### When to use FICO® Xpress Global ?
 * Whenever a reliable bound on the optimal value is needed:

 * Solution quality
 * Regulatory compliance
 * Workflow validation
 * Problems with many local optima
 * Nonlinear problems with discrete entities
 * Infeasibility detection/guarantee: IIS, repairinfeas


##### Xpress Global solver: High-level overview

 * The Global solver finds provably optimal solutions through:

 1. _Nonlinear presolve_: Bound tightening and problem simplification
 2. _Reformulation_: Transform problem using auxiliary variables \(DAG representation\)
 3. _MIP presolve_: Standard presolve on reformulated problem
 4. _Root LP solve_: Solve initial relaxation with convexification cuts

 * If unbounded, use bounding box approach
 6. _Branch-and-bound search_:

 * Additional propagation and convexification cuts to enforce nonlinearities
 * Branch on both integer and continuous variables \(spatial branching\)
 * Run local NLP solver on MIP-feasible solutions as a heuristic


##### Reformulation via Directed Acyclic Graph


* _Example_: 2<sup>cos\(x<sup>2</sup>\)</sup>≤ 1 * Build the so-called expression tree * Identify common subtrees to build a _Directed Acyclic Graph_ * Introduce an auxiliary variable for each internal node: * w<sub>3</sub>≤ 1 \[w<sub>1</sub> = x<sup>2</sup>, w<sub>2</sub> = cos\(w<sub>1</sub>\), w<sub>3</sub> = 2<sup>w<sub>2</sub></sup>\] * Identify and propagate domain reductions: * w<sub>3</sub>≤ 1 ⇒ w<sub>2</sub> = log<sub>2</sub>\(w<sub>3</sub>\) ≤ log<sub>2</sub>\(1\) = 0 * Ignore the nonlinear part initially and solve for the linear system _(graphic file NonLinear/DAGreform.png)_ 


##### Convexification cuts

  _(graphic file NonLinear/convexcuts.png)_
      

##### Convexification cuts

 * Global solver uses _convexification cuts_ to create linear over/underestimators:

 * Cuts are _added dynamically_ at three stages:

 * Initial root relaxation setup
 * Root and node cutloops
 * During branching evaluation
 * _Standard cuts_ for most operators:

 * Secant cuts: Linear interpolation between bounds
 * Tangent cuts: First-order approximations
 * _Additional specialized cuts_ for:

 * Quadratics: Lifted tangent \(LTI\) cuts, RLT cuts, SDP cuts
 * Trigonometric functions: Specialized approximations
 * These cuts progressively tighten the relaxation as the tree search proceeds


##### Spatial branching strategy

 * _Spatial branching_ extends MIP branching to continuous variables:

 * Branch on continuous variables to partition nonlinear terms' domains
 * Enables tighter convexification cuts in sub-problems
 * _Branch candidate evaluation_:

 * Uses standard MIP technology: strong branching and pseudocosts
 * Propagates and cuts from candidates before evaluation
 * No inherent preference between integer and continuous variables
 * By default prefers original over auxiliary variables

 * _Exception_ : When auxiliary branching leads to many bound changes at root
 * _Heuristics integration_:

 * MIP heuristics run normally during search
 * When MIP-feasible but NLP-infeasible solution is found, local NLP solver fixes integers and solves reduced problem
 * Uses MIP-feasible solution as initial values for NLP


##### Convexification Cuts & Spatial Branching

  _(graphic file NonLinear/cutsspat1.png)_
      

##### Convexification Cuts & Spatial Branching

  _(graphic file NonLinear/cutsspat2.png)_
      

##### Convexification Cuts & Spatial Branching

  _(graphic file NonLinear/cutsspat3.png)_
      

##### Convexification Cuts & Spatial Branching

  _(graphic file NonLinear/cutsspat4.png)_
      

##### Bounding Box

 * LP with auxiliary variables _can be unbounded_:

 * min \\\{x &#124; x<sup>2</sup> - x<sup>4</sup>≥ 0\\\}
 * Apply initial bound propagation and convexification cuts.
 * Solve the initial LP relaxation, if unbounded:

 * Impose artificial bounds on the original variables and resolve.
 * If still unbounded, impose bounds on the auxiliary variables.


##### Bounding Box

 * If bounding box was applied:

 * Xpress Global finds \(globally\) best solution _within those bounds_
 * Better solutions may exist outside those bounds
 * _Solstatus_ will be _Feasible_ instead of _Optimal_.
 * We cannot \(and do not\) declare global optimality in this case
 * Size of bounding box can be adjusted using control [globalboundingbox](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/GLOBALBOUNDINGBOX.html).
 * _Importance of tight bounds_:

 * Xpress Global _requires bounds_ on variables to function effectively
 * Tighter bounds on more variables lead to better performance and stronger cuts
 * Weak bounds result in weaker convexification cuts and slower solves or worse dual bounds


##### Nonlinear solver selection and tuning controls

 * Xpress provides various controls to tune nonlinear solver performance

 * Reasonable defaults are preconfigured, but tuning can significantly improve performance for specific problem types
 * _Solver selection controls_ to choose between local and global solvers:

 * [nlpsolver](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_NLPSOLVER.html): Switches between local and global solves
 * [localsolver](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_SOLVER.html): Switches between different local solvers \(SLP or Knitro\)
 * _Xpress Tuner_ supports all kinds of nonlinear solves:

 * Set [tunermethod](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/TUNERMETHOD.html) accordingly: 
     * 6: SLP
     * 7: MISLP
     * 9: Global


---
Note: _Important caution for SLP tuning:_ Tuner optimizes for faster solves, which can favor settings that quickly converge to poor local optima over settings that find better solutions more slowly. Always manually evaluate solution quality vs. solve time trade-offs when using tuner with local solvers
---


##### Global solver tuning

 * _Cutting plane controls_ for convexification:

 * [globalnuminitnlpcuts](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/GLOBALNUMINITNLPCUTS.html): How many cuts to separate and add to the root LP for each nonlinear term 
     * More cuts improve the root bound and may help with unboundedness
     * But will make LP solves more expensive

 * [globalnlpcuts](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/GLOBALNLPCUTS.html), [globaltreenlpcuts](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/GLOBALTREENLPCUTS.html): How many rounds of convexification cuts to add at each node before switching to branching
 * _Branching and propagation controls_:

 * [globalspatialbranchifpreferorig](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/GLOBALSPATIALBRANCHIFPREFERORIG.html): Whether to always branch on original columns \(1\) or consider both original and auxiliary columns \(0\)
 * [globalspatialbranchcuttingeffort](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/GLOBALSPATIALBRANCHCUTTINGEFFORT.html), [globalspatialbranchpropagationeffort](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/GLOBALSPATIALBRANCHPROPAGATIONEFFORT.html): Control how much effort to spend on cutting and propagation when evaluating branching entities

---
Note: Propagation and cutting on branching entities are important for good decisions but can be time and memory intensive
---


##### Global solver tuning

 * _Heuristic controls_:

 * [globallsheurstrategy](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/GLOBALLSHEURSTRATEGY.html): How aggressively to run SLP on integer-feasible node solutions
 * _Bound tightening_:

 * [globalpresolveobbt](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/GLOBALPRESOLVEOBBT.html): Whether to run optimization-based bound tightening at the root 
     * Off by default
     * Very costly \(up to two LP solves per column\)
     * Can improve bounds and lead to stronger cuts

 * Example of setting global solver controls: 
```
p.controls.globalnuminitnlpcuts = 10      # add 10 cuts per NL term at root
p.controls.globalnlpcuts = 5              # 5 rounds of cuts per node
```




##### Successive Linear Programming \(SLP\)

 * _SLP algorithm_: Iteratively solves linear approximations of the nonlinear problem

 * At each iteration, linearize nonlinear terms around current solution by introducing _delta-variables_ _𝑦_  and _penalty variables_ _𝑧_ :

  _(graphic file NonLinear/SLPreform.png)_
       * Solve the resulting LP to find a new iterate
 * Repeat until convergence \(variables and objective stabilize\)


##### Successive Linear Programming \(SLP\)

  _(graphic file NonLinear/SLP.png)_
      

##### SLP: Trust regions and penalty costs

 * _Trust regions (step bounds)_: Delta-variables are step-bounded with dynamic updates

 * Ensures LP solution stays in neighborhood of current point where linearization is valid
 * Prevents unbounded linearizations when approximation is poor
 * Step bounds adapt during solve based on progress
 * _Penalty costs_: Penalize constraint violations during iterations

 * Allows temporary infeasibility to escape poor regions
 * Fix penalty breakers if penalty terms become too large
 * Costs adjusted automatically to balance feasibility and objective improvement
 * Solve KKT subproblem to check for local optimality


##### SLP: Infeasibility


* Non-convex non-linear with feasible region. * Iterate solution _x<sup>k</sup>_ in infeasible region. * Can result in infeasible LP * Use penalty variables to make LP feasible. _(graphic file NonLinear/SLPinfeas.png)_ 


##### SLP convergence and local optima

 * _Convergence criteria_: SLP stops when solution stabilizes

 * _Strict convergence_: Variable values don't change significantly
 * _Extended convergence_: Objective value and feasibility stabilize
 * Multiple tolerance levels for different convergence stages
 * _Local optima behavior_: SLP finds local optima, not necessarily global

 * Smaller penalty costs and larger step bounds allow exploring bigger parts of the feasible region and potentially finding better local optima at the cost of slower convergence
 * Initial point significantly affects which local optimum is found
 * For problems with many local optima, use multistart or Xpress Global
 * _MISLP (Mixed-Integer SLP)_: Combines SLP with Branch-and-Bound

 * Three approaches: Solve NLP then round, MIP outer approximation, or nonlinear Branch&Bound
 * Only guarantees local optimality for given integer solution


##### What convergence looks like

  _(graphic file NonLinear/SLPconvergence.png)_
      

##### SLP tuning: Penalty costs

 * Penalty costs for constraint violations during iterations:

 * [slpobjtopenaltycost](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_OBJTOPENALTYCOST.html): Estimate initial penalty costs based on factor to objective coefficients 
     * Typically values between 1 and 100
     * Smaller values lead to more iterations
     * Higher values tend to find local optima very close to the initial point

 * [slperrorcostfactor](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_ERRORCOSTFACTOR.html): Factor by which to increase penalty costs in each iteration when rows are still infeasible 
     * Typically values between 1 and 5
     * Similar effect to slpobjtopenaltycost, but applied more gradually

 * Example: 
```
p.controls.nlpsolver = 1                  # use local solver
p.controls.localsolver = 0                # use SLP
p.controls.slpobjtopenaltycost = 10       # initial penalty factor
p.controls.slperrorcostfactor = 2         # penalty increase factor
```




##### SLP tuning: Convergence and reformulation

 * _Convergence controls_:

 * [slpconvergenceops](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_CONVERGENCEOPS.html): What kind of convergence to require before checking for KKT conditions 
     * 3: strict convergence
     * 15: extended convergence
     * 511: check KKT when not progressing any more
     * Can be useful if checking KKT conditions is particularly expensive

 * [slpfilter](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_FILTER.html): By default SLP returns best solution encountered; unset bit 0 to always get solution from final iterate
 * _Reformulation controls_:

 * [nlpreformulate](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_REFORMULATE.html): Decides whether `min`/`max`/`abs`/`pwl` should be handled as MIP constructs or nonlinear 
     * Handling them in SLP is usually faster but finds local optima instead of global ones
     * By default converts to MIP if problem becomes fully MIP



##### SLP tuning: Probing and advanced options

 * _Probing and bound tightening_:

 * [nlpprobing](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_PROBING.html): Apply bounds on columns and see if we can show infeasibility through propagation 
     * Values from 0 to 5 with increasing levels of probing
     * Decrease if it takes too long
     * Increase if running into unboundedness

 * _Advanced iteration controls_:

 * [slpdeltazlimit](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_DELTAZLIMIT.html): For how many iterations to keep small but nonzero derivatives 
     * Can be useful for avoiding bad local minima
     * Makes LP solves harder



##### Multistart for local solvers

 * Both SLP and Knitro can use _multistart_ with different initial points to find multiple local optima:

 * _[problem.msAddPreset](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/problem.msAddPreset.html)_: Create a given number of random initial points to start SLP from 
     * Use `xprs.MSSET_INITIALVALUES` preset

 * _[problem.msAddJob](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/problem.msAddJob.html)_: Manually add individual jobs to the multistart queue with handcrafted initial points or settings
 * Example with multistart: 
```
import xpress as xp

p = xp.problem()
# ... define model ...

# add 10 random initial points for multistart
p.msAddPreset(xp.constants.MSSET_INITIALVALUES, 10)

p.optimize()
```




##### User functions

 * A _user function_ enables the creation of an expression, the value of which is _computed through external code_:

 * Behaves the same as any other mathematical function, used in a formula to calculate the current value of a coefficient
 * Is normally _free-standing_  and needs no access to problem or other data apart from what it receives through its argument list
 * Use cases:

 * When an algebraic description is not possible, for example when working with a _simulation or machine learning_ model
 * Functions that are not supported by Xpress
 * Important considerations when using user functions:

 * Be aware of losses in _determinism_ and _performance_
 * _Speed considerations:_ User function evaluation can dominate solve time, especially if derivatives are computed numerically


##### User functions

 * Any user-defined function can be called within a problem by using the function _xpress.user()_: 
```
xp.user(f, a1, a2, ...)
```


 * Where `f` represents the user-defined function name and `a1, a2, ...` the necessary arguments, as in the example below:

```
def myfunc(v1, v2, data):
	model = MLmodel(v1, v2, data)   # mLmodel() defined elsewhere
	return model.results

data = readData()  # readData() defined elsewhere
x, y = p.addVariable(), p.addVariable()
p.setObjective(xp.user(myfunc, x, y, data))
```




##### User functions: Derivatives

 * _Derivative computation_ for user functions and model expressions:

 * _Numeric derivatives_: Used for user functions if derivatives not provided by the user

 * SLP queries f\(x + _εe<sub>n</sub>_ \) for all directions if derivatives not provided
 * Can become a significant bottleneck if function evaluation is costly
 * _Symbolic derivatives_: Default for smaller formulas, provides exact derivatives
 * _Automatic differentiation_: Default for larger formulas, efficient and accurate
 * _Providing user function derivatives_ can significantly improve performance:

 * Use specialized Python function types to provide derivative information
 * Many machine learning libraries in Python can provide derivatives automatically
 * See [xpress.user](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/xpress.user.html) documentation for details on providing derivatives
 * Control for user function evaluation:

 * [xslpevaluate](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_EVALUATE.html): By default \(0\) SLP tries to use derivatives to avoid costly re-evaluations if the new iterate is sufficiently close 
     * Set to 1 to force reevaluation if userfunction is discontinuous



##### MISLP tuning

 * MISLP \(Mixed-Integer SLP\) solves problems with both nonlinear and integer variables using three approaches:

 * _SLP-in-MIP_ \(default\): Nonlinear Branch&Bound with SLP solve in every node - most reliable
 * _SLP-MIP-SLP_: Relax integers, solve SLP, fix linearization and solve MIP, fix integers and resolve SLP - fastest but risky
 * _MIP-in-SLP_: Single SLP solve with linearizations as MIPs - faster when nonlinear part dominates
 * [slpmipalgorithm](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_MIPALGORITHM.html): Controls which MISLP algorithm to use: 
     * Set bit 9: run MIP-in-SLP \(usually not recommended\)
     * Set bit 10: run SLP-MIP-SLP \(fastest but most likely to run into local infeasibility or bad local optima\)

 * _Cutting planes and heuristics_:

 * [slpcutstrategy](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_CUTSTRATEGY.html): Set to -1/1/2/3 to enable MIP-cutting planes in MISLP 
     * Generally speeds up the solve
     * May lead to local infeasibility by cutting off bad local optima

 * [slpheurstrategy](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/nonlinear/HTML/XSLP_HEURSTRATEGY.html): Controls heuristics in MISLP 
     * When left at default, also takes [heuremphasis](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/HEUREMPHASIS.html) into account



##### Guidelines for solver choice and tuning

 * _When to use Global solver_:

 * Whenever a reliable bound on the optimal value is needed
 * Problems with many local optima
 * Infeasibility detection or repair
 * _When to use SLP over Global_:

 * When quick solves are crucial \(Global can be orders of magnitude slower, especially for NLPs\)
 * Large-scale problems where Global's branch-and-bound becomes prohibitive
 * Problems with user functions \(not supported by Global\)
 * _When to use Knitro_:

 * Highly nonlinear models
 * When SLP convergence is slow
 * _General tuning strategy_:

 * Start with default settings
 * Use Xpress Tuner to automatically find good parameter settings _(be careful with tuner for SLP/local solves - may optimize for speed over solution quality)_
 * Fine-tune specific controls based on problem characteristics


##### Piecewise linear \(PWL\) functions

 * Piecewise linear constraints define a variable as a _piecewise linear function of another variable_: 
     * Can be used to _model stepwise functions_ or to _approximate nonlinear functions_
     * Example for discounts on unit costs depending on the quantity of items bought: 

|  _(graphic file IntroMIPForm/pricebreak)_ * First 50 items: _COST<sub>1</sub> =_ $4 each * Next 50 items: _COST<sub>2</sub> =_ $3 each * Then, up to 200: _COST<sub>3</sub> =_ $2 each 

 * Quantity break points _x<sub>i</sub>_ : 0, 50, 100, 200
 * Cost break points _y<sub>i</sub>_  \( = total cost of buying quantity _x<sub>i</sub>_ \): 0, 200, 350, 550 

_y<sub>i</sub> = COST<sub>i</sub>· \(x<sub>i</sub>-x<sub>i-1</sub>\) + y<sub>i-1</sub>_ for _i=1,2,3_ 





##### Piecewise linear \(PWL\) functions

 * Piecewise linear functions can be intuitively added to a problem by using the _xp.pwl_\(`dict`\) method in constraints or objectives: 
     * Receives a _dictionary_ as argument that associates intervals with linear functions with: 
         * _Keys_: intervals specified as _two-element tuples_ \(must be pairwise disjoint, no overlap\)
         * _Values_: linear expressions \(or constants\). Function must use only one variable in all of the dictionary's values

     * Modeling the previous example where `y` is a piecewise linear function of `x`: 
```
x = p.addVariable(vartype=xp.integer, ub=200)
y = p.addVariable()
p.addConstraint(xp.pwl({(0, 50): 4*x,
                        (50, 100): 3*(x-50) + 200,
                        (100, 200): 2*(x-100) + 350]}) == y)
```




---
Note: The piecewise linear function is always univariate, i.e. there must always be only one input variable
---


##### Piecewise linear approximation of nonlinear functions

 * Piecewise linear constraints can also be used to _approximate nonlinear functions_: 
     * Approximating the function _sin\(5π\)_ , _∀ x_  in _\[0, 2/π\]_ , to be _maximized_:

  _(graphic file NonLinear/PWL10.png)_
      

 * Note: _Optimal breakpoint placement_ is itself an optimization problem - breakpoints can be decision variables


##### Piecewise linear approximation using  _p.addpwlcons_

 * The low-level function [problem.addPWLCons](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/problem.addPWLCons.html) can be used for creating and directly adding piecewise linear constraints to a problem: 
```
problem.addPWLCons(colind, resultant, start, xval, yval)
```


 * `colind`: integer array containing the input variables `x` of the piecewise linear functions
 * `resultant`: integer array containing the output variables `y` of the piecewise linear functions
 * `start`: integer array containing the start index of each constraint in the `xval` and `yval` arrays
 * `xval`: array containing the x-values of the breakpoints
 * `yval`: array containing the y-values of the breakpoints


---
Note: A PWL constraint `y = f(x)` consists of an \(input\) column `x`, a resultant \(output\) column `y` and a piecewise linear function `f` described by breakpoints `(xval,yval)`. The function does not need to be continuous - if there are jumps, the solver may return values at any point in the jump
---


##### Piecewise linear approximation using  _p.addpwlcons_

 1. Define breakpoints and values at breakpoints: 
```
N = 10       # number of segments
freq = 5     # frequency
step = (2 / math.pi) / (N - 1)  # width of each segment = domain / (N-1)
breakpoints = np.array([i * step for i in range(N)]) # breakpoints x
values = np.sin(freq * breakpoints)                  # value at breakpoints

```



 2. Define piecewise linear function using [p.addPWLCons](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/problem.addPWLCons.html): 
```
y = p.addVariable()         # auxiliary variable for 'resultant'

p.addPWLCons([x], [y], [0], breakpoints, values)
```



 3. Set `y` as the objective function to be maximized, and optimize: 
```
p.setObjective(y, xp.ObjSense.MAXIMIZE)

p.optimize()
	
```




##### Piecewise linear approximation using  _xp.pwl_

 1. Define breakpoints, values at breakpoints and _slopes_: 
```
N = 10       # number of segments
freq = 5     # frequency
step = (2 / math.pi) / (N - 1)  # width of each segment = domain / (N-1)
breakpoints = np.array([i * step for i in range(N)]) # breakpoints x
values = np.sin(freq * breakpoints)                  # value at breakpoints
slopes = freq * np.cos(freq * breakpoints)           # derivatives

```



 2. Define piecewise linear function using _list comprehension_ with [xp.pwl](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/xpress.pwl.html): 
```
pw = xp.pwl({(breakpoints[i], breakpoints[i+1]):
    values[i] + slopes[i] * (x - breakpoints[i]) for i in range(N - 1)})
```



 3. Set `pw` as the objective function to be maximized, and optimize: 
```
p.setObjective(pw, xp.ObjSense.MAXIMIZE)

p.optimize()
	
```




##### Piecewise linear approximation

 * Solution for _N = 10_: 
  _(graphic file NonLinear/PWLsol10.png)_
      


##### Piecewise linear approximation

 * Solution for _N = 100_: 
  _(graphic file NonLinear/PWLsol100.png)_
      


##### Python Notebook \[PN-4.2\]: Using PWL to approximate a nonlinear function

 * Navigate to _Exercise 4.2 - Using PWL to approximate a nonlinear function_
 * Run the code cells in _Exercise 4.2_ for progressively higher number of breakpoints $N$: 10, 15, 20, ...
 * Visualize the evolution of the piecewise linear approximation and the approximation of the nonlinear function


## <a id="chapmipsolspy"></a>Chapter 6 Multiple MIP solutions


##### Multiple MIP solutions

 * When solving a MIP problem, _FICO® Xpress will typically find a number of MIP solutions_ before finding the optimal solution: 
     * Sometimes you may want to use these intermediate solutions, or give the user the opportunity to stop the search early and use one of them

 * Once it has found a MIP solution, it will only search for _better MIP solutions_: 
     * The value of MIP solutions saved in the search always improves in the order that they are found

 * Finding multiple MIP solutions is the most common use case of library _callbacks_

---
Note: Xpress is designed to find good MIP solutions. It cannot be used to find all possible MIP solutions to a problem
---


##### Callback functions

 * To capture all MIP solutions found by Xpress, you need to _declare a callback function_
 * The library [callbacks](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/chCallbacks.html) are a collection of functions which allow _user–defined routines_ to be specified to Xpress Optimizer: 
     * Called at various stages during the optimization process, prompting the Optimizer to return to the user's program before continuing with the solution algorithm
     * In Python, names of functions for defining callbacks are of the form _problem.add*Callback()_

 * With the MIP solution callback method [problem.addIntsolCallback\(\)](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/problem.addIntsolCallback.html), you can access any new integer solution found, display it, store it, output it, allow the user to examine it and stop the search early,  _etc._ 


##### Main MIP-related callbacks

 * Logging callbacks: _message, lplog, barlog, cutlog, miplog_
 * Tracking the MIP branch-and-bound tree: _newnode, infnode, nodecutoff_
 * Callbacks that influence the MIP search:

 * _prenode, nodelpsolved_: tighten bounds, add solutions
 * _optnode_: tighten bounds, add solutions, add cuts, add branching candidates
 * _chgbranchobject_: override Xpress selected branching object
 * _preintsol_: tighten bounds, add solutions, add cuts, add branching candidates, reject MIP solution, adjust cutoff
 * Controls can be changed deterministically within node specific callbacks
 * Use _problem.getCallbackSolution()_ inside the defined function to retrieve the context specific solution

---
Note: Adding cuts or branching candidates is not yet supported for Global solves
---


##### MIP Node Callback Flow

  _(graphic file Opt/mipcbflow.png)_
      

##### Using callback functions in Python

 * Steps for using callbacks using the Python API: 
     1. Define a callback function \(say `exportsol`\) that is to be run at certain points in time \(for _p.addIntsolCallback()_, every time a new integer solution is found\):

```
def exportsol(prob, data, soltype, cutoff):
   with open('solutions.txt', 'a') as file:
      file.write(f"New solution: {prob.getCallbackSolution()}")
   
```

     3. Call the corresponding _problem.add*Callback()_ method with `exportsol` as its argument

```
p.addIntsolCallback(exportsol, data)  # assume data defined elsewhere
```

     5. Run the _p.optimize()_ command that launches the appropriate solver

 * A callback function is passed once as an argument and used possibly many times while a solver is running, and receives: 
     * A `problem object` declared with `p = xp.problem()`
     * A user-defined `data object` to read and/or modify information within the callback

     * The data object may be optional, depending on the callback type



##### MIP solution callback

 * Example for a callback function named `intsolcb` that is called every time a new integer solution is found via the _p.addIntsolCallback()_ method: 
```
import xpress as xp

def printsolcb(prob, data, soltype, cutoff):
	 # callback to be used when an integer solution is found defined here
		 print(f"Solution: {prob.getCallbackSolution()}")
	 
p = xp.problem()
p.read('myprob.lp')  # reads in a problem, let's say a MIP

p.addIntsolCallback(printsolcb, data)  # assume 'data' defined elsewhere
p.optimize()
```



---
Note: While the `function` argument is necessary for all  _p.add*Callback()_ functions, the `data` object can be specified as `None`. In that case, the callback function will be run with `None` as its data argument
---


##### Finding multiple MIP solutions

 * Xpress Optimizer finds increasingly better solutions: 
     * New solutions that are valued the same or worse than the current best are discarded by the Optimizer by default
     * The value of the _mipaddcutoff_ control parameter can be added to the current best solution's objective value to set a new cutoff
     * Since it is an absolute value, the sign must be set _depending on the objective sense_. Example for a _maximization_ problem:

```
p.controls.mipaddcutoff = -0.5 # accept solutions 0.5 worse than current cutoff
```


 * Setting _mipaddcutoff_ to a negative \(positive\) value for a maximization \(minimization\) problem allows the solver to find worse solutions


##### Adding MIP solutions

 * Provide Xpress Optimizer with a new _feasible, infeasible or partial_ MIP solution via the [problem.addMipSol\(\)](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML/problem.addMipSol.html) method:

```
     p.addMipSol(solval, colind, name)
```

 * If a _partial solution_ is provided:

 * if values are given for all discrete columns, these will be fixed to those values and the continuous part optimized
 * if some integer values are not defined, a local search will be run in an attempt to find any remaining integer feasible values
 * If the provided solution is found to be _infeasible_:

 * local search heuristic will be run in an attempt to find a close feasible integer solution
 * The method _can also be called from callbacks_

---
Hint: Check the [online TSP example](https://www.fico.com/fico-xpress-optimization/docs/latest/examples/python/GUID-EDE11C09-F189-30C8-8811-763F7F772943.html) that demonstrates the basic use of providing a full, feasible solution to warm-start a MIP solve
---


##### Python Notebook \[PN-5\]: Multiple MIP solutions

 * Navigate to _Exercise 5 - Multiple MIP solutions_ in the notebook

 1. Storing multiple MIP solutions via callbacks:

 * Examine the callback functions _printsol, exportsol, validatesol_ to understand what they are programmed to do
 * Run the code cell with the optimization model three times calling a different callback function each time and analyze the output\(s\)
 * In the last code cell of this part, set the _mipaddcutoff_ control value to `-0.5` and re-run the MIP model using `printsol` as callback:

 * How many additional solutions are found by the Optimizer ?
 3. Adding MIP solutions:

 * Run the code cell in part 5.2 and analyze the output log:

 * Has any of the randomly generated solutions resulted feasible ?
 * If not, has a feasible solution been obtained after applying local search to any of those initially infeasible solutions ?


## <a id="chapmoopy"></a>Chapter 7 Optimizing with multiple  objectives


##### Optimizing for different objectives sequentially

 * The _problem.setObjective()_ method allows users to add several _linear_ objectives for solving a problem for different objectives _sequentially_: 
     * Multiple calls to _p.setObjective()_ are allowed
     * The user _must define the `objidx` argument_ \(with consecutive integers starting with 0\) to indicate the multi-objective context and the sequence of objectives to consider
     * The model is run for each objective sequentially, thus _runs are independent of each other_
     * The `sense` of the the first objective \(`objidx=0`\) defines the default optimization sense for all objectives: 
         * To _reverse the optimization sense_ for secondary objectives, set the `weight` attribute to `-1`


```

      p.setObjective(x1, objidx=0)             # minimize first objective
      p.setObjective(x2, objidx=1, weight=-1)  # maximize second objective
      p.setObjective(...)                      # other objectives

      p.optimize()
		
```


 * The Optimizer will _print the logs for each sequential run_ and, in the end, a summary of the objective values found for each run: 
 * This can be useful to assess the maximum possible value for each objective




##### Optimizing with multiple objectives

 * The _problem.addObjective()_ method allows users to add one or more _linear_ objectives for solving _multi-objective optimization_ problems: 
     * Use _p.addObjective()_, possibly after an initial call to _p.setObjective()_, to create _additional objectives_ \(existing objectives will remain in the same problem\):

```
p.addObjective(obj1,obj2,...,priority=None,weight=None,abstol=None,reltol=None)
```


 * With at least one objective expression and a set of _optional_  arguments: 
 * `obj1,obj2,...`: expression\(s\) for the objective\(s\) to be added to the problem
 * _priority_ : priority for the new objective\(s\)
 * _weight_ : weight for the new objective\(s\); _negative values invert the sense of the objective_
 * _abstol_ : absolute tolerance for the new objective\(s\)
 * _reltol_ : relative tolerance for the new objective\(s\)



---
Note: A multi-objective problem may only contain linear objective functions. The problem itself may be of any kind supported by Xpress, but nonlinear objective terms must be modeled using a transfer variable
---


##### Optimizing with multiple objectives

 * Approaches followed by the Optimizer for solving multi-objective problems:

 * _Blended (or Archimedian) approach_: 
     * Applied when _objectives have equal priority_ \(their weights may be equal or different\)
     * Weighted sum optimization, setting as objective function the linear combination of the added objectives and their weights \(weights default to 1 if left undefined, giving an equally-weighted blend\)

 * _Lexicographic (or preemptive) approach_: 
     * Applied when _each objective has a different priority and a unit weight_
     * Xpress will solve the problem once for each distinct objective priority that is defined
     * All objectives from previous iterations are fixed to their optimal values within the tolerances specified in the configuration of the individual objective:

```
objective <= optimal_value * (1 + reltol) + abstol  # for minimization obj.
objective >= optimal_value * (1 - reltol) - abstol  # for maximization obj.
```


 * _Hybrid approach_: 
     * Applied when _objectives have both different priorities and different weights_
     * Xpress will solve the problem once for each distinct objective priority defined, optimizing in each iteration a linear combination of the objective functions with the same priority



##### Optimizing with multiple objectives

 * Examples: 
```
# blended (weighted sum) approach: equal priority, different weights
p.addObjective(2*x + y, priority=0, weight=-0.7) # maximize, higher weight
p.addObjective(y, priority=0, weight=0.3)        # minimize, lower weight

# lexicographic approach with setObjective()
p.setObjective(xp.Dot(x, return), sense=xp.ObjSense.MAXIMIZE, priority=1) # max. return
p.addObjective(variance, priority=0, weight=-1)                  # minimize risk

# hybrid approach with three objectives
p.addObjective(xp.Sum(x), priority=1, weight=0.5, reltol=0.1)  
p.addObjective(xp.Dot(A,x), priority=1, weight=0.3)  
p.addObjective(xp.Dot(B,x), priority=0, weight=-0.2)  

```



---
Hint: Check the [MULTIOBJOPS control](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/HTML/MULTIOBJOPS.html) to configure the behaviour of the optimizer when solving multi-objective problems
---


##### Python Notebook \[PN-6\]: Optimizing with multiple objectives

 * Navigate to _Exercise 6 - Multi-objective optimization_ in the notebook

 1. Blended \(or Archimedean\) and Lexicographic approaches:

 * Analyze the code in the first code cell, run it, and visualize the generated efficient frontier
 * Read the second code cell and run it. Check the solver logs and confirm that:

 * The Optimizer performs two solving procedures, printing the solver log for each one sequentially
 * The value for each objective is printed in the end of all runs
 * The resulting solution falls within the generated efficient frontier
 3. _Optional: Goal programming_ 

 * Read the problem description to become familiar with the model
 * Run the code cell and analyze the log. Which target is not achieved by the final solution ?

