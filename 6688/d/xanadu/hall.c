// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

string *s1 = ({	"问","苍","茫","大","地","谁","主","沉","浮","数","风","流",
		"人","物","还","看","今","朝","江","山","如","此","多","娇"});

void create()
{
	set("short", CLR+YEL"\n\n\n\n\n\n幽明山庄正厅"NOR);
	set("long", 
"	你人尚未到，一丝淡淡的清香已自沁入你的心脾。走进大厅，迎面是一幅\n"
"极大的泼墨山水，墨迹纵横淋漓，笔锋峥嵘有致。画面上绘的是山河社稷图，东起\n"
"茫茫大海，西至皑皑雪山，气势不凡，令人顿生仰止之感，旁边是一幅对联：\n\n"
"                「 问苍茫大地  谁主沉浮\n"NOR
"                   数风流人物  还看今朝 」\n"NOR
NOR"横批：\n"
"                    江山如此多娇"NOR+"\n\n"				
"整座大厅虽然富丽堂皇，气势恢宏，可是你总感觉有点不太协调的地方。似乎和你\n"
"一路所见所闻不太相象。\n\n\n"
	);

	set("exits", ([ /* sizeof() == 2 */
	  "south" : __DIR__"dynamic/jiuqu16",
	  "north" : __DIR__"neishi",
	]));

	set("objects", ([
			__DIR__"npc/liuxingyu" : 1,
			__DIR__"npc/xiaohua" : 1,
		])
	);                                      

	setup();
}                               

int init()
{
	add_action("do_think","think");
	add_action("do_uncover","uncover");
	::init();
}                                      

int valid_leave(object me,string dir)
{
	object logs;

	if( dir == "north" && me->query("gender") == "男性" && logs = present("liuxing yu",this_object()) )
	{
		return notify_fail(logs->name()+"伸手拦住了你：后面是内子居室，阁下男客，不便进入。\n");
	}

	if( dir == "north" && me->query("gender") == "无性" && logs = present("liuxing yu",this_object()) )
	{
		logs->kill_ob(me);
		me->fight_ob(logs);
		return notify_fail(logs->name()+"对你喝道：后面是内子居室，你这个不男不女的家伙想进去干什么？\n");
	}

	return 1;
}

int do_think(string arg)
{
	object me;

	me = this_player();
	if( random(me->query_skill("qimen-bagua",1))<20 && !me->query_temp("marks/xanadu_hall1") )
	{
		write("你想啊想，结果想破了脑袋，白白的脑浆流了一地。\n");
		me->receive_damage("sen",100);
	}
	else
	{
		write("你闷头苦思，突然发现地上有一块方砖似乎边缘特别的光滑。\n");
		me->set_temp("marks/xanadu_hall1",1);
	}
	return 1;
}                             

int do_uncover(string arg)
{
	object me,logs;
	int i,j,k,l;

	me = this_player();
	if(!arg || arg != "brick" || !me->query_temp("marks/xanadu_hall1") )//|| wizardp(me) )             
		return 0;
	if( (logs = present("liuxing yu",this_object())) )
	{
		message_vision("$N伸手拦住$n说：这位"+RANK_D->query_respect(me)+"且慢。\n",logs,me);		
	}
	else
	{
		message_vision(GRN"$N小心翼翼地把地板砖揭开，只听“叮”的一声轻响...\n"NOR,me);
		message_vision(RED"一蓬牛毛细针向$N射来，正好命中，只听你一声惨嚎，细针深深地钉入了你的手里！\n"NOR,me);		
		me->set_temp("last_damage_from",me); //hehe,别想用假死蒙混过关。
		me->receive_wound("kee",random(me->query("kar"))*80);
		me->apply_condition("iceshock",random(me->query("kar"))*3);
		COMBAT_D->report_status(me,me,1);                               
		if( me->query("kee") > 100 )
                {
			me->delete_temp("marks/xanadu_hall1");
			i=random(9);
			j=random(9);
			k=random(6);
			l=random(6);
			me->set_temp("marks/xanadu_hall2",l*1000+k*100+j*10+i);                                          
			write("你惊魂甫定，发现地板翻起来的背面刻着一行小字："+s1[i]+s1[9+j]+s1[18+k]+s1[18+l]+"\n");
		}
	}       
	return 1;
}
