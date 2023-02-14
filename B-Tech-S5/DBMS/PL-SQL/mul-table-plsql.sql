DECLARE
n int;
a int;
r int;
l int;
BEGIN
n:=&n;
l:=&l;
DBMS_OUTPUT.PUT_LINE('Multiplication Table:'); 
FOR a in 1 .. l LOOP
r:=n*a;
DBMS_OUTPUT.PUT_LINE(n||'x'||a||'='||r); 
END LOOP;
END;
/

OUTPUT:
Enter value for n: 5
old   7: n:=&n;
new   7: n:=5;
Enter value for l: 10
old   8: l:=&l;
new   8: l:=10;
Multiplication Table:
5x1=5
5x2=10
5x3=15
5x4=20
5x5=25
5x6=30
5x7=35
5x8=40
5x9=45
5x10=50

PL/SQL procedure successfully completed.