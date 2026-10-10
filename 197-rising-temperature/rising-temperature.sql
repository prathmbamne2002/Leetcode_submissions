 select t1.id 
 from Weather t1,Weather t2
 Where datediff(t1.recordDate,t2.recordDate)=1 and t1.temperature>t2.temperature;
