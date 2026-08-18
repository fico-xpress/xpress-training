# FICO Xpress Training

This repository contains training material for the FICO&reg; Xpress Optimization suite. It is aimed at users who want to learn how to model and solve optimization problems with Xpress, from first steps through to advanced solver usage.

The material is organised into three self-contained courses. Each course provides slide decks as PDF, together with a Markdown rendering of the same content.

## Contents

### `python/` &mdash; Xpress Python API

A complete introduction to the FICO&reg; Xpress Python interface, aimed at users with a Python background who are new to Xpress.

* [`pdf/`](python/pdf) &mdash; full course slide deck ([python-full-course.pdf](python/pdf/python-full-course.pdf)) plus one PDF per topic: Introduction, Installation, Modeling, Solving, Read/Write, NumPy, Pandas, Hints, Indicators, SOS, Piecewise Linear, General Constraints, Multi-Objective, Nonlinear, Controls, Callbacks.
* [`md/`](python/md) &mdash; Markdown rendering of the full course ([python-full-course.md](python/md/python-full-course.md)).

### `solver/` &mdash; Xpress Solver

Advanced solver topics for users already familiar with Xpress, using the Python interface for the examples.

* [`pdf/`](solver/pdf) &mdash; full course slide deck ([solver-full-course.pdf](solver/pdf/solver-full-course.pdf)) plus one PDF per topic: Introduction, MIP Solving, Tolerances and Scaling, Infeasibility Handling, Nonlinear Solving, Multiple MIP Solutions, Multi-Objective Optimization.
* [`md/`](solver/md) &mdash; Markdown rendering of the full course ([solver-full-course.md](solver/md/solver-full-course.md)).
* [`exercises/`](solver/exercises) &mdash; hands-on exercise notebook ([Xpress_solver_training.ipynb](solver/exercises/Xpress_solver_training.ipynb)) and worked solutions ([Xpress_solver_training_Solutions.ipynb](solver/exercises/Xpress_solver_training_Solutions.ipynb)), aligned with the course chapters, plus the required data files. The notebooks run on Xpress 9.9 with the free Community license.

### `mosel/` &mdash; Xpress Mosel

An introduction to modeling and problem solving with the FICO&reg; Xpress Mosel language.

* [`pdf/`](mosel/pdf) &mdash; full course slide deck ([mosel-full-course.pdf](mosel/pdf/mosel-full-course.pdf)) plus one PDF per topic: Introduction and Xpress overview, Modeling with Mosel, Embedding Mosel models, Summary and further information.
* [`md/`](mosel/md) &mdash; Markdown rendering of the full course ([mosel-full-course.md](mosel/md/mosel-full-course.md)).
* [`exercises/`](mosel/exercises) &mdash; project worksheet ([MoselintroProjects.pdf](mosel/exercises/MoselintroProjects.pdf)) with a set of hands-on modeling exercises: starter models in [`Projects/`](mosel/exercises/Projects), worked [`Solutions/`](mosel/exercises/Solutions), and the shared data files in [`data/`](mosel/exercises/data) (read by the models via the relative path `../data/`). Some exercises also refer to example models shipped with the Xpress distribution (under the `examples/` directory of your installation).

## Getting started with Xpress

* Install the FICO&reg; Xpress Python interface with `pip install xpress`. This includes a free Community license that solves small to medium sized problems.
* [Python interface documentation](https://www.fico.com/fico-xpress-optimization/docs/latest/solver/optimizer/python/HTML)
* [FICO Xpress Python notebook examples](https://github.com/fico-xpress/python-notebooks)
* [FICO Xpress documentation](https://www.fico.com/fico-xpress-optimization/docs/latest/overview.html)

### Obtaining Mosel

If you do not have any recent installation of FICO Xpress, download the free Xpress Community Edition from [Xpress Community Edition download](https://content.fico.com/xpress-optimization-community-license), located on FICO's website. Please note that this download is solely governed under FICO's Xpress Community License, [Xpress Shrinkwrap License Agreement](https://www.fico.com/en/shrinkwrap-license-agreement-fico-xpress-optimization-suite-on-premises).

## Legal and license requirements

The material in this repository is licensed under the Apache License, Version 2.0. You may not use these files except in compliance with the License. You may obtain a copy of the License at [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0), or see [LICENSE](LICENSE) for the full license text. Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

The exercises use FICO&reg; Xpress software. By running them, you agree to the Community License terms of the [Xpress Shrinkwrap License Agreement](https://www.fico.com/en/shrinkwrap-license-agreement-fico-xpress-optimization-suite-on-premises) with respect to the FICO&reg; Xpress software. See the [licensing options](https://www.fico.com/en/fico-xpress-trial-and-licensing-options) overview for additional details and information about obtaining a paid license.
