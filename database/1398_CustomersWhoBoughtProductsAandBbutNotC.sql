# SQL Schema
Create table If Not Exists Customers (customer_id int, customer_name varchar(30));
Create table If Not Exists Orders (order_id int, customer_id int, product_name varchar(30));
Truncate table Customers;
insert into Customers (customer_id, customer_name) values ('1', 'Daniel');
insert into Customers (customer_id, customer_name) values ('2', 'Diana');
insert into Customers (customer_id, customer_name) values ('3', 'Elizabeth');
insert into Customers (customer_id, customer_name) values ('4', 'Jhon');
Truncate table Orders;
insert into Orders (order_id, customer_id, product_name) values ('10', '1', 'A');
insert into Orders (order_id, customer_id, product_name) values ('20', '1', 'B');
insert into Orders (order_id, customer_id, product_name) values ('30', '1', 'D');
insert into Orders (order_id, customer_id, product_name) values ('40', '1', 'C');
insert into Orders (order_id, customer_id, product_name) values ('50', '2', 'A');
insert into Orders (order_id, customer_id, product_name) values ('60', '3', 'A');
insert into Orders (order_id, customer_id, product_name) values ('70', '3', 'B');
insert into Orders (order_id, customer_id, product_name) values ('80', '3', 'D');
insert into Orders (order_id, customer_id, product_name) values ('90', '4', 'C');


# Write your MySQL query statement below
# Solution 1
select a.customer_id, a.customer_name
from ((
		select distinct customers.customer_id, customers.customer_name
		from orders left join customers
		on orders.customer_id = customers.customer_id
		where orders.product_name = 'A'
	) as a
    inner join (
		select distinct customers.customer_id, customers.customer_name
		from orders left join customers
		on orders.customer_id = customers.customer_id
		where orders.product_name = 'B'
    ) as b
    on a.customer_id = b.customer_id
)
where a.customer_id not in (
	select distinct customers.customer_id
	from orders left join customers
	on orders.customer_id = customers.customer_id
	where orders.product_name = 'C'
);

# Solution 2
# without join
with tmp as (
	select customer_id
	from orders
	where orders.product_name = 'A' or  orders.product_name = 'B'
    group by customer_id
    having count(distinct product_name)=2
)
select *
from customers
where
	customer_id in (select * from tmp) and 
    customer_id not in (select distinct customer_id from orders where product_name ='C');


