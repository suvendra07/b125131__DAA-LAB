**Questions**

1. **Put them in Order:** Using implementation in C, place the given functions in a list by *increasing order of growth* for sufficiently large values of $n$.

| | | | |
| :---: | :---: | :---: | :---: |
| $n \log_2 n$ | $12\sqrt{n}$ | $\frac{1}{n}$ | $n^{\log_2 n}$ |
| $100n^2 + 6n$ | $n^{0.51}$ | $n^2 - 324$ | $50n^{0.5}$ |
| $2n^3$ | $3^n$ | $2^{32}n$ | $\log_2 n$ |

2. **Fair vs Biased coin:** Using simulation in C, show that the probability of getting a *HEAD* by tossing a *fair coin* is about $0.5$. Extend your simulation to compare fair vs biased coin-tossing experiments.
[Interesting Read] Check this article on arXiv titled "*Random Coin Tossing with unknown bias*" for more insight.

3. **Performance analysis of bubble sort:** Using C, implement two different versions of bubble sort simulation for randomised data sequences as follows:
   $(i)$ Bubble sort that terminates if the array is sorted before the $(n - 1)^{th}$ pass.
   $(ii)$ Bubble sort that always completes the $(n - 1)^{th}$ pass.
   Plot the number of comparisons in both cases to analyse their efficiency.

4. **Towers of Hanoi (ToH):** Simulate the solution to the ToH problem using C. Plot the total number of moves required for solving the problem of $n$-discs. What can you conclude about your algorithm from the plot obtained?

5. **Find the partition point:** Consider an array $A$ with $n$ elements containing a run of $0$'s followed by a run of $1$'s. Implement a method to find out the exact point of transition between them.

6. **Element uniqueness::** For given $n$ random numbers, implement a method in C to check if there are any duplicates. What can you conclude about your method for a sufficiently large value of $n$?
