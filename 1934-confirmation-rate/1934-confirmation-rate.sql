# Write your MySQL query statement below
# select s.user_id, round(avg(if(c.action="confirmed",1,0)),2) as confirmation_rate
# from Signups as s 
# left join Confirmations as c 
# on s.user_id= c.user_id 
# group by user_id;
SELECT s.user_id,
      ROUND((AVG(CASE
          WHEN action='confirmed' THEN 1
          ELSE 0
          END)),2) AS confirmation_rate
FROM Signups as s
LEFT JOIN Confirmations as c 
ON s.user_id=c.user_id
GROUP BY user_id