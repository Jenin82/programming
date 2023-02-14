create Table product(id int PRIMARY KEY, name varchar(30),cost float(12,2),price float(12,2));

insert into product VALUES(101,'A',10.5,20),(102,'B',13.5,25),(103,'C',14.5,25);

delimiter //
create function profit(cost float,price float) returns float(12,2)
begin
declare profit float(12,2);
set profit = price - cost;
return profit;
end //
delimiter;
select *, profit(cost, price) as profit from product;

delimiter //
create Procedure incPrice()
begin
update product set price = price + price*0.5;
select * from product;
end //
delimiter;
call incPrice();