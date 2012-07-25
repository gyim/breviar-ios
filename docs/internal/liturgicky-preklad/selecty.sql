/*
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

select -- top 100 
* from lc
where sur like 'Ezd%'
or sur like 'Ezd%'
order by 2

/*
select * from biblia where spis = 'Ezd'
and nvg is not null
*/
