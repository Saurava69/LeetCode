# Write your MySQL query statement below
select IF(COUNT(*) = 1, num, null) as num 
from MyNumbers
group by num
order by num desc

limit 1 