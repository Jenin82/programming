EXP- IMPLEMENTATION OF TRIGGER

AIM:
To implement triggers

Program:
1. Create the the following tables:
    Event(event ID, name, desc, city)
    Participant(player ID, name, event ID, gender, year)
    Prizes(prize ID, money, event ID, rank, year)
    Winners(prize ID, player ID)

-> create table event(id INT PRIMARY KEY,name VARCHAR(30),description VARCHAR(30),city VARCHAR(30));
-> insert into event VALUES(1001,'A','','Ernakulam'), (1002,'B','','Trissur'), (1003,'C','','Ernakulam'),(1004,'D','','Ernakulam'),(1005,'E','','Trissur');
select * from event;
+------+------+-------------+-----------+
| id   | name | description | city      |
+------+------+-------------+-----------+
| 1001 | A    |             | Ernakulam |
| 1002 | B    |             | Trissur   |
| 1003 | C    |             | Ernakulam |
| 1004 | D    |             | Ernakulam |
| 1005 | E    |             | Trissur   |
+------+------+-------------+-----------+
5 rows in set (0.00 sec)

-> create table parti(id INT PRIMARY KEY,name VARCHAR(30),eid INT REFERENCES event(id),gender VARCHAR(30),year INT);
-> insert into parti VALUES(10001,'H',1001,'M',2000),(10002,'I',1002,'F',2001),(10003,'J',1003,'F',2001),(10004,'K',1004,'M',2003),(10005,'L',1005,'M',2000);
select * from parti;
+-------+------+------+--------+------+
| id    | name | eid  | gender | year |
+-------+------+------+--------+------+
| 10001 | H    | 1001 | M      | 2000 |
| 10002 | I    | 1002 | F      | 2001 |
| 10003 | J    | 1003 | F      | 2001 |
| 10004 | K    | 1004 | M      | 2003 |
| 10005 | L    | 1005 | M      | 2000 |
+-------+------+------+--------+------+
5 rows in set (0.00 sec)

-> create table prizes(id INT PRIMARY KEY auto_increment,money INT,eid INT REFERENCES event(id),rank1 INT,year INT);

-> create table winner(prizeID INT REFERENCES prizes(id),pid INT REFERENCES parti(id));
-> insert into winner values(20001,10001);
select * from winner;
+---------+-------+
| prizeID | pid   |
+---------+-------+
|   20001 | 10001 |
+---------+-------+
1 row in set (0.00 sec)


2. Write a trigger to make sure that for every new event created 3 prizes are created in prize table (1st prize - 1500, 2nd prize - 1000, 3rd prize - 500)
-> delimiter;
create trigger t after insert on event for each row
begin
declare 
t int;
set t = new.id;
insert into prizes(money,eid,rank1,year) values(1500,t,1,2022);
insert into prizes(money,eid,rank1,year) values(1000,t,2,2022);
insert into prizes(money,eid,rank1,year) values(500,t,3,2022);
end ;
//

-> insert into event VALUES(1006,'A','','Ernakulam');
Query OK, 1 row affected (0.00 sec)

-> select * from prizes;
+----+-------+------+-------+------+
| id | money | eid  | rank1 | year |
+----+-------+------+-------+------+
|  1 |  1500 | 1006 |     1 | 2022 |
|  2 |  1000 | 1006 |     2 | 2022 |
|  3 |   500 | 1006 |     3 | 2022 |
+----+-------+------+-------+------+
3 rows in set (0.00 sec)