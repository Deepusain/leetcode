# Write your MySQL query statement below
SELECT product_name , year,price
from Sales as a
left join Product as b
on a.product_id = b.product_id 