

<p align="center">
    <strong>Exhaustive search</strong>
</p>
<p align="center">
    A brute force solution to a problem involving search for an <br />
element with a special property usually among element with a special property, usually among<br />
combinatorial objects such as permutations, combinations, <br />
or subsets of a set.<br />

<br />
    </p>
<p align="center">
    <strong>Method</strong>
* Generate a list of all potential solutions to the problem a list of all potential solutions to the problem<br />
in a systematic manner
    * all solutions are eventually listed
    * no solution is repeated
* aluate potential solutions one by one, disqualifying <br />
infeasible ones and for an optimization problem infeasible ones and, for an optimization problem, <br />
keeping track of the best one found so far<br />
    * CHANGE: Remove `setDefaultXYZ()`
    * ADD: Add `init()`
* When search ends, announce the solution(s) found
</p>
<p align="center">
* Examples
    * Traveling Salesperson Problem (TSP)
    *  Knapsack Problem,etc.
</p>
