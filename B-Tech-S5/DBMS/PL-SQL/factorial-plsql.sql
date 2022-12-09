DECLARE
n INT;
r INT := 1;
BEGIN
n:=&n;
WHILE n>0 LOOP
r:=r*n;
n:=n-1;
END LOOP;
DBMS_OUTPUT.PUT_LINE('Factorial is: '||r);
END;
/

OUTPUT:
Enter value for n: 5
old   5: n:=&n;
new   5: n:=5;
Factorial is: 120

PL/SQL procedure successfully completed.