# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary
FROM Employee 
WHERE Employee.salary<(
    SELECT MAX(salary)
    FROM Employee
)
ORDER BY salary DESC
LIMIT 1;