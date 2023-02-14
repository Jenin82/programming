create table student(id int primary key,name varchar(30),dept varchar(30),CGPA decimal(4,2));

insert into student values (101,'A','CSE',8.9);
insert into student values (102,'B','ME',6.9);
insert into student values (103,'C','CE',7.2);
insert into student values (104,'D','EEE',7.5);

declare
begin
insert into student values ('S105','E','CSE',6.5);
exception
when invalid_number then
dbms_output.put_line('Invalid ID');
end;
/

declare
n student.name%type;
name_null exception;
begin
if n is null then
raise name_null;
insert into student values ('105','','CSE',6.5);
end if;
exception
when name_null then
dbms_output.put_line('Inalid name');
end;
/