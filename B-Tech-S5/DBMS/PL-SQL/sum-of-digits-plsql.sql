DECLARE
n INT;
r INT;
a INT :=0;
BEGIN
n:=&n;
WHILE n>0 LOOP
r:=MOD(n,10);
a:= a+r;
n:=n/10;
END LOOP;
DBMS_OUTPUT.PUT_LINE('Sum is: '||a);
END;