//LHQPAIFANG.C

#include <ansi.h>

inherit ROOM;                       

string *names = ({
	"yin yewang",
	"yin wufu",
	"yin wulu",
	"yin wushou",
});
	
void create()
{
	set("short", HIY"光明顶"NOR);
	set("long", @LONG
这里是昆仑山山颠的一片开阔地，四周白云环绕，青木遮天，正对
路中的是一座巨大的汉白玉牌坊。阳光照射在牌坊之上，衬着四周
云海，气势恢宏，令人为之仰止。这里就是武林中第一教派 － 明
教的总坛之所在。向北就是教中重地，无关人等最好不要入内。
LONG
	);

	set("exits", ([
		"north"	: __DIR__"center",
		"southdown" : __DIR__"shanlu4",
	]));

        set("objects",([
        	__DIR__"npc/yinwufu":1,
        	__DIR__"npc/yinwulu":1,
        	__DIR__"npc/yinwushou":1,
        	__DIR__"npc/yinyewang":1,		
	]));

	set("outdoors", "mingjiao");
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	string fml;
	int i;

	if(dir == "north")
	{
		if( (!fml=me->query("family/family_name")) || (fml != "明教") )
		for(i=0;i<4;i++)
		if( ob = present(names[i],this_object()) )
		{
			message_vision(HIR"\n"+ob->query("name")+"大喝一声：干什么的？！\n"NOR,me);
			return notify_fail(ob->query("name")+"挡住了你的去路！\n");
		}
	}
	return ::valid_leave(me, dir);
}

