create table emp(id int primary key, name varchar(30),salary decimal(12,2));

insert into emp values(101,'A',30000.45);
insert into emp values(102,'B',452.6);
insert into emp values(103,'C',75122.80);

create or replace package emp_sal as
procedure find_sal(e_id emp.id%type);
end emp_sal;
/

create or replace package body emp_sal as
	procedure find_sal(e_id emp.id%type) is sal emp.salary%type;
		begin
		select salary into sal from emp where id = e_id;
		dbms_output.put_line('Salary = ' || sal);
	end find_sal;
end emp_sal;
/

declare
code emp.id%type := &code;
begin
emp_sal.find_sal(code);
end;
/