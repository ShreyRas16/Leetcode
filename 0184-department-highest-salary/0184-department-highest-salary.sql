# Write your MySQL query statement below
SELECT d.name as Department,e.name as Employee,e.salary as Salary
FROM Employee e
JOIN Department d
ON e.departmentId=d.id
WHERE e.salary=(
    SELECT MAX(e1.salary)
    FROM Employee e1
    WHERE e1.departmentId=e.departmentId
);