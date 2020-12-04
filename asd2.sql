DELETE FROM Sale_order_copy where Order_status= “Cancelled”;

DELETE FROM Product_master_copy where Description like “%floppies”;

DELETE FROM Client_master_copy where City NOT IN(“Mumbai”, “Delhi”);

DELETE FROM Sale_order_copy where Billed_yn= “Y”;

DELETE FROM sale_order_details_copy where Qty_ordered<= 1;

DELETE FROM Client_master_copy where Bal_due<1000;
