# Write your MySQL query statement below

SELECT w1.id from weather w1
LEFT JOIN weather w2
ON w1.recordDate = w2.recordDate+ INTERVAL 1 DAY
where w1.temperature>w2.temperature;