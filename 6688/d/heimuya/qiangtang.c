// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

#include <ansi.h>

inherit ROOM;

int do_canxiu(string arg);

string wall_skill = "spear";
string wall_skill_cn = "枪";

void create()
{
        set("short",GRN"神"+wall_skill_cn+"阁"NOR);
        set("long", @LONG
	这是一间空荡荡的练功室，除了地下的蒲团以外没有什么别的
陈设，左面墙上挂着一把兵器，对面是一面石壁，上面刻着很多字。蒲团
上一人正在冥想，不时起来拔出兵器演练几下。
LONG
        );

        set("exits", ([
		"east"  :__DIR__"futang",
		"west"  :__DIR__"jiantang",
        ]));
        set("objects",([
                __DIR__"npc/yangyanqing" : 1,
        ]));

        setup();
}

void init()
{
	add_action("do_canxiu","canxiu");
}

int do_canxiu(string arg)
{
	object me;
	int level;

	me = this_player();
	if( me->query("family/family_name") != "日月神教" )
		return notify_fail("你不是神教弟子，不能参修这里的武功。\n");
	
        message_vision("$N专心地研究墙壁上的字迹。\n", me); 

        if ((int)me->query_skill("literate", 1) <= 150)  
        {
                 tell_object(me, "你似乎看不懂这些东西!\n");
 	         return 1;
        }
        tell_object(me, 
		"你发现这些字迹似乎和"+wall_skill_cn+"法有关!\n"
		"定神一看，最上面刻着:魔"+wall_skill_cn+"诀"+wall_skill_cn+"法精要。\n"
	);
	
	level = me->query_skill(wall_skill,1);

        if ( level <= 50) 
        {
                 tell_object(me, "这些对于你来说太深了！！！\n");
		 return 1;
        }
        if ( level > 120) 
        {
                 tell_object(me, "这些对于你来说太浅了！！！\n");
		 return 1;
        }
        if( me->query("combat_exp") < level*level/10*level )
                 return notify_fail("你经验不足，快去练功.\n");

	if( me->query("gin") < 50 )
                 return notify_fail("你太累了，还是休息一下吧.\n");
		
     me->receive_damage("gin", 30);
        tell_object(me, "你的基本"+wall_skill_cn+"法有所提高！！！\n");

	return 1;

}

