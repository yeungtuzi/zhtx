// kedian4.c 如归客栈上房
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"上房"NOR);
	set("long", @TEXT
如归客栈的一间上房。整个房间整洁明亮，东西摆放得整整齐齐。使人住得
舒舒服服，就像在家里住的一样舒适。房子东边墙上开着一个大窗户，窗台下边
是个小桌子。地板上铺着平整的五十公分见方的方砖。
TEXT
	);
	set("exits",([
		"south":__DIR__"kedian1",
		]));
	set("item_desc",([
	  "table":"一张小桌子，摆放得很合理，没有必要再移动(move)它了。\n",
	  "brick":"五十公分见方的方砖，方砖与方砖之间是粘合性很强的粘土。\n",
		]));
	set("nobook",1);
	setup();

}
void init()
{
	add_action("do_move","move");
	add_action("do_qiao","qiao");
	add_action("do_search","search");
}
int do_move(string arg)
{	object who;
	who=this_player();
	if(!arg||arg=="")
	   return notify_fail("你要移动什么?\n");
	if(arg!="table")
	   return notify_fail("这个房子里能移动的东西好象只有桌子(table)。\n");
	message_vision("$N轻轻地把桌子移开，但地板上还是只有方砖(brick)。你还继续搜索(search)么?\n",who);
	who->set_temp("marks/havemove",1);
	return 1;
}

int do_search(string arg)
{	object who;
	who=this_player();
	if(!arg||arg!="brick"||arg=="")
	   return notify_fail("你要搜索什么？\n");
	if(!who->query_temp("marks/havemove"))
	  return notify_fail("你仔细搜索了整个房间的方砖，没有发现什么异常的地方。\n");
	
	if(who->query("huanggong/haspi7"))
	    {
	     message_vision("$N仔细搜索了一下方砖，发现有一块方砖好象是有人动过，而它的\n"+
		"周围是用石灰新封起来的，好像有人在这里藏了什么东西似的。\n",who);
	     who->set_temp("havesearch",1);
	    }
	    else 
	      message_vision("$N仔细搜索了一下桌子底下的方砖，没有发现它和别的方砖不一样的地方。\n",who);
	return 1;
}
int do_qiao(string arg)
{
	object me,ob, weapon;
	me = this_player();

	if( !arg || arg!="brick" ) 
		return notify_fail("你要撬什么？\n");
	if (me->query_temp("marks/havemove") )
	{
		if (!objectp(weapon = me->query_temp("weapon")))
			return notify_fail("不用家伙恐怕不行吧！\n");
	        message_vision("$N拔出兵刃，将一块方砖撬起。\n",me);
             if(!query("nobook")||query("havegiven"))
		{
		message_vision("砖下露出了一个油布包，$N打开一看，正是一部《四十二章经》。$N忍不住叫了一声。\n",me);
		ob=new(__DIR__"obj/book14_2");
		ob->move(me);
               set("havegiven",1);
		return 1;	
		}
		
	}
	else
		message_vision("\n$N胡乱撬开几块砖，结果什么也没发现。\n", this_player());
	return 1;
}
