# Write your MySQL query statement below

SELECT  e1.name as Employee from Employee e1
WHERE  e1.salary > (SELECT e2.salary from Employee e2 WHERE
 e2.id = e1.managerId)
