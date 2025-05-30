SELECT I.ANIMAL_ID, I.NAME
FROM ANIMAL_INS AS I LEFT OUTER JOIN ANIMAL_OUTS AS O
ON I.ANIMAL_ID = O.ANIMAL_ID
WHERE I.DATETIME > O.DATETIME
ORDER BY I.DATETIME;

-- DATEDIFF(I.DATETIME, O.DATETIME) > 0 : YYYY-MM-DD 차이만 계산하므로 HH-MM-SS 시각이 무시된다