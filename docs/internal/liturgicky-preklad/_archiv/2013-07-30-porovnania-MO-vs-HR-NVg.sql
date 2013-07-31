select mo.nvg, hr.nvg, mo.*, hr.*
from dkc..biblia mo
join dkchr..biblia hr
	on	mo.id = hr.id
	and		mo.spis = hr.spis
	and		hr.vers = 1
	and		mo.vers = 1
where 
		isnull(cast(mo.nvg as nvarchar(max)), N'') != isnull(cast(hr.nvg as nvarchar(max)), N'')
;
go
