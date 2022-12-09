DECLARE
n int;
a int;
r int;
BEGIN
n:=&n;
DBMS_OUTPUT.PUT_LINE('Multiplication Table:'); 
FOR a in 1 .. 10 LOOP
r:=n*a;
DBMS_OUTPUT.PUT_LINE(n||'x'||a||'='||r); 
END LOOP;
END;
/

OUTPUT:
Enter value for n: 5
old   6: n:=&n;
new   6: n:=5;
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