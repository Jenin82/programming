create table event(id int primary key, name varchar(30),city varchar(30));
create table participant(id int primary key, name varchar(30),eid int references event(id),age int);
create table prize(id int primary key auto_increment,money int,eid int references event(id),rank1 int);
create table winner(pid int references prize(id),id int references participant(id));

delimiter //
CREATE TRIGGER t after insert on event for each row
begin
declare
t int;
set t = new.id;
insert into prize(money,eid,rank1) values(1500,t,1);
insert into prize(money,eid,rank1) values(1000,t,2);
insert into prize(money,eid,rank1) values(500,t,3);
end;
//

insert into event values(1001,'A','X');