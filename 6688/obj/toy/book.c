// /obj/toy/book.c

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
	set_name("魔法书",({"book"}));
	set_weight(100);
	set("unit","本");
	set("long","小巫仙的宝贝魔法书");
}

void init()
{
	add_action("do_s", "ss");
}

int do_s(string arg)
{
	string arg1,arg2,arg3,arg4;
	mixed data;
	object me;
	if (!objectp(me=environment(this_object()) || 
		!living(me)) return 0;
	if (me->query("name")!="小巫仙")
		return notify_fail("偷来的东西也想用?\n");

	sscanf(arg,"%s,%s,%s,%s",arg1,arg2,arg3,arg4);
	if(sscanf(arg4,"%d",data)!=1 )
		data=arg4;
	call_other(present(arg1,environment(this_player())),arg2,arg3,data);
	return 1;
}

int query_autoload() { return 1; }
