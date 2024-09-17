SELECT id, company, salary
FROM (
	SELECT 
        id, 
        company, 
        salary, 
        ROW_NUMBER() OVER (PARTITION BY company ORDER BY salary) AS ranking, -- 公司内，按照工资升序排列，并添加行号。
        COUNT(id) OVER (PARTITION BY company ) AS cnt -- 统计每个公司的总人数，附加在每条记录的后面；
	FROM 
        Employee
) tmp -- 子查询必须有个alias
WHERE 
    ranking >= cnt / 2 AND ranking <= cnt / 2 + 1  -- 很巧妙，恰好可以选出中间的一位（部门总员工数为奇数）或二位（部门总员工数为偶数）
;

/*
中位数定义：排名在中间的一位（部门总员工数为奇数）或二位（部门总员工数为偶数）
ROW_NUMBER() 是 SQL 中的一个窗口函数，用于为查询结果集中的每一行按特定的顺序分配唯一的行号。这个行号是基于你指定的分区和排序条件生成的。它不依赖于表中的数据本身，而是根据查询时的排序规则生成的序号。
	语法：
		ROW_NUMBER() OVER (PARTITION BY column_name ORDER BY column_name)
*/

/*
PARTITION BY（窗口函数）：
PARTITION BY 是窗口函数中的一种，用于将数据分组（划分），但与 GROUP BY 不同，它不会减少结果集的行数。窗口函数会为每一行计算一个聚合值，并将其作为一个新的列附加到该行。
输出结果：使用 PARTITION BY 时，结果集的行数保持不变，计算的结果会基于每个分区添加到每一行中。

举个类比：
`GROUP BY` 类似于你将一个班级的同学按照性别分组统计人数，每个性别只输出一行（男生一共多少人，女生一共多少人）。
`PARTITION BY` 类似于你统计每个同学的百米成绩，但是要按照性别分开进行排名（男子第一名，女子第一名，......）。
*/