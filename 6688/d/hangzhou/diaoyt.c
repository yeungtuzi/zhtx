//daoyt.c
//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{      
	set("short", CYN"西湖美景"NOR);
	set("long", @LONG
	  这儿荷叶渐稀，处处可见鱼虾游动，见人也不怕，仍然不紧不
慢地游着，许多游人正在垂钓，让你也有些心痒。一个小女孩正用童音唱
道：一天到晚游泳的鱼的鱼呀游个不休---- 
LONG
	);    
	set("exits", ([
		"north" : __DIR__"huaxint",
		"southup" : __DIR__"xhroad2",
	]));
	set("objects", ([
	__DIR__"npc/wuji" : 1,
	]));              
        setup();
}              

void init()
{
	add_action("do_fish", "fish");
}

int do_fish()
{
 	object ob,me;
	me = this_player(); 
                           
	if ((int)me->query("combat_exp") < 1000)  
		return 0;  
	ob=new(__DIR__"npc/fish"); 
	ob->move(me);  
	me->receive_damage("kee", 20);
	me->receive_damage("sen", 10);
	me->set("mark/fish", 1);
	tell_room(__DIR__"diaoyt", "你钓起一条鱼来。\n");   
		return 1; 
}
