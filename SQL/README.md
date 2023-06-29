# SQL Query

#### 1. Write SQL query to find the 3rd highest salary from a table without using the TOP/limit keyword.
Using Correlated Query is the best Option to eliminate Top/Limit
put n = 3

```bash
   SELECT salary
   FROM Empsalary Emp1
   WHERE (N-1) = (
                   SELECT count(DISTINCT(Emp2.salary))
                   FROM Empsalary Emp2
                   WHERE Emp2.salary > Emp1.Salary
                 )
```
#### 2. Write SQL query to find the 3rd highest salary from a table.

Put n = 3

Using Top Keyword (SQL server)
```bash
   SELECT TOP 1 Salary
   FROM (
          SELECT TOP N salary
          FROM Employee
          ORDER BY Salary DESC
   )
   ORDER BY Salary ASC;
```
Using LIMIT Keyword (MYSOL server)
```bash
   SELECT Salary
   FROM Employee
   ORDER BY Salary DESC LIMIT N-1,1; 
```
ORDER BY DESC will give result in Desending Order Inner Query will Return From Bottom N Highest

#### 3. Write SQL query to find N top Records.

Using Top Keyword(SQL server)
```bash
   SELECT TOP N * 
   FROM Emplyoee
   ORDER BY Salary DESC;
```
Using LIMIT Keyword(MYSQL)
```bash
   SELECT *
   FROM Emplyoee
   ORDER BY Salary DESC LIMIT N;
```