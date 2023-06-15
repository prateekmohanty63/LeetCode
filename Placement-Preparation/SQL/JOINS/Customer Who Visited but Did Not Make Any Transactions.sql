-- Customer Who Visited but Did Not Make Any Transactions

# Write your MySQL query statement below


select customer_id , COUNT(v.visit_id) as count_no_trans from Visits v
left join transactions t on  v.visit_id=t.visit_id where transaction_id IS NULL GROUP BY customer_id;