create Table account (name varchar(30),balance float(12,2),acc_no int PRIMARY KEY);

INSERT INTO account VALUES('A',29000.5,1001),('B',5500.23,1002),('C',34500.3,1003);

DELIMITER //
CREATE Procedure insertAcc (in n varchar(30),in b float(12,2),in a int)
begin
INSERT INTO account VALUES (n,b,a);
end //
DELIMITER;
call insertAcc ('D',78000.36,1004);

delimiter //
create Procedure fine ()
begin
update account set balance=balance-100 where balance<10000;
end //
delimiter;
call fine ();

delimiter //
create Procedure updatename(in a int,in n varchar(30))
begin
update account set name=n where acc_no=a;
end //
delimiter;
call updatename(1001,'Tim');