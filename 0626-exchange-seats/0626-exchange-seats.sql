# Write your MySQL query statement below


SELECT id,
case 
when mod(id,2)=0 then lag(student) OVER(order BY id)
else IFNULL (lead(student) OVER(order by id),student) end as student
from Seat;