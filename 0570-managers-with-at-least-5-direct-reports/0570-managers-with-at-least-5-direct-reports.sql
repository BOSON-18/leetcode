-- SELECT e1.name FROm Employee e1 
-- LEFT JOIN employee e2 ON e1.id=e2.managerId
-- GROUP BY e1.id
-- HAVING COUNT(e2.name)>=5;

# Write your MySQL query statement below
select name from Employee 
where id in (select managerId from Employee group by managerId 
having count(managerId)>4);