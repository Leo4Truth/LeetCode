# solution 1
select Email
from (
    select count(*) as email_count, Email
    from Person
    group by Email
) as tmp
where email_count > 1;


# solution 2
select Email
from Person
group by Email
having count(Email) > 1;