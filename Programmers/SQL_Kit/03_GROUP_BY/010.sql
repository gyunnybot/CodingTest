SELECT MCDP_CD AS 진료과코드, COUNT(*) AS 5월예약건수
FROM APPOINTMENT
WHERE APNT_YMD LIKE '2022-05%'
GROUP BY 진료과코드 -- ORDER BY, GROUP BY 절은 테이블이 완성되었다고 가정. 속성의 alias가 적용된다
ORDER BY COUNT(*) ASC, 진료과코드 ASC; -- ORDER BY, GROUP BY 절은 테이블이 완성되었다고 가정. 속성의 alias가 적용된다