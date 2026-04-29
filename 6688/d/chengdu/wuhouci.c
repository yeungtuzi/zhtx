
#include <ansi.h>
inherit ROOM;

void init();
int do_ketou(object me);
	
void create()
{
        set("short",HIR"武候祠"NOR);
	set("long",@LONG
	武候祠是祭祀三国时期蜀国丞相武乡候诸葛亮的祠堂。诸葛孔明惊才绝艳，未
出茅庐而知天下三分，然而却出师未捷身先死。每年清明，前来祭祀这位遗爱于后人的
四方人士络绎不绝。祠外遍植苍松翠柏，林间黄鹂啾啾；祠内庄严肃穆，诸葛丞相的塑
像(suxiang)居于正中，也许你应该向这位先人磕几个头(ketou)以示敬意。
LONG
	);
	
        set("exits", ([
		"south" : __DIR__"bailin3",
        ]));

	set("item_desc", ([
	    "suxiang" : "孔明的塑像看起来英俊倜倘，只是眉间似有重忧，仿佛还放不下刘皇叔的临终重托。\n",
        ]));

	setup();
}

void init()
{
	add_action("do_ketou", "ketou");
}

int do_ketou(object me)
{      
        me=this_player();
	message_vision("$N跪了下来，恭恭敬敬地向武候的塑像磕了一个头。\n",me);
	if( me->query("shen") >= 0 )
	{
		message_vision("$N只觉得胸臆之中一股正气充盈，感觉天地之间再无可惧之事！\n",me);
//		me->set("shen",(me->query("shen") + 200));
	}                                            
	else
	{
		message_vision("$N仰视塑像，只觉自己从前所为实是十恶不赦！\n",me);		
//		me->set("shen",me->query("shen") + 500);		
	}
//	me->set("gin",(me->query("gin") - (40+random(20))));
	return 1;	
}

