declare
l1 number;
l2 number;
l3 number;
BEGIN
l1:=&l1;
l2:=&l2;
l3:=&l3;
IF(l1>l2) and (l1>l3) THEN
DBMS_output.put_line('Largest number is: '||l1);
elsIF(l2>l1) and (l2>l3) THEN
DBMS_output.put_line('Largest number is: '||l2);
else
DBMS_output.put_line('Largest number is: '||l3);
end IF;
end;
/

OUTPUT:
Enter value for l1: 8
old   6: l1:=&l1;
new   6: l1:=8;
Enter value for l2: 45
old   7: l2:=&l2;
new   7: l2:=45;
Enter value for l3: 3
old   8: l3:=&l3;
new   8: l3:=3;
Largest number is: 45

PL/SQL procedure successfully completed.