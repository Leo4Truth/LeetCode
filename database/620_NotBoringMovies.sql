/* 
    Table: Cinema
    +----------------+----------+
    | Column Name    | Type     |
    +----------------+----------+
    | id             | int      |
    | movie          | varchar  |
    | description    | varchar  |
    | rating         | float    |
    +----------------+----------+
    Write an SQL query to report the movies with an odd-numbered ID and a description that is not "boring".
 */

select *
from `Cinema`
where mod(`id`, 2) = 1 and `description` != "boring"
order by `rating` desc;


