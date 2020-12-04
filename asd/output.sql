CREATE TABLE EMPLOYEE
(
    EMP_NO INT
    NOTNULL PRIMARYKEY,
    NAME VARCHAR
    (25),
    JOB VARCHAR
    (50),
    SALARY FLOAT
    (5,2),
    PHONE_
);
    create table EMPLOYEE
    (
        emp_no int not null primary key,
        name varchar(10),
        job varchar(10),
        salary int,
        phone_no int,
        dept_no int not null primary key,
        gender varchar(1)
    );