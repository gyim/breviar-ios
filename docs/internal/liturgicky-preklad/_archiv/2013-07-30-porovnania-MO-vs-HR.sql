-- MO = WT, Moskovská 13
-- HR = doma, Hrobákova 26

-- porovnanie databáz na nezrovnalosti

select mo.nvg, hr.nvg, mo.*, hr.*
from dkc..biblia mo
join dkchr..biblia hr
	on	mo.id = hr.id
	and		mo.spis = hr.spis
	and		hr.vers = 1
	and		mo.vers = 1
where 
		isnull(cast(mo.nvg as nvarchar(max)), N'') != isnull(cast(hr.nvg as nvarchar(max)), N'')
		or	isnull(mo.lc_id, 0) != isnull(hr.lc_id, 0)
		or	isnull(mo.lh_id, N'') != isnull(hr.lh_id, N'')
;
go

select mo.nvg, hr.nvg, mo.*, hr.*
from dkc..biblia mo
join dkchr..biblia hr
	on	mo.id = hr.id
	and		mo.spis = hr.spis
	and		hr.vers = 1
	and		mo.vers = 1
where 
mo.spis = 'Mud' and mo.k = 18 and mo.v in (6, 16)
