IMPLIMENTATION OF EXCEPTION HANDLING

CREATE TABLE studj(id INT PRIMARY KEY,name VARCHAR(30),depart VARCHAR(30),mark1 DECIMAL(4,2),mark2 DECIMAL(4,2),CGPA DECIMAL(4,2));
INSERT INTO studj VALUES(101,'A','CSE',88.5,70.6,8.2);
INSERT INTO studj VALUES(102,'B','CE',82.1,77.3,8.1);
INSERT INTO studj VALUES(103,'C','ME',67.3,65.8,7.2);
INSERT INTO studj VALUES(104,'D','CSE',68.5,61.3,6.8);
INSERT INTO studj VALUES(105,'E','EEE',38.5,60.2,5.2);

        ID NAME                           DEPART
---------- ------------------------------ ------------------------------
     MARK1      MARK2       CGPA
---------- ---------- ----------
       101 A                              CSE
      88.5       70.6        8.2

       102 B                              CE
      82.1       77.3        8.1

       103 C                              ME
      67.3       65.8        7.2


        ID NAME                           DEPART
---------- ------------------------------ ------------------------------
     MARK1      MARK2       CGPA
---------- ---------- ----------
       104 D                              CSE
      68.5       61.3        6.8

       105 E                              EEE
      38.5       60.2        5.2


DECLARE
BEGIN
INSERT INTO studj VALUES('S106','F','CSE',78.5,60.6,7.1);
EXCEPTION
WHEN INVALID_NUMBER THEN
DBMS_OUTPUT.PUT_LINE('Invalid ID');
END;
/

OUTPUT:
Invalid ID

PL/SQL procedure successfully completed.


DECLARE
n studj.name%TYPE;
NAME_NULL EXCEPTION;
BEGIN
if n IS NULL THEN
RAISE NAME_NULL;
INSERT INTO studj VALUES('106','','CSE',78.5,60.6,7.1);
END IF;
EXCEPTION
WHEN NAME_NULL THEN
DBMS_OUTPUT.PUT_LINE('Invalid Name');
END;
/

OUTPUT:
Invalid Name

PL/SQL procedure successfully completed.