create table accnt
(
    Cid int(5),
    Name varchar(10),
    Acntno int(5),
    Balance int(10)
);
insert into accnt
values(1, 'name1', 123, 20000);
insert into accnt
values(2, 'name2', 133, 120000);
insert into accnt
values(3, 'name3', 136, 10000);
insert into accnt
values(4, 'name4', 187, 150000);
insert into accnt
values(5, 'name5', 107, 160000);
delimiter $$
create procedure balance(a int
(5),b int
(5),c int
(5))
BEGIN
    DECLARE i INT DEFAULT 0;
    DECLARE j INT DEFAULT 0;
select balance
into i
from accnt
where acntno=a;
select balance
into j
from accnt
where acntno=b;
update accnt set balance=i-c where acntno=a;
update accnt set balance=j+c where acntno=b;
end $$
delimiter ;
call balance
(187,123,30000);

create table student
(
    RollNo int(5),
    Name varchar(10),
    mark1 int(5),
    mark2 int(2),
    Totalm int(5)
);
insert into student
values(1, 'name1', 80, 70, 0);
insert into student
values(2, 'name2', 84, 79, 0);
insert into student
values(3, 'name3', 95, 89, 0);
insert into student
values(4, 'name4', 95, 97, 0);
insert into student
values(5, 'name5', 91, 77, 0);
delimiter $$
create function totalmark(m1 int(5),m2 int
(5))
returns integer
(10)
deterministic
begin
    set m1
    =m1+m2;
    return(m1);
    end$$



delimiter
;
delimiter $$
create procedure calculate_marks()
begin
    declare i int default 1;
    while i<=5 do
    update student set totalm=totalmark(mark1,mark2) where rollno=i;
    set i
    =i+1;
end
while;
end $$

delimiter ;
call calculate_marks
();