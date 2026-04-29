// Room: /d/wizard/wizard_room.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"巫师休息室"NOR);
	set("long", @LONG
	这里就是「纵横天下」巫师的休息所在，刚粉刷过的四周墙壁上
光秃秃的什么都没有，屋子的正中央放着一张楠木桌，上面摆着一本巫师
留言簿(board)。墙上贴了一张广告：
[33m               		
                    	  通知
      为了便于规划，请各位巫师将各自的计划写在留言簿上
  	      现在正在写的和准备写的最好都写上.
[36m  	     
    桌子上面摆着一个麦克风,你可以用它来向大家发布通知(ann)。  	
[2;37;0m   
LONG
);

	set("exits", ([ /* sizeof() == 2 */
        "down" : __DIR__"guest_room",
        "north" : __DIR__"newsroom",
//      "south": "/d/mingrentang/whall"
  	"west" : __DIR__"wwww",

 ]));

	set("valid_startroom", 1);
	set("no_fight", "1");
	set("no_clean_up", 0);
	setup();

	call_other("/obj/board/wizard_j", "???");
}

void init()
{
	add_action("do_ann","ann");
}

int do_ann(string arg)
{
	object me,*ob;
	
	if(!stringp(arg))
	{
		write("你清了清嗓子，却突然发现面对着这么多人，实在是说不出话来。 :)\n");
		return 1;
	}
	me = this_player();
	
	if( !wiz_level(me) )
	{
		me->move("/d/snow/inn");
		return notify_fail("你是什么人？怎么敢到这里来随意乱动东西？\n");
	}
	
	ob=users();
        message("announce", HIY "【通知】纵横天下工作组" 
                + "：" + arg + "\n" NOR, ob);
        return 1;

}
