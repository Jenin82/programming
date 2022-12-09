DECLARE
n INT;
r INT;
a INT :=0;
BEGIN
n:=&n;
WHILE n>0 LOOP
r:=MOD(n,10);
a:= a+r;
n:=TRUNC(n/10);
END LOOP;
DBMS_OUTPUT.PUT_LINE('Sum is: '||a);
END;
/

OUTPUT:
Enter value for n: 123
old   6: n:=&n;
new   6: n:=123;
Sum is: 6

PL/SQL procedure successfully completed.