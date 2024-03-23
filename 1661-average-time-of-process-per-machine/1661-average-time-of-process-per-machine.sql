# Write your MySQL query statement below
SELECT A1.machine_id , ROUND(AVG(A2.timestamp-A1.timestamp),3) AS processing_time
FROM Activity AS A1, Activity AS A2
WHERE  A1.machine_id = A2.machine_id AND A1.process_id =A2.process_id AND A1.timestamp <A2.timeStamp
group by A1.machine_id;