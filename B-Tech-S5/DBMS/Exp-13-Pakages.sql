EXP-13 PACKAGES

AIM:
To implement packages in PL/SQL

Program:
Create a table employee with attributes employee ID, name, age, address, job and salary. Insert 5 rows into it and do the following.

-> CREATE TABLE ej(id INT PRIMARY KEY,name VARCHAR(30),age INT,address VARCHAR(30),job VARCHAR(30),salary DECIMAL(8,2)); 
-> INSERT INTO ej VALUES(101,'A',28,'Goa','X',10000);
-> INSERT INTO ej VALUES(102,'B',38,'Goa','Y',15000);
-> INSERT INTO ej VALUES(103,'C',23,'Goa','Y',40000);
-> INSERT INTO ej VALUES(104,'D',35,'Goa','Z',50000);
-> INSERT INTO ej VALUES(105,'E',45,'Goa','X',60000);

        ID NAME                                  AGE
---------- ------------------------------ ----------
ADDRESS                        JOB                                SALARY
------------------------------ ------------------------------ ----------
       101 A                                      28
Goa                            X                                   10000

       102 B                                      38
Goa                            Y                                   15000

       103 C                                      23
Goa                            Y                                   40000


        ID NAME                                  AGE
---------- ------------------------------ ----------
ADDRESS                        JOB                                SALARY
------------------------------ ------------------------------ ----------
       104 D                                      35
Goa                            Z                                   50000

       105 E                                      45
Goa                            X                                   60000


1. Create Package named "emp_sal" which shows a package specification having a single procedure.
-> CREATE OR REPLACE PACKAGE emp_sal AS 
   PROCEDURE find_sal(e_id ej.id%type);
END emp_sal; 
/

Package created.

2. Implement the code that shows the package body declaration for the "emp_sal" package created above.
Creating the Package Body
-> CREATE OR REPLACE PACKAGE BODY emp_sal AS 
   PROCEDURE find_sal(e_id ej.id%TYPE) IS e_sal ej.salary%TYPE; 
   BEGIN 
      SELECT salary INTO e_sal 
      FROM ej
      WHERE id = e_id; 
      dbms_output.put_line('Salary = '|| e_sal); 
   END find_sal; 
END emp_sal; 
/

Package body created.


3. Implement the code that  uses the included procedure methodd of the "emp_sal" package in such a way that it prompts to enter thge employee ID and when you enter an ID it displays the corresponding salary of the employee.
-> DECLARE 
   code ej.id%type := &emp_id;
BEGIN 
   emp_sal.find_sal(code); 
END; 
/

Enter value for emp_id: 104
old   2:    code ej.id%type := &emp_id;
new   2:    code ej.id%type := 104;
Salary = 50000

PL/SQL procedure successfully completed.