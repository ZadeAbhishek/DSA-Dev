# Data Structures and Algorithms + Development Projects

Welcome to this GitHub repository that provides a comprehensive collection of Data Structures and Algorithms (DSA) concepts along with solutions to common coding questions. Additionally, it includes various React.js projects to demonstrate practical implementations and usage of these DSA concepts in real-world scenarios.

### INDEX

* [Time Complexity Contraints Table](#time-complexity-contraints-table)
* [Problem Solving Techniques](#problem-solving-strategies)
* [JavaScript Event Loop Diagram](#javascript-event-loop)
* [Repository Setup Guide](#setup-guide)

## 🚀 About Me

I am a fresher looking for an SDE Role. I am a Google Summer of Code 2021 participant with skills in Web Development and Machine Learning. I have also worked on various projects, such as MQTT servers using Flutter.


## Time Complexity Contraints Table

| Contraints               | Time Complexity |
| --------                 | -------  |
| 10<sup>18</sup>          | O(logN)  |
| 10<sup>8</sup>           | O(N)     |
| 10<sup>6</sup>           | O(NlogN) |
| 10<sup>4</sup>           | O(N<sup>2</sup>)|
| 500                      | O(N<sup>3</sup>)|
| 85-90                    | O(N<sup>4</sup>)|
| 20                       | O(2<sup>N</sup>)|
| 11                       | O(N!)|


## Problem Solving Strategies

### Recursive and Dynamic Programming

When you have access to the solution for smaller instances of a given problem, you can use recursive or dynamic programming techniques to construct the solution to the original problem efficiently. This involves breaking the problem into smaller subproblems and solving them independently before combining their solutions to solve the larger problem.

### Divide and Conquer Strategy

Divide and Conquer involves breaking the problem into two or more smaller and independent subproblems and then solving the original problem using the solutions to these subproblems. It's particularly useful for problems that can be easily solved when broken down into simpler components.

### Case Analysis

For certain problems, you can split the input or execution into multiple cases and solve each case independently. This approach is helpful when different cases require different strategies to reach a solution.

### Generalization

Sometimes, a problem can be subsumed by a more general problem that is easier to solve. If you can identify such a generalization, you can solve the more general problem and then map the solution back to the original problem.

### Data Structures

Consider whether there are specific data structures that directly map to the given problem. Choosing appropriate data structures can significantly simplify the problem-solving process.

### Iterative Refinement

Starting with a brute-force solution, you can iteratively refine it to improve its efficiency and effectiveness. This involves formalizing the brute-force approach and then optimizing it step by step.

### Small Examples

Finding solutions to small concrete instances of the problem can help you understand the patterns and properties that can be generalized to solve arbitrary instances of the problem.

### Reduction

If you encounter a problem that bears similarities to another problem with a known solution, you can use the known solution as a subroutine to solve the current problem.

### Graph Modeling

You can describe the problem using graphs and utilize existing graph algorithms to solve it efficiently. This approach is particularly useful for problems with graph-like structures.

### Write an Equation

Expressing the relationships and constraints in the problem using equations can provide valuable insights into the problem's nature and lead to an analytical solution.

### Auxiliary Element

Introducing new elements or modifications to the problem can help you approach a solution more effectively. This could involve transforming the problem or adding additional constraints.

### Variation

If you find a slightly different problem that can be solved easily, you can try to map it back to your original problem, thus solving the initial problem indirectly.

### Parallelism

In some cases, the problem can be decomposed into subproblems that can be solved independently and concurrently on different machines, leveraging parallel computing power.

### Caching

Save intermediate results or solutions to avoid redundant computations and look them up when needed, which can significantly speed up the overall solving process.

### Symmetry

Exploit any symmetry in the input or solution space to reduce the search space and optimize the problem-solving process.

## JavaScript Event Loop
![Event LOOP](./StudyPDFs/EventLoop.gif)

## Setup Guide

### From Vscode Extension

1. Install Docker.
2. Install Dev-container.
3. Run the following commands in the terminal:

```bash
sudo groupadd docker
sudo usermod -aG docker $USER
```

4. Start Docker:

```bash
sudo systemctl start docker
```

5. Build Docker Image for Linux:

```bash
sudo docker build . -t <ImageName>
```

6. Start the Docker Image:

```bash
sudo docker run -it --rm -v `pwd`:/work <ImageName/Id>
```

7. Directly run Step 1: Script Change User Permission:

```bash
chmod u+x run.sh
sed -i -e 's/\r$//' run.sh
```

(Change your Docker name in run.sh)

8. Directly run Step 2: After the first time, follow step 2 only:

```bash
./run.sh
```

9. List the Docker Image:

```bash
sudo docker container ls
```

10. Stop the Docker Image:

```bash
sudo docker stop container_ID
```

### Build Docker Image for Windows:

```bash
docker build . -t <ImageName/Id>
```

### Start the Docker Image:

```bash
docker run -it --rm -v ${pwd}:/work <ImageName/Id>
```

## Additional Notes

Finally, open files in Remote Server Vscode using the Remote Vscode Extension. Install C++ and Cmake extensions for a smooth development experience.

Check Total Files:

```bash
git ls-files | wc -l
git ls-files "./*.json" | wc -l
```

Caution: Always keep your date and time updated for both operating systems.