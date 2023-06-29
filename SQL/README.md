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
#### 4. Write an SQL query to create an empty table with the same structure as some other table.


```bash
   CREATE TABLE Newtable
   SELECT * FROM Employee WHERE 1 = 0;
```
1 = 0 Will Be false so only structure will be copied no data will Copy


#### 5. Write an SQL query to create a table with the same data and Structure as some other table.

```bash
   CREATE TABLE Newtable
   SELECT * FROM Employee;
```

#### 6. Write an SQL query to fetch only even rows from the table.
In case we have an auto-increment field e.g. EmpId then we can simply use the below query-
```bash
   SELECT * FROM EmployeeDetails 
   WHERE MOD (EmpId, 2) = 0;
```

In case we don’t have such a field then we can use the below queries.
Using Row_number in SQL server and checking that the remainder, when divided by 2, is 1-
```bash
   SELECT E.EmpId, E.Project, E.Salary
   FROM (
    SELECT *, Row_Number() OVER(ORDER BY EmpId) AS RowNumber
    FROM EmployeeSalary
    ) E
   WHERE E.RowNumber % 2 = 0;
```
Using a user-defined variable in MySQL-
```bash
   SELECT *
   FROM (
      SELECT *, @rowNumber := @rowNumber+ 1 rn
      FROM EmployeeSalary
      JOIN (SELECT @rowNumber:= 0) r
     ) t 
   WHERE rn % 2 = 0;
```

#### 7. Write an SQL query to fetch only odd rows from the table.
In case we have an auto-increment field e.g. EmpId then we can simply use the below query-
```bash
   SELECT * FROM EmployeeDetails 
   WHERE MOD (EmpId, 2) = 1;
```

In case we don’t have such a field then we can use the below queries.
```bash
   SELECT E.EmpId, E.Project, E.Salary
   FROM (
    SELECT *, Row_Number() OVER(ORDER BY EmpId) AS RowNumber
    FROM EmployeeSalary
    ) E
   WHERE E.RowNumber % 2 = 1;
```
Using a user-defined variable in MySQL-
```bash
   SELECT *
   FROM (
      SELECT *, @rowNumber := @rowNumber+ 1 rn
      FROM EmployeeSalary
      JOIN (SELECT @rowNumber:= 0) r
     ) t 
   WHERE rn % 2 = 1;
```

#### 8. Write an SQL query to remove duplicates from a table without using a temporary table.
In case we can use DELETE with INNER JOIN
```bash
   DELETE E1 from EmployeeTable E1
   INNER JOIN EmployeeDetails E2
   WHERE E1.EmpId > E2.EmpId
   AND E1.FullName = E2.FullName
   AND E1.ManagerID = E2.ManagerID // Basically We habe to write all Attb here
   AND E1.DataOfJoining = E2.DataogJoining
   AND E1.city = E2.city
```