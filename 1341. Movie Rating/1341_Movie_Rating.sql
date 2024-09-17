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

UNION ALL -- 用户名可能会和电影名重复，此处不能去重！

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

/*
UNION 是 SQL 中用于将两个或多个 SELECT 查询的结果集合并在一起的关键字。UNION 的关键功能是将多个查询的结果合并成一个结果集，返回不重复的记录。如果希望返回重复的记录，则使用 UNION ALL。

UNION 和 UNION ALL 的区别：
    UNION：会自动对结果集进行去重，即如果两个 SELECT 查询的结果有重复的行，UNION 只会保留一行。去重的过程会有一些性能开销。
    UNION ALL：不去重，直接将所有查询的结果合并，包括重复的行。相比 UNION，UNION ALL 性能更高，因为它省去了去重的步骤。
*/
