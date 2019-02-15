declare

cursor c is select aid,balance from ba where balance=6000;
z c%rowtype;

begin

if c%NOTFOUND then
	dbms_output.put_line('No records found');
elseif c%FOUND then
	dbms_output.put_line('The result of the query is:');
	dbms_output.put_line('AID Balance');
	dbms_output.put_line('-----------');
	for z in c loop
		dbms_output.put_line(z.aid||' '||z.balance);
	end loop;
end if;
end;
/
