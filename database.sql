/* Creating database */

CREATE DATABASE pdd;
use pdd;

/* Creating user tables */
CREATE TABLE CUSTOMER
(
    Customer_Id int NOT NULL AUTO_INCREMENT,
    Customer_Name VARCHAR(255) NOT NULL,
    Address VARCHAR(542) NOT NULL,
    PRIMARY KEY (Customer_Id)
);

INSERT INTO CUSTOMER
    (Customer_Name,Address)
VALUES
    ('Customer1', 'Customer1 address');
INSERT INTO CUSTOMER
    (Customer_Name,Address)
VALUES
    ('Customer2', 'Customer2 address');
INSERT INTO CUSTOMER
    (Customer_Name,Address)
VALUES
    ('Customer3', 'Customer3 address');

CREATE TABLE SALESPERSON
(
    Salesperson_Id int NOT NULL AUTO_INCREMENT,
    Salesperson_Name VARCHAR(255) NOT NULL,
    PRIMARY KEY (Salesperson_Id)
);

INSERT INTO SALESPERSON
    (Salesperson_Name)
VALUES
    ('Salesperon1');
INSERT INTO SALESPERSON
    (Salesperson_Name)
VALUES
    ('Salesperon2');
INSERT INTO SALESPERSON
    (Salesperson_Name)
VALUES
    ('Salesperon3');

CREATE TABLE MECHANIC
(
    Mechanic_Id int NOT NULL AUTO_INCREMENT,
    Mechanic_Name VARCHAR(255) NOT NULL,
    PRIMARY KEY (Mechanic_Id)
);

INSERT INTO MECHANIC
    (Mechanic_Name)
VALUES
    ('Mechanic1');
INSERT INTO MECHANIC
    (Mechanic_Name)
VALUES
    ('Mechanic2');
INSERT INTO MECHANIC
    (Mechanic_Name)
VALUES
    ('Mechanic3');

/* Creating the car table */
CREATE TABLE CAR
(
    Car_Id int NOT NULL AUTO_INCREMENT,
    Color VARCHAR(255) NOT NULL,
    Make VARCHAR(255) NOT NULL,
    PRIMARY KEY (Car_Id)
);

INSERT INTO CAR
    (Color, Make)
VALUES
    ('Red', 'New');
INSERT INTO CAR
    (Color, Make)
VALUES
    ('Yellow', 'Old');
INSERT INTO CAR
    (Color, Make)
VALUES
    ('Green', 'New');

/* Services table */
CREATE TABLE SERVICES
(
    Service_Id int NOT NULL AUTO_INCREMENT,
    Services_Name VARCHAR(255) NOT NULL,
    PRIMARY KEY (Service_Id)
);

INSERT INTO SERVICES
    (Services_Name)
VALUES
    ('Tire change');
INSERT INTO SERVICES
    (Services_Name)
VALUES
    ('Seat change');
INSERT INTO SERVICES
    (Services_Name)
VALUES
    ('Oil Change');

/* Sales invoice */
CREATE TABLE SALES_INVOICE
(
    Invoice_Id int NOT NULL AUTO_INCREMENT,
    PRIMARY KEY (Invoice_Id),
    Invoice_Date DATE NOT NULL,
    Car_Id int,
    FOREIGN KEY (Car_Id) REFERENCES CAR(Car_Id),
    Customer_Id int,
    FOREIGN KEY (Customer_Id) REFERENCES CUSTOMER(Customer_Id),
    Salesperson_Id int,
    FOREIGN KEY (Salesperson_Id) REFERENCES SALESPERSON(Salesperson_Id)
);

INSERT INTO SALES_INVOICE
    (Invoice_Date,Car_Id,Customer_Id,Salesperson_Id)
VALUES
    ('2020-06-21', 1, 1, 1);
INSERT INTO SALES_INVOICE
    (Invoice_Date,Car_Id,Customer_Id,Salesperson_Id)
VALUES
    ('2020-06-21', 2, 2, 1);

/* Service Ticket */
CREATE TABLE SERVICE_TICKET
(
    Ticket_Id int NOT NULL AUTO_INCREMENT,
    PRIMARY KEY (Ticket_Id),
    Ticket_Date DATE NOT NULL,
    Car_Id int,
    FOREIGN KEY (Car_Id) REFERENCES CAR(Car_Id),
    Customer_Id int,
    FOREIGN KEY (Customer_Id) REFERENCES CUSTOMER(Customer_Id)
);

INSERT INTO SERVICE_TICKET
    (Ticket_Date,Car_Id,Customer_Id)
VALUES
    ('2020-06-21', 3, 3);

/* Service Mechanic */
CREATE TABLE SERVICE_MECHANIC
(
    SM_Id int NOT NULL AUTO_INCREMENT,
    PRIMARY KEY (SM_Id),
    Ticket_Id int,
    FOREIGN KEY (Ticket_Id) REFERENCES SERVICE_TICKET(Ticket_Id),
    Service_Id int,
    FOREIGN KEY (Service_Id) REFERENCES SERVICES(Service_Id),
    Mechanic_Id int,
    FOREIGN KEY (Mechanic_Id) REFERENCES MECHANIC(Mechanic_Id)
);

INSERT INTO SERVICE_MECHANIC
    (Ticket_Id,Service_Id,Mechanic_Id)
VALUES
    (1, 2, 1);

/* Parts table */
CREATE TABLE PART
(
    Part_Id int NOT NULL AUTO_INCREMENT,
    PRIMARY KEY (Part_Id),
    Part_Name VARCHAR(250) NOT NULL
);

INSERT INTO PART
    (Part_Name)
VALUES
    ('Tyre');
    INSERT INTO PART
    (Part_Name)
VALUES
    ('Seat');
    INSERT INTO PART
    (Part_Name)
VALUES
    ('Oil');

/* Parts used table */
CREATE TABLE PARTS_USED
(
    Parts_Used_Id int NOT NULL AUTO_INCREMENT,
    PRIMARY KEY (Parts_Used_Id),
    Part_Id int,
    FOREIGN KEY (Part_Id) REFERENCES PART(Part_Id),
    Ticket_Id int,
    FOREIGN KEY (Ticket_Id) REFERENCES SERVICE_TICKET(Ticket_Id)
);

INSERT INTO PARTS_USED
    (Part_Id,Ticket_Id)
VALUES
    (2, 1);

