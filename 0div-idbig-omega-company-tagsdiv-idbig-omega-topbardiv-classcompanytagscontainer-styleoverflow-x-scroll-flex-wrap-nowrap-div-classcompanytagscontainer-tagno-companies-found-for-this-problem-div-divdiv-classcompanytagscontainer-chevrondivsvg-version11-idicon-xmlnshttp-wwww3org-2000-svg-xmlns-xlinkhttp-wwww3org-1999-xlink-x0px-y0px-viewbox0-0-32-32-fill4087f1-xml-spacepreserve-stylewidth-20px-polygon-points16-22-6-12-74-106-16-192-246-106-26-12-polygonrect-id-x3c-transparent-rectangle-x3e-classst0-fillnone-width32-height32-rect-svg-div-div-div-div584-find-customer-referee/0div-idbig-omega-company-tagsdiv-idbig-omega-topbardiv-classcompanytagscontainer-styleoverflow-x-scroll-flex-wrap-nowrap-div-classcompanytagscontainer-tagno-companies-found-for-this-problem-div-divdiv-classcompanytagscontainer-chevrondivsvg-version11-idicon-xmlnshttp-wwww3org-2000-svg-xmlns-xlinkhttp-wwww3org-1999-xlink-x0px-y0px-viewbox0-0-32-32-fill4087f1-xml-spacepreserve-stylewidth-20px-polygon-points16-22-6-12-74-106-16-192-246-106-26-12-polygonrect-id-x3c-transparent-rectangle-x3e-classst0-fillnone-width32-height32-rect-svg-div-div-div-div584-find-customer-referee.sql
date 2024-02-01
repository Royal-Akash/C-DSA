# Write your MySQL query statement below

SELECT name from Customer
WHERE IFNULL(referee_id, 1) <> 2;