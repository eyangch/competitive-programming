-- Write your PostgreSQL query statement below
(WITH UserCount AS (
    SELECT user_id, COUNT(*) AS count FROM MovieRating GROUP BY user_id
)
SELECT name AS results FROM UserCount
JOIN Users ON UserCount.user_id=Users.user_id
ORDER BY count DESC, name ASC LIMIT 1)

UNION ALL

(WITH FebRating AS (
    SELECT movie_id, AVG(rating) AS rating FROM MovieRating WHERE created_at >= '2020-02-01' AND created_at < '2020-03-01' GROUP BY movie_id
)
SELECT title AS results FROM FebRating
JOIN Movies ON Movies.movie_id=FebRating.movie_id
ORDER BY rating DESC, title ASC LIMIT 1);