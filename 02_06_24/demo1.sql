-- SQLite
select p_code as `Product Code`, 
       p_descript as 'Description', 
       p_price as "Price", 
       p_qoh as `Quantity on Hand`,  
       p_qoh * p_price as `Total Value`                       
from product