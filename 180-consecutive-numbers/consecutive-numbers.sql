
select distinct(l1.num) as ConsecutiveNums
from Logs l1
join Logs l2 on l2.id-1=l1.id
join Logs l3 on l3.id-1=l2.id
where l1.num=l2.num and l2.num=l3.num;