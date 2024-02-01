# Write your MySQL query statement below

SELECT customer_id, count(customer_id) as count_no_trans from Visits as v
LEFT JOIN Transactions as t
ON t.visit_id = v.visit_id
WHERE t.transaction_id is NULL
group by customer_id;