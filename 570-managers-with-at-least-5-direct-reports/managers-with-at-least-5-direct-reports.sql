
select e1.name
from Employee e1,Employee e2
where e1.id = e2.managerId
group by e1.id,e1.name
having count(e2.id)>=5;
