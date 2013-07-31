select top 100
*, cast(
	'<span>' + 
	'<var>' + cast(v as nvarchar(5)) + '</var>' + 
	replace(replace(replace(rtrim(cast(nvg as nvarchar(max))), '_', ' '), ' / ', '<br/>'), ' // ', '<p>') + 
	'</span>' as text
	) as nvg_new
from biblia where nvg is not null 
and lh_id is not null