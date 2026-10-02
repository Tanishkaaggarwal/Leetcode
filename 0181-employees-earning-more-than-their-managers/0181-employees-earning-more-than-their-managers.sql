# Write your MySQL query statement below
SELECT e1.name AS Employee
FROM employee e1 
JOIN Employee e2 ON e1.managerID = e2.id
where e1.salary>e2.salary;