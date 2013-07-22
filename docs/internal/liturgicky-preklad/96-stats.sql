select SUM(nvg) nvg_spolu, SUM(vsetky) ssv_spolu, cast(SUM(nvg) as float) / SUM(vsetky) as nvg_z_ssv from stat

/*
select * from stat
order by _0

select * from stat_lc
order by _0

select * from stat_lh
order by _0
*/

select stat._0, stat.spis, stat.vsetky, stat.nvg, stat_lc.nvg as lc, stat_lh.nvg as lh, stat.percento, stat_lc.percento as perc_lc, stat_lh.percento as perc_lh 
from stat
join stat_lc
	on stat.spis = stat_lc.spis
join stat_lh
	on stat.spis = stat_lh.spis
order by stat._0
