# Write your MySQL query statement below

SELECT class FROm courses
GROUP BY class  HAVING COUNT(student)>=5;