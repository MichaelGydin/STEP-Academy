-- 1.
select *
from Books
where Pages > 500 and Pages < 650;

-- 2.
select *
from Books
where LEFT(Name, 1) in ('A', 'Z');

-- 3.
select *
from Books
where Genre = 'Detective' and Sold > 30;

-- 4.
select *
from Books
where Name like '%Microsoft%' and Name not like '%Windows%';

-- 5. 
select concat(Name, ', ', Genre, ', ', AuthorFullName) as BookInfo
from Books
where Price / Pages < 0.65;

-- 6.
select *
from Books
where LEN(Name) - LEN(REPLACE(Name, ' ', '')) = 3;

-- 7.
select B.Name as BookName, B.Genre, B.AuthorFullName, B.Price, B.Sold, S.ShopName
from Books B
join Sales S on B.ID = S.BookID
join Shops SH on S.ShopID = SH.ID
where B.Name not like '%A%' and B.Genre <> 'Programming' and B.AuthorFullName <> 'Herbert Schildt' and B.Price between 10 and 20 and B.Sold >= 8 and SH.Country not in ('Russia');

-- 8.
select 'Number authors', count(distinct AuthorFullName)
union all
select 'Number books', count(*)
union all
select 'Average sell', avg(Price)
union all
select 'Average pages', avg(Pages)
from Books;

-- 9.
select Genre, sum(Pages) as TotalPages
from Books
group by Genre;

 -- 10.
select AuthorFullName, count(*) as BookCount, sum(Pages) as TotalPages
from Books
group by AuthorFullName;

-- 11.
select top 1 *
from Books
where Theme = 'Програмування'
order by Pages desc;

-- 12.
select Theme, avg(Pages) as AvgPages
from Books
where Pages <= 400
group by Theme;

-- 13.select Theme, sum(Pages) as TotalPages
from Books
where Pages > 400 and Theme in ('Програмування', 'Адміністрація', 'Дизайн')
group by Theme;

-- 14.select S.ShopName, B.Name as BookName, A.Name as AuthorName, S.SaleDate, S.Quantity
from Sales S
join Books B on S.BookId = B.Id
join Authors A on B.AuthorId = A.Id;

-- 15.
select top 1 S.ShopName, sum(S.Price * S.Quantity) as TotalRevenue
from Sales S
join Shops SH on S.ShopId = SH.Id
group by S.ShopId, S.ShopName
order by TotalRevenue desc;
 