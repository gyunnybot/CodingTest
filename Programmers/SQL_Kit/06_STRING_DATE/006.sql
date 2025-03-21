SELECT HISTORY_ID, CAR_ID, 
DATE_FORMAT(START_DATE, '%Y-%m-%d') AS START_DATE, 
DATE_FORMAT(END_DATE, '%Y-%m-%d') AS END_DATE, 
CASE WHEN DATEDIFF(END_DATE, START_DATE) + 1 >= 30 THEN '장기 대여'
     ELSE '단기 대여'
END AS RENT_TYPE
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE START_DATE LIKE '2022-09%'
ORDER BY HISTORY_ID DESC;
 
-- START_DATE와 END_DATE의 경우 예시의 데이트 포맷과 동일해야 정답처리 됩니다. 문제의 조건을 정확히 읽자!