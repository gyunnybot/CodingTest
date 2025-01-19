SELECT date_format(SALES_DATE,'%Y-%m-%d') AS SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
FROM ONLINE_SALE
WHERE SALES_DATE LIKE '2022-03%'

UNION

SELECT date_format(SALES_DATE,'%Y-%m-%d') AS SALES_DATE, PRODUCT_ID, NULL USER_ID, SALES_AMOUNT
FROM OFFLINE_SALE
WHERE SALES_DATE LIKE '2022-03%'

ORDER BY SALES_DATE ASC, PRODUCT_ID ASC, USER_ID ASC;

-- UNION: set, UNION: multi_set
-- NULL 속성 : 해당 속성의 모든 값들은 NULL로 표시