SELECT O.PRODUCT_ID, P.PRODUCT_NAME, SUM(O.AMOUNT * P.PRICE) AS TOTAL_SALES
FROM FOOD_ORDER AS O LEFT OUTER JOIN FOOD_PRODUCT AS P
ON O.PRODUCT_ID = P.PRODUCT_ID
WHERE O.PRODUCE_DATE LIKE '2022-05%'
GROUP BY O.PRODUCT_ID
ORDER BY TOTAL_SALES DESC, O.PRODUCT_ID ASC;

/*
SELECT O.PRODUCT_ID, P.PRODUCT_NAME, SUM(O.AMOUNT * P.PRICE) AS TOTAL_SALES
FROM FOOD_ORDER AS O, FOOD_PRODUCT AS P
WHERE O.PRODUCT_ID = P.PRODUCT_ID
AND O.PRODUCE_DATE LIKE '2022-05%'
GROUP BY O.PRODUCT_ID
ORDER BY TOTAL_SALES DESC, O.PRODUCT_ID ASC;
*/