declare 
r number;
begin 
update student set CGPA = CGPA + 1;
if sql%notfound then
dbms_output.put_line('no student found');
elsif sql%found then
r:=sql%rowcount;
dbms_output.put_line('Student found and ' || r || 'student record updated');
end if;
end;
/

declare
id student.id%type;
name student.name%type;
cgpa student.CGPA%type;
cursor stu is select id,name,CGPA from student;
begin
open stu;
loop
fetch stu into id,name,cgpa;
exit when stu%notfound;
dbms_output.put_line(id || name || cgpa);
end loop;
close stu;
end;
/

