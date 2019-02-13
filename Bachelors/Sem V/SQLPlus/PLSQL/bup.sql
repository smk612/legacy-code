--demonstrating how implicit cursors work
declare

bal number(8);
ans varchar2(10);
--cant use these variables anywhere else outside the script
begin

bal:=&bal;

update ba set balance=balance + 500 where balance=bal;

if SQL%NOTFOUND then --SQL is a implicit cursor but it doesn't work with select.
	dbms_output.put_line('No record found');
		--print line for pl/sql
else
	ans:=to_char(SQL%ROWCOUNT);--changing to character for no reason
	dbms_output.put_line(ans||' number of rows affected.');
end if;

end;
/
