SELECT *
FROM CUSTOMER JOIN SALES_INVOICE ON CUSTOMER.Customer_Id = SALES_INVOICE.Customer_Id;

/*
mysql> SELECT *
    -> FROM CUSTOMER JOIN SALES_INVOICE ON CUSTOMER.Customer_Id = SALES_INVOICE.Customer_Id;
+-------------+---------------+-------------------+------------+--------------+--------+-------------+----------------+
| Customer_Id | Customer_Name | Address           | Invoice_Id | Invoice_Date | Car_Id | Customer_Id | Salesperson_Id |
+-------------+---------------+-------------------+------------+--------------+--------+-------------+----------------+
|           1 | Customer1     | Customer1 address |          1 | 2020-06-21   |      1 |           1 |              1 |
|           2 | Customer2     | Customer2 address |          2 | 2020-06-21   |      2 |           2 |              1 |
+-------------+---------------+-------------------+------------+--------------+--------+-------------+----------------+
2 rows in set (0.01 sec)
*/

SELECT Part_Name, Ticket_Id
FROM PART JOIN PARTS_USED ON PART.Part_Id = PARTS_USED.Part_Id;

/*
mysql> SELECT Part_Name, Ticket_Id
    -> FROM PART JOIN PARTS_USED ON PART.Part_Id = PARTS_USED.Part_Id;
+-----------+-----------+
| Part_Name | Ticket_Id |
+-----------+-----------+
| Seat      |         1 |
+-----------+-----------+
1 row in set (0.00 sec)
*/

SELECT Customer_Id, Ticket_Date, Mechanic_Id
FROM SERVICE_MECHANIC JOIN SERVICE_TICKET 
WHERE SERVICE_MECHANIC.Mechanic_Id = '1';

/*
mysql> SELECT Customer_Id, Ticket_Date, Mechanic_Id
    -> FROM SERVICE_MECHANIC JOIN SERVICE_TICKET 
    -> WHERE SERVICE_MECHANIC.Mechanic_Id = '1';
+-------------+-------------+-------------+
| Customer_Id | Ticket_Date | Mechanic_Id |
+-------------+-------------+-------------+
|           3 | 2020-06-21  |           1 |
+-------------+-------------+-------------+
1 row in set (0.00 sec)
*/