/*

-- 2013-07-02: priebeh
select _0, spis, count(1) as versov -- * 
from biblia where 1=1 -- spis = '2Sam'
and nvg is not null
group by _0, spis
order by _0




select top 100 * from biblia where vers = 1
and spis = 'jn'
and k > 18

select distinct _0, spis from biblia order by 1

select * from biblia
where nvg is not null
and isnull(vers, 0) != 1

select * from biblia
where spis = '1Kr' and k = 10
and v between 1 and 10
-- and vers = 1

select * from biblia
where spis = '1Kr' and k = 11
-- and vers = 1

select -- top 100 
* from lc
where sur like '1Kr %'
or sur like '1 Kr %'

select * from biblia where spis = '1Kr' and k = 8

select -- top 100 
* from lc
where sur like '2Kr %'
or sur like '2 Kr %'
order by 2

select * from biblia where spis = '2Kr'
and nvg is not null

select distinct lc.id
from lc left join biblia
on lc.id = biblia.lc_id
where sur like '2Kr %'
or sur like '2 Kr %'
*/

/*
select -- top 100 
* from lc
where sur like 'Ex%'
-- or sur like 'Ezd%'
order by 2

select * from biblia where spis = 'Ex'
and nvg is not null

select * from biblia where spis = 'Tob'
and nvg is not null


select -- top 100 
* from lc
where sur like 'Lv%'
order by 2

select * from biblia where spis = 'Lv'
and nvg is not null

select -- top 100 
* from lc
where sur like 'Nm%'
order by 2

select * from biblia where spis = 'Nm'
and nvg is not null

select * from lc
where sur like 'Sir%'
order by 2

select * from biblia where spis = 'Sir'
and nvg is not null

select * from lc
where sur like 'Dt%'
order by 2

select * from biblia where spis = 'Dt'
and nvg is not null

select * from lc
where sur like 'Joz%'
order by 2

select * from biblia where spis = 'Joz'
and nvg is not null

select * from lc
where sur like 'Sdc%'
order by 2

select * from biblia where spis = 'Sdc'
and nvg is not null

select * from lc
where sur like '1Sam%'
or sur like '1 Sam%'
order by 2

select * from biblia where spis = '1Sam'
and nvg is not null

select * from lc
where sur like '2Sam%'
or sur like '2 Sam%'
order by 2

select * from biblia where spis = '2Sam'
and nvg is not null

select * from lc
where sur like 'Gn%'
order by 2

select * from biblia where spis = 'Gn'
and nvg is not null

select * from lc
where sur like 'Jdt%'
order by 2

select * from biblia where spis = 'Jdt'
and nvg is not null

select * from lc
where sur like 'Est%'
order by 2

select * from biblia where spis = 'Est'
and nvg is not null

select * from lc
where sur like 'Ba%'
order by 2

select * from biblia where spis = 'Bar'
and nvg is not null
*/
select * from lc
where sur like 'Múd%'
order by 2

select * from biblia where spis = 'Mud' -- 'Múd'
and nvg is not null
