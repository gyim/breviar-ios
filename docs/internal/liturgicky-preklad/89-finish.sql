-- doplnenie èísel veršov (<var>...</var>) a obalenie veršov do <span>...</span>
-- zmena " / " na <br/>; "//" na <p>

alter table biblia
add nvg_html text;
go

update biblia
set nvg_html = cast(
	'<span>' + 
	'<var>' + cast(v as nvarchar(5)) + '</var>' + 
	replace(replace(replace(rtrim(cast(nvg as nvarchar(max))), '_', ' '), ' / ', '<br/>'), ' // ', '<p>') + 
	'</span>' as text
	)
where nvg is not null
go

update biblia
set nvg_html = cast(
	replace(rtrim(cast(nvg_html as nvarchar(max))), ' /</span>', '<br/></span>')
	as text
	)
where nvg_html like '% /</span>%'
go
