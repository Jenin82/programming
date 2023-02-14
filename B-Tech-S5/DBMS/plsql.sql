LARGEST OF THREE NUMBERS:

declare
l1 number;
l2 number;
l3 number;
begin
l1:=&l1;
l2:=&l2;
l3:=&l3;
if (l1>l2) and (l1>=l3) then
dbms_output.put_line(l1 || ' is the largest');
elsif (l2>l1) and (l2>l3) then
dbms_output.put_line(l2 || ' is the largest');
else
dbms_output.put_line(l3 || ' is the largest');
end if;
end;
/


SUM OF DIGITS

declare
n number;
r number;
s int;
begin
n:=&n;
s:=0;
while n<>0 loop
r:=mod(n,10);
s:=s+r;
n:=trunc(n/10);
end loop;
dbms_output.put_line('sum of digits = ' || s);
end;
/ 


FACTORIAL

declare
n number;
s int;
begin
n:=&n;
s:=1;
while n>0 loop
s:=s*n;
n:=n-1;
end loop;
dbms_output.put_line('sum of digits = ' || s);
end;
/


MULTIPLICATION TABLE

declare
n number;
s int;
l int;
begin
n:=&n;
l:=&l;
for i in 1 .. l loop
s:=i*n;
dbms_output.put_line(i || 'x' || n || '=' || s);
end loop;
end;
/
