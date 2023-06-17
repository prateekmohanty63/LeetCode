# Write your MySQL query statement below

SELECT w1.id from Weather AS w1 , Weather as W2 WHERE w1.Temperature>w2.Temperature and DATEDIFF(w1.recordDate,w2.recordDate)=1;