# Write your MySQL query statement below

SELECT distinct viewer_id as id from Views
where author_id=viewer_id
order by id;