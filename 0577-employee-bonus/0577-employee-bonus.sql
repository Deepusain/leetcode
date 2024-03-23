# Write your MySQL query statement below
SELECT Employee.name ,Bonus.bonus
from Employee 
LEFT JOIN Bonus ON Employee.empID = Bonus.empID
WHERE bonus < 1000 OR Bonus IS NULL ;