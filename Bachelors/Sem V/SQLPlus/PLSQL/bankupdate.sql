declare

ano number(4);
amt number(8);
bal number(8);
ans varchar2(10);
yes varchar2(10):='yes';
--cant use these variables anywhere else outside the script
begin

ano:=&ano;
select 'yes' into ans from ba where aid=ano and (sysdate-dol)>182;

if ans = yes then
	insert into bastatus values (ano,'I');
	dbms_output.put_line(ano || 'is deactivated');
end if;

exception
when NO_DATA_FOUND then
	select balance into bal from ba where aid=ano;
	amt:=&amt;
	if bal-amt<1000 then
		dbms_output.put_line('Insufficient Balance');
		--print line for pl/sql
	else
		update ba set balance=bal-amt,dol=(select sysdate from dual) where aid=ano;
	end if; 
end;
/
