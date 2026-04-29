inherit ROOM;

void create()
{
        set("short", "9号看台");
	set("long", @LONG
 这是比武大会的看台，你周围的人正在大声呐喊助威。
前上方是一个比武擂台，从这可以看到擂台上的比武情况。
LONG
        );
        set("exits", ([
	  "out" : __DIR__"sheshen",
 	  "up"  : __DIR__"leitai",
	]));
	
        set("no_clean_up", 0);
        set("outdoors", "xx" );
        set("no_death",1);
        set("no_fight",1);
        set("no_magic",1);

        setup();
}

void init()
{
	add_action("do_study","study");
	add_action("do_practice","practice");
	add_action("do_get","get");
	add_action("do_drop","drop");
	add_action("do_qu","qu");
	add_action("do_play","play");
}

int do_play(string arg)
{
	write("不准在这弹琴.\n");
	return 1;
}

int do_get(string arg)
{
	if (!wizardp(this_player()) )
	{
		write("不许在这拿东西。\n");
		return 1;
	}
	return 0;
}

int do_drop(string arg)
{
	write("请保持卫生，不能在随便扔东西。\n");
	return 1;
}

int do_practice(string arg)
{
	write("不能在这练武。\n");
	return 1;
}

int do_study(string arg)
{
	write("这不是读书的地方。\n");
	return 1;
}

int do_qu(string arg)
{
	object ob,me=this_player();
	if(me->query_temp("get_weapon") ) return notify_fail("你已经拿了一样了。\n");
	if(arg=="sword")
	{
		if(ob=new("/obj/weapon/c_sword"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="blade")
	{
		if(ob=new("/obj/weapon/c_blade"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="whip")
	{
		if(ob=new("/obj/weapon/c_whip"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="hammer")
	{
		if(ob=new("/obj/weapon/c_hammer"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}

	if(arg=="spear")
	{
		if(ob=new("/obj/weapon/c_spear"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="staff")
	{
		if(ob=new("/obj/weapon/c_staff"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="gun")
	{
		if(ob=new("/obj/weapon/c_club"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="ji")
	{
		if(ob=new("/obj/weapon/c_halberd.c"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}

	if(arg=="dagger")
	{
		if(ob=new("/obj/weapon/c_dagger.c"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="qin")
	{
		if(ob=new("/obj/weapon/c_qin.c"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="dart")
	{
		if(ob=new("/obj/weapon/c_dart.c"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一些飞镖。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}

	return notify_fail("找不到你要的。\n");
}


int valid_leave(object me, string dir)
{
	object obj;
	if (dir=="up")
	{	
		return notify_fail("没到你上场，老老实实呆着。\n");
	}
        return ::valid_leave(me, dir);
}
