create or replace trigger audit_ba after delete or update or insert on ba for each row 
--1st time execute hole create hobe, 2nd time just replace hobe.
declare
oper varchar2(10);
naid ba.aid%TYPE := :old.aid;
ndop ba.dop%TYPE := :old.dop;
ndol ba.dol%TYPE := :old.dol;
nbal ba.balance%TYPE := :old.balance;

begin

	if deleting then
		oper:='delete';
	elsif updating then
		oper:='update';
	elsif inserting then
		oper:='insert';
		naid:= :new.aid;
		ndop:= :new.dop;
		ndol:= :new.dol;
		nbal:= :new.balance;
	else
		oper:='misc';
	end if;
	insert into log_ba(aid,dop,dol,balance,oper,doper,opertime) values(naid,ndop,ndol,nbal,oper,sysdate,to_char(sysdate,'hh24:mi'));
	
end;
/
