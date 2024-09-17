-- 查找评论电影数量最多的用户名
SELECT name AS results
FROM (
    SELECT u.name, COUNT(mr.movie_id) AS review_count
    FROM MovieRating mr
    JOIN Users u ON mr.user_id = u.user_id
    GROUP BY u.name
    ORDER BY review_count DESC, u.name
    LIMIT 1
) AS MostReviews

UNION ALL

-- 查找 2020 年 2 月份平均评分最高的电影名称
SELECT title AS results
FROM (
    SELECT m.title, AVG(mr.rating) AS avg_rating
    FROM MovieRating mr
    JOIN Movies m ON mr.movie_id = m.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY m.title
    ORDER BY avg_rating DESC, m.title
    LIMIT 1
) AS BestMovieInFebruary;