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