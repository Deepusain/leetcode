# # Write your MySQL query statement below

# select b.visited_on, sum(a.amount) as amount, round(sum(a.amount)/7,2) as average_amount
# from Customer a, (select distinct visited_on from Customer) b
# where DATEDIFF(b.visited_on, a.visited_on) between 0 and 6
# group by b.visited_on
# having count(distinct a.visited_on)=7
# Write your MySQL query statement below
SELECT visited_on, amount, ROUND(amount/7, 2) average_amount
FROM (
    SELECT DISTINCT visited_on, 
    SUM(amount) OVER(ORDER BY visited_on RANGE BETWEEN INTERVAL 6 DAY   PRECEDING AND CURRENT ROW) amount, 
    MIN(visited_on) OVER() 1st_date 
    FROM Customer
) t
WHERE visited_on>= 1st_date+6;