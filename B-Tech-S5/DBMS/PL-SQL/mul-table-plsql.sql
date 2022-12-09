DECLARE
n int;
a int;
r int;
BEGIN
DBMS_OUTPUT.PUT_LINE('Multiplication Table:'); 
FOR a in 1 .. 10 LOOP
r:=n*a;
DBMS_OUTPUT.PUT_LINE(n||'x'||a||'='||r); 
END LOOP;
END;