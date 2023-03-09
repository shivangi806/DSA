# Write your MySQL query statement below
select email as Email from person where email is not null group by email having count(email) > 1;