create view stat
as
(
select _0, spis, sum(versov) as NVg, sum(versov_all) as vsetky, sum(versov) / cast(sum(versov_all) as float)* 100.0 as percento
from
(
select _0, spis, count(1) as versov, 0 as versov_all
from biblia 
where 1=1
and vers = 1
and nvg is not null
group by _0, spis

union all

select biblia._0, biblia.spis, 0 as versov, count(1) as versov_all
from biblia 
where 1=1
and vers = 1
group by biblia._0, biblia.spis
) a
group by _0, spis 
-- order by _0
);
go

create view stat_lc
as
(
select _0, spis, sum(versov) as NVg, sum(versov_all) as vsetky, sum(versov) / cast(sum(versov_all) as float)* 100.0 as percento
from
(
select _0, spis, count(1) as versov, 0 as versov_all
from biblia 
where 1=1
and vers = 1
and nvg is not null
and lc_id is not null
group by _0, spis

union all

select biblia._0, biblia.spis, 0 as versov, count(1) as versov_all
from biblia 
where 1=1
and vers = 1
group by biblia._0, biblia.spis
) a
group by _0, spis 
-- order by _0
);
go

create view stat_lh
as
(
select _0, spis, sum(versov) as NVg, sum(versov_all) as vsetky, sum(versov) / cast(sum(versov_all) as float)* 100.0 as percento
from
(
select _0, spis, count(1) as versov, 0 as versov_all
from biblia 
where 1=1
and vers = 1
and nvg is not null
and lh_id is not null
group by _0, spis

union all

select biblia._0, biblia.spis, 0 as versov, count(1) as versov_all
from biblia 
where 1=1
and vers = 1
group by biblia._0, biblia.spis
) a
group by _0, spis 
-- order by _0
);
