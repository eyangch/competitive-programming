-- Write your PostgreSQL query statement below

WITH ManagerSalary AS (
    SELECT e.id, e.name, e.salary, m.salary AS msalary FROM Employee AS e
    JOIN Employee as m on e.managerId=m.id
)
SELECT e.name AS Employee FROM ManagerSalary AS e
WHERE e.salary > e.mSalary;