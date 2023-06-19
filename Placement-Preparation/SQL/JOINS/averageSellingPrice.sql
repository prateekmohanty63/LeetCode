# Write your MySQL query statement below

select a.product_id , round(sum(price*units)/sum(units),2) as average_price from Prices a inner join UnitsSold b on a.product_id=b.product_id where b.purchase_date between a.start_date and a.end_date group by a.product_id; 