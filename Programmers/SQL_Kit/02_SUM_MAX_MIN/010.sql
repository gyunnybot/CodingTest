SELECT YEAR(A.DIFFERENTIATION_DATE) AS YEAR, B.MAX_SIZE - A.SIZE_OF_COLONY AS YEAR_DEV, A.ID
FROM ECOLI_DATA AS A LEFT OUTER JOIN (
                                      SELECT YEAR(DIFFERENTIATION_DATE) AS Y, MAX(SIZE_OF_COLONY) AS MAX_SIZE
                                      FROM ECOLI_DATA
                                      GROUP BY Y
                                     ) AS B
ON YEAR(A.DIFFERENTIATION_DATE) = B.Y -- WHERE, ON 절은 미완성 테이블로 가정. 속성에 대한 alias가 적용되지 않는다. (완성된 테이블 alias는 적용 가능)
ORDER BY YEAR, YEAR_DEV; -- ORDER BY, GROUP BY 절은 테이블이 완성되었다고 가정. 속성의 alias가 적용된다

-- 정렬, 묶음에 관한 SQL 명령어와 그 하위 명령어는 이미 상위 테이블이 완성된 상태이므로 alias가 사용 가능하다